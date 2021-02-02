# Benchmarking of Data Structures in C++

## Overview

Structures benchmarking is semester project for the school subject [Data Structures and Algorithms](https://vzdelavanie.uniza.sk/vzdelavanie/planinfo.php?kod=274661&lng=sk "Data Structures and Algorithms").
 The goal wasto program and experimentally compare the performance of different implementations of data structures.

The structures and the test application are written in C++ with manual memory management.
[Qt Framework](http://www.qt.io "Qt Framework") (v5.15) was used for better and more convenient testing and visualization.
## User manual
![alt text](https://raw.githubusercontent.com/GabrielHalvonik/Udajovky_Semestralka_1/master/manual_res/manual_1.png "User manual")

##### 1. combobox for choosing ADT(BitSet, List, Matrix, PriorityQueue)
##### 2. list for choosing ADS of selected ADT
##### 3. widget for choosing operations performed on selected ADS
##### 4. widget for choosing operations count (0-1M) and button for starting/clear
##### 5. chart legend for color representation of ADS (click to toggle ADS)
##### 6. chart widget for ADS operations benchmark using scatter plot
* ##### X axis: operation count
* ##### Y axis: time [ns]
* ##### ArrowUp/ArrowDown: scale y axis
* ##### movable chart area
##### 7. pie chart widget for summary time stats performed on ADS
##### 8. bar chart widget for each selected ADS operation total time execution
* ##### SPACE: toggle full view of operation total time execution
![alt text](https://raw.githubusercontent.com/GabrielHalvonik/Udajovky_Semestralka_1/master/manual_res/manual_2.png "User manual2")

### Description of tested ADS

![alt text](https://raw.githubusercontent.com/GabrielHalvonik/Udajovky_Semestralka_1/master/manual_res/UML.png "UML")

#### List
* ArrayList : dynamic array in contiguous memory
* LinkedList : linear chained list in non-contiguous memory
* DoublyCircularLinkedList : double-chained cyclic list in non-contiguous memory

#### PriorityQueue
* PriorityQueueUnsortedArrayList : priority queue implemented with dynamic array unsorted
* PriorityQueueSortedArrayList : priority queue implemented with dynamic array sorted
* PriorityQueueLinkedList : priority queue implemented with linked list unsorted
* PriorityQueueTwoList : priority queue implemented with 2 lists. Shorter list is implemented with dynamic array as priority queue and longer list is implemented as linked list.
* Heap : priority queue implemented as Leftist Heap

#### Matrix
* MatrixHeap : matrix in non-contiguous memory
* MatrixHeapContinous : matrix in contiguous memory, map function used for indexing.
* MatrixStack : matrix on stack memory (contiguous)

#### BitSet
* BaseSet: base set implemented with array
* BitSet : bitset mapped to base set with bit operation support(conjunction, unification...)
* BitSetLarge: bitset with 10x more element count

### Testing description

The core of testing selected structures are the **TestTime** (Timer) and **TestStructure** classes. Both classes are designed generically to be able to test type-independent structures.

**TestTime**
I tried to design the **TestTime** class as general as possible so that it could test any function with a different number of parameters.
For these needs, I used a relatively new C ++ feature, a template with a variable number of parameters.
For timing, I use std::chrono with high precision in nanoseconds.
The TestTime class is designed to be static, as the application works with it frequently and for the whole duration of the application.

Here is an example of a timer implementation.
![alt text](https://raw.githubusercontent.com/GabrielHalvonik/Udajovky_Semestralka_1/master/manual_res/TestTime.png "User manual")

**TestStructure**
The **TestStructure** class stores and tests individual operations assigned as function pointers.
Based on the specified probability, it further selects from individual pointers to functions, and sends them to **TestTime** (Timer).
![alt text](https://raw.githubusercontent.com/GabrielHalvonik/Udajovky_Semestralka_1/master/manual_res/TestStructure.png "User manual")

For more information and **analysis of results** you can check untranslated version of 
[official documentation](https://github.com/GabrielHalvonik/Udajovky_Semestralka_1/blob/master/manual_res/HalvonikGabrielAUS1.docx)
