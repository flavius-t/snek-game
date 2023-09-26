cmake_minimum_required(VERSION 3.22)

project(SnekGame)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(testEntity tests/testEntity.cpp Entity.cpp)

target_link_libraries(testEntity ${GTEST_LIBRARIES} pthread)