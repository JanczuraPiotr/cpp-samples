project(interface)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")

add_executable(interface
        main.cpp

        Class.cpp       Class.hpp
        Interface.cpp   Interface.hpp
        Object.cpp      Object.hpp

        )

#target_link_libraries(interface)