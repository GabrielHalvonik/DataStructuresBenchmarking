#pragma once

#include <map>
#include <string>
#include <vector>
#include "ListOperations.h"
#include "PriorityQueueOperations.h"
#include "MatrixOperations.h"
#include "BitSetOperations.h"
#include "TableOperations.h"
#include "DSStructureTypes.h"
#include "Data/DataTypes.h"

namespace Structures {

	template <typename T>
	class TestOperationMapper {
	public:
		static void(*getOperationPointer(const ListOperationType))(List<T>*);
		static void(*getOperationPointer(const PriorityQueueOperationType))(PriorityQueue<T>*);
		static void(*getOperationPointer(const MatrixOperationType))(Matrix<T>*);
		static void(*getOperationPointer(const BitSetOperationType))(BitSet<T>*);
//		static void(*getOperationPointer(const TableOperationType))(Table<T, T>*);

		static std::vector<std::string> getADTOperationsStr(const std::string&);
		static std::vector<StructureADS> getADSsTypesOfADT(const StructureADT);
		static std::vector<StructureADT> getADTTypes();

		static std::vector<ListOperationType> getListOperations();
		static std::vector<PriorityQueueOperationType> getPriorityQueueOperations();
		static std::vector<BitSetOperationType> getBitSetOperations();
		static std::vector<MatrixOperationType> getMatrixOperations();
//		static std::vector<TableOperationType> getTableOperations();

		static AllStructureOperationType getStructureOperationName(void(*)(T));

		static ListOperationType getListOperationFromAll(AllStructureOperationType);
		static PriorityQueueOperationType getPqOperationFromAll(AllStructureOperationType);
		static MatrixOperationType getMatrixOperationFromAll(AllStructureOperationType);
		static BitSetOperationType getBitSetOperationFromAll(AllStructureOperationType);
//		static TableOperationType getTableOperationFromAll(AllStructureOperationType);

		static AllStructureOperationType getAllOperationType(ListOperationType);
		static AllStructureOperationType getAllOperationType(PriorityQueueOperationType);
		static AllStructureOperationType getAllOperationType(MatrixOperationType);
		static AllStructureOperationType getAllOperationType(BitSetOperationType);
//		static AllStructureOperationType getAllOperationType(TableOperationType);

	private:
		static std::map<ListOperationType, void(*)(List<T>*)> listOperationMap;
		static std::map<PriorityQueueOperationType, void(*)(PriorityQueue<T>*)> pqOperationMap;
		static std::map<MatrixOperationType, void(*)(Matrix<T>*)> matrixOperationMap;
		static std::map<BitSetOperationType, void(*)(BitSet<T>*)> bitSetOperationMap;
//		static std::map<TableOperationType, void(*)(Table<T, T>*)> tableOperationMap;

		static std::map<AllStructureOperationType, ListOperationType> allToListOperationMap;
		static std::map<AllStructureOperationType, PriorityQueueOperationType> allToPqOperationMap;
		static std::map<AllStructureOperationType, MatrixOperationType> allToMatrixOperationMap;
		static std::map<AllStructureOperationType, BitSetOperationType> allToBitSetOperationMap;
//		static std::map<AllStructureOperationType, TableOperationType> allToTableOperationMap;

		static std::map<ListOperationType, AllStructureOperationType> listToAllOperationMap;
		static std::map<PriorityQueueOperationType, AllStructureOperationType> pqToAllOperationMap;
		static std::map<MatrixOperationType, AllStructureOperationType> matrixToAllOperationMap;
		static std::map<BitSetOperationType, AllStructureOperationType> bitSetToAllOperationMap;
//		static std::map<TableOperationType, AllStructureOperationType> tableToAllOperationMap;

		static std::map<void(*)(T), AllStructureOperationType> listOperationNameMap;
		static std::map<void(*)(T), AllStructureOperationType> pqOperationNameMap;
		static std::map<void(*)(T), AllStructureOperationType> matrixOperationNameMap;
		static std::map<void(*)(T), AllStructureOperationType> bitSetOperationNameMap;
//		static std::map<void(*)(T), AllStructureOperationType> tableOperationNameMap;

		static std::map<std::string, std::vector<std::string>> adtOperationsStrMap;
		static std::map<StructureADT, std::vector<StructureADS>> adtToAdsMap;
	};

	template <typename T>
	void (*TestOperationMapper<T>::getOperationPointer(const ListOperationType op))(List<T>*) {
		return TestOperationMapper::listOperationMap[op];
	}

	template <typename T>
	void(*TestOperationMapper<T>::getOperationPointer(const PriorityQueueOperationType op))(PriorityQueue<T>*) {
		return TestOperationMapper::pqOperationMap[op];
	}

	template <typename T>
	void(*TestOperationMapper<T>::getOperationPointer(const MatrixOperationType op))(Matrix<T>*) {
		return TestOperationMapper::matrixOperationMap[op];
	}

	template <typename T>
	void(*TestOperationMapper<T>::getOperationPointer(const BitSetOperationType op))(BitSet<T>*) {
		return TestOperationMapper::bitSetOperationMap[op];
	}

//	template <typename T>
//	void(*TestOperationMapper<T>::getOperationPointer(const TableOperationType op))(Table<T, T>*) {
//		return TestOperationMapper::tableOperationMap[op];
//	}

	template <typename T>
	std::vector<std::string> TestOperationMapper<T>::getADTOperationsStr(const std::string& adt) {
		return TestOperationMapper::adtOperationsStrMap[adt];
	}

	template <typename T>
	std::vector<StructureADS> TestOperationMapper<T>::getADSsTypesOfADT(const StructureADT adt) {
		return TestOperationMapper::adtToAdsMap[adt];
	}

	template <typename T>
	std::vector<StructureADT> TestOperationMapper<T>::getADTTypes() {
		std::vector<StructureADT> adts;
		for (const auto& [key, value] : TestOperationMapper::adtToAdsMap) {
			adts.push_back(key);
		}
		return adts;
	}

	template <typename T>
	std::vector<ListOperationType> TestOperationMapper<T>::getListOperations() {
		std::vector<ListOperationType> ops;
		for (const auto& [key, value] : TestOperationMapper::listOperationMap) {
			ops.push_back(key);
		}
		return ops;
	}

	template <typename T>
	std::vector<PriorityQueueOperationType> TestOperationMapper<T>::getPriorityQueueOperations() {
		std::vector<PriorityQueueOperationType> ops;
		for (const auto& [key, value] : TestOperationMapper::pqOperationMap) {
			ops.push_back(key);
		}
		return ops;
	}

	template <typename T>
	std::vector<MatrixOperationType> TestOperationMapper<T>::getMatrixOperations() {
		std::vector<MatrixOperationType> ops;
		for (const auto& [key, value] : TestOperationMapper::matrixOperationMap) {
			ops.push_back(key);
		}
		return ops;
	}

	template <typename T>
	std::vector<BitSetOperationType> TestOperationMapper<T>::getBitSetOperations() {
		std::vector<BitSetOperationType> ops;
		for (const auto& [key, value] : TestOperationMapper::bitSetOperationMap) {
			ops.push_back(key);
		}
		return ops;
	}

//	template <typename T>
//	std::vector<TableOperationType> TestOperationMapper<T>::getTableOperations() {
//		std::vector<TableOperationType> ops;
//		for (const auto& [key, value] : TestOperationMapper::tableOperationMap) {
//			ops.push_back(key);
//		}
//		return ops;
//	}

	template <typename T>
	AllStructureOperationType TestOperationMapper<T>::getAllOperationType(ListOperationType op) {
		return TestOperationMapper<T>::listToAllOperationMap[op];
	}

	template <typename T>
	AllStructureOperationType TestOperationMapper<T>::getAllOperationType(PriorityQueueOperationType op) {
		return TestOperationMapper<T>::pqToAllOperationMap[op];
	}

	template <typename T>
	AllStructureOperationType TestOperationMapper<T>::getAllOperationType(MatrixOperationType op) {
		return TestOperationMapper<T>::matrixToAllOperationMap[op];
	}

	template <typename T>
	AllStructureOperationType TestOperationMapper<T>::getAllOperationType(BitSetOperationType op) {
		return TestOperationMapper<T>::bitSetToAllOperationMap[op];
	}

//	template <typename T>
//	AllStructureOperationType TestOperationMapper<T>::getAllOperationType(TableOperationType op) {
//		return TestOperationMapper<T>::tableToAllOperationMap[op];
//	}

	template<typename T>
	AllStructureOperationType TestOperationMapper<T>::getStructureOperationName(void(*fun)(T)) {
		if constexpr (std::is_same<T, Structures::List<Data::DataType>*>::value) {
			return TestOperationMapper::listOperationNameMap[fun];
		} else if constexpr (std::is_same<T, Structures::PriorityQueue<Data::DataType>*>::value) {
			return TestOperationMapper::pqOperationNameMap[fun];
		} else if constexpr (std::is_same<T, Structures::Matrix<Data::DataType>*>::value) {
			return TestOperationMapper::matrixOperationNameMap[fun];
		} else if constexpr (std::is_same<T, Structures::BitSet<Data::DataType>*>::value) {
			return TestOperationMapper::bitSetOperationNameMap[fun];
        } /*else if constexpr (std::is_same<T, Structures::Table<Data::DataType, Data::DataType>*>::value) {
			return TestOperationMapper::tableOperationNameMap[fun];
        }*/ else {
			return AllStructureOperationType::UNDEFINED;
		}
	}

	template <typename T>
	std::map<ListOperationType, void(*)(Structures::List<T>*)> TestOperationMapper<T>::listOperationMap {
		{ ListOperationType::VLOZ_PRVY,	ListOperations::vlozPrvy },
		{ ListOperationType::VLOZ_POSLEDNY, ListOperations::vlozPosledny },
		{ ListOperationType::VLOZ_NA_INDEX, ListOperations::vlozNaIndex	},
		{ ListOperationType::ZRUS_PRVY,	ListOperations::zrusPrvy },
		{ ListOperationType::ZRUS_POSLEDNY, ListOperations::zrusPosledny },
		{ ListOperationType::ZRUS_NA_INDEXE, ListOperations::zrusNaIndexe },
		{ ListOperationType::SPRISTUPNI, ListOperations::spristupni	},
		{ ListOperationType::NASTAV, ListOperations::nastav	},
		{ ListOperationType::INDEX_PRVKU, ListOperations::indexPrvku } };

	template <typename T>
	std::map<PriorityQueueOperationType, void(*)(Structures::PriorityQueue<T>*)> TestOperationMapper<T>::pqOperationMap {
		{ PriorityQueueOperationType::VLOZ, PriorityQueueOperations::vloz },
		{ PriorityQueueOperationType::VYBER, PriorityQueueOperations::vyber },
		{ PriorityQueueOperationType::UKAZ, PriorityQueueOperations::ukaz } };


	template <typename T>
	std::map<MatrixOperationType, void(*)(Structures::Matrix<T>*)> TestOperationMapper<T>::matrixOperationMap {
		{ MatrixOperationType::SPRISTUPNI, MatrixOperations::spristupni },
		{ MatrixOperationType::NASTAV, MatrixOperations::nastav },
		{ MatrixOperationType::VYNASOB, MatrixOperations::vynasob } };

	template <typename T>
	std::map<BitSetOperationType, void(*)(Structures::BitSet<T>*)> TestOperationMapper<T>::bitSetOperationMap {
		{ BitSetOperationType::VLOZ, BitSetOperations::vloz },
		{ BitSetOperationType::VYBER, BitSetOperations::vyber },
		{ BitSetOperationType::PATRI, BitSetOperations::patri },
		{ BitSetOperationType::JE_PODMNOZINOU, BitSetOperations::jePodmnozinou },
		{ BitSetOperationType::PRIENIK, BitSetOperations::prienik },
		{ BitSetOperationType::ZJEDNOTENIE, BitSetOperations::zjednotenie },
		{ BitSetOperationType::ROZDIEL, BitSetOperations::rozdiel } };

//	template <typename T>
//	std::map<TableOperationType, void(*)(Structures::Table<T, T>*)> TestOperationMapper<T>::tableOperationMap {
//		{ TableOperationType::VLOZ, TableOperations::vloz },
//		{ TableOperationType::VYBER, TableOperations::vyber },
//		{ TableOperationType::NAJDI, TableOperations::najdi } };

	template <typename T>
	std::map<AllStructureOperationType, ListOperationType> TestOperationMapper<T>::allToListOperationMap {
		{ AllStructureOperationType::VLOZ_PRVY, ListOperationType::VLOZ_PRVY },
		{ AllStructureOperationType::VLOZ_POSLEDNY, ListOperationType::VLOZ_POSLEDNY },
		{ AllStructureOperationType::VLOZ_NA_INDEX , ListOperationType::VLOZ_NA_INDEX },
		{ AllStructureOperationType::ZRUS_PRVY, ListOperationType::ZRUS_PRVY },
		{ AllStructureOperationType::ZRUS_POSLEDNY, ListOperationType::ZRUS_POSLEDNY },
		{ AllStructureOperationType::ZRUS_NA_INDEXE, ListOperationType::ZRUS_NA_INDEXE },
		{ AllStructureOperationType::SPRISTUPNI, ListOperationType::SPRISTUPNI },
		{ AllStructureOperationType::NASTAV, ListOperationType::NASTAV },
		{ AllStructureOperationType::INDEX_PRVKU, ListOperationType::INDEX_PRVKU } };

	template <typename T>
	std::map<AllStructureOperationType, PriorityQueueOperationType> TestOperationMapper<T>::allToPqOperationMap {
		{ AllStructureOperationType::VLOZ, PriorityQueueOperationType::VLOZ },
		{ AllStructureOperationType::VYBER, PriorityQueueOperationType::VYBER },
		{ AllStructureOperationType::UKAZ, PriorityQueueOperationType::UKAZ }, };

	template <typename T>
	std::map<AllStructureOperationType, MatrixOperationType> TestOperationMapper<T>::allToMatrixOperationMap {
		{ AllStructureOperationType::NASTAV, MatrixOperationType::NASTAV },
		{ AllStructureOperationType::SPRISTUPNI, MatrixOperationType::SPRISTUPNI },
		{ AllStructureOperationType::VYNASOB, MatrixOperationType::VYNASOB } };

	template <typename T>
	std::map<AllStructureOperationType, BitSetOperationType> TestOperationMapper<T>::allToBitSetOperationMap {
		{ AllStructureOperationType::VLOZ , BitSetOperationType::VLOZ },
		{ AllStructureOperationType::VYBER , BitSetOperationType::VYBER },
		{ AllStructureOperationType::PATRI , BitSetOperationType::PATRI },
		{ AllStructureOperationType::JE_PODMNOZINOU , BitSetOperationType::JE_PODMNOZINOU },
		{ AllStructureOperationType::PRIENIK , BitSetOperationType::PRIENIK },
		{ AllStructureOperationType::ZJEDNOTENIE , BitSetOperationType::ZJEDNOTENIE },
		{ AllStructureOperationType::ROZDIEL , BitSetOperationType::ROZDIEL } };

//	template <typename T>
//	std::map<AllStructureOperationType, TableOperationType> TestOperationMapper<T>::allToTableOperationMap {
//		{ AllStructureOperationType::VLOZ , TableOperationType::VLOZ },
//		{ AllStructureOperationType::VYBER , TableOperationType::VYBER },
//		{ AllStructureOperationType::NAJDI , TableOperationType::NAJDI } };

	template <typename T>
	std::map<ListOperationType, AllStructureOperationType> TestOperationMapper<T>::listToAllOperationMap {
		{ ListOperationType::VLOZ_PRVY, AllStructureOperationType::VLOZ_PRVY },
		{ ListOperationType::VLOZ_POSLEDNY, AllStructureOperationType::VLOZ_POSLEDNY },
		{ ListOperationType::VLOZ_NA_INDEX, AllStructureOperationType::VLOZ_NA_INDEX },
		{ ListOperationType::ZRUS_PRVY, AllStructureOperationType::ZRUS_PRVY },
		{ ListOperationType::ZRUS_POSLEDNY, AllStructureOperationType::ZRUS_POSLEDNY },
		{ ListOperationType::ZRUS_NA_INDEXE, AllStructureOperationType::ZRUS_NA_INDEXE },
		{ ListOperationType::SPRISTUPNI, AllStructureOperationType::SPRISTUPNI },
		{ ListOperationType::NASTAV, AllStructureOperationType::NASTAV },
		{ ListOperationType::INDEX_PRVKU, AllStructureOperationType::INDEX_PRVKU } };

	template <typename T>
	std::map<PriorityQueueOperationType, AllStructureOperationType> TestOperationMapper<T>::pqToAllOperationMap {
		{ PriorityQueueOperationType::VLOZ, AllStructureOperationType::VLOZ },
		{ PriorityQueueOperationType::VYBER, AllStructureOperationType::VYBER },
		{ PriorityQueueOperationType::UKAZ , AllStructureOperationType::UKAZ } };

	template <typename T>
	std::map<MatrixOperationType, AllStructureOperationType> TestOperationMapper<T>::matrixToAllOperationMap {
		{ MatrixOperationType::NASTAV, AllStructureOperationType::NASTAV },
		{ MatrixOperationType::SPRISTUPNI, AllStructureOperationType::SPRISTUPNI },
		{ MatrixOperationType::VYNASOB, AllStructureOperationType::VYNASOB } };

	template <typename T>
	std::map<BitSetOperationType, AllStructureOperationType> TestOperationMapper<T>::bitSetToAllOperationMap {
		{ BitSetOperationType::VLOZ, AllStructureOperationType::VLOZ },
		{ BitSetOperationType::VYBER, AllStructureOperationType::VYBER },
		{ BitSetOperationType::PATRI, AllStructureOperationType::PATRI },
		{ BitSetOperationType::JE_PODMNOZINOU, AllStructureOperationType::JE_PODMNOZINOU },
		{ BitSetOperationType::PRIENIK, AllStructureOperationType::PRIENIK },
		{ BitSetOperationType::ZJEDNOTENIE, AllStructureOperationType::ZJEDNOTENIE },
		{ BitSetOperationType::ROZDIEL, AllStructureOperationType::ROZDIEL } };

//	template <typename T>
//	std::map<TableOperationType, AllStructureOperationType> TestOperationMapper<T>::tableToAllOperationMap {
//		{ TableOperationType::VLOZ, AllStructureOperationType::VLOZ },
//		{ TableOperationType::VYBER, AllStructureOperationType::VYBER },
//		{ TableOperationType::NAJDI, AllStructureOperationType::NAJDI } };

	template <typename T>
	std::map<void(*)(T), AllStructureOperationType> TestOperationMapper<T>::listOperationNameMap {
		{ ListOperations::vlozPrvy, AllStructureOperationType::VLOZ_PRVY },
		{ ListOperations::vlozPosledny, AllStructureOperationType::VLOZ_POSLEDNY },
		{ ListOperations::vlozNaIndex, AllStructureOperationType::VLOZ_NA_INDEX },
		{ ListOperations::zrusPrvy, AllStructureOperationType::ZRUS_PRVY },
		{ ListOperations::zrusPosledny, AllStructureOperationType::ZRUS_POSLEDNY },
		{ ListOperations::zrusNaIndexe, AllStructureOperationType::ZRUS_NA_INDEXE },
		{ ListOperations::spristupni, AllStructureOperationType::SPRISTUPNI },
		{ ListOperations::nastav, AllStructureOperationType::NASTAV },
		{ ListOperations::indexPrvku, AllStructureOperationType::INDEX_PRVKU } };

	template <typename T>
	std::map<void(*)(T), AllStructureOperationType> TestOperationMapper<T>::pqOperationNameMap {
		{ PriorityQueueOperations::vloz, AllStructureOperationType::VLOZ },
		{ PriorityQueueOperations::vyber, AllStructureOperationType::VYBER },
		{ PriorityQueueOperations::ukaz, AllStructureOperationType::UKAZ } };

	template <typename T>
	std::map<void(*)(T), AllStructureOperationType> TestOperationMapper<T>::matrixOperationNameMap {
		{ MatrixOperations::spristupni, AllStructureOperationType::SPRISTUPNI },
		{ MatrixOperations::nastav, AllStructureOperationType::NASTAV },
		{ MatrixOperations::vynasob, AllStructureOperationType::VYNASOB } };

	template <typename T>
	std::map<void(*)(T), AllStructureOperationType> TestOperationMapper<T>::bitSetOperationNameMap {
		{ BitSetOperations::vloz, AllStructureOperationType::VLOZ },
		{ BitSetOperations::vyber, AllStructureOperationType::VYBER },
		{ BitSetOperations::patri, AllStructureOperationType::PATRI },
		{ BitSetOperations::jePodmnozinou, AllStructureOperationType::JE_PODMNOZINOU },
		{ BitSetOperations::prienik, AllStructureOperationType::PRIENIK },
		{ BitSetOperations::zjednotenie, AllStructureOperationType::ZJEDNOTENIE },
		{ BitSetOperations::rozdiel, AllStructureOperationType::ROZDIEL } };

//	template <typename T>
//	std::map<void(*)(T), AllStructureOperationType> TestOperationMapper<T>::tableOperationNameMap {
//		{ TableOperations::vloz, AllStructureOperationType::VLOZ },
//		{ TableOperations::vyber, AllStructureOperationType::VYBER },
//		{ TableOperations::najdi, AllStructureOperationType::NAJDI } };

	template <typename T>
	std::map<std::string, std::vector<std::string>> TestOperationMapper<T>::adtOperationsStrMap {
		{ "List", { "Vloz prvy", "Vloz posledny", "Vloz na index", "Zrus prvy", "Zrus posledny", "Zrus na indexe",
					"Spristupni", "Nastav", "Index prvku" } },
		{ "Priority queue", { "Vloz", "Vyber", "Ukaz"} },
		{ "Matrix", { "Spristupni", "Nastav", "Vynasob" } },
        { "BitSet", { "Vloz", "Vyber", "Patri", "Je podmnozinou", "Prienik", "Zjednotenie", "Rozdiel"} }/*,
        { "Table", { "Vloz", "Vyber", "Najdi" } }*/ };

	template <typename T>
	std::map<StructureADT, std::vector<StructureADS>> TestOperationMapper<T>::adtToAdsMap {
		{ StructureADT::adtLIST, { StructureADS::adsLIST_ARRAY,
								   StructureADS::adsLIST_ARRAY_RAW,
								   StructureADS::adsLIST_LINKED,
								   StructureADS::adsLIST_DOUBLE_LINKED,
								   StructureADS::adsLIST_CYCLICAL } },
		{ StructureADT::adtPRIORITY_QUEUE, { StructureADS::adsPRIORITY_QUEUE_ARRAY_LIST_UNSORTED,
											 StructureADS::adsPRIORITY_QUEUE_ARRAY_LIST_SORTED,
											 StructureADS::adsPRIORITY_QUEUE_LINKED_LIST,
//											 StructureADS::adsPRIORITY_QUEUE_DOUBLE_LAYER,
											 StructureADS::adsPRIORITY_QUEUE_TWO_LISTS,
											 StructureADS::adsPRIORITY_QUEUE_TWO_LISTS_MEDIUM,
											 StructureADS::adsPRIORITY_QUEUE_TWO_LISTS_LARGE,
											 StructureADS::adsPRIORITY_QUEUE_HEAP} },
		{ StructureADT::adtMATRIX, { StructureADS::adsMATRIX_STACK,
									 StructureADS::adsMATRIX_HEAP,
									 StructureADS::adsMATRIX_HEAP_CONTINUOUS } },
		{ StructureADT::adtBITSET, { StructureADS::adsBITSET, StructureADS::adsBITSET_LARGE } },
        /*{ StructureADT::adtTABLE, { StructureADS::adsTABLE_SEQUENCE_UNSORTED,
									StructureADS::adsTABLE_SEQUENCE_SORTED,
									StructureADS::adsTABLE_HASH,
									StructureADS::adsTABLE_BST,
                                    StructureADS::adsTABLE_TREAP } } */};

}

