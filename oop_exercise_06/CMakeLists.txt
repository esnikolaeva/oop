cmake_minimum_required(VERSION 3.5)

project(oop_exercise_06)


add_executable(map_test map_test.cpp)
set_target_properties(map_test PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

add_executable(oop_exercise_06 main.cpp)
set_target_properties(oop_exercise_06 PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")