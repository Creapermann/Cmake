#include <iostream>

#include "mylib_export.h"


class MyTest
{
public:
    MYLIB_EXPORT MyTest() = default;
    
    MYLIB_EXPORT int times_two(int x);
    MYLIB_EXPORT int minus_one(int x);
    MYLIB_EXPORT int plus_four(int x);
};