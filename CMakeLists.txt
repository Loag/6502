cmake_minimum_required(VERSION 3.25)

project(
    emulator6502
    VERSION 0.1.0
    DESCRIPTION "6502 emulator"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)

add_library(emulator_core STATIC
    src/placeholder.cpp
)

target_include_directories(emulator_core
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(emulator_core PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

add_executable(emulator6502
    cli/main.cpp
)

target_link_libraries(emulator6502
    PRIVATE emulator_core
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(emulator6502 PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

add_executable(emulator_core_tests
    tests/placeholder_test.cpp
)

target_link_libraries(emulator_core_tests
    PRIVATE
        emulator_core
        GTest::gtest_main
)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(emulator_core_tests PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

include(GoogleTest)
gtest_discover_tests(emulator_core_tests)

install(TARGETS emulator6502
    RUNTIME DESTINATION bin
)