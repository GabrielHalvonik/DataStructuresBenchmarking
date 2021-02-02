#pragma once

#include "Sort.h"
#include "Table/UnsortedSequenceTable.h"
#include "Comparator.h"

namespace Structures {

	template <typename K, typename T>
	class BubbleSort : public Sort<K, T> {
	public:
		void sort(UnsortedSequenceTable<K, T>& table) override;
		void sort(UnsortedSequenceTable<K, T>&, const Comparator<T>&) override;
	};

	template<typename K, typename T>
	inline void BubbleSort<K, T>::sort(UnsortedSequenceTable<K, T>& table) {
		bool wasSwap;
		do {
			wasSwap = false;

			for (int i = 0; i < table.size() - 1; ++i) {
				if (table.getItemAtIndex(i).getKey() > table.getItemAtIndex(i + 1).getKey()) {
					table.swap(i, i + 1);
					wasSwap = true;
					this->notify();
				}
			}

		} while (wasSwap);
	}

	template<typename K, typename T>
	inline void BubbleSort<K, T>::sort(UnsortedSequenceTable<K, T>& table, const Comparator<T>& cmp) {
		bool wasSwap;
		do {
			wasSwap = false;

			for (int i = 0; i < table.size() - 1; ++i) {
				if (cmp(table.getItemAtIndex(i).accessData(), table.getItemAtIndex(i + 1).accessData())) {
					table.swap(i, i + 1);
					wasSwap = true;
					this->notify();
				}
			}

		} while (wasSwap);
	}

}
