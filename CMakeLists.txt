cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(PlantsVsZombies)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY
            "${CLANG_TIDY_EXE}"
            "--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy"
            "--extra-arg=-std=c++17"
    )
else()
    message(FATAL_ERROR "You need to install clang-tidy")
endif()

set(TARGET run)

file(GLOB_RECURSE SOURCE "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp")

add_executable(${TARGET} ${SOURCE} ${HEADERS})

include_directories(src)

find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network)
target_link_libraries(${TARGET} PRIVATE SFML::Graphics SFML::Audio SFML::Network)

add_compile_options(-fsanitize=address,alignment,undefined)
add_link_options(-fsanitize=address,alignment,undefined)