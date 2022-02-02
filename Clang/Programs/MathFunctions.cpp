#include <iostream>
#include <cmath>                                                                                //If we include any headerfile, they will get added to std namespace

int main(){
    int value1 {10};
    float value2 {95.55};

    std::cout << "Absolute value of " << value1 << " is: " << std::abs(value1) << std::endl;
    std::cout << "Sine of " << value2 << " is: " << std::sin(value2) << std::endl;
    std::cout << "Cosine of " << value1 << " is: " << std::cos(value1) << std::endl;
    std::cout << "Tan of " << value2 << " is: " << std::tan(value2) << std::endl;

    std::cout << "sqrt of " << value1 << " is: " << std::sqrt(value1) << std::endl;
    std::cout << "Log of " << value2 << " is: " << std::log(value2) << std::endl;
    std::cout << "Ceil of " << value1 << " is: " << std::ceil(value1) << std::endl;
    std::cout << "Floor of " << value2 << " is: " << std::floor(value2) << std::endl;

    //EXPONENTIAL -> e = 2.71828
    std::cout << "Exponential of " << value1 << " is: " << std::exp(value1) << std::endl;

    //Power -> std::pow(x, y) -> x to the power of y -> x ^ y
    std::cout << "Power of " << value1 << " and " << value2 << " is: " << std::pow(value1, value2) << std::endl;
    
    return 0;
}