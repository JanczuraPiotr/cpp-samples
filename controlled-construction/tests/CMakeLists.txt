project(gtest-controlled-construction)

add_executable(${PROJECT_NAME} gtest.cpp ControlledConstructionGTest.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES})