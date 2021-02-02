QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    AppData/MeasuredData.cpp \
    GUI/ADSDock.cpp \
    GUI/ADSList.cpp \
    GUI/ADSListItem.cpp \
    GUI/ADSOperationWidget.cpp \
    GUI/ADSTestWidget.cpp \
    GUI/ADTComboBox.cpp \
    GUI/ADTPanel.cpp \
    GUI/AppManager.cpp \
    GUI/BarChart.cpp \
    GUI/Chart.cpp \
    GUI/ChartControl.cpp \
    GUI/ChartData.cpp \
    GUI/ChartWidget.cpp \
    GUI/MainWindow.cpp \
    GUI/PieChart.cpp \
    GUI/UIRoutines.cpp \
    RandomGenerator.cpp \
    Tests/StructureInstances.cpp \
    Tests/TestTime.cpp \
    main.cpp \
    DSRoutines.cpp \
    DSStructureFactory.cpp \
    MemoryRoutines.cpp \
    Structure.cpp \
    Vector/Vector.cpp \
    Table/Sorting/Sort.cpp \

HEADERS += \
    Data/Pair.h \
    GUI/ADSDock.h \
    GUI/ADSList.h \
    GUI/ADSListItem.h \
    GUI/ADSOperationWidget.h \
    GUI/ADSTestWidget.h \
    GUI/ADTComboBox.h \
    GUI/ADTPanel.h \
    GUI/AppManager.h \
    GUI/BarChart.h \
    GUI/Chart.h \
    GUI/ChartControl.h \
    GUI/ChartData.h \
    GUI/ChartWidget.h \
    GUI/MainWindow.h \
    GUI/PieChart.h \
    GUI/UIRoutines.h \
    List/ArrayListRaw.h \
    List/DoublyCircularLinkedList.h \
    List/DoublyLinkedList.h \
    Array/Array.h \
    List/ArrayList.h \
    DSRoutines.h \
    DSStructureFactory.h \
    DSStructureTypes.h \
    HeapMonitor.h \
    Matrix/MatrixHeap.h \
    Matrix/MatrixHeapContinuous.h \
    Matrix/MatrixStack.h \
    MultiArray.h \
    PriorityQueue/PriorityQueueLimitedSortedArrayList.h \
    PriorityQueue/PriorityQueueTwoLists.h \
    Queue/ExplicitQueue.h \
    RandomGenerator.h \
    Set/BaseSet.h \
    Set/BaseSetBinarySearchTree.h \
    Set/BitSetBinarySearchTree.h \
    Stack/ExplicitStack.h \
    PriorityQueue/Heap.h \
    Queue/ImplicitQueue.h \
    Stack/ImplicitStack.h \
    List/LinkedList.h \
    List/List.h \
    MemoryRoutines.h \
    PriorityQueue/PriorityQueue.h \
    PriorityQueue/PriorityQueueLinkedList.h \
    PriorityQueue/PriorityQueueList.h \
    PriorityQueue/PriorityQueueSortedArrayList.h \
    PriorityQueue/PriorityQueueUnsortedArrayList.h \
    Queue/Queue.h \
    Stack/Stack.h \
    Structure.h \
    StructureIterator.h \
    Table/Sorting/Comparator.h \
    Tests/BitSetOperations.h \
    Tests/ListOperations.h \
    Tests/MatrixOperations.h \
    Tests/OperationProbability.h \
    Tests/OperationTimeInfo.h \
    Tests/PriorityQueueOperations.h \
    Tests/StructureInstances.h \
    Tests/TableOperations.h \
    Tests/TestOperationTypes.h \
    Tests/TestStructure.h \
    Tests/TestTime.h \
    Tests/TimeFileWriter.h \
    Vector/Vector.h \
    Matrix/Matrix.h \
    AppData/MeasuredData.h \
    Set/BitSet.h \
    Data/DataTypes.h \
    Tree/Tree.h \
    Tree/KWayTree.h \
    Tree/BinaryTree.h \
    Tree/MultiWayTree.h \
    Table/BinarySearchTree.h \
    Table/HashTable.h \
    Table/LinkedTable.h \
    Table/SequenceTable.h \
    Table/Sorting/Shuffle.h \
    Table/Sorting/BubbleSort.h \
    Table/Sorting/HeapSort.h \
    Table/Sorting/InsertSort.h \
    Table/Sorting/MergeSort.h \
    Table/Sorting/QuickSort.h \
    Table/Sorting/RadixSort.h \
    Table/Sorting/SelectSort.h \
    Table/Sorting/ShellSort.h \
    Table/Sorting/Sort.h \
    Table/Table.h \
    Table/Treap.h \
    Table/SortedSequenceTable.h \
    Table/UnsortedSequenceTable.h \

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    GUI/images.qrc
