#pragma once

#include <QtCharts/QLineSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QPieSeries>
#include "DSStructureTypes.h"
#include <map>
#include <QList>

using namespace QtCharts;

using QtCharts::QLineSeries;
using QtCharts::QStackedBarSeries;
using QtCharts::QPieSeries;
using QtCharts::QBarSet;

class ChartData {
public:
	ChartData();
	~ChartData();

	std::map<Structures::StructureADS, QAbstractSeries*> getData() const;
//	std::map<Structures::AllStructureOperationType, QStackedBarSeries*> getBarData();
	QList<QBarSet*>* getBarData() const;
	QPieSeries* getPieData() const;
	QList<Structures::AllStructureOperationType> getOperations() const;
	void addOperationType(Structures::AllStructureOperationType);

	void addData(QList<QPointF>*, const Structures::StructureADS);
	void addBarData(const Structures::StructureADS, const std::map<Structures::AllStructureOperationType, std::vector<uint32_t>>&);
	void addPieData(qreal, Structures::StructureADS);
//	void addAveragedData(const std::vector<qreal>&);


private:
	QList<QPieSlice*> pieSlices;
	std::map<Structures::StructureADS, QAbstractSeries*> series;
//	std::map<Structures::AllStructureOperationType, QStackedBarSeries*> barSeriesMap;
	QList<QBarSet*>* set;
	QList<Structures::AllStructureOperationType> operations;
};

