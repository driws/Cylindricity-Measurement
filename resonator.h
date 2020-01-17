#include <QtWidgets/QMainWindow>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE
#include "ui_mine.h"
#include <QString>
#include <QVector>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <time.h>
#include <QButtonGroup>
#include "curve_2d.h"
#include "kalman_filter.h"
#include "./Resources/single_card/gts.h"
#include "./Resources/Inc/bdaqctrl.h"
#include "pos_motion_thread.h"

using namespace Automation::BDaq;

struct ConfigureParameter
{
	QString deviceName;
	int channelCount;
	int channelStart;
	ValueRange valueRange;
	const wchar_t* profilePath;
};


const int SoftLimit = 4000000;

typedef enum { VEL, POS } MotionMode; 

class Resonator : public QMainWindow
{
	Q_OBJECT
public:
	Resonator(QWidget *parent = Q_NULLPTR);
	~Resonator();
	void InitUI();
	void CommandHandler(int sRtn, QString msg = "");
	void CheckError(ErrorCode errorcode);
	void showCurve();
	void readTxtData(QString filename, int num_var,QVector<QVector<double>>& data);
private:
	Ui::ResonatorClass ui;
	Curve_2d m_Curve2d;
	PolarCurve_2d m_polarCurve2d;
	QTimer * m_showTimer;
	QTimer * m_sensorTimer;
	QVector<QString> m_vstrAxisName = { "S","R","T" };
	QVector<QString> m_vstrDirection = { "Up","Down","Right","Left" };
	int m_iAxisToCheck;
	QVector<QString> m_vstrValueRange;
	QVector<QPushButton *> m_vpbtnDirection;
	QVector<QVector<double>> dataVector;
	QVector<QRadioButton *> m_vRadioState;
	QVector<QLineEdit *> m_vlineDestPos;
	QVector<QLineEdit *> m_vlineDestVel;
	QVector<QLineEdit *> m_vlineLogPos;
	QVector<QLineEdit *> m_vlineFeedPos;
	QVector<QLineEdit*> m_vlineAxisState;
	QVector<QPushButton*> m_vpbtnRun;
	QVector<QPushButton*> m_vpbtnClear;
	QVector<QPushButton*> m_vpbtnStop;
	KalmanFilter* m_KalmanFilter;
	InstantAiCtrl * m_instantAiCtrl;
	ConfigureParameter m_configure;
	bool m_bSensorStatus;
	bool m_bCardStatus;
	double m_dSensorProp = 80.0;
	double m_dAngleProp = 8000.0;
	//function 
	int InitCard();
	int InitSensor();
	void EmergencyStop();
	void MotorRun(int axis, MotionMode mode, int sign = 1);
	private slots:
	void onSensorTimerOut();
	void onAdjustDirectionRun();
	void onShowTimerOut();
	void onClearZeroPos();
	void onMotorRun();
	void onMotorStop();
	void onConnectCard();
	void onDisconnectCard();
	void onPosMotionFinished(int axis);
	void on_m_pbtnTest_clicked();
	void on_m_pbtnEmerStop_clicked();
	void on_m_pbtnInitCrd_clicked();
	void on_m_pbtnMeasureStart_clicked();
};
