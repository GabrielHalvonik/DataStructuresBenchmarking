#pragma once

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtWidgets>
#include <QList>
#include <map>
#include <QMetaObject>

#include "Chart.h"

using namespace QtCharts;

class BarChart : public Chart {
    Q_OBJECT
public:
	BarChart(QWidget* parent = nullptr);
	virtual ~BarChart() override;

	void toggleStretch(bool);
	int getBarCount() const;

    void addBarSeries(QList<QBarSet*>*, const QList<Structures::AllStructureOperationType>&);
    void clear();
public slots:
    void barSetPressed(int, QBarSet*);

signals:
    void opClicked(const QString&, const QString&);

protected:
	void keyPressEvent(QKeyEvent* event) override;

private:
    QBarCategoryAxis* axis;
	QValueAxis* valueAxis;
	QStackedBarSeries* series;
	uint8_t barCount;
    QMetaObject::Connection connection;
};

