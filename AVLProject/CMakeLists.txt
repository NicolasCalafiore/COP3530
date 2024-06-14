cmake_minimum_required(VERSION 3.27)
project(AVLProject)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(AVLProject
        src/AVLTree.h
        src/main.cpp
        src/TreeNode.h)
