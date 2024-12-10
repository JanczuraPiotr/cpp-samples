project(controlled-construction)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(controlled-construction
        main.cpp
        ../Logger.cpp
)

add_subdirectory(tests)