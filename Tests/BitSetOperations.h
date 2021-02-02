#pragma once

#include "Set/BitSet.h"
#include "RandomGenerator.h"

class BitSetOperations {
public:
	BitSetOperations() = delete;

	template <typename T>
	static void vloz(Structures::BitSet<T>*);

	template <typename T>
	static void vyber(Structures::BitSet<T>*);

	template <typename T>
	static void patri(Structures::BitSet<T>*);

	template <typename T>
	static void jePodmnozinou(Structures::BitSet<T>*);

	template <typename T>
	static void zjednotenie(Structures::BitSet<T>*);

	template <typename T>
	static void prienik(Structures::BitSet<T>*);

	template <typename T>
	static void rozdiel(Structures::BitSet<T>*);
};

template<typename T>
void BitSetOperations::vloz(Structures::BitSet<T>* set) {
	set->insert(RandomGenerator::randomIntBetween(0, set->size()));
}

template<typename T>
void BitSetOperations::vyber(Structures::BitSet<T>* set) {
	set->extract(RandomGenerator::randomIntBetween(0, set->size()));
}

template<typename T>
void BitSetOperations::patri(Structures::BitSet<T>* set) {
	set->contains(RandomGenerator::randomIntBetween(0, set->size()));
}

template<typename T>
void BitSetOperations::jePodmnozinou(Structures::BitSet<T>* set) {
	set->hasSubset(*set);
}

template<typename T>
void BitSetOperations::zjednotenie(Structures::BitSet<T>* set) {
	set->unionWith(*set);
}

template<typename T>
void BitSetOperations::prienik(Structures::BitSet<T>* set) {
	set->intersectionWith(*set);
}

template<typename T>
void BitSetOperations::rozdiel(Structures::BitSet<T>* set) {
	set->substract(*set);
}
