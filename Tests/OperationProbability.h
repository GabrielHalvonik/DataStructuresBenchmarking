#pragma once

#include <cinttypes>
#include <chrono>

template <typename T>
struct OperationProbability {
	void(*operation)(T);
	uint8_t probability;

	inline bool operator>=(uint8_t second) { return this->probability >= second; }
	inline bool operator<=(uint8_t second) { return this->probability <= second; }
	inline bool operator==(const OperationProbability& second) const { return this->probability == second.probability; }
};
