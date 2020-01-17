#ifndef POLARCURVE_TWOD_H
#define POLARCURVE_TWOD_H
#include <QtCharts\qsplineseries.h>
#include <QtCharts\qchartview.h>
#include <QtCharts\qvalueaxis.h>
#include <QtCharts\qpolarchart.h>
#include <QtCharts\qscatterseries.h>
#include <QVector>
#include <QColor>
#include <QtCharts/QChartView>
using QtCharts::QSplineSeries;
using QtCharts::QChartView;
using QtCharts::QValueAxis;
using QtCharts::QPolarChart;
using QtCharts::QScatterSeries;
class PolarCurve_2d
{
public:
	QSplineSeries *m_lineSeries;
	//QSplineSeries *m_lineSeriesStatic;
	QScatterSeries *m_scatterSeries;
	QPolarChart *m_polarChart;
	QValueAxis *m_angleAxis;
	QValueAxis *m_radiusAxis;
	void InitCurve()
	{
		m_lineSeries = new QSplineSeries();
		m_lineSeries->setName("Sensor Displacement");

		m_scatterSeries = new QScatterSeries();
		m_scatterSeries->setMarkerSize(10);
		m_scatterSeries->setColor(Qt::red);
		m_scatterSeries->setBorderColor(Qt::red);


		m_polarChart = new QPolarChart();
		m_polarChart->addSeries(m_lineSeries);
		m_polarChart->addSeries(m_scatterSeries);
		m_angleAxis = new QValueAxis();
		m_angleAxis->setLabelFormat("%.1f");
		m_angleAxis->setShadesVisible(true);
		m_angleAxis->setShadesBrush(QBrush(QColor(249, 249, 255)));
		m_angleAxis->setRange(0, 360);
		m_polarChart->addAxis(m_angleAxis, QPolarChart::PolarOrientationAngular);
		m_radiusAxis = new QValueAxis();
		m_radiusAxis->setTickCount(9);
		m_radiusAxis->setRange(0, 20);
		m_radiusAxis->setLabelFormat("%.1f");
		m_polarChart->addAxis(m_radiusAxis, QPolarChart::PolarOrientationRadial);
		m_lineSeries->attachAxis(m_radiusAxis);
		m_lineSeries->attachAxis(m_angleAxis);
		m_scatterSeries->attachAxis(m_radiusAxis);
		m_scatterSeries->attachAxis(m_angleAxis);
	}
};
#endif // !POLARCURVE_TWOD
