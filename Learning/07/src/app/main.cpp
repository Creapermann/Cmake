#include <iostream>

#include "selfMath.hpp"


int main()
{
    std::cout << "Starting...\n";
    
    SelfMath sm;
    std::cout << sm.times_two(2) << "\n";
    
    hellos();
    
    return 0;
}