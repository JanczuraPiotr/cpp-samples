project(future-promise)

add_executable(${PROJECT_NAME}
        main.cpp
        ../../Logger.cpp
        )
target_compile_definitions(${PROJECT_NAME} PRIVATE EXAMPLE_NAME="${PROJECT_NAME}")
