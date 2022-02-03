#include <iostream>

int main(int argc, char** argv){

    const float pi {3.142f};                                //prefix with f for float, else default will be double
    //pi++;                                                 //compiler error as pi is const
    std::cout << "value of pi is: " << pi << std::endl;
    float pi = 3.142;                                       //compiler error, conflicting declaration
    std::cout << "value of pi is: " << pi << std::endl;
    return 0;
}