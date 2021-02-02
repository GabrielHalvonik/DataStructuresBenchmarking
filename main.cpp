#include <QApplication>
#include "GUI/MainWindow.h"
#include "MultiArray.h"
#include "Table/HashTable.h"
#include "List/ArrayList.h"
#include "List/ArrayListRaw.h"
#include "Tests/ListOperations.h"
#include "List/LinkedList.h"
#include "List/DoublyLinkedList.h"
#include "List/DoublyCircularLinkedList.h"
#include "Set/BitSet.h"
#include "Set/BitSetBinarySearchTree.h"
#include "Set/BaseSet.h"
#include "Data/DataTypes.h"
#include "Matrix/MatrixHeap.h"
#include "Matrix/MatrixHeapContinuous.h"
#include "PriorityQueue/PriorityQueueLinkedList.h"
#include "PriorityQueue/PriorityQueueUnsortedArrayList.h"
#include "PriorityQueue/PriorityQueueSortedArrayList.h"
#include "PriorityQueue/PriorityQueueTwoLists.h"
#include "PriorityQueue/Heap.h"
#include "Tests/StructureInstances.h"
#include "Tests/TestStructure.h"
#include "Tests/BitSetOperations.h"
#include "Tests/TimeFileWriter.h"


using namespace Structures;

class TimeTest {
public:
TimeTest() : start(std::chrono::high_resolution_clock::now()) {}
	~TimeTest() {
		this->stop = std::chrono::high_resolution_clock::now();
		std::cout << (stop - start).count() << std::endl;
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start, stop;
};

int main(int argc, char *argv[]) {

	QApplication a(argc, argv);
	MainWindow mw;
	mw.showFullScreen();

	return a.exec();
}
