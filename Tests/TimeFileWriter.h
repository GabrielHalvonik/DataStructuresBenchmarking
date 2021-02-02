#pragma once

#include <string>
#include <fstream>
#include "TestStructure.h"
#include "ListOperations.h"
#include "MatrixOperations.h"
#include "PriorityQueueOperations.h"

class TimeFileWriter {
public:
	TimeFileWriter() = delete;

	template <typename T>
    static std::vector<OperationTimeInfo> collectTimesToFile(const std::string&, TestStructure<T>&, T, uint32_t);
};

template<typename T>
std::vector<OperationTimeInfo> TimeFileWriter::collectTimesToFile(const std::string& fileName, TestStructure<T>& scenar, T structure, uint32_t count) {
    std::vector<OperationTimeInfo> result;
	std::ofstream fout(fileName, std::ios_base::app);
    for (uint32_t i = 0; i < count; ++i) {
		OperationTimeInfo info = scenar.testRandomOperation(structure);
        result.push_back(info);
		fout << static_cast<int>(info.operationID) << "," << info.time.count() << std::endl;
	}
    return result;
}
