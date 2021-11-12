cmake_minimum_required(VERSION 3.8)

project(testing VERSION 1.0
                LANGUAGES CXX)
            
include_guard()



function(myfunc)
    
    # Define supported set of keywords
    set(prefix      TEST)
    set(valueless   READY WHAT_NOW)
    set(singlevalue TARGET)
    set(multivalue  SOURCES)
    
    
    # Process passed in arguments
    include(CMakeParseArguments)
    cmake_parse_arguments(${prefix}
        "${valueless}" "${singlevalue}" "${multivalue}"
        ${ARGV}
    )
    
    
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



myfunc(READY test TARGET mytarget SOURCES main.cpp test.hpp test.cpp house.cpp house.hpp)