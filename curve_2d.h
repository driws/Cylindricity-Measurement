#ifndef DD_CURVE_H
#define DD_CURVE_H

#include <QtCharts\qlineseries.h>
#include <QtCharts\qchartview.h>
#include <QtCharts\qvalueaxis.h>

class Curve_2d
{
public:
	QtCharts::QSplineSeries *m_lineseries;
	QtCharts::QChart * m_chart;
	QValueAxis * m_axisX;
	QValueAxis * m_axisY;

	void InitCurve()
	{
		m_chart = new QChart();
		m_chart->setWindowTitle("2dCurve");

		m_lineseries = new QSplineSeries();
		m_lineseries->setColor(QColor(0, 114, 182));
		QPen pen(QColor(0, 114, 182), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
		m_lineseries->setPen(pen);
		m_axisX = new QValueAxis;
		m_axisX->setRange(-15, 15);
		m_axisX->setLabelFormat("%d");
		m_axisX->setGridLineVisible(true);
		m_axisX->setTickCount(10);
		m_axisX->setTitleText("X");
		m_axisY = new QValueAxis;
		m_axisY->setRange(-4, 18);
		m_axisY->setLabelFormat("%d");
		m_axisY->setGridLineVisible(true);
		m_axisY->setTickCount(10);
		m_axisY->setMinorTickCount(5);
		m_axisY->setTitleText("Y");

		m_chart->addAxis(m_axisX, Qt::AlignBottom);
		m_chart->addAxis(m_axisY, Qt::AlignLeft);
		m_chart->createDefaultAxes();
	}
};

#endif // !2D_CURVE_H
