cmake_minimum_required(VERSION 3.31)
project(TeaPacket_Core_Base)

if(NOT DEFINED TP_DEBUG)
    set(TP_DEBUG 0)
endif()

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE sources source/*.c*)

add_library(${PROJECT_NAME} STATIC ${sources})
target_include_directories(${PROJECT_NAME} include PUBLIC)
target_include_directories(${PROJECT_NAME} source PRIVATE)
include("${CMAKE_CURRENT_LIST_DIR}/CommonEnd.CMake")