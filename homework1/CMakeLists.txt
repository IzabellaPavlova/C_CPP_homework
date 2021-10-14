cmake_minimum_required(VERSION 3.16)
project(homework1)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SOURCE_FILES films.c)

set(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_library(films STATIC ${LIB_SOURCE_FILES})

add_executable(main main.c)
target_link_libraries(main films)

option(BUILD_TESTS ON)
if (BUILD_TESTS)
    enable_testing()

    include(GoogleTest)
    add_executable(films_test films_test.cpp)

    target_link_libraries(films_test gtest_main company)
    gtest_add_tests(TARGET films_test)
endif()
