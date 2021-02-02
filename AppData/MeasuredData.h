#pragma once

#include <QList>
#include <QPointF>
#include "Tests/TestStructure.h"
#include "List/ArrayList.h"
#include <QPair>
#include <vector>
#include <QMap>

using namespace Structures;

class MeasuredData {
public:
	MeasuredData();
	~MeasuredData();

	template <typename T>
    std::vector<OperationTimeInfo> measureStructures(TestStructure<T>&, T, const StructureADS, uint32_t, QMap<QPair<StructureADS, AllStructureOperationType>, std::vector<OperationTimeInfo>>&);

	template <typename T>
    void measureStructures(TestStructure<T>&, T, const StructureADS, const std::vector<OperationTimeInfo>&, QMap<QPair<StructureADS, AllStructureOperationType>, std::vector<OperationTimeInfo>>&);

//	template <typename T>
//	void measureAverageStructures(TestStructure<T>&, T, uint32_t);

	QList<QPointF>* getMeasuredData();
	std::vector<qreal> getMeasuredAverageData();
    std::map<Structures::AllStructureOperationType, std::vector<uint32_t>> getMeasuredOpsTimes();
	inline qreal getSum() const { return this->sum; }
private:
    QList<QPointF>* data;
    std::map<Structures::AllStructureOperationType, std::vector<uint32_t>> timesOfOps;
	qreal sum;
//	int average;
};

template<typename T>
std::vector<OperationTimeInfo> MeasuredData::measureStructures(TestStructure<T>& scenar, T structure, const StructureADS ads, uint32_t count, QMap<QPair<StructureADS, AllStructureOperationType>, std::vector<OperationTimeInfo>>& result) {
    std::vector<OperationTimeInfo> res;
    for (size_t i = 0; i < count; ++i) {
		OperationTimeInfo timeInfo = scenar.testRandomOperation(structure);
        res.push_back(timeInfo);
        QPair QPair = {ads, timeInfo.type};
        if (result.count(QPair) == 0) {
            result.insert(QPair, {});
        }
        result[QPair].push_back(timeInfo);

		uint32_t time = timeInfo.time.count();
		sum += time;
		data->append(QPointF(i, time));
		this->timesOfOps[timeInfo.type].push_back(time);
    }
    return res;
}

template <typename T>
void MeasuredData::measureStructures(TestStructure<T>& scenar, T structure, const StructureADS ads, const std::vector<OperationTimeInfo>& opsID, QMap<QPair<StructureADS, AllStructureOperationType>, std::vector<OperationTimeInfo>>& result) {
    for (size_t i = 0; i < opsID.size(); ++i) {
        OperationTimeInfo timeInfo = scenar.testRandomOperation(structure, opsID[i].operationID);
        QPair QPair = {ads, timeInfo.type};
        if (result.count(QPair) == 0) {
            result.insert(QPair, {});
        }
        result[QPair].push_back(timeInfo);

		uint32_t time = timeInfo.time.count();
		sum += time;
		data->append(QPointF(i, time));
		this->timesOfOps[timeInfo.type].push_back(time);
    }
}

//template<typename T>
//void MeasuredData::measureAverageStructures(TestStructure<T>& scenar, T structure, uint32_t count) {
//	if (this->valData->empty()) {
////		this->valData->reserve(count);
//		this->valData->resize(count);
//	}

//	for (size_t i = 0; i < count; ++i) {
//		(*valData)[i] += scenar.testRandomOperation(structure).count();
//	}

//	++this->average;
//}
