cmake_minimum_required(VERSION 3.8)

project(Testing VERSION 1.0
                LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Build type detection
if(NOT GENERATOR_IS_MULTI_CONFIG)
    set(BUILD_TYPE)
    string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
    
    if("${BUILD_TYPE}" STREQUAL "DEBUG")
        message(NOTICE "You are building in debug mode")
        # Do work...
    elseif("${BUILD_TYPE}" STREQUAL "RELEASE")
        message(NOTICE "You are building in release mode")
        # Do work...
    else()
        message(NOTICE "You are building in another mode than debug or release")
        # Do work...
    endif()
else()
    message(NOTICE "Your generator is multi-config")
endif()