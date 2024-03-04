cmake_minimum_required(VERSION 3.27)
project(Learning C)

set(CMAKE_C_STANDARD 11)

add_subdirectory("${PROJECT_SOURCE_DIR}/SquaresOfSortedArray" "${PROJECT_SOURCE_DIR}/SquaresOfSortedArray/Output")
add_subdirectory("${PROJECT_SOURCE_DIR}/TwoSums" "${PROJECT_SOURCE_DIR}/TwoSums/Output")
add_subdirectory("${PROJECT_SOURCE_DIR}/AddTwoNumbers" "${PROJECT_SOURCE_DIR}/AddTwoNumbers/Output")
