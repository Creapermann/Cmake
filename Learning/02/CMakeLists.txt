
cmake_minimum_required(VERSION 3.8)

project(testing VERSION 1.0
                LANGUAGES CXX)
            
include_guard()



function(myfunc)
    
    # Define supported set of keywords
    set(prefix      TEST)
    set(valueless   READY WHAT_NOW)
    set(singlevalue TARGET)
    set(multivalue  SOURCES FILES)


    # Process passed in arguments
    include(CMakeParseArguments)
    cmake_parse_arguments(${prefix}
        "${valueless}" "${singlevalue}" "${multivalue}"
        ${ARGV}
    )

    # EXPLENTATION:
    # The defined keywords are elements of the list they were defined in,
    # e.g. "TEST" is an element of the list "prefix" and the list "multivalue"
    # contains the elements "SOURCES" and "FILES".
    # The function cmake_parse_arguments automatically creates lists of these keywords
    # called like this: ${prefix}_${keyword}, so there is a list for every keyword which
    # contains the arguments the caller passed to these keywords.
    # So the list "multivalue" contains 2 other lists called "TEST_SOURCES" and "TEST_FILES"
    # (TEST_ because the prefix is "TEST"). "TEST_SOURCES" then contains the strings:
    # "main.cpp" "test.hpp" "test.cpp" the list "TEST_FILES" is empty
    
    
    message("Option overview:")
    
    foreach(arg IN LISTS valueless)
        if(${prefix}_${arg})
            message("${arg} is activated!")
        else()
            message("${arg} is deactivated!")
        endif()
    endforeach()

    message("")
    

    if(TEST_READY)
        
        # print all singlevalue
        message("singlevalue:")
        
        foreach(arg IN LISTS singlevalue)
            message(${${prefix}_${arg}})
        endforeach()
        
        message("")
        
        
        # print all multivalue
        message("multivalue:")
        
                
        # Determine all the multivalue arguments
        set(TEMP_MULTIVALUE_COUNT "0")
        foreach(arg IN LISTS multivalue)
            set(TEMP_LIST_LENGTH)
            list(LENGTH "${prefix}_${arg}" TEMP_LIST_LENGTH)
            
            math(EXPR TEMP_MULTIVALUE_COUNT "${TEMP_MULTIVALUE_COUNT}+${TEMP_LIST_LENGTH}")
        
        endforeach()
        
        set(MULTIVALUE_ARGUMENT_COUNT ${TEMP_MULTIVALUE_COUNT})   
        
        # Reduce by one because zero indexed
        math(EXPR MULTIVALUE_ARGUMENT_COUNT "${MULTIVALUE_ARGUMENT_COUNT}-1")
        
        
        set(COUNTER "0")
        foreach(list_arg IN LISTS multivalue)
            foreach(arg IN LISTS "${prefix}_${list_arg}")
                
                # Run for all but the last element of the list
                if(NOT ${COUNTER} EQUAL ${MULTIVALUE_ARGUMENT_COUNT})
                    message(${arg}, )
                else()
                    
                    message(${arg})
                endif()
                
                math(EXPR COUNTER "${COUNTER}+1")
            
            endforeach()
        endforeach()
        
        
        message("")
        
        
        message("Unused arguments:")
        
        foreach(arg IN LISTS "${prefix}_UNPARSED_ARGUMENTS")
            message(${arg})
        endforeach()
        
    else()
        message("Not ready to execute")
        
    endif()
    
    
endfunction()



myfunc(READY test TARGET mytarget SOURCES main.cpp test.hpp test.cpp)
