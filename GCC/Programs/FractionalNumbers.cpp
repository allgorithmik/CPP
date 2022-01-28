#include<iostream>
#include<iomanip>

int main(int argc, char **argv){

    //double number4 {5.5};
    //double number5 {};
    //double number6 {};

    //value of pi upto 100 decimal points
    float number1 {3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067f};         //must be prefixed with f for floating      
    double number2 {3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067};         //DEFAULT IS DOUBLE SO NO PREFIX
    long double number3 {3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067L};   //must be prefixed with L for long double

    long double number3 (3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067f);
    long double number3 (3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067);
    long double number3 (3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067L);

    std::cout << std::setprecision(100);                                                                                            //setprecision from std
    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(long double) << std::endl;
    //std::cout << number1 << " / " << number2 << " evaluates to " << number1 / number2 << std::endl;                               //infinity
    //std::cout << number2 << " / " << number3 << " evaluates to " << number2 / number3 << std::endl;                               //NaN not a number
    std::cout << "Floating Point: " << number1 << std::endl;
    std::cout << "Double: " << number2 << std::endl;
    std::cout << "Long Double: " << number3 << std::endl;

    return 0;
}