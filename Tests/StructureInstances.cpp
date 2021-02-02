#include "StructureInstances.h"

#include "List/ArrayList.h"
#include "List/ArrayListRaw.h"
#include "List/LinkedList.h"
#include "List/DoublyLinkedList.h"
#include "List/DoublyCircularLinkedList.h"
#include "Matrix/MatrixStack.h"
#include "Matrix/MatrixHeap.h"
#include "Matrix/MatrixHeapContinuous.h"
#include "PriorityQueue/PriorityQueueUnsortedArrayList.h"
#include "PriorityQueue/PriorityQueueSortedArrayList.h"
#include "PriorityQueue/PriorityQueueLinkedList.h"
#include "PriorityQueue/PriorityQueueTwoLists.h"
#include "PriorityQueue/Heap.h"
#include "Table/UnsortedSequenceTable.h"
#include "Table/SortedSequenceTable.h"
#include "Table/HashTable.h"
#include "Table/BinarySearchTree.h"
#include "Table/Treap.h"

Structures::StructureInstances::StructureInstances() : mnozina(new BaseSet<Data::DataType>(1000)), mnozinaLarge(new BaseSet<Data::DataType>(10000)) {
	for (size_t i = 0; i < mnozina->size(); ++i) {
		mnozina[i] = i;
	}

	this->listInstances.insert({StructureADS::adsLIST_ARRAY, new ArrayList<Data::DataType>});
	this->listInstances.insert({StructureADS::adsLIST_ARRAY_RAW, new ArrayListRaw<Data::DataType>});
	this->listInstances.insert({StructureADS::adsLIST_LINKED, new LinkedList<Data::DataType>});
	this->listInstances.insert({StructureADS::adsLIST_DOUBLE_LINKED, new DoublyLinkedList<Data::DataType>});
	this->listInstances.insert({StructureADS::adsLIST_CYCLICAL, new DoublyCircularLinkedList<Data::DataType>});

	this->bitSetInstances.insert({StructureADS::adsBITSET, new BitSet<Data::DataType>(mnozina)});
	this->bitSetInstances.insert({StructureADS::adsBITSET_LARGE, new BitSet<Data::DataType>(mnozinaLarge)});
//	this->bitSetInstances.insert({StructureADS::adsBITSET_BST, new BitSetBinarySearchTree<Data::DataType>(mnozinaBST)});
//	this->bitSetInstances.insert({StructureADS::adsBITSET_LARGE_BST, new BitSetBinarySearchTree<Data::DataType>(mnozinaLargeBST)});

	this->matrixInstances.insert({StructureADS::adsMATRIX_STACK, new MatrixStack<M_SIZE, M_SIZE, Data::DataType>});
	this->matrixInstances.insert({StructureADS::adsMATRIX_HEAP, new MatrixHeap<Data::DataType>(M_SIZE, M_SIZE)});
	this->matrixInstances.insert({StructureADS::adsMATRIX_HEAP_CONTINUOUS, new MatrixHeapContinous<Data::DataType>(M_SIZE, M_SIZE)});

	this->priorityQueueInstances.insert({StructureADS::adsPRIORITY_QUEUE_ARRAY_LIST_UNSORTED, new PriorityQueueUnsortedArrayList<Data::DataType>});
	this->priorityQueueInstances.insert({StructureADS::adsPRIORITY_QUEUE_ARRAY_LIST_SORTED, new PriorityQueueSortedArrayList<Data::DataType>});
	this->priorityQueueInstances.insert({StructureADS::adsPRIORITY_QUEUE_LINKED_LIST, new PriorityQueueLinkedList<Data::DataType>});
	this->priorityQueueInstances.insert({StructureADS::adsPRIORITY_QUEUE_TWO_LISTS, new PriorityQueueTwoLists<Data::DataType>});
	this->priorityQueueInstances.insert({StructureADS::adsPRIORITY_QUEUE_TWO_LISTS_MEDIUM, new PriorityQueueTwoLists<Data::DataType>(64)});
	this->priorityQueueInstances.insert({StructureADS::adsPRIORITY_QUEUE_TWO_LISTS_LARGE, new PriorityQueueTwoLists<Data::DataType>(1024)});
	this->priorityQueueInstances.insert({StructureADS::adsPRIORITY_QUEUE_DOUBLE_LAYER, nullptr});
	this->priorityQueueInstances.insert({StructureADS::adsPRIORITY_QUEUE_HEAP, new Heap<Data::DataType>});

//	this->tableInstances.insert({StructureADS::adsTABLE_SEQUENCE_UNSORTED, new UnsortedSequenceTable<Data::DataType, Data::DataType>});
//	this->tableInstances.insert({StructureADS::adsTABLE_SEQUENCE_SORTED, new SortedSequenceTable<Data::DataType, Data::DataType>});
//	this->tableInstances.insert({StructureADS::adsTABLE_HASH, new HashTable<Data::DataType, Data::DataType>});
//	this->tableInstances.insert({StructureADS::adsTABLE_BST, new BinarySearchTree<Data::DataType, Data::DataType>});
//	this->tableInstances.insert({StructureADS::adsTABLE_TREAP, new Treap<Data::DataType, Data::DataType>});
}

Structures::StructureInstances::~StructureInstances() {
	for (auto& temp : this->listInstances) {
		if (temp.second != nullptr)
			delete temp.second;
		temp.second = nullptr;
	}
	for (auto& temp : this->bitSetInstances) {
		if (temp.second != nullptr)
			delete temp.second;
		temp.second = nullptr;
	}
	for (auto& temp : this->matrixInstances) {
		if (temp.second != nullptr)
			delete temp.second;
		temp.second = nullptr;
	}
	for (auto& temp : this->priorityQueueInstances) {
		if (temp.second != nullptr)
			delete temp.second;
		temp.second = nullptr;
	}
//	for (auto& temp : this->tableInstances) {
//		if (temp.second != nullptr)
//			delete temp.second;
//		temp.second = nullptr;
//	}

	delete this->mnozina;
	this->mnozina = nullptr;

	delete this->mnozinaLarge;
	this->mnozinaLarge = nullptr;
}

Structures::List<Data::DataType>* Structures::StructureInstances::getListInstance(const Structures::StructureADS ads) {
	return this->listInstances[ads];
}

Structures::BitSet<Data::DataType>* Structures::StructureInstances::getBitSetInstance(const Structures::StructureADS ads) {
	return this->bitSetInstances[ads];
}

Structures::Matrix<Data::DataType>* Structures::StructureInstances::getMatrixInstance(const Structures::StructureADS ads) {
	return this->matrixInstances[ads];
}

Structures::PriorityQueue<Data::DataType>* Structures::StructureInstances::getPriorityQueueInstance(const Structures::StructureADS ads) {
	return this->priorityQueueInstances[ads];
}

//Structures::Table<Data::DataType, Data::DataType>* Structures::StructureInstances::getTableInstance(const Structures::StructureADS ads) {
//	return this->tableInstances[ads];
//}
