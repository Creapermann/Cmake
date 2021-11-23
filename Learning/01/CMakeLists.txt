# Learning about functions and variable types #

cmake_minimum_required(VERSION 3.8)

project(mytest VERSION 1.0
               LANGUAGES CXX)

include_guard()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


function(print_reversed)

    if(${EVERYTHING_FINE})

        # Reverse and print
        list(REVERSE ARGN)
        foreach(item IN ITEMS ${ARGN})

            message(${item})
            
        endforeach()
    
    else()
        
        message("Doing nothing")
        
    endif()
        
endfunction()


set(MY_STR "Hello" CACHE STRING "Just a test")
set(SECOND)
set(THIRD)

# Condition to run the priting
option(EVERYTHING_FINE "OFF")


# Setting variables
add_subdirectory(mysub)


print_reversed(${MY_STR} ${SECOND} ${THIRD})
