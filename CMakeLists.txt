cmake_minimum_required(VERSION 3.19)
project(cpp_design_pattern)

set(CMAKE_CXX_STANDARD 14)

include_directories(abstract-factory)
include_directories(builder)

add_executable(abstract-factory
        abstract-factory/abstract_factory.cpp
        abstract-factory/abstract_factory.h)

add_executable(builder
        builder/builder.cpp
        builder/builder.h)
