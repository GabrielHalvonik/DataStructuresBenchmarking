#include "UIRoutines.h"

std::string UIRoutines::convertStructureADTToStr(const Structures::StructureADT adt) {
	switch (adt) {
		case Structures::StructureADT::adtVECTOR:
			return "Vector";
		case Structures::StructureADT::adtARRAY:
			return "Array";
		case Structures::StructureADT::adtBITSET:
			return "BitSet";
		case Structures::StructureADT::adtLIST:
			return "List";
		case Structures::StructureADT::adtMATRIX:
			return "Matrix";
		case Structures::StructureADT::adtQUEUE:
			return "Queue";
		case Structures::StructureADT::adtSTACK:
			return "Stack";
		case Structures::StructureADT::adtPRIORITY_QUEUE:
			return "Priority queue";
		case Structures::StructureADT::adtTREE:
			return "Tree";
		case Structures::StructureADT::adtGRAPH:
			return "Graph";
        case Structures::StructureADT::adtTABLE:
            return "Table";
		default:
			return "Unknown ADT";
	}
}

std::string UIRoutines::convertStructureADSToStr(const Structures::StructureADS ads) {
	switch (ads) {
		case Structures::StructureADS::adsVECTOR:
			return "Vector";

		case Structures::StructureADS::adsARRAY:
			return "Array";

		case Structures::StructureADS::adsBITSET:
			return "BitSet";
		case Structures::StructureADS::adsBITSET_LARGE:
			return "BitSet large";

		case Structures::StructureADS::adsLIST_ARRAY:
			return "Array list";
		case Structures::StructureADS::adsLIST_ARRAY_RAW:
			return "Array list Raw";
		case Structures::StructureADS::adsLIST_LINKED:
			return "Linked list";
		case Structures::StructureADS::adsLIST_DOUBLE_LINKED:
			return "Double-linked list";
		case Structures::StructureADS::adsLIST_CYCLICAL:
			return "Double-Cyclical list";

		case Structures::StructureADS::adsMATRIX_STACK:
			return "Matrix stack";
		case Structures::StructureADS::adsMATRIX_HEAP:
			return "Matrix heap";
		case Structures::StructureADS::adsMATRIX_HEAP_CONTINUOUS:
			return "Matrix heap continuous";

		case Structures::StructureADS::adsQUEUE_ARRAY:
			return "Queue by array";
		case Structures::StructureADS::adsQUEUE_LIST:
			return "Queue by list";

		case Structures::StructureADS::adsSTACK_ARRAY:
			return "Stack by array";
		case Structures::StructureADS::adsSTACK_LIST:
			return "Stack by list";

		case Structures::StructureADS::adsPRIORITY_QUEUE_ARRAY_LIST_SORTED:
			return "Priority queue by sorted array list";
		case Structures::StructureADS::adsPRIORITY_QUEUE_ARRAY_LIST_UNSORTED:
			return "Priority queue by unsorted array list";
		case Structures::StructureADS::adsPRIORITY_QUEUE_LINKED_LIST:
			return "Priority queue by linked list";
		case Structures::StructureADS::adsPRIORITY_QUEUE_TWO_LISTS:
			return "Priority queue by two lists";
		case Structures::StructureADS::adsPRIORITY_QUEUE_TWO_LISTS_MEDIUM:
			return "Priority queue by two lists (M)";
		case Structures::StructureADS::adsPRIORITY_QUEUE_TWO_LISTS_LARGE:
			return "Priority queue by two lists (L)";
//		case Structures::StructureADS::adsPRIORITY_QUEUE_DOUBLE_LAYER:
//			return "Priority queue double layer implementation";
		case Structures::StructureADS::adsPRIORITY_QUEUE_HEAP:
			return "Heap";

		case Structures::StructureADS::adsTREE_MULTI_WAY:
			return "Multi way tree";
		case Structures::StructureADS::adsTREE_K_WAY:
			return "K way tree";
		case Structures::StructureADS::adsTREE_BINARY:
			return "Binary tree";

		case Structures::StructureADS::adsGRAPH_MATRIX:
			return "Graph by matrix";
		case Structures::StructureADS::adsGRAPH_FORWARD_STAR:
			return "Graph by forward star";
		case Structures::StructureADS::adsGRAPH_BI_STAR:
			return "Graph by bidirectional star";

		case Structures::StructureADS::adsTABLE_SEQUENCE_SORTED:
			return "Sorted sequence table";
		case Structures::StructureADS::adsTABLE_SEQUENCE_UNSORTED:
			return "Unsorted sequence table";
		case Structures::StructureADS::adsTABLE_LINKED:
			return "Linked table";
		case Structures::StructureADS::adsTABLE_DIAMOND:
			return "Diamond table";
		case Structures::StructureADS::adsTABLE_HASH:
			return "Hash table";
		case Structures::StructureADS::adsTABLE_BST:
			return "Binary search tree";
		case Structures::StructureADS::adsTABLE_TREAP:
			return "Treap";
		default:
			return "Unknown ADS";
	}
}

std::string UIRoutines::convertOperationTypeToStr(const Structures::ListOperationType opType) {
	switch (opType) {
		case Structures::ListOperationType::VLOZ_PRVY:
			return "Vloz prvy";
		case Structures::ListOperationType::VLOZ_POSLEDNY:
			return "Vloz posledny";
		case Structures::ListOperationType::VLOZ_NA_INDEX:
			return "Vloz na index";
		case Structures::ListOperationType::ZRUS_PRVY:
			return "Zrus prvy";
		case Structures::ListOperationType::ZRUS_POSLEDNY:
			return "Zrus posledny";
		case Structures::ListOperationType::ZRUS_NA_INDEXE:
			return "Zrus na indexe";
		case Structures::ListOperationType::SPRISTUPNI:
			return "Spristupni";
		case Structures::ListOperationType::NASTAV:
			return "Nastav";
		case Structures::ListOperationType::INDEX_PRVKU:
			return "Index prvku";
		default:
			return "Unknown List Operation Type";
	}
}

std::string UIRoutines::convertOperationTypeToStr(const Structures::PriorityQueueOperationType opType) {
	switch (opType) {
		case Structures::PriorityQueueOperationType::VLOZ:
			return "Vloz";
		case Structures::PriorityQueueOperationType::VYBER:
			return "Vyber";
		case Structures::PriorityQueueOperationType::UKAZ:
			return "Ukaz";
		default:
			return "Unknown Priority Queue Operation Type";
	}
}

std::string UIRoutines::convertOperationTypeToStr(const Structures::MatrixOperationType opType) {
	switch (opType) {
		case Structures::MatrixOperationType::NASTAV:
			return "Nastav";
		case Structures::MatrixOperationType::SPRISTUPNI:
			return "Spristupni";
		case Structures::MatrixOperationType::VYNASOB:
			return "Vynasob";
		default:
			return "Unknown Matrix Operation Type";
	}
}

std::string UIRoutines::convertOperationTypeToStr(const Structures::BitSetOperationType opType) {
	switch (opType) {
		case Structures::BitSetOperationType::VLOZ:
			return "Vloz";
		case Structures::BitSetOperationType::VYBER:
			return "Vyber";
		case Structures::BitSetOperationType::PATRI:
			return "Patri";
		case Structures::BitSetOperationType::JE_PODMNOZINOU:
			return "Je podmnozinou";
		case Structures::BitSetOperationType::PRIENIK:
			return "Prienik";
		case Structures::BitSetOperationType::ZJEDNOTENIE:
			return "Zjednotenie";
		case Structures::BitSetOperationType::ROZDIEL:
			return "Rozdiel";
		default:
			return "Unknown BitSet Operation Type";
	}
}

std::string UIRoutines::convertOperationTypeToStr(const Structures::TableOperationType opType) {
	switch (opType) {
		case Structures::TableOperationType::VLOZ:
			return "Vloz";
		case Structures::TableOperationType::VYBER:
			return "Vyber";
		case Structures::TableOperationType::NAJDI:
			return "Najdi";
		default:
			return "Unknown BitSet Operation Type";
	}
}

std::string UIRoutines::convertOperationTypeToStr(const Structures::AllStructureOperationType opType) {
	switch (opType) {
		case Structures::AllStructureOperationType::VLOZ_PRVY:
			return "Vloz prvy";
		case Structures::AllStructureOperationType::VLOZ_POSLEDNY:
			return "Vloz posledny";
		case Structures::AllStructureOperationType::VLOZ_NA_INDEX:
			return "Vloz na index";
		case Structures::AllStructureOperationType::ZRUS_PRVY:
			return "Zrus prvy";
		case Structures::AllStructureOperationType::ZRUS_POSLEDNY:
			return "Zrus posledny";
		case Structures::AllStructureOperationType::ZRUS_NA_INDEXE:
			return "Zrus na indexe";
		case Structures::AllStructureOperationType::SPRISTUPNI:
			return "Spristupni";
		case Structures::AllStructureOperationType::NASTAV:
			return "Nastav";
		case Structures::AllStructureOperationType::INDEX_PRVKU:
			return "Index prvku";
		case Structures::AllStructureOperationType::VLOZ:
			return "Vloz";
		case Structures::AllStructureOperationType::VYBER:
			return "Vyber";
		case Structures::AllStructureOperationType::UKAZ:
			return "Ukaz";
		case Structures::AllStructureOperationType::PATRI:
			return "Patri";
		case Structures::AllStructureOperationType::JE_PODMNOZINOU:
			return "Je podmnozinou";
		case Structures::AllStructureOperationType::ZJEDNOTENIE:
			return "Zjednotenie";
		case Structures::AllStructureOperationType::PRIENIK:
			return "Prienik";
		case Structures::AllStructureOperationType::ROZDIEL:
			return "Rozdiel";
		case Structures::AllStructureOperationType::VYNASOB:
            return "Vynasob";
        case Structures::AllStructureOperationType::NAJDI:
            return "Najdi";
		default:
			return "Undefined";
    }
}

const std::string& UIRoutines::getColorOfADS(const Structures::StructureADS ads) {
    return UIRoutines::colorsOfADS[ads];
}

Structures::StructureADS UIRoutines::getAdsOfStr(const std::string& str) {
    return UIRoutines::adsOfStr[str];
}

Structures::AllStructureOperationType UIRoutines::getAllOpsOfStr(const std::string& str) {
    return UIRoutines::allOpsOfStr[str];
}


std::map<std::string, Structures::StructureADS> UIRoutines::adsOfStr {
    { "Array list", Structures::StructureADS::adsLIST_ARRAY },
    { "Array list Raw", Structures::StructureADS::adsLIST_ARRAY_RAW },
    { "Linked list", Structures::StructureADS::adsLIST_LINKED },
    { "Double-linked list", Structures::StructureADS::adsLIST_DOUBLE_LINKED },
    { "Double-Cyclical list", Structures::StructureADS::adsLIST_CYCLICAL },
    { "Heap", Structures::StructureADS::adsPRIORITY_QUEUE_HEAP },
    { "Priority queue by two lists", Structures::StructureADS::adsPRIORITY_QUEUE_TWO_LISTS },
    { "Priority queue by two lists (M)", Structures::StructureADS::adsPRIORITY_QUEUE_TWO_LISTS_MEDIUM },
    { "Priority queue by two lists (L)", Structures::StructureADS::adsPRIORITY_QUEUE_TWO_LISTS_LARGE },
    { "Priority queue by linked list", Structures::StructureADS::adsPRIORITY_QUEUE_LINKED_LIST },
    { "Priority queue by sorted array list", Structures::StructureADS::adsPRIORITY_QUEUE_ARRAY_LIST_SORTED },
    { "Priority queue by unsorted array list", Structures::StructureADS::adsPRIORITY_QUEUE_ARRAY_LIST_UNSORTED },
    { "Matrix stack", Structures::StructureADS::adsMATRIX_STACK },
    { "Matrix heap", Structures::StructureADS::adsMATRIX_HEAP },
    { "Matrix heap continuous", Structures::StructureADS::adsMATRIX_HEAP_CONTINUOUS },
    { "BitSet", Structures::StructureADS::adsBITSET },
    { "BitSet large", Structures::StructureADS::adsBITSET_LARGE },
    { "Unsorted sequence table", Structures::StructureADS::adsTABLE_SEQUENCE_UNSORTED },
    { "Sorted sequence table", Structures::StructureADS::adsTABLE_SEQUENCE_SORTED },
    { "Hash table", Structures::StructureADS::adsTABLE_HASH },
    { "Binary search tree", Structures::StructureADS::adsTABLE_BST },
    { "Treap", Structures::StructureADS::adsTABLE_TREAP } };

std::map<std::string, Structures::AllStructureOperationType> UIRoutines::allOpsOfStr {
    { "Vloz prvy", Structures::AllStructureOperationType::VLOZ_PRVY },
    { "Vloz posledny", Structures::AllStructureOperationType::VLOZ_POSLEDNY },
    { "Vloz na index", Structures::AllStructureOperationType::VLOZ_NA_INDEX },
    { "Zrus prvy", Structures::AllStructureOperationType::ZRUS_PRVY },
    { "Zrus posledny", Structures::AllStructureOperationType::ZRUS_POSLEDNY },
    { "Zrus na indexe", Structures::AllStructureOperationType::ZRUS_NA_INDEXE },
    { "Spristupni", Structures::AllStructureOperationType::SPRISTUPNI },
    { "Nastav", Structures::AllStructureOperationType::NASTAV },
    { "Index prvku", Structures::AllStructureOperationType::INDEX_PRVKU },
    { "Vloz", Structures::AllStructureOperationType::VLOZ },
    { "Vyber", Structures::AllStructureOperationType::VYBER },
    { "Ukaz", Structures::AllStructureOperationType::UKAZ },
    { "Patri", Structures::AllStructureOperationType::PATRI },
    { "Je podmnozinou", Structures::AllStructureOperationType::JE_PODMNOZINOU },
    { "Zjednotenie", Structures::AllStructureOperationType::ZJEDNOTENIE },
    { "Prienik", Structures::AllStructureOperationType::PRIENIK },
    { "Rozdiel", Structures::AllStructureOperationType::ROZDIEL },
    { "Vynasob", Structures::AllStructureOperationType::VYNASOB },
    { "Najdi", Structures::AllStructureOperationType::NAJDI } };

std::map<Structures::StructureADS, std::string> UIRoutines::colorsOfADS {
	{ Structures::StructureADS::adsLIST_ARRAY, "#651fff"},
	{ Structures::StructureADS::adsLIST_ARRAY_RAW, "#0066FF"},
	{ Structures::StructureADS::adsLIST_LINKED, "#00c853"},
	{ Structures::StructureADS::adsLIST_DOUBLE_LINKED, "#FF4500"},
	{ Structures::StructureADS::adsLIST_CYCLICAL, "#CCFF90"},
	{ Structures::StructureADS::adsPRIORITY_QUEUE_HEAP, "#651fff"},
	{ Structures::StructureADS::adsPRIORITY_QUEUE_TWO_LISTS, "#CCFF90"},
	{ Structures::StructureADS::adsPRIORITY_QUEUE_TWO_LISTS_MEDIUM, "#FF4500"},
	{ Structures::StructureADS::adsPRIORITY_QUEUE_TWO_LISTS_LARGE, "#00c853"},
	{ Structures::StructureADS::adsPRIORITY_QUEUE_LINKED_LIST, "#00c853"},
	{ Structures::StructureADS::adsPRIORITY_QUEUE_ARRAY_LIST_SORTED, "#EEEEEE"},
	{ Structures::StructureADS::adsPRIORITY_QUEUE_ARRAY_LIST_UNSORTED, "#FF4500"},
	{ Structures::StructureADS::adsMATRIX_STACK, "#651fff"},
	{ Structures::StructureADS::adsMATRIX_HEAP, "#0066FF"},
	{ Structures::StructureADS::adsMATRIX_HEAP_CONTINUOUS, "#00c853"},
	{ Structures::StructureADS::adsBITSET, "#FF4500"},
	{ Structures::StructureADS::adsBITSET_LARGE, "#0066FF"},
    /*{ Structures::StructureADS::adsTABLE_SEQUENCE_UNSORTED, "#651fff"},
	{ Structures::StructureADS::adsTABLE_SEQUENCE_SORTED, "#0066FF"},
	{ Structures::StructureADS::adsTABLE_HASH, "#00c853"},
	{ Structures::StructureADS::adsTABLE_BST, "#FF4500"},
    { Structures::StructureADS::adsTABLE_TREAP, "#CCFF90"}*/ };
