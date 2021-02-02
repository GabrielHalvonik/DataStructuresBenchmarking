#pragma once

#include "RandomGenerator.h"
#include "TestTime.h"
#include "List/ArrayListRaw.h"
#include "OperationProbability.h"
#include "TestOperationTypes.h"
#include "GUI/UIRoutines.h"
#include <map>
#include <vector>
#include "OperationTimeInfo.h"

template <typename T>
class TestStructure {
public:
	TestStructure(/*Structures::StructureADT*/);
	~TestStructure();

	TestStructure& addTestOperation(void(*function)(T), uint8_t probability);
	OperationTimeInfo testRandomOperation(T list);
	OperationTimeInfo testRandomOperation(T list, int8_t);

private:
	Structures::ArrayListRaw<OperationProbability<T>> operations;
//	Structures::StructureADT adt;
	uint8_t sumOperation;
};



template <typename T>
TestStructure<T>::TestStructure(/*Structures::StructureADT ads*/) : /*adt(ads),*/ sumOperation(0) {
}

template<typename T>
TestStructure<T>::~TestStructure() {
	sumOperation = 0;
}

template<typename T>
TestStructure<T>& TestStructure<T>::addTestOperation(void(*function)(T), uint8_t probability) {
	if (this->sumOperation < 100) {
		this->sumOperation = (this->sumOperation + probability >= 100) ? 100 : this->sumOperation + probability;
		operations.add({function, this->sumOperation});
	}
	return *this;
}

template<typename T>
OperationTimeInfo TestStructure<T>::testRandomOperation(T structure) {
	std::chrono::nanoseconds time {};
	uint8_t rand = RandomGenerator::randomIntBetween(1, 100);
    for (size_t i = 0; i < this->operations.size(); ++i) {
		if (rand <= this->operations[i].probability) {
            time = TestTime::testTime(operations[i].operation, structure);
            return { time, Structures::TestOperationMapper<T>::getStructureOperationName(operations[i].operation), (int8_t)i, structure->size() };
		}
    }
    return { time, Structures::AllStructureOperationType::UNDEFINED, -1, structure->size() };
}

template <typename T>
OperationTimeInfo TestStructure<T>::testRandomOperation(T structure, int8_t opID) {
	std::chrono::nanoseconds time {};
    if (opID == -1) {
        return { time, Structures::AllStructureOperationType::UNDEFINED, -1, structure->size() };
	}
    time = TestTime::testTime(operations[opID].operation, structure);
    return { time, Structures::TestOperationMapper<T>::getStructureOperationName(operations[opID].operation), opID, structure->size() };
}

