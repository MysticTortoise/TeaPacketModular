set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.8.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

file(GLOB_RECURSE sources source/*.c*)
add_executable(${PROJECT_NAME} ${sources})
message(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)