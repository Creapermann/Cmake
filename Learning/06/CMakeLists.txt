# Print the content of a file to the terminal

cmake_minimum_required(VERSION 3.8)

project(myprj)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(SRC_PATH CACHE STRING "The source files's path")

# Check if a path is defined
if(NOT DEFINED SRC_PATH)
    message(FATAL_ERROR "No source defined!")
endif()


file(TOUCH "${SRC_PATH}")

# Get content
file(STRINGS "${SRC_PATH}" content)

# Check if 
list(LENGTH content list_length)

if(${list_length} EQUAL 0)
    message(WARNING "Your source file is empty")
else()
    set(is_not_empty "OFF")
    
    foreach(var IN LISTS content)
        if(NOT ${var} STREQUAL "")
            set(is_not_empty "ON")
        endif()
    endforeach()
endif()


foreach(var IN LISTS content)
    message(NOTICE ${var})
endforeach()