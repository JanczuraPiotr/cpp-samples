project(first_directory_lib)

message(${PROJECT_NAME})
message(${CMAKE_CURRENT_LIST_FILE})

add_library(first_directory_lib
        SHARED
        ./DuplicateName.cpp
        ./Wrapper.cpp
        )

#target_include_directories(first_directory_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#target_include_directories(${PROJECT_NAME} PRIVATE .)
