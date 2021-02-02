#pragma once

#include "PriorityQueue/PriorityQueue.h"
#include "RandomGenerator.h"

const int MAX_PRIORITY = 10000;

class PriorityQueueOperations {
public:
	PriorityQueueOperations() = delete;

	template <typename T>
	static void vloz(Structures::PriorityQueue<T>*);
	template <typename T>
	static void vyber(Structures::PriorityQueue<T>*);
	template <typename T>
	static void ukaz(Structures::PriorityQueue<T>*);
};

template<typename T>
void PriorityQueueOperations::vloz(Structures::PriorityQueue<T>* queue) {
	int priorita = RandomGenerator::randomIntBetween(0, MAX_PRIORITY);
	queue->push(priorita, priorita);
}

template<typename T>
void PriorityQueueOperations::vyber(Structures::PriorityQueue<T>* queue) {
	if (!queue->isEmpty()) {
		queue->pop();
	}
}

template<typename T>
void PriorityQueueOperations::ukaz(Structures::PriorityQueue<T>* queue) {
	if (!queue->isEmpty()) {
		queue->peek();
	}
}
