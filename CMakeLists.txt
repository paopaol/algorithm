cmake_minimum_required(VERSION 3.3)

project(algorithm-study)

include_directories(include)


# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/thrd/googletest googletest)
include_directories(${CMAKE_SOURCE_DIR}/thrd/googletest/googlemock/include)
include_directories(${CMAKE_SOURCE_DIR}/thrd/googletest/googletest/include)

enable_testing()

add_subdirectory(test)
