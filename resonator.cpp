#pragma execution_character_set("utf-8") 
#include "resonator.h"


QSplineSeries series_pred;
QFile fp;
QTextStream out;
int AxisTest = 1;

Resonator::Resonator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	showCurve();
	InitUI();
	remove("Resources/data/traj_pred.txt");
}


Resonator::~Resonator()
{
	m_showTimer->stop();
	int axis;
	int sRtn;
	sRtn = GT_Reset();
	for (axis = 1; axis <= 3; axis++)
	{
		sRtn = GT_AxisOff(axis);
	}
	sRtn = GT_Close();
}


void Resonator::InitUI()
{
	QButtonGroup * m_bgS = new QButtonGroup(this);
	QButtonGroup * m_bgR = new QButtonGroup(this);
	QButtonGroup * m_bgT = new QButtonGroup(this);
	m_bgS->addButton(ui.m_radioSPos);
	m_bgS->addButton(ui.m_radioSVel);
	m_bgS->setExclusive(true);
	m_bgR->addButton(ui.m_radioRPos);
	m_bgR->addButton(ui.m_radioRVel);
	m_bgR->setExclusive(true);
	m_bgT->addButton(ui.m_radioTPos);
	m_bgT->addButton(ui.m_radioTVel);
	m_bgT->addButton(ui.m_radioTPos);
	m_bgT->setExclusive(true);

	m_vpbtnDirection.push_back(ui.m_pbtnUp);
	m_vpbtnDirection.push_back(ui.m_pbtnDown);
	m_vpbtnDirection.push_back(ui.m_pbtnRight);
	m_vpbtnDirection.push_back(ui.m_pbtnLeft);

	for (int k = 0; k < 4; k++)
	{
		QString filename = "Resources/pic/arrow_%1.ico";
		filename = filename.arg(m_vstrDirection[k]);
		m_vpbtnDirection[k]->setIcon(QIcon(filename));
	}

	m_showTimer = new QTimer(this);
	m_showTimer->setInterval(10);
	connect(m_showTimer, SIGNAL(timeout()), this, SLOT(onShowTimerOut()));

	m_sensorTimer = new QTimer(this);
	m_sensorTimer->setInterval(100);
	connect(m_sensorTimer, SIGNAL(timeout()), this, SLOT(onSensorTimerOut()));

	m_vlineFeedPos.push_back(ui.m_lineSFeedPos);
	m_vlineFeedPos.push_back(ui.m_lineRFeedPos);
	m_vlineFeedPos.push_back(ui.m_lineTFeedPos);

	m_vlineLogPos.push_back(ui.m_lineSLogPos);
	m_vlineLogPos.push_back(ui.m_lineRLogPos);
	m_vlineLogPos.push_back(ui.m_lineTLogPos);

	m_vlineDestPos.push_back(ui.m_lineSDestPos);
	m_vlineDestPos.push_back(ui.m_lineRDestPos);
	m_vlineDestPos.push_back(ui.m_lineTDestPos);

	m_vlineDestVel.push_back(ui.m_lineSDestVel);
	m_vlineDestVel.push_back(ui.m_lineRDestVel);
	m_vlineDestVel.push_back(ui.m_lineTDestVel);

	m_vRadioState.push_back(ui.m_radioSPos);
	m_vRadioState.push_back(ui.m_radioRPos);
	m_vRadioState.push_back(ui.m_radioTPos);


	m_vpbtnRun.push_back(ui.m_pbtnSRun);
	m_vpbtnRun.push_back(ui.m_pbtnRRun);
	m_vpbtnRun.push_back(ui.m_pbtnTRun);

	m_vpbtnClear.push_back(ui.m_pbtnSClear);
	m_vpbtnClear.push_back(ui.m_pbtnRClear);
	m_vpbtnClear.push_back(ui.m_pbtnTClear);

	m_vpbtnStop.push_back(ui.m_pbtnSStop);
	m_vpbtnStop.push_back(ui.m_pbtnRStop);
	m_vpbtnStop.push_back(ui.m_pbtnTStop);
	m_vlineAxisState.push_back(ui.m_lineSaxisState);
	m_vlineAxisState.push_back(ui.m_lineRaxisState);
	m_vlineAxisState.push_back(ui.m_lineTaxisState);


	connect(ui.m_pbtnConnectCard, SIGNAL(clicked()), this, SLOT(onConnectCard()));
	connect(ui.m_pbtnDisconnectCard, SIGNAL(clicked()), this, SLOT(onDisconnectCard()));

	for (int k = 0; k < 3; k++)
	{
		connect(m_vpbtnRun[k], SIGNAL(clicked()), this, SLOT(onMotorRun()));
		connect(m_vpbtnStop[k], SIGNAL(clicked()), this, SLOT(onMotorStop()));
		connect(m_vpbtnClear[k], SIGNAL(clicked()), this, SLOT(onClearZeroPos()));

	}
	
	for (int k = 0; k < 4; k++)
	{
		connect(m_vpbtnDirection[k], SIGNAL(pressed()), this, SLOT(onAdjustDirectionRun()));
		connect(m_vpbtnDirection[k], SIGNAL(released()), this, SLOT(onMotorStop()));
	}

	m_bCardStatus = false;
	m_KalmanFilter = new KalmanFilter(6, 3, 0);
	m_KalmanFilter->Init("Resources/data/kalman.txt");
}

int Resonator::InitCard()
{
	int sRtn;
	sRtn = GT_Open();
	sRtn += GT_Reset();
	sRtn += GT_LoadConfig("./Resources/single_card/test.cfg");
	sRtn += GT_ClrSts(1, 8);
	sRtn += GT_SetSoftLimit(1, SoftLimit, -SoftLimit);
	sRtn += GT_SetSoftLimit(2, SoftLimit, -SoftLimit);
	return sRtn;
}

int Resonator::InitSensor()
{
	short sRtn;
	m_instantAiCtrl = InstantAiCtrl::Create();
	Array<DeviceTreeNode>* supportedDevices = m_instantAiCtrl->getSupportedDevices();
	if (supportedDevices->getCount() == 0)
	{
		return 1;
	}
	DeviceTreeNode const & node = supportedDevices->getItem(0);
	DeviceInformation selected(node.Description);
	ErrorCode errorcode = m_instantAiCtrl->setSelectedDevice(selected);
	if (errorcode != 0)
	{
		QMessageBox::information(this, "Warning Information", "Error");
		QCoreApplication::quit();
	}
	Array<ValueRange>* valueRanges = m_instantAiCtrl->getFeatures()->getValueRanges();
	wchar_t vrgDesp[128];
	MathInterval ranges;
	for (int k = 0; k < valueRanges->getCount(); k++)
	{
		errorcode = AdxGetValueRangeInformation(valueRanges->getItem(k), sizeof(vrgDesp), vrgDesp, &ranges, NULL);
		CheckError(errorcode);
		QString str = QString::fromWCharArray(vrgDesp);
		m_vstrValueRange.push_back(str);
	}
	m_configure.channelStart = 0;
	m_configure.channelCount = 2;
	m_configure.valueRange = valueRanges->getItem(0);
	m_configure.profilePath = QString("./Resources/profile/DemoDevice.xml").toStdWString().c_str();

	errorcode = m_instantAiCtrl->LoadProfile(m_configure.profilePath);
	CheckError(errorcode);

	Array<AiChannel> * channels = m_instantAiCtrl->getChannels();
	for (int k = 0; k < channels->getCount(); k++)
	{
		channels->getItem(k).setValueRange(m_configure.valueRange);
	}
	supportedDevices->Dispose();

	return 0;
}

void Resonator::CommandHandler(int sRtn, QString msg)
{
	if (!sRtn)
		QMessageBox::information(this, "infomation", msg + "成功");
	else
		QMessageBox::warning(this, "warning", msg + "失败");
}

void Resonator::CheckError(ErrorCode errorcode)
{
	if (errorcode >= 0xE0000000 && errorcode != Success)
	{
		QString msg = tr("Sorr,there are some errors occured, Error Code 0x") + QString::number(errorcode, 16).right(8).toUpper();
		qDebug() << msg << endl;
	}
}

void Resonator::showCurve()
{
	QVector<double> param = { -300,0,-300,0,10,4 };
	m_Curve2d.InitCurve(param);
	m_polarCurve2d.InitCurve();
	ui.m_chartViewPolarCurve->setChart(m_polarCurve2d.m_polarChart);
	ui.m_chartViewTraj->setChart(m_Curve2d.m_chart);
}

void Resonator::readTxtData(QString filename, int num_var, QVector<QVector<double>>& data)
{
	data.clear();
	QFile fp(filename);
	if (!fp.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return;
	}
	QTextStream in(&fp);
	QStringList numList;
	QVector<double> tmp;
	while (!in.atEnd())
	{
		numList = in.readLine().split(" ");
		tmp.clear();
		for (int k = 0;k < num_var;k++)
		{
			tmp.push_back(numList[k].toDouble());
		}
		data.push_back(tmp);
	}
}

void Resonator::MotorRun(int axis, MotionMode mode, int sign)
{
	short sRtn;
	long sts;
	double dVel;

	dVel = m_vlineDestVel[axis - 1]->text().toDouble();
	if (sign<0)
		dVel = sign*fabs(dVel);

	sRtn = GT_AxisOn(axis);
	m_vlineAxisState[axis - 1]->setText("1");
	if (mode == POS)
	{
		PosMotionThread * posthread = new PosMotionThread(axis, m_vlineDestPos[axis - 1]->text().toDouble(), dVel);
		connect(posthread, SIGNAL(MotionFinished(int)), this, SLOT(onPosMotionFinished(int)));
		posthread->start();
	}
	else if (mode == VEL)
	{
		TJogPrm jog;
		sRtn = GT_PrfJog(axis);
		sRtn = GT_GetJogPrm(axis, &jog);
		jog.acc = 0.0625;
		jog.dec = 0.0625;
		sRtn = GT_SetJogPrm(axis, &jog);
		sRtn = GT_SetVel(axis, dVel);
		sRtn = GT_Update(1 << (axis - 1));
	}
	else
	{
		QMessageBox::warning(this, "warning", "运动类型错误");
	}
}

void Resonator::EmergencyStop()
{
	short sRtn = GT_Reset();
	for (int axis = 1; axis <= 3; axis++)
	{
		sRtn = GT_AxisOff(axis);
	}
}

void Resonator::onSensorTimerOut()
{
	double m_dscaledData[16];
	ErrorCode errorcode = Success;
	errorcode = m_instantAiCtrl->Read(m_configure.channelStart, m_configure.channelCount, m_dscaledData);
	if (errorcode != Success)
		return;
	double dSensorPos = m_dSensorProp*m_dscaledData[0];
	ui.m_lineSensorData->setText(QString::number(m_dscaledData[0]));
	if (fabs(dSensorPos) > 300)
	{
		dSensorPos = (1 - (dSensorPos < 0) * 2)*300;
	}
	ui.m_prbrSensorData->setValue(dSensorPos);
	static QList<QPointF> data_sc;
	static QList<QPointF> data_line;
	static double dmeanL = 0;
	static double count = 0;
	int dAngle = ui.m_lineTFeedPos->text().toInt() % (int)m_dAngleProp;
	dAngle = dAngle * 360.0 / m_dAngleProp;
	
	if (data_line.isEmpty())
	{
		for (int k = 0; k < 360; k++)
			data_line.append(QPointF(k, 15));
	}
	else
	{
		
		for (int k = 0; k < 360; k++)
		{
			if (fabs(data_line[k].x() - dAngle) < 5)
			{
				dmeanL = (dmeanL*count + dSensorPos) / (count+1);
				count++;
				data_line[k].setY(15 + (dSensorPos -dmeanL)/5);
			}
		}
		if (count==360)
		{
			dmeanL = 0;
			count = 0;
		}
	}
	data_sc.clear();
	data_sc.append(QPointF(dAngle,10));
	m_polarCurve2d.m_scatterSeries->replace(data_sc);
	m_polarCurve2d.m_lineSeries->replace(data_line);

}

void Resonator::onShowTimerOut()
{
	if (!m_bCardStatus)
		return;
	double prfPos;
	int sRtn;
	double encPos;
	int axis;
	double dPos[3];
	bool moveStatus = false;
	
	for (axis = 1; axis <= 3; axis++)
	{
		sRtn = GT_GetPrfPos(axis, &prfPos);
		m_vlineLogPos[axis - 1]->setText(QString::number(prfPos));
		sRtn = GT_GetEncPos(axis, &encPos);
		dPos[axis - 1] = encPos/2000;
		if (m_vlineAxisState[axis - 1]->text().toInt() == 1)
		{
			moveStatus = true;
			QString filename;
			filename.sprintf("./Resources/data/%c.txt", m_vstrAxisName[axis - 1]);
			QFile fw(filename);
			fw.open(QIODevice::WriteOnly | QIODevice::Append);
			QTextStream out(&fw);
			out << QString::number(prfPos) << "   " << QString::number(encPos) << "\r\n";
		}
		m_vlineFeedPos[axis - 1]->setText(QString::number(encPos));
	}

	if (moveStatus)
	{
		static QList<QPointF> data_sc;
		static QList<QPointF> data_line;
		data_sc.clear();
		data_sc.append(QPointF(dPos[1], dPos[0]));
		data_line.append(QPointF(dPos[1], dPos[0]));
		m_Curve2d.m_lineSeries->replace(data_line);
		m_Curve2d.m_scatterSeries->replace(data_sc);
	}
	
}

void Resonator::onClearZeroPos()
{

	QPushButton * btn = qobject_cast<QPushButton*>(sender());
	int axis = m_vpbtnClear.indexOf(btn) + 1;
	int sRtn = GT_ZeroPos(axis);
	CommandHandler(sRtn, m_vstrAxisName[axis - 1] + "清零");
}

void  Resonator::onMotorRun()
{
	if (m_bCardStatus)
	{
		QPushButton * btn = qobject_cast<QPushButton *>(sender());
		int axis = m_vpbtnRun.indexOf(btn) + 1;
		int sRtn = GT_AxisOn(axis);
		if (m_vRadioState[axis - 1]->isChecked())
		{
			MotorRun(axis, POS);
		}
		else
		{
			MotorRun(axis, VEL);
		}
	}
	else
	{
		QMessageBox::warning(this, "warning", "下位机未连接");
	}
}

void Resonator::onMotorStop()
{
	QPushButton * btn = qobject_cast<QPushButton *>(sender());
	int axis = m_vpbtnStop.indexOf(btn) + 1;
	if (axis == 0)
	{
		axis = m_vpbtnDirection.indexOf(btn) / 2 + 1;
	}
	int sRtn = GT_AxisOff(axis);
	m_vlineAxisState[axis - 1]->setText("0");
}

void Resonator::onConnectCard()
{
	int status = 0;
	status += InitCard();
	status += InitSensor();
	m_bCardStatus = true;
	m_showTimer->start();
	ui.m_pbtnConnectCard->setEnabled(false);
	ui.m_pbtnDisconnectCard->setEnabled(true);
	ui.m_pbtnMeasureStart->setEnabled(true);
}

void Resonator::onDisconnectCard()
{
	int axis;
	int sRtn;
	sRtn = GT_Reset();
	for (axis = 1; axis <= 3; axis++)
	{
		sRtn = GT_AxisOff(axis);
	}
	sRtn = GT_Close();
	m_instantAiCtrl->Dispose();
	m_showTimer->stop();
	m_bCardStatus = false;
	ui.m_pbtnConnectCard->setEnabled(true);
	ui.m_pbtnDisconnectCard->setEnabled(false);
	ui.m_pbtnMeasureStart->setEnabled(false);

}

void Resonator::onAdjustDirectionRun()
{
	if (m_bCardStatus)
	{
		QPushButton * btn = qobject_cast<QPushButton *>(sender());
		int Idx = m_vpbtnDirection.indexOf(btn);
		int axis = Idx / 2 + 1;
		int sign = 1 - (Idx % 2) * 2;
		MotorRun(axis, VEL, sign);
	}
	else
		QMessageBox::warning(this, "warning", "下位机未连接");
}

void Resonator::onPosMotionFinished(int axis)
{
	m_vlineAxisState[axis - 1]->setText("0");
}

void Resonator::on_m_pbtnEmerStop_clicked()
{
	EmergencyStop();
}

void Resonator::on_m_pbtnInitCrd_clicked()
{
	short sRtn;
	TCrdPrm crdPrm;

	memset(&crdPrm, 0, sizeof(crdPrm));
	crdPrm.dimension = 2;                        
	crdPrm.synVelMax = 5;                      
	crdPrm.synAccMax = 0.1;                        // 坐标系的最大合成加速度
	crdPrm.evenTime = 0;                         // 坐标系的最小匀速时间为0
	crdPrm.profile[0] = 1;                       // 规划器1对应到X轴                       
	crdPrm.profile[1] = 2;                       // 规划器2对应到Y轴
	crdPrm.profile[2] = 0;
	crdPrm.profile[3] = 0;
	crdPrm.profile[4] = 0;
	crdPrm.profile[5] = 0;
	crdPrm.profile[6] = 0;
	crdPrm.profile[7] = 0;
	crdPrm.setOriginFlag = 1;                    // 需要设置加工坐标系原点位置
	crdPrm.originPos[0] = 0;                     // 加工坐标系原点位置在(0,0)，即与机床坐标系原点重合
	crdPrm.originPos[1] = 0;
	crdPrm.originPos[2] = 0;
	crdPrm.originPos[3] = 0;
	crdPrm.originPos[4] = 0;
	crdPrm.originPos[5] = 0;
	crdPrm.originPos[6] = 0;
	crdPrm.originPos[7] = 0;

	sRtn = GT_SetCrdPrm(1, &crdPrm);
	CommandHandler(sRtn, "坐标系建立");
}

void Resonator::on_m_pbtnTest_clicked()
{
}

void Resonator::on_m_pbtnMeasureStart_clicked()
{
	QString text = "采集数据";
	if (ui.m_pbtnMeasureStart->text() == text)
	{
		m_sensorTimer->start();
		ui.m_pbtnMeasureStart->setText("停止采集");
	}
	else
	{
		m_sensorTimer->stop();
		ui.m_pbtnMeasureStart->setText(text);
	}

}