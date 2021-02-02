#pragma once

#include "Table/UnsortedSequenceTable.h"

namespace Structures {

	class SortNotifier {
	public:
		SortNotifier(int notificationPeriod);
		void notify();
	protected:
		virtual void doNotify() = 0;
	private:
		int notificationPeriod;
		int currentNotification;
	};

	template <typename K, typename T>
	class Sort {
	public:
		Sort();
		virtual ~Sort();

		void operator()(UnsortedSequenceTable<K, T>& table);

		virtual void sort(UnsortedSequenceTable<K, T>& table) = 0;
		void setNotifier(SortNotifier* sortNotifier);
	protected:
		void notify();
	private:
		SortNotifier* sortNotifier;
	};

	template<typename K, typename T>
	inline Sort<K, T>::Sort(): sortNotifier(nullptr) {
	}

	template<typename K, typename T>
	inline Sort<K, T>::~Sort() {
		this->sortNotifier = nullptr;
	}

	template<typename K, typename T>
	inline void Sort<K, T>::operator()(UnsortedSequenceTable<K, T>& table) {
		this->sort(table);
	}

	template<typename K, typename T>
	inline void Sort<K, T>::setNotifier(SortNotifier * sortNotifier) {
		this->sortNotifier = sortNotifier;
	}

	template<typename K, typename T>
	inline void Sort<K, T>::notify() {
		if (this->sortNotifier != nullptr) {
			this->sortNotifier->notify();
		}
	}
}
