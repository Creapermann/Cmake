cmake_minimum_required(VERSION 3.22)

# Language
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)



# Add the tests
add_executable(mylib_test 
                    main.cpp)
                
target_link_libraries(mylib_test
                    PRIVATE
                        gtest
                        mylib)


# Run the tests upon build time
add_custom_target(run_tests ALL
                    COMMAND
                        mylib_test
    )