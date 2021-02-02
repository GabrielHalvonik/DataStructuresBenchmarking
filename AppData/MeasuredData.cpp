#include "MeasuredData.h"
#include <algorithm>

MeasuredData::MeasuredData() : data(new QList<QPointF>), sum(0) {
}

MeasuredData::~MeasuredData() {
}

QList<QPointF>* MeasuredData::getMeasuredData() {
	return this->data;
}

//std::vector<qreal> MeasuredData::getMeasuredAverageData() {
//	std::vector<qreal> averageData = *this->valData;
//	for (size_t i = 0; i < averageData.size(); ++i) {
//		averageData[i] /= this->average;
//	}
//	return averageData;
//}

std::map<Structures::AllStructureOperationType, std::vector<uint32_t>> MeasuredData::getMeasuredOpsTimes() {
	return this->timesOfOps;
}
