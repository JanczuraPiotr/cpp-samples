project(duplicate_name)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")

add_subdirectory(first_directory)
add_subdirectory(second_directory)

add_executable(duplicate_name
        main.cpp
        ../Logger.cpp
        )


target_link_libraries(duplicate_name PRIVATE first_directory_lib second_directory_lib)

