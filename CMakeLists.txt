cmake_minimum_required(VERSION 3.10)

set(PROJECT  cpp-samples)
project(${PROJECT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")
set(CMAKE_CXX_STANDARD 20)

set(Boost_DEBUG OFF)
find_package(Boost)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif ()

add_subdirectory(const-in-share_ptr)
add_subdirectory(controlled-construction)
add_subdirectory(decltype)
add_subdirectory(inheritance)
add_subdirectory(inheritance-and-static)
add_subdirectory(inheritance-diamond)
add_subdirectory(interface)
add_subdirectory(move)
add_subdirectory(unique_ptr)
add_subdirectory(weak_ptr)

#add_subdirectory(reference)
#add_subdirectory(type-matching)
#add_subdirectory(variable_in_memory)
#add_subdirectory(xxx_ptr_in_containers)
#add_subdirectory(zasiegi_dziedziczenia)
