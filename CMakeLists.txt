cmake_minimum_required(VERSION 3.9)
project(BoostProcessTests)

set(CMAKE_CXX_STANDARD 14)

add_executable(BoostProcessTests main.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(BoostProcessTests ${CMAKE_THREAD_LIBS_INIT})

find_package(Boost 1.64.0 COMPONENTS system coroutine REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(BoostProcessTests ${Boost_LIBRARIES})
