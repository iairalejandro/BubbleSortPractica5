cmake_minimum_required(VERSION 3.14)
project(BubbleSortXUnit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Cobertura de código con gcov (-O0 para que las líneas se mapeen bien)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")

# xUnit: GoogleTest, importado vía FetchContent
find_package(GTest QUIET)
if(NOT GTest_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  )
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)
endif()

# Código de implementación (main)
add_library(bubblesorter src/BubbleSorter.cpp)
target_include_directories(bubblesorter PUBLIC src)

# Código de pruebas (test)
enable_testing()
add_executable(bubblesorter_tests test/BubbleSorterTest.cpp)
target_link_libraries(bubblesorter_tests bubblesorter GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(bubblesorter_tests)
