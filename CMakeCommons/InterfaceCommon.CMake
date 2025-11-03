if(NOT DEFINED TP_DEBUG)
    set(TP_DEBUG 0)
endif()

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
include("${CMAKE_CURRENT_LIST_DIR}/CommonEnd.CMake")