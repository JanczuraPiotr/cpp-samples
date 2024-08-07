project("boost-path")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")

add_executable("boost-path"
        main.cpp
        )
target_link_libraries("boost-path"
        boost_filesystem
        )