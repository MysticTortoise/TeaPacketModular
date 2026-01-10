cmake_minimum_required(VERSION 3.28)
project(TeaPacket_Extension_STBImageLoader)
include("${TEAPACKET_ROOT}/CMakeCommons/CommonFunctions.CMake")
set(CMAKE_CXX_STANDARD 20)

TP_add_interface_subdirectory(Graphics)
TP_add_interface_subdirectory(Assets)

file(GLOB_RECURSE sources source/*.c*)
add_library(TeaPacket_Extension_STBImageLoader STATIC ${sources})

target_include_directories(TeaPacket_Extension_STBImageLoader PUBLIC include)
target_include_directories(TeaPacket_Extension_STBImageLoader PRIVATE source)
target_link_libraries(TeaPacket_Extension_STBImageLoader 
        TeaPacket_Graphics_Base
        TeaPacket_Assets_Base)

include("${TEAPACKET_ROOT}/CMakeCommons/CommonEnd.CMake")