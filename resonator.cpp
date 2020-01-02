#pragma execution_character_set("utf-8") 
#include "resonator.h"


QSplineSeries series_pred;
QFile fp;
QTextStream out;

Resonator::Resonator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_Curve2d.InitCurve();
	showCurve();
	InitUI();
	remove("data/traj_pred.txt");
}


Resonator::~Resonator()
{
	m_showTimer->stop();
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
	m_bgT->setExclusive(true);

	m_vpbtnDirection.push_back(ui.m_pbtnUp);
	m_vpbtnDirection.push_back(ui.m_pbtnDown);
	m_vpbtnDirection.push_back(ui.m_pbtnLeft);
	m_vpbtnDirection.push_back(ui.m_pbtnRight);

	for (int k = 0; k < 4; k++)
	{
		QString filename = "pic/arrow_%1.ico";
		filename = filename.arg(m_vsDirection[k]);
		m_vpbtnDirection[k]->setIcon(QIcon(filename));
	}

	m_showTimer = new QTimer(this);
	m_showTimer->setInterval(10);
	connect(m_showTimer, SIGNAL(timeout()), this, SLOT(onShowTimerOut()));

	m_kalmanFilter = new KalmanFilter(6, 3, 0);
	m_kalmanFilter->Init();
}


void Resonator::showCurve()
{
	readTxtData("data/res_2d.txt", 2, dataVector);
	QList<QPointF> data;
	for (int k = 0;k < dataVector.size();k++)
		data.append(QPointF(dataVector[k][0], dataVector[k][1]));
	series_pred.setName("预测值");
	series_pred.setColor(QColor(0, 114, 182));
	series_pred.setUseOpenGL(true);
	series_pred.append(data);
	m_Curve2d.m_lineseries->setName("实际值");
	m_Curve2d.m_lineseries->append(data);
	m_Curve2d.m_chart->addSeries(m_Curve2d.m_lineseries);
	m_Curve2d.m_lineseries->attachAxis(m_Curve2d.m_axisX);
	m_Curve2d.m_lineseries->attachAxis(m_Curve2d.m_axisY);
	m_Curve2d.m_chart->addSeries(&series_pred);
	series_pred.attachAxis(m_Curve2d.m_axisX);
	series_pred.attachAxis(m_Curve2d.m_axisY);
	ui.m_chartView2dCurve->setChart(m_Curve2d.m_chart);

	readTxtData("data/res_3d_cy.txt", 3, dataVector);
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



void Resonator::onShowTimerOut()
{
	static int count = 0;
	static QList<QPointF> data_pred_2d;
	static QScatterDataArray * data_pred_3d = new QScatterDataArray();
	static VectorXd xprev = VectorXd::Zero(m_kalmanFilter->get_state_size());
	static VectorXd y_meas = VectorXd::Zero(m_kalmanFilter->get_meas_size());
	QPen pen(QColor(255, 0, 0), 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
	series_pred.setPen(pen);
	if (count < dataVector.size())
	{
		if (count == 0)
		{
			ui.m_3dSeries->dataProxy()->addItems(*data_pred_3d);
			fp.setFileName("data/traj_pred.txt");
			fp.open(QIODevice::ReadWrite | QIODevice::Text);
			out.setDevice(&fp);
			xprev << dataVector[count][0], 0, dataVector[count][1], 0,dataVector[count][2],0;
		}
		m_kalmanFilter->Predict(xprev);
		y_meas << dataVector[count][0],dataVector[count][1],dataVector[count][2];
		xprev = m_kalmanFilter->Update(y_meas);
		data_pred_2d.append(QPointF(xprev[2], xprev[4]));
		out << QString::number(xprev[0]) << "," << QString::number(xprev[2]) << "," << QString::number(xprev[4]) << "\r\n";
		series_pred.replace(data_pred_2d);
		data_pred_3d->append(QVector3D(xprev[2]*cos(xprev[0]), xprev[4], xprev[2]*sin(xprev[0])));
		ui.m_3dSeries->dataProxy()->resetArray(data_pred_3d);
		count++;
	}
}


void Resonator::on_m_pbtnTest_clicked()
{
	m_showTimer->start();
	return;
	
}