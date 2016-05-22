cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("LIP")

#enable_testing()

set(MY_CXX_FLAGS "-Wall -Wc++11-extensions -std=c++11")
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_CXX_FLAGS}")


file(GLOB_RECURSE LIP_SOURCES "lip_*.cpp")
file(GLOB_RECURSE LIP_HEADERS "lip_*.h")

set (LIP_INCLUDE_DIRS "")
foreach (_headerFile ${LIP_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND LIP_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES LIP_INCLUDE_DIRS)

include_directories(${LIP_INCLUDE_DIRS})
add_executable (a.out ${LIP_SOURCES} "driver/driver.cpp")

#add_test(todo_test todo.tsk)
