cmake_minimum_required(VERSION 3.23)
project(2courses_work)

set(CMAKE_CXX_STANDARD 14)

add_executable(2courses_work main.cpp 2course_work_1_lib.cpp 2course_work_lib_branch_and_bound.cpp 2course_work_1_lib.hpp)
