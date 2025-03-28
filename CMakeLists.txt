cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 20)
set(EXPORT_COMPILE_COMMANDS ON)

project(PlantsVsZombies)

set(TARGET run)

file(GLOB_RECURSE SOURCE "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp")

add_executable(${TARGET} ${SOURCE} ${HEADERS})

include_directories(src)
target_link_libraries(${TARGET} PRIVATE sfml-graphics sfml-window sfml-system)
