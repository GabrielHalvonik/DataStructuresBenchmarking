#pragma once

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QLegendMarker>
#include <QtWidgets>
#include <QMap>
#include "DSStructureTypes.h"

using namespace QtCharts;

class Chart : public QChartView {
public:
	Chart(QWidget* parent = nullptr);
	virtual ~Chart() override;
    void addSeries(QAbstractSeries*);
//	void addSeries(QPieSeries*);
	void addSerieses(std::map<Structures::StructureADS, QtCharts::QAbstractSeries*>);
	void removeSeries(QAbstractSeries*);
	void removeAllSeries();
	void clear();
	void hideLabels();
	void hideLegend();
	void hideAxis();
	void showAxis();

	friend class BarChart;
    friend class PieChart;

    std::map<Structures::StructureADS, QAbstractSeries*> getSerieses() const;

public slots:
    void handleMarkerClicked();

protected:
    //	void mousePressEvent(QMouseEvent* event) override;
	void keyPressEvent(QKeyEvent* event) override;
	bool event(QEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
	QChart* chart;
	QValueAxis* axisX;
	QValueAxis* axisY;
	bool labelVisible;
    std::map<Structures::StructureADS, QAbstractSeries*> serieses;
};

