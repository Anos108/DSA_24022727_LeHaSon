cmake_minimum_required(VERSION 4.0)
project(DSA_24022727_LeHaSon)

set(CMAKE_CXX_STANDARD 17)

include_directories(Homework
        week1
        week3
        week4)

add_executable(DSA_24022727_LeHaSon
        Homework/Homework.cpp
        week1/LinkedList.cpp
        week1/List.cpp
        week3/BInaryHeap.cpp
        week3/PriorityQueue.cpp
        week3/sort.cpp
        week4/binarySearchTree.cpp

)
