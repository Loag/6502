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

install(TARGETS emulator6502
    RUNTIME DESTINATION bin
)