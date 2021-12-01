cmake_minimum_required(VERSION 3.22)

# Language
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)


add_executable(test_exe
                    main.cpp
                    MyLib_Tests.hpp
    )

target_link_libraries(test_exe
                    PRIVATE
                        gtest
                        mylib
    )



# Run the tests upon build time
add_custom_target(run_tests ALL
                    COMMAND
                        test_exe
    )