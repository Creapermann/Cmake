#include <iostream>


int main(int argc, char* argv[])
{
    std::cout << "Worked, " << argc << " arguments passed in: \n";
    
    for(int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << "\n";
    }
}