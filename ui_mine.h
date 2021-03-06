/********************************************************************************
** Form generated from reading UI file 'resonator.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESONATOR_H
#define UI_RESONATOR_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include <QtDataVisualization/Q3DScatter>
#include <QProgressBar>
#include "polarcurve_2d.h"
using namespace QtDataVisualization;
QT_BEGIN_NAMESPACE

class Ui_ResonatorClass
{
public:
	QWidget *centralWidget;
	QVBoxLayout *verticalLayout;
	QGridLayout *m_gridLayoutAxis;
	QLabel *m_labelLogPos;
	QLineEdit *m_lineSLogPos;
	QRadioButton *m_radioRPos;
	QRadioButton *m_radioSPos;
	QPushButton *m_pbtnSHome;
	QLabel *m_labelR;
	QLineEdit *m_lineRDestPos;
	QLabel *m_labelAxisNum;
	QPushButton *m_pbtnRRun;
	QLabel *m_labelDestPos;
	QLineEdit *m_lineSDestVel;
	QLabel *m_labelFeedPos;
	QPushButton *m_pbtnSRun;
	QLineEdit *m_lineSaxisState;
	QLineEdit *m_lineRDestVel;
	QRadioButton *m_radioRVel;
	QLabel *m_labelDestVel;
	QRadioButton *m_radioSVel;
	QLineEdit *m_lineSDestPos;
	QLineEdit *m_lineSFeedPos;
	QLabel *m_labelAxisState;
	QPushButton *m_pbtnSStop;
	QPushButton *m_pbtnSClear;
	QLineEdit *m_lineRLogPos;
	QLabel *m_labelS;
	QLineEdit *m_lineRFeedPos;
	QPushButton *m_pbtnTClear;
	QPushButton *m_pbtnTRun;
	QLineEdit *m_lineTaxisState;
	QRadioButton *m_radioTVel;
	QLineEdit *m_lineTLogPos;
	QLineEdit *m_lineTFeedPos;
	QLineEdit *m_lineTDestPos;
	QPushButton *m_pbtnTHome;
	QPushButton *m_pbtnRStop;
	QLineEdit *m_lineTDestVel;
	QRadioButton *m_radioTPos;
	QPushButton *m_pbtnTStop;
	QPushButton *m_pbtnRClear;
	QLabel *m_labelT;
	QLineEdit *m_lineRaxisState;
	QPushButton *m_pbtnRHome;
	QChartView *m_chartViewPolarCurve;
	QChartView *m_chartViewTraj;
	QMenuBar *menuBar;
	QToolBar *mainToolBar;
	QStatusBar *statusBar;
	QGridLayout * m_gridLayoutPlot;

	//测试
	QPushButton *m_pbtnTest;
	QPushButton *m_pbtnEmerStop;
	QPushButton *m_pbtnInitCoordinate;
	QPushButton *m_pbtnLinearMotion;
	QPushButton *m_pbtnUp;
	QPushButton *m_pbtnDown;
	QPushButton *m_pbtnLeft;
	QPushButton *m_pbtnRight;
	QHBoxLayout *m_hbLayoutTest;

	QHBoxLayout *m_hbLayoutSensor;
	QPushButton *m_pbtnConnectCard;
	QPushButton *m_pbtnDisconnectCard;
	QPushButton *m_pbtnMeasureStart;
	QLabel *m_labelSensorData;
	QLineEdit *m_lineSensorData;
	QProgressBar *m_prbrSensorData;
	void setupUi(QMainWindow *ResonatorClass)
	{
		if (ResonatorClass->objectName().isEmpty())
			ResonatorClass->setObjectName(QStringLiteral("ResonatorClass"));
		ResonatorClass->resize(1043, 642);
		centralWidget = new QWidget(ResonatorClass);
		centralWidget->setObjectName(QStringLiteral("centralWidget"));
		verticalLayout = new QVBoxLayout(centralWidget);
		verticalLayout->setSpacing(6);
		verticalLayout->setContentsMargins(11, 11, 11, 11);
		verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
		
		addMotionWidget(ResonatorClass);
		addTestButton(ResonatorClass);
		verticalLayout->addLayout(m_hbLayoutTest);

		addSensorWidget(ResonatorClass);
		verticalLayout->addLayout(m_hbLayoutSensor);
		addPlotWidget(ResonatorClass);
		verticalLayout->addLayout(m_gridLayoutPlot);
		ResonatorClass->setCentralWidget(centralWidget);
		menuBar = new QMenuBar(ResonatorClass);
		menuBar->setObjectName(QStringLiteral("menuBar"));
		menuBar->setGeometry(QRect(0, 0, 1043, 23));
		ResonatorClass->setMenuBar(menuBar);
		mainToolBar = new QToolBar(ResonatorClass);
		mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
		ResonatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
		statusBar = new QStatusBar(ResonatorClass);
		statusBar->setObjectName(QStringLiteral("statusBar"));
		ResonatorClass->setStatusBar(statusBar);

		retranslateUi(ResonatorClass);

		QMetaObject::connectSlotsByName(ResonatorClass);
	}

	void addMotionWidget(QMainWindow *ResonatorClass)
	{
		m_gridLayoutAxis = new QGridLayout();
		m_gridLayoutAxis->setSpacing(6);
		m_gridLayoutAxis->setObjectName(QStringLiteral("m_gridLayoutAxis"));
		m_gridLayoutAxis->setContentsMargins(0, -1, -1, -1);
		m_labelLogPos = new QLabel(centralWidget);
		m_labelLogPos->setObjectName(QStringLiteral("m_labelLogPos"));

		m_gridLayoutAxis->addWidget(m_labelLogPos, 0, 1, 1, 1);

		m_lineSLogPos = new QLineEdit(centralWidget);
		m_lineSLogPos->setObjectName(QStringLiteral("m_lineSLogPos"));
		m_lineSLogPos->setEnabled(true);
		m_lineSLogPos->setContextMenuPolicy(Qt::DefaultContextMenu);
		m_lineSLogPos->setReadOnly(true);
		m_lineSLogPos->setClearButtonEnabled(false);

		m_gridLayoutAxis->addWidget(m_lineSLogPos, 2, 1, 1, 1);

		m_radioRPos = new QRadioButton(centralWidget);
		m_radioRPos->setObjectName(QStringLiteral("m_radioRPos"));
		m_radioRPos->setChecked(false);
		m_radioRPos->setAutoExclusive(false);

		m_gridLayoutAxis->addWidget(m_radioRPos, 3, 6, 1, 1);

		m_radioSPos = new QRadioButton(centralWidget);
		m_radioSPos->setObjectName(QStringLiteral("m_radioSPos"));
		m_radioSPos->setChecked(false);
		m_radioSPos->setAutoExclusive(false);

		m_gridLayoutAxis->addWidget(m_radioSPos, 2, 6, 1, 1);

		m_pbtnSHome = new QPushButton(centralWidget);
		m_pbtnSHome->setObjectName(QStringLiteral("m_pbtnSHome"));

		m_gridLayoutAxis->addWidget(m_pbtnSHome, 2, 11, 1, 1);

		m_labelR = new QLabel(centralWidget);
		m_labelR->setObjectName(QStringLiteral("m_labelR"));

		m_gridLayoutAxis->addWidget(m_labelR, 3, 0, 1, 1);

		m_lineRDestPos = new QLineEdit(centralWidget);
		m_lineRDestPos->setObjectName(QStringLiteral("m_lineRDestPos"));

		m_gridLayoutAxis->addWidget(m_lineRDestPos, 3, 3, 1, 1);

		m_labelAxisNum = new QLabel(centralWidget);
		m_labelAxisNum->setObjectName(QStringLiteral("m_labelAxisNum"));

		m_gridLayoutAxis->addWidget(m_labelAxisNum, 0, 0, 1, 1);

		m_pbtnRRun = new QPushButton(centralWidget);
		m_pbtnRRun->setObjectName(QStringLiteral("m_pbtnRRun"));

		m_gridLayoutAxis->addWidget(m_pbtnRRun, 3, 7, 1, 1);

		m_labelDestPos = new QLabel(centralWidget);
		m_labelDestPos->setObjectName(QStringLiteral("m_labelDestPos"));

		m_gridLayoutAxis->addWidget(m_labelDestPos, 0, 3, 1, 1);

		m_lineSDestVel = new QLineEdit(centralWidget);
		m_lineSDestVel->setObjectName(QStringLiteral("m_lineSDestVel"));

		m_gridLayoutAxis->addWidget(m_lineSDestVel, 2, 4, 1, 1);

		m_labelFeedPos = new QLabel(centralWidget);
		m_labelFeedPos->setObjectName(QStringLiteral("m_labelFeedPos"));

		m_gridLayoutAxis->addWidget(m_labelFeedPos, 0, 2, 1, 1);

		m_pbtnSRun = new QPushButton(centralWidget);
		m_pbtnSRun->setObjectName(QStringLiteral("m_pbtnSRun"));

		m_gridLayoutAxis->addWidget(m_pbtnSRun, 2, 7, 1, 1);

		m_lineSaxisState = new QLineEdit(centralWidget);
		m_lineSaxisState->setObjectName(QStringLiteral("m_lineSaxisState"));
		m_lineSaxisState->setReadOnly(true);

		m_gridLayoutAxis->addWidget(m_lineSaxisState, 2, 12, 1, 1);

		m_lineRDestVel = new QLineEdit(centralWidget);
		m_lineRDestVel->setObjectName(QStringLiteral("m_lineRDestVel"));

		m_gridLayoutAxis->addWidget(m_lineRDestVel, 3, 4, 1, 1);

		m_radioRVel = new QRadioButton(centralWidget);
		m_radioRVel->setObjectName(QStringLiteral("m_radioRVel"));
		m_radioRVel->setChecked(true);
		m_radioRVel->setAutoExclusive(false);

		m_gridLayoutAxis->addWidget(m_radioRVel, 3, 5, 1, 1);

		m_labelDestVel = new QLabel(centralWidget);
		m_labelDestVel->setObjectName(QStringLiteral("m_labelDestVel"));

		m_gridLayoutAxis->addWidget(m_labelDestVel, 0, 4, 1, 1);

		m_radioSVel = new QRadioButton(centralWidget);
		m_radioSVel->setObjectName(QStringLiteral("m_radioSVel"));
		m_radioSVel->setChecked(true);
		m_radioSVel->setAutoExclusive(false);

		m_gridLayoutAxis->addWidget(m_radioSVel, 2, 5, 1, 1);

		m_lineSDestPos = new QLineEdit(centralWidget);
		m_lineSDestPos->setObjectName(QStringLiteral("m_lineSDestPos"));

		m_gridLayoutAxis->addWidget(m_lineSDestPos, 2, 3, 1, 1);

		m_lineSFeedPos = new QLineEdit(centralWidget);
		m_lineSFeedPos->setObjectName(QStringLiteral("m_lineSFeedPos"));
		m_lineSFeedPos->setEnabled(true);
		m_lineSFeedPos->setReadOnly(true);

		m_gridLayoutAxis->addWidget(m_lineSFeedPos, 2, 2, 1, 1);

		m_labelAxisState = new QLabel(centralWidget);
		m_labelAxisState->setObjectName(QStringLiteral("m_labelAxisState"));

		m_gridLayoutAxis->addWidget(m_labelAxisState, 0, 12, 1, 1);

		m_pbtnSStop = new QPushButton(centralWidget);
		m_pbtnSStop->setObjectName(QStringLiteral("m_pbtnSStop"));

		m_gridLayoutAxis->addWidget(m_pbtnSStop, 2, 8, 1, 1);

		m_pbtnSClear = new QPushButton(centralWidget);
		m_pbtnSClear->setObjectName(QStringLiteral("m_pbtnSClear"));

		m_gridLayoutAxis->addWidget(m_pbtnSClear, 2, 9, 1, 1);

		m_lineRLogPos = new QLineEdit(centralWidget);
		m_lineRLogPos->setObjectName(QStringLiteral("m_lineRLogPos"));

		m_gridLayoutAxis->addWidget(m_lineRLogPos, 3, 1, 1, 1);

		m_labelS = new QLabel(centralWidget);
		m_labelS->setObjectName(QStringLiteral("m_labelS"));

		m_gridLayoutAxis->addWidget(m_labelS, 2, 0, 1, 1);

		m_lineRFeedPos = new QLineEdit(centralWidget);
		m_lineRFeedPos->setObjectName(QStringLiteral("m_lineRFeedPos"));

		m_gridLayoutAxis->addWidget(m_lineRFeedPos, 3, 2, 1, 1);

		m_pbtnTClear = new QPushButton(centralWidget);
		m_pbtnTClear->setObjectName(QStringLiteral("m_pbtnTClear"));

		m_gridLayoutAxis->addWidget(m_pbtnTClear, 4, 9, 1, 1);

		m_pbtnTRun = new QPushButton(centralWidget);
		m_pbtnTRun->setObjectName(QStringLiteral("m_pbtnTRun"));

		m_gridLayoutAxis->addWidget(m_pbtnTRun, 4, 7, 1, 1);

		m_lineTaxisState = new QLineEdit(centralWidget);
		m_lineTaxisState->setObjectName(QStringLiteral("m_lineTaxisState"));
		m_lineTaxisState->setReadOnly(true);

		m_gridLayoutAxis->addWidget(m_lineTaxisState, 4, 12, 1, 1);

		m_radioTVel = new QRadioButton(centralWidget);
		m_radioTVel->setObjectName(QStringLiteral("m_radioTVel"));
		m_radioTVel->setChecked(true);
		m_radioTVel->setAutoExclusive(false);

		m_gridLayoutAxis->addWidget(m_radioTVel, 4, 5, 1, 1);

		m_lineTLogPos = new QLineEdit(centralWidget);
		m_lineTLogPos->setObjectName(QStringLiteral("m_lineTLogPos"));

		m_gridLayoutAxis->addWidget(m_lineTLogPos, 4, 1, 1, 1);

		m_lineTFeedPos = new QLineEdit(centralWidget);
		m_lineTFeedPos->setObjectName(QStringLiteral("m_lineTFeedPos"));

		m_gridLayoutAxis->addWidget(m_lineTFeedPos, 4, 2, 1, 1);

		m_lineTDestPos = new QLineEdit(centralWidget);
		m_lineTDestPos->setObjectName(QStringLiteral("m_lineTDestPos"));

		m_gridLayoutAxis->addWidget(m_lineTDestPos, 4, 3, 1, 1);

		m_pbtnTHome = new QPushButton(centralWidget);
		m_pbtnTHome->setObjectName(QStringLiteral("m_pbtnTHome"));

		m_gridLayoutAxis->addWidget(m_pbtnTHome, 4, 11, 1, 1);

		m_pbtnRStop = new QPushButton(centralWidget);
		m_pbtnRStop->setObjectName(QStringLiteral("m_pbtnRStop"));

		m_gridLayoutAxis->addWidget(m_pbtnRStop, 3, 8, 1, 1);

		m_lineTDestVel = new QLineEdit(centralWidget);
		m_lineTDestVel->setObjectName(QStringLiteral("m_lineTDestVel"));

		m_gridLayoutAxis->addWidget(m_lineTDestVel, 4, 4, 1, 1);

		m_radioTPos = new QRadioButton(centralWidget);
		m_radioTPos->setObjectName(QStringLiteral("m_radioTPos"));
		m_radioTPos->setChecked(false);
		m_radioTPos->setAutoExclusive(false);

		m_gridLayoutAxis->addWidget(m_radioTPos, 4, 6, 1, 1);

		m_pbtnTStop = new QPushButton(centralWidget);
		m_pbtnTStop->setObjectName(QStringLiteral("m_pbtnTStop"));

		m_gridLayoutAxis->addWidget(m_pbtnTStop, 4, 8, 1, 1);

		m_pbtnRClear = new QPushButton(centralWidget);
		m_pbtnRClear->setObjectName(QStringLiteral("m_pbtnRClear"));

		m_gridLayoutAxis->addWidget(m_pbtnRClear, 3, 9, 1, 1);

		m_labelT = new QLabel(centralWidget);
		m_labelT->setObjectName(QStringLiteral("m_labelT"));

		m_gridLayoutAxis->addWidget(m_labelT, 4, 0, 1, 1);

		m_lineRaxisState = new QLineEdit(centralWidget);
		m_lineRaxisState->setObjectName(QStringLiteral("m_lineRaxisState"));
		m_lineRaxisState->setReadOnly(true);

		m_gridLayoutAxis->addWidget(m_lineRaxisState, 3, 12, 1, 1);

		m_pbtnRHome = new QPushButton(centralWidget);
		m_pbtnRHome->setObjectName(QStringLiteral("m_pbtnRHome"));

		m_gridLayoutAxis->addWidget(m_pbtnRHome, 3, 11, 1, 1);

		verticalLayout->addLayout(m_gridLayoutAxis);
	}
	void addTestButton(QMainWindow *ResonatorClass)
	{
		m_pbtnTest = new QPushButton("测试", ResonatorClass);
		m_pbtnTest->setObjectName(QStringLiteral("m_pbtnTest"));
		m_pbtnEmerStop = new QPushButton("紧急停止", ResonatorClass);
		m_pbtnEmerStop->setObjectName(QStringLiteral("m_pbtnEmerStop"));

		m_pbtnInitCoordinate = new QPushButton("建立坐标系", ResonatorClass);
		m_pbtnInitCoordinate->setObjectName(QStringLiteral("m_pbtnInitCrd"));
		m_pbtnLinearMotion = new QPushButton("直线插补", ResonatorClass);
		m_pbtnUp = new QPushButton(ResonatorClass);
		m_pbtnDown = new QPushButton(ResonatorClass);
		m_pbtnLeft = new QPushButton(ResonatorClass);
		m_pbtnRight = new QPushButton(ResonatorClass);
		m_hbLayoutTest = new QHBoxLayout();
		m_hbLayoutTest->addWidget(m_pbtnTest);
		m_hbLayoutTest->addWidget(m_pbtnEmerStop);
		m_hbLayoutTest->addWidget(m_pbtnInitCoordinate);
		m_hbLayoutTest->addWidget(m_pbtnLinearMotion);
		m_hbLayoutTest->addWidget(m_pbtnUp);
		m_hbLayoutTest->addWidget(m_pbtnDown);
		m_hbLayoutTest->addWidget(m_pbtnLeft);
		m_hbLayoutTest->addWidget(m_pbtnRight);
	}
	void addSensorWidget(QMainWindow *ResonatorClass)
	{
		m_pbtnConnectCard = new QPushButton("连接下位机");
		m_pbtnDisconnectCard = new QPushButton("断开连接");
		m_pbtnDisconnectCard->setEnabled(false);
		m_pbtnMeasureStart = new QPushButton("采集数据");
		m_pbtnMeasureStart->setEnabled(false);
		m_pbtnMeasureStart->setObjectName("m_pbtnMeasureStart");
		m_labelSensorData = new QLabel(ResonatorClass);
		m_labelSensorData->setText("探头数据");
		m_labelSensorData->setObjectName(QStringLiteral("m_labelSensorData"));

		m_lineSensorData = new QLineEdit(ResonatorClass);
		m_prbrSensorData = new QProgressBar(ResonatorClass);
		m_prbrSensorData->setRange(-300, 300);
		m_prbrSensorData->setOrientation(Qt::Horizontal);
		m_prbrSensorData->setFormat("%v");
		m_prbrSensorData->setStyleSheet("QProgressBar::chunk {border: none;background: rgb(0, 160, 230);}");
		m_prbrSensorData->setFixedWidth(300);
		m_prbrSensorData->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
		m_hbLayoutSensor = new QHBoxLayout();
		m_hbLayoutSensor->addWidget(m_pbtnConnectCard);
		m_hbLayoutSensor->addWidget(m_pbtnDisconnectCard);
		m_hbLayoutSensor->addWidget(m_pbtnMeasureStart);
		m_hbLayoutSensor->addWidget(m_labelSensorData);
		m_hbLayoutSensor->addWidget(m_lineSensorData);
		m_hbLayoutSensor->addWidget(m_prbrSensorData);
		m_hbLayoutSensor->addStretch(3);
	}
	void addPlotWidget(QMainWindow * ResonatorClass)
	{
		m_gridLayoutPlot = new QGridLayout();
		m_chartViewPolarCurve = new QChartView();
		m_chartViewPolarCurve->setObjectName(QStringLiteral("m_chartViewPolarCurve"));

		m_chartViewTraj = new QChartView();
		m_chartViewPolarCurve->setObjectName(QStringLiteral("m_chartViewTraj"));

		m_gridLayoutPlot->addWidget(m_chartViewPolarCurve, 0, 0);
		m_gridLayoutPlot->addWidget(m_chartViewTraj, 0, 1);
	}
	void retranslateUi(QMainWindow *ResonatorClass)
	{
		ResonatorClass->setWindowTitle(QApplication::translate("ResonatorClass", "Resonator", Q_NULLPTR));
		m_labelLogPos->setText(QApplication::translate("ResonatorClass", "\351\200\273\350\276\221\344\275\215\347\275\256", Q_NULLPTR));
		m_lineSLogPos->setText(QApplication::translate("ResonatorClass", "0", Q_NULLPTR));
		m_radioRPos->setText(QApplication::translate("ResonatorClass", "\344\275\215\347\275\256\346\250\241\345\274\217", Q_NULLPTR));
		m_radioSPos->setText(QApplication::translate("ResonatorClass", "\344\275\215\347\275\256\346\250\241\345\274\217", Q_NULLPTR));
		m_pbtnSHome->setText(QApplication::translate("ResonatorClass", "S\345\233\236\351\233\266", Q_NULLPTR));
		m_labelR->setText(QApplication::translate("ResonatorClass", "R", Q_NULLPTR));
		m_lineRDestPos->setText(QApplication::translate("ResonatorClass", "200", Q_NULLPTR));
		m_labelAxisNum->setText(QApplication::translate("ResonatorClass", "\350\275\264\345\217\267", Q_NULLPTR));
		m_pbtnRRun->setText(QApplication::translate("ResonatorClass", "Rrun", Q_NULLPTR));
		m_labelDestPos->setText(QApplication::translate("ResonatorClass", "\347\233\256\346\240\207\344\275\215\347\275\256\350\256\276\345\256\232", Q_NULLPTR));
		m_lineSDestVel->setText(QApplication::translate("ResonatorClass", "5", Q_NULLPTR));
		m_labelFeedPos->setText(QApplication::translate("ResonatorClass", "\345\217\215\351\246\210\344\275\215\347\275\256", Q_NULLPTR));
		m_pbtnSRun->setText(QApplication::translate("ResonatorClass", "Srun", Q_NULLPTR));
		m_lineSaxisState->setText(QApplication::translate("ResonatorClass", "0", Q_NULLPTR));
		m_lineRDestVel->setText(QApplication::translate("ResonatorClass", "5", Q_NULLPTR));
		m_radioRVel->setText(QApplication::translate("ResonatorClass", "\351\200\237\345\272\246\346\250\241\345\274\217", Q_NULLPTR));
		m_labelDestVel->setText(QApplication::translate("ResonatorClass", "\347\233\256\346\240\207\351\200\237\345\272\246\350\256\276\345\256\232", Q_NULLPTR));
		m_radioSVel->setText(QApplication::translate("ResonatorClass", "\351\200\237\345\272\246\346\250\241\345\274\217", Q_NULLPTR));
		m_lineSDestPos->setText(QApplication::translate("ResonatorClass", "200", Q_NULLPTR));
		m_lineSFeedPos->setText(QApplication::translate("ResonatorClass", "0", Q_NULLPTR));
		m_labelAxisState->setText(QApplication::translate("ResonatorClass", "\350\275\264\347\212\266\346\200\201", Q_NULLPTR));
		m_pbtnSStop->setText(QApplication::translate("ResonatorClass", "Sstop", Q_NULLPTR));
		m_pbtnSClear->setText(QApplication::translate("ResonatorClass", "S\346\270\205\351\233\266", Q_NULLPTR));
		m_lineRLogPos->setText(QApplication::translate("ResonatorClass", "0", Q_NULLPTR));
		m_labelS->setText(QApplication::translate("ResonatorClass", "S", Q_NULLPTR));
		m_lineRFeedPos->setText(QApplication::translate("ResonatorClass", "0", Q_NULLPTR));
		m_pbtnTClear->setText(QApplication::translate("ResonatorClass", "\311\265\346\270\205\351\233\266", Q_NULLPTR));
		m_pbtnTRun->setText(QApplication::translate("ResonatorClass", "\311\265run", Q_NULLPTR));
		m_lineTaxisState->setText(QApplication::translate("ResonatorClass", "0", Q_NULLPTR));
		m_radioTVel->setText(QApplication::translate("ResonatorClass", "\351\200\237\345\272\246\346\250\241\345\274\217", Q_NULLPTR));
		m_lineTLogPos->setText(QApplication::translate("ResonatorClass", "0", Q_NULLPTR));
		m_lineTFeedPos->setText(QApplication::translate("ResonatorClass", "0", Q_NULLPTR));
		m_lineTDestPos->setText(QApplication::translate("ResonatorClass", "200", Q_NULLPTR));
		m_pbtnTHome->setText(QApplication::translate("ResonatorClass", "\311\265\345\233\236\351\233\266", Q_NULLPTR));
		m_pbtnRStop->setText(QApplication::translate("ResonatorClass", "Rstop", Q_NULLPTR));
		m_lineTDestVel->setText(QApplication::translate("ResonatorClass", "5", Q_NULLPTR));
		m_radioTPos->setText(QApplication::translate("ResonatorClass", "\344\275\215\347\275\256\346\250\241\345\274\217", Q_NULLPTR));
		m_pbtnTStop->setText(QApplication::translate("ResonatorClass", "\311\265stop", Q_NULLPTR));
		m_pbtnRClear->setText(QApplication::translate("ResonatorClass", "R\346\270\205\351\233\266", Q_NULLPTR));
		m_labelT->setText(QApplication::translate("ResonatorClass", "\311\265", Q_NULLPTR));
		m_lineRaxisState->setText(QApplication::translate("ResonatorClass", "0", Q_NULLPTR));
		m_pbtnRHome->setText(QApplication::translate("ResonatorClass", "R\345\233\236\351\233\266", Q_NULLPTR));
	} // retranslateUi

};

namespace Ui {
	class ResonatorClass : public Ui_ResonatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESONATOR_H
