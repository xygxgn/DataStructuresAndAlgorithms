cmake_minimum_required(VERSION 3.0.2)
project(data_structure)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
  ${CMAKE_CURRENT_LIST_DIR}/Graphs
)
add_executable(Dijkstra 
  ${CMAKE_CURRENT_LIST_DIR}/Graphs/Dijkstra.cpp
)
add_executable(Floyd 
  ${CMAKE_CURRENT_LIST_DIR}/Graphs/Floyd.cpp
)
add_executable(GraphSearch 
  ${CMAKE_CURRENT_LIST_DIR}/Graphs/GraphSearch.cpp
)
add_executable(Kruskal 
  ${CMAKE_CURRENT_LIST_DIR}/Graphs/Kruskal.cpp
)
add_executable(Prim 
  ${CMAKE_CURRENT_LIST_DIR}/Graphs/Prim.cpp
)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/SortingAlgorithms)
add_executable(BubbleSort 
  ${CMAKE_CURRENT_LIST_DIR}/SortingAlgorithms/BubbleSort.cpp
)
add_executable(HeapSort 
  ${CMAKE_CURRENT_LIST_DIR}/SortingAlgorithms/HeapSort.cpp
)
add_executable(InsertSort 
  ${CMAKE_CURRENT_LIST_DIR}/SortingAlgorithms/InsertSort.cpp
)
add_executable(QuickSort 
  ${CMAKE_CURRENT_LIST_DIR}/SortingAlgorithms/QuickSort.cpp
)
add_executable(SelectSort 
  ${CMAKE_CURRENT_LIST_DIR}/SortingAlgorithms/SelectSort.cpp
)
add_executable(ShellShort 
  ${CMAKE_CURRENT_LIST_DIR}/SortingAlgorithms/ShellShort.cpp
)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/Trees)
add_executable(BinarySearchTree 
  ${CMAKE_CURRENT_LIST_DIR}/Trees/BinarySearchTree.cpp
)
add_executable(Heap 
  ${CMAKE_CURRENT_LIST_DIR}/Trees/Heap.cpp
)
add_executable(PostInBuildTree 
  ${CMAKE_CURRENT_LIST_DIR}/Trees/PostInBuildTree.cpp
)
add_executable(PreInBuildTree 
  ${CMAKE_CURRENT_LIST_DIR}/Trees/PreInBuildTree.cpp
)
add_executable(TreeTraverse 
  ${CMAKE_CURRENT_LIST_DIR}/Trees/TreeTraverse.cpp
)

# build for Windows
# cd build && cmake -G "MinGW Makefiles" ..
# make for Windows
# mingw32-make.exe

# build for Linux
# cd build && cmake ..
# make for Linux
# make