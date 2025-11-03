cmake_minimum_required(VERSION 3.31)
project(TeaPacket_TextureUtils)
set(CMAKE_CXX_STANDARD 20)

include("${TEAPACKET_ROOT}/CMakeCommons/CommonFunctions.CMake")

file(GLOB_RECURSE sources source/*.c*)

TP_add_interface_subdirectory(Math)
TP_add_interface_subdirectory(Graphics)
TP_add_interface_subdirectory(Types)

add_library(TeaPacket_TextureUtils STATIC ${sources})
target_link_libraries(TeaPacket_TextureUtils TeaPacket_Math_Base TeaPacket_Graphics_Base TeaPacket_Types_Base)
target_include_directories(TeaPacket_TextureUtils PRIVATE source)
target_include_directories(TeaPacket_TextureUtils PUBLIC include)

include("${TEAPACKET_ROOT}/CMakeCommons/CommonEnd.CMake")