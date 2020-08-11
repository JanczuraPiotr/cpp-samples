cmake_minimum_required(VERSION 3.10)

set(PROJECT  cpp-samples)
project(${PROJECT})

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")
#
#
#set(Boost_DEBUG OFF)
#find_package(Boost)
#if (NOT Boost_FOUND)
#    message(FATAL_ERROR "Could not find boost!")
#endif ()
#

add_subdirectory(konwersje)
add_subdirectory(interface)
