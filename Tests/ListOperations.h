#pragma once

#include "List/List.h"
#include "RandomGenerator.h"

class ListOperations {
public:
	ListOperations() = delete;

	template <typename T>
	static void vlozPrvy(Structures::List<T>*);
	template <typename T>
	static void vlozPosledny(Structures::List<T>*);
	template <typename T>
	static void vlozNaIndex(Structures::List<T>*);

	template <typename T>
	static void zrusPrvy(Structures::List<T>*);
	template <typename T>
	static void zrusPosledny(Structures::List<T>*);
	template <typename T>
	static void zrusNaIndexe(Structures::List<T>*);

	template <typename T>
	static void spristupni(Structures::List<T>*);
	template <typename T>
	static void nastav(Structures::List<T>*);

	template <typename T>
	static void indexPrvku(Structures::List<T>*);
};

template<typename T>
void ListOperations::vlozPrvy(Structures::List<T>* list) {
	list->insert(list->size(), 0);
}

template<typename T>
void ListOperations::vlozPosledny(Structures::List<T>* list) {
	list->add(list->size());
}

template<typename T>
void ListOperations::vlozNaIndex(Structures::List<T>* list) {
	list->insert(list->size(), RandomGenerator::randomIntBetween(0, list->size()));
}

template<typename T>
void ListOperations::zrusPrvy(Structures::List<T>* list) {
	if (!list->isEmpty()) {
		list->removeAt(0);
	}
}

template<typename T>
void ListOperations::zrusPosledny(Structures::List<T>* list) {
	if (!list->isEmpty()) {
		list->removeAt(list->size() - 1);
	}
}

template<typename T>
void ListOperations::zrusNaIndexe(Structures::List<T>* list) {
	if (!list->isEmpty()) {
		list->removeAt(RandomGenerator::randomIntBetween(0, list->size() - 1));
	}
}

template<typename T>
void ListOperations::spristupni(Structures::List<T>* list) {
	if (!list->isEmpty()) {
		(*list)[RandomGenerator::randomIntBetween(0, list->size() - 1)];
	}
}

template<typename T>
void ListOperations::nastav(Structures::List<T>* list) {
	if (!list->isEmpty()) {
		size_t s = list->size();
		(*list)[RandomGenerator::randomIntBetween(0, s - 1)] = s;
	}
}

template<typename T>
void ListOperations::indexPrvku(Structures::List<T>* list) {
	if (!list->isEmpty()) {
		list->getIndexOf(RandomGenerator::randomIntBetween(0, list->size() - 1));
	}
}
