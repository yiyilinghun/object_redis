cmake_minimum_required(VERSION 3.0.0)
message(STATUS "限定cmake版本(3.0.0)")

project(redis_test VERSION 0.0.1)
message(STATUS "项目[redis_test](0.0.1)")

aux_source_directory(. base_dir_srcs)
aux_source_directory(./redis base_dir_srcs)

add_executable(redis_test.out ${base_dir_srcs})
message(STATUS "输出文件(redis_test.out)")

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-pthread ${CMAKE_CXX_FLAGS}")
    message(STATUS "增加线程库引用")   

    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
    message(STATUS "c++版本11")   

    set(CMAKE_CXX_FLAGS "-g ${CMAKE_CXX_FLAGS}")
    message(STATUS "具有调试信息")

    set(CMAKE_CXX_FLAGS "-O2 ${CMAKE_CXX_FLAGS}")
    message(STATUS "具有一级优化(O2)")
    
endif(CMAKE_COMPILER_IS_GNUCXX)

message(STATUS "cmake完成")
