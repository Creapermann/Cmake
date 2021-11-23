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

# Check if the source file is empty
list(LENGTH content list_length)

if(${list_length} EQUAL 0)           # no content at all
    message(WARNING "Your source file is empty")
else()                               # just whitespaces
    set(is_empty "TRUE")
    
    foreach(var IN LISTS content)
        if(NOT ${var} STREQUAL "")
            set(is_empty "FALSE")
        endif()
    endforeach()
    
    if(${is_empty})
        message(WARNING "Your source file is empty")
    endif()
endif()


foreach(var IN LISTS content)
    message(NOTICE ${var})
endforeach()