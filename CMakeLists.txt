cmake_minimum_required(VERSION 3.13)
project(scheduler_simulator CXX)

file(GLOB_RECURSE SOURCE_LIST LIST_DIRECTORIES false CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(schedule STATIC ${SOURCE_LIST})

add_executable(schefuler_simulator ${PROJECT_SOURCE_DIR}/main.cpp)
target_include_directories(schefuler_simulator PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(schefuler_simulator schedule)
