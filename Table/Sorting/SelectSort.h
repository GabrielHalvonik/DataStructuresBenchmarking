#pragma once

#include "Sort.h"
#include "Table/UnsortedSequenceTable.h"

namespace Structures {

	/// <summary> Triedenie Select sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class SelectSort : public Sort<K, T> {
	public:
		/// <summary> Utriedi tabulku triedenim Select sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
	};

	template<typename K, typename T>
	inline void SelectSort<K, T>::sort(UnsortedSequenceTable<K, T>& table) {
		for (int i = 0; i < table.size() - 1; ++i) {
			int min	= i;
			for (int j = 0; j < table.size(); ++j) {
				if (table.getItemAtIndex(j).getKey() < table.getItemAtIndex(min).getKey()) {
					min = j;
				}
			}
			table.swap(i, min);
			this->notify();
		}
	}

}
