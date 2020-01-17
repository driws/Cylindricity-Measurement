#ifndef DD_CURVE_H
#define DD_CURVE_H

#include <QtCharts\qchartview.h>
#include <QtCharts\qvalueaxis.h>
#include <QtCharts\qsplineseries.h>
#include <QtCharts\qscatterseries.h>
#include <QVector>
#include <QColor>
using QtCharts::QSplineSeries;
using QtCharts::QScatterSeries;
using QtCharts::QValueAxis;
class Curve_2d
{
public:
	QSplineSeries *m_lineSeries;
	QScatterSeries *m_scatterSeries;
	QChart * m_chart;
	QValueAxis * m_axisX;
	QValueAxis * m_axisY;
	void InitCurve(QVector<double> paramVector,int lineWidth = 3, QColor color = QColor(0,114,182))
	{
		if (paramVector.size() < 6)
			return;
		double minX, minY, maxX, maxY, tickCount,minorTickCount;
		minX = paramVector[0];
		maxX = paramVector[1];
		minY = paramVector[2];
		maxY = paramVector[3];
		tickCount = paramVector[4];
		minorTickCount = paramVector[5];
	

		m_lineSeries = new QSplineSeries();
		m_lineSeries->setColor(color);
		QPen pen(color, lineWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
		m_lineSeries->setPen(pen);
		m_lineSeries->setName("¹ì¼£");

		m_scatterSeries = new QScatterSeries();
		m_scatterSeries->setName("Ì½Õë");
		m_scatterSeries->setMarkerSize(10);
		m_scatterSeries->setBorderColor(Qt::red);
		m_scatterSeries->setColor(Qt::red);
		m_chart = new QChart();
		m_chart->setWindowTitle("2dCurve");
		m_chart->addSeries(m_lineSeries);
		m_chart->addSeries(m_scatterSeries);
		m_axisX = new QValueAxis;
		m_axisX->setRange(minX, maxX);
		m_axisX->setLabelFormat("%.1f");
		m_axisX->setGridLineVisible(true);
		m_axisX->setTickCount(tickCount);
		m_axisX->setMinorTickCount(minorTickCount);
		m_axisX->setTitleText("X");

		m_axisY = new QValueAxis;
		m_axisY->setRange(minY, maxY);
		m_axisY->setLabelFormat("%.1f");
		m_axisY->setGridLineVisible(true);
		m_axisY->setTickCount(tickCount);
		m_axisY->setMinorTickCount(minorTickCount);
		m_axisY->setTitleText("Y");

		m_chart->addAxis(m_axisX, Qt::AlignBottom);
		m_chart->addAxis(m_axisY, Qt::AlignLeft);
		m_lineSeries->attachAxis(m_axisX);
		m_lineSeries->attachAxis(m_axisY);
		m_scatterSeries->attachAxis(m_axisX);
		m_scatterSeries->attachAxis(m_axisY);
	}
};

#endif // !2D_CURVE_H
