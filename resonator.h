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
using namespace QtCharts;
class Resonator : public QMainWindow
{
	Q_OBJECT
public:
	Resonator(QWidget *parent = Q_NULLPTR);
	~Resonator();
	void InitUI();
	void showCurve();
	void readTxtData(QString filename, int num_var,QVector<QVector<double>>& data);
private:
	Ui::ResonatorClass ui;
	QVector<QString> m_vsDirection = { "Up","Down","Left","Down" };
	QVector<QPushButton *> m_vpbtnDirection;
	Curve_2d m_Curve2d;
	KalmanFilter *m_kalmanFilter;
	QTimer * m_showTimer;
	QVector<QVector<double>> dataVector;
	private slots:
	void onShowTimerOut();
	void on_m_pbtnTest_clicked();
};
