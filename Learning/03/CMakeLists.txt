cmake_minimum_required(VERSION 3.8)

project(Testing VERSION 1.0
                LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Build type detection
if(NOT GENERATOR_IS_MULTI_CONFIG)
    
    # If CMAKE_BUILD_TYPE cache variable was set on command line
    if(CMAKE_BUILD_TYPE)
        
        # Get build type and convert to upper
        set(BUILD_TYPE)
        string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
        
        
        if("${BUILD_TYPE}" STREQUAL "DEBUG")
            message(STATUS "You are building in debug mode")
            # Do work...
        elseif("${BUILD_TYPE}" STREQUAL "RELEASE")
            message(STATUS "You are building in release mode")
            # Do work...
        else()
            message(STATUS "You are building in another mode than debug or release")
            # Do work...
        endif()
    
    # If CMAKE_BUILD_TYPE cache variable was not set on command line
    else()
        set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "" FORCE)
        
        # Check if CMAKE_BUILD_TYPE cache variable was set correctly
        if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
            message(STATUS "You are now automatically building in debug mode")
        else()
            message(FATAL_ERROR "CMAKE_BUILD_TYPE could not be set!")
        endif()
        
    endif()
    
else()
    message(NOTICE "Your generator is multi-config")
endif()