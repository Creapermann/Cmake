# Copies a file to another location #

cmake_minimum_required(VERSION 3.8)

project(myproj)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(SRC_PATH CACHE STRING "The path of the source file")    # empty by default
set(DEST_PATH ${PROJECT_BINARY_DIR}/copy_dir/test.txt CACHE STRING "The path of the destination file")

if(NOT DEFINED SRC_PATH)
    message(FATAL_ERROR "No source file provided")
endif()

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/copy_dir)

# Check for file existence
file(TOUCH ${SRC_PATH})
file(READ ${SRC_PATH} content)


# if file is not empty
if(content)
    configure_file(${SRC_PATH} ${DEST_PATH} 
        USE_SOURCE_PERMISSIONS)
else()
    file(WRITE ${DEST_PATH} "WARNING: NO CONTENT IN SOURCE FILE")
endif()
