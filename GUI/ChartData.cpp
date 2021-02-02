#include "ChartData.h"
#include "UIRoutines.h"
#include <QtCharts/QScatterSeries>
#include <QtCharts/QSplineSeries>
#include <numeric>

ChartData::ChartData() : set(new QList<QBarSet*>) {
}

ChartData::~ChartData() {
}

QList<QBarSet*>* ChartData::getBarData() const {
	return this->set;
}

std::map<Structures::StructureADS ,QtCharts::QAbstractSeries*> ChartData::getData() const {
	return this->series;
}

QList<Structures::AllStructureOperationType> ChartData::getOperations() const {
	return this->operations;
}

void ChartData::addOperationType(Structures::AllStructureOperationType op) {
	this->operations.append(op);
}

//std::map<Structures::AllStructureOperationType, QStackedBarSeries*> ChartData::getBarData() {
//	return this->barSeriesMap;
//}

QtCharts::QPieSeries* ChartData::getPieData() const {
	QPieSeries* pieSeries = new QPieSeries;
	pieSeries->setPieSize(0.95);
	pieSeries->setUseOpenGL(true);
	pieSeries->setLabelsVisible(false);
	pieSeries->append(this->pieSlices);
	return pieSeries;
}

void ChartData::addData(QList<QPointF>* data, const Structures::StructureADS ads) {
	QScatterSeries* series = new QScatterSeries;
	series->setMarkerSize(4);
	series->setUseOpenGL(true);
	series->setName(QString::fromStdString(UIRoutines::convertStructureADSToStr(ads)));
	series->setColor(UIRoutines::getColorOfADS(ads).c_str());
	series->append(*data);
	this->series.insert({ads, series});
}

void ChartData::addBarData(const Structures::StructureADS ads, const std::map<Structures::AllStructureOperationType, std::vector<uint32_t>>& opTimes) {
	QBarSet* newSet = new QBarSet(QString::fromStdString(UIRoutines::convertStructureADSToStr(ads)));
	this->set->append(newSet);
	for (const auto& temp : opTimes) {
//		if (!first) {
//			first = true;
//		} else {
//		}
		newSet->setColor(UIRoutines::getColorOfADS(ads).c_str());
		newSet->append(std::accumulate(temp.second.begin(), temp.second.end(), 0));
//		if (this->barSeriesMap.count(temp.first) > 0) {
//			this->barSeriesMap[temp.first]->append(set);
//		} else {
//			QStackedBarSeries* series = new QStackedBarSeries;
//			series->setName(QString::fromStdString(UIRoutines::convertOperationTypeToStr(temp.first)));
//			series->setUseOpenGL(true);
//			series->append(set);
//			this->barSeriesMap.insert({temp.first, series});
//		}
	}
}

void ChartData::addPieData(qreal time, Structures::StructureADS ads) {
	QPieSlice* slice = new QPieSlice(QString::fromStdString(UIRoutines::convertStructureADSToStr(ads)), time);
	slice->setColor(QColor(QString::fromStdString(UIRoutines::getColorOfADS(ads))));
	this->pieSlices.append(slice);
}


//void ChartData::addAveragedData(const std::vector<qreal>& data) {
//	this->series->clear();
//	for (qreal i = 0; i < data.size(); ++i) {
//		this->series->append({i, data[i]});
//	}

//}
