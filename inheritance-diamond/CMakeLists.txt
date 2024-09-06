project(inheritance-diamound)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Werror -Wconversion -pedantic-errors -Weffc++ -MMD -MP -MF")
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp
        ../Logger.cpp
        )
