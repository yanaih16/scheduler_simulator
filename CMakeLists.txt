cmake_minimum_required(VERSION 3.13)
project(scheduler_simulator CXX)

file(GLOB_RECURSE SOURCE_LIST LIST_DIRECTORIES false CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(schedule STATIC ${SOURCE_LIST})

add_executable(main.out ./main.cpp)
target_include_directories(main.out PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(main.out schedule)
