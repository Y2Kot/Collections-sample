cmake_minimum_required(VERSION 3.5)

project(CollectionsSample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CollectionsSample main.cpp
    additionaloperations.h
    arrays.h arrays.cpp
    lists.h lists.cpp
    stack.h stack.cpp
    queue.h queue.cpp
    linkedlist.h linkedlist.cpp
  "prints.h" "prints.cpp"   "samplestructs.h")

install(TARGETS CollectionsSample
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
