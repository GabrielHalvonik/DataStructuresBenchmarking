#pragma once

#include "Structure.h"
#include "DSStructureTypes.h"
#include "Data/DataTypes.h"
#include "List/List.h"
#include "Set/BitSet.h"
#include "Set/BitSetBinarySearchTree.h"
#include "PriorityQueue/PriorityQueueList.h"
#include "Table/Table.h"
#include "Matrix/Matrix.h"
#include <map>

namespace Structures {

	const size_t M_SIZE = 100;

	class StructureInstances {
	public:
		StructureInstances();
		~StructureInstances();

		List<Data::DataType>* getListInstance(const StructureADS);
		BitSet<Data::DataType>* getBitSetInstance(const StructureADS);
		Matrix<Data::DataType>* getMatrixInstance(const StructureADS);
		PriorityQueue<Data::DataType>* getPriorityQueueInstance(const StructureADS);
		Table<Data::DataType, Data::DataType>* getTableInstance(const StructureADS);

	private:
		std::map<StructureADS, List<Data::DataType>*> listInstances;
		std::map<StructureADS, BitSet<Data::DataType>*> bitSetInstances;
		std::map<StructureADS, Matrix<Data::DataType>*> matrixInstances;
		std::map<StructureADS, PriorityQueue<Data::DataType>*> priorityQueueInstances;
//		std::map<StructureADS, Table<Data::DataType, Data::DataType>*> tableInstances;
		BaseSet<Data::DataType>* mnozina;
		BaseSet<Data::DataType>* mnozinaLarge;
//		BaseSetBinarySearchTree<Data::DataType>* mnozinaBST;
//		BaseSetBinarySearchTree<Data::DataType>* mnozinaLargeBST;
	};

}
