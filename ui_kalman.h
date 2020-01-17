#ifndef UI_KALMAN_H
#define UI_KALMAN_H
#include <QtWidgets\QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
QT_BEGIN_NAMESPACE
class Ui_KalmanDlg 
{
public:
	QLabel* m_labelA;
	QLabel* m_labelB;
	QLabel* m_labelH;
	QLabel* m_labelQ;
	QLabel* m_labelR;
	QLineEdit* m_lineA;
	QLineEdit* m_lineB;
	QLineEdit* m_lineH;
	QLineEdit* m_lineQ;
	QLineEdit* m_lineR;
	QGridLayout* m_gridLayout;
	QWidget * m_ctrWidget;
	void setupUi(QDialog *kalmanClass)
	{
		m_labelA = new QLabel("A", kalmanClass);
		m_labelB = new QLabel("B", kalmanClass);
		m_labelH = new QLabel("H", kalmanClass);
		m_labelQ = new QLabel("Q", kalmanClass);
		m_labelR = new QLabel("R", kalmanClass);
		m_lineA = new QLineEdit(kalmanClass);
		m_lineB = new QLineEdit(kalmanClass);
		m_lineH = new QLineEdit(kalmanClass);
		m_lineQ = new QLineEdit(kalmanClass);
		m_lineR = new QLineEdit(kalmanClass);
		m_gridLayout = new QGridLayout(kalmanClass);
		m_gridLayout->addWidget(m_labelA, 0, 0);
		m_gridLayout->addWidget(m_lineA, 0, 1);
		m_gridLayout->addWidget(m_labelB, 1, 0);
		m_gridLayout->addWidget(m_lineB, 1, 1);
		m_gridLayout->addWidget(m_labelH, 2, 0);
		m_gridLayout->addWidget(m_lineH, 2, 1);
		m_gridLayout->addWidget(m_labelQ, 3, 0);
		m_gridLayout->addWidget(m_lineQ, 3, 1);
		m_gridLayout->addWidget(m_labelR, 4, 0);
		m_gridLayout->addWidget(m_lineR, 4, 1);
		kalmanClass->setLayout(m_gridLayout);
	}


};
QT_END_NAMESPACE

#endif // !UI_KALMAN_H
