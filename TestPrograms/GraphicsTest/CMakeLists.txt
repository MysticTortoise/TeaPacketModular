cmake_minimum_required(VERSION 3.31)
project(TeaPacket_TestPrograms_Graphics)
include("${TEAPACKET_ROOT}/CMakeCommons/CommonFunctions.CMake")

TP_add_impl_subdirectory(Graphics Direct3D11)
TP_add_impl_subdirectory(System Windows)
TP_add_impl_subdirectory(Assets STDFile)

add_executable(TeaPacket_TestPrograms_Graphics main.cpp)
target_link_libraries(TeaPacket_TestPrograms_Graphics PUBLIC
        TeaPacket_Graphics_Direct3D11
        TeaPacket_System_Windows
        TeaPacket_Assets_STDFile)
set_target_properties(TeaPacket_TestPrograms_Graphics PROPERTIES CXX_STANDARD 20)