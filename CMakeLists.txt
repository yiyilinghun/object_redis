cmake_minimum_required(VERSION 3.0.0)
project(redis_test VERSION 0.0.1)

aux_source_directory(. base_dir_srcs)

add_executable(redis_test.out ${base_dir_srcs})

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
    message(STATUS "c++版本11")   
    set(CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}")
    message(STATUS "具有调试信息")   
endif(CMAKE_COMPILER_IS_GNUCXX)

