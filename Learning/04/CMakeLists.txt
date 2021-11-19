cmake_minimum_required(VERSION 3.8)

project(mytest)


function(myfunc placeholder1 placeholder2)
    
    set(prefix "MYFUNC")
    set(noval "ENABLE" "PRINT_EXTRA")
    set(singleval "TARGET")
    set(multival "OPTIONS" "CONFIGS")
    
    cmake_parse_arguments(${prefix}
        "${noval}" "${singleval}" "${multival}"
        ${ARGV}
    )

    if(${prefix}_ENABLE)
        
        message(NOTICE "Setting options: ")
        
        foreach(list ${multival})
            foreach(var ${${prefix}_${list}})
                message(NOTICE "- ${var}")
            endforeach()
        endforeach()
        
        message(NOTICE "For the TARGET: ")
        
        foreach(list ${singleval})
            foreach(var ${${prefix}_${list}})
                message(NOTICE ${var})
            endforeach()
        endforeach()
        
    else()
        message(NOTICE "Not enabled!")
    
    endif()
    
    message("")
    
    if(${prefix}_PRINT_EXTRA)
        message(VERBOSE "Extra info")
    endif()
    
    message("")
        
endfunction()

myfunc(ENABLE PRINT_EXTRA TARGET myapp OPTIONS "ENABLE_ALL_OPTIMISATIONS" "NO_DEBUG_FILES")

#add_executable(app src/main.cpp)