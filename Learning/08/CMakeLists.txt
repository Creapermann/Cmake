cmake_minimum_required(VERSION 3.20)

project(MyApp VERSION 0.0.1)

enable_testing()


# Language
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS OFF)


# Options
option(MYAPP_TESTS ON)


# Add libraries
add_subdirectory(src/mylib)


# Add Tests
if(MYAPP_TESTS)
    add_subdirectory(libs/googletest)
    add_subdirectory(tests/mylib_tests)
endif()



# Create app
add_executable(app 
                src/app/main.cpp
    )

target_link_libraries(app
                PRIVATE
                        mylib
    )