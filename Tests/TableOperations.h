#pragma once

#include "Table/Table.h"
#include "RandomGenerator.h"

class TableOperations {
public:
	TableOperations() = delete;

	template <typename K, typename T>
	static void vloz(Structures::Table<K, T>*);
	template <typename K, typename T>
	static void vyber(Structures::Table<K, T>*);
	template <typename K, typename T>
	static void najdi(Structures::Table<K, T>*);
};

template<typename K, typename T>
void TableOperations::vloz(Structures::Table<K, T>* table) {
    int hodnota = RandomGenerator::randomIntBetween(INT_MIN + 1, INT_MAX - 1);
	table->insert(hodnota, hodnota);
}

template<typename K, typename T>
void TableOperations::vyber(Structures::Table<K, T>* table) {
	table->remove(RandomGenerator::randomIntBetween(0, INT_MAX - 1));
}

template<typename K, typename T>
void TableOperations::najdi(Structures::Table<K, T>* table) {
	T val;
	table->tryFind(RandomGenerator::randomIntBetween(0, INT_MAX - 1), val);
}
