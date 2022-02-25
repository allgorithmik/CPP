#include<iostream>

int main(int argc, char **argv){
    double number1 {100.55};
    double &number1_ref {number1};
    number1_ref = 55.99;
    std::cout << "number1 value: " << number1 << std::endl; //can change the value of original variable through its reference variable

    double number2 {55.90};
    const double &number2_ref {number2};
    //number2_ref = 99.99;                                  ERROR => const references will not allow the values to be modified => const applies only reference variable name

    number2 = 55.9;                                         //but ORIGINAL VARIABLE can still be modified if it is NOT const

    const double *const pointer1 {&number2};                //same functionality of const reference variable can be achieved using const pointer to const value
    //*pointer1 = 45;                                       ERROR => const pointer is pointing to const value, hence cannot be modified

    return 0;
}