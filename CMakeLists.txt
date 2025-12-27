cmake_minimum_required(VERSION 4.0)
project(ex_curs)

set(CMAKE_CXX_STANDARD 20)


add_executable(ex_curs main.cpp
        cap1/union_find.cpp
        cap1/union_find.h
        cap1/union_find_max.cpp
        cap1/union_find_max.h
        cap1/ex4.cpp
        cap1/ex4.h
        cap1/ex6.cpp
        cap1/ex6.h
        cap1/ex7.cpp
        cap1/ex7.h
        cap1/test_mem.cpp
        cap1/test_mem.h
        cap2/simpleLinkedList.cpp
        cap2/simpleLinkedList.h
        cap2/linkedListInsert.cpp
        cap2/linkedListInsert.h
        cap2/doubleLinkedList.cpp
        cap2/doubleLinkedList.h
        cap2/list.cpp
        cap2/list.h
        cap2/circularList.cpp
        cap2/circularList.h
        cap2/ex_c1.cpp
        cap2/ex_c1.h
        cap2/ex_c2.cpp
        cap2/ex_c2.h
        cap2/ex_c3.cpp
        cap2/ex_c3.h
        cap3/linearSearch.cpp
        cap3/linearSearch.h
        cap3/binarySearch.cpp
        cap3/binarySearch.h
        cap3/sqrtBinarySearch.cpp
        cap3/sqrtBinarySearch.h
        cap3/insertionSort.cpp
        cap3/insertionSort.h
        cap3/selectionSort.cpp
        cap3/selectionSort.h
        cap3/mergeSort.cpp
        cap3/mergeSort.h
)
