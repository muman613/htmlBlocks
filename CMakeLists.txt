cmake_minimum_required(VERSION 3.15)
project(htmlBlocks)

set(CMAKE_CXX_STANDARD 14)

include_directories(htmlBlocks)

add_executable(htmlBlocks
        htmlBlocks/htmlblock_types.h
        htmlBlocks/htmlblockbase.cpp
        htmlBlocks/htmlblockbase.h
        htmlBlocks/htmlblockfactory.cpp
        htmlBlocks/htmlblockfactory.h
        test/main.cpp)

add_definitions(-DUSE_STL)
