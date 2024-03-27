cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(banking)

option(BUILD_TESTS "Build tests" OFF)

if (BUILD_TESTS)
	include(third-party/coveralls/cmake/Coveralls.cmake)
	coveralls_turn_on_coverage()
endif()

include_directories(lib source)
add_library(banking STATIC lib/banking.h lib/banking.cpp)
add_executable(example source/example.cpp)
target_link_libraries(example banking)

if(BUILD_TESTS)
    coveralls_setup(
        "${LIB_SRC}" 
        ${COVERALLS_UPLOAD}                 
        "${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake")
    enable_testing()
    add_subdirectory(third-party/gtest)
    file(GLOB banking_tests "tests/*.cpp")
    foreach(test ${banking_tests})
         add_executable(check ${test})
         target_link_libraries(check gtest_main gmock_main banking)
         add_test(NAME check COMMAND check)
    endforeach(test ${banking_tests})
endif()
