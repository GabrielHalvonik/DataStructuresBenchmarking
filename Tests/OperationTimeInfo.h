#pragma once

#include "DSStructureTypes.h"
#include <chrono>

struct OperationTimeInfo {
	std::chrono::nanoseconds time;
	Structures::AllStructureOperationType type;
	int8_t operationID;
    size_t structureSize;
};
