#include<iostream>
#include "Function.h"   //including a custom header with custom function prototypes
#include "Mars.h"       //including a custom header with custom function prototypes => .h file different name than .cpp file (translation unit) 

//ODR - ONE DEFINITION RULE: THE SAME FUNCTION IMPLEMENTATION CANNOT APPEAR IN THE GLOBAL NAMESPACE MORE THAN ONCE

//THE LINKER SEARCHES FOR DEFINITIONS IN ALL TRANSLATION UNITS (.cpp) FILES IN THE PROJECT. IT DOESN'T HAVE TO LIVE IN A .cpp FILE THE SAME NAME AS THE HEADER

int main(int argc, char **argv){
    int minimum {min(10, 20)};
    int mars_var {20};
    std::cout << "Max number is: " << max(10, 20) << std::endl;
    std::cout << "Min number is: " << minimum << std::endl;

    //occupy_mars() prototype is in Function.h header file but its defintion is implemented in a file whose name is NOT Function.cpp, but still the linker is able to find
    //the function definition and execute it with correct results => C++ DOES NOT REQUIRE THE FUNCTION DEFINITIONS TO BE IN FILES WHOSE NAME IS SAME AS THE FUNCTION
    //PROTOYPE HEADERS, IT CAN BE ANY IN FILE 
    std::cout << "Will we occupy mars?: " << occupy_mars(mars_var) << std::endl;
    std::cout << std::boolalpha;
    std::cout << "Will we occupy mars?: " << occupy_mars(mars_var) << std::endl;

    return 0;
}