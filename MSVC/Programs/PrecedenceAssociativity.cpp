#include <iostream>

int main(){

    //Multiplication and Division First -> Left to Right
    //Addition and Substraction Second -> Left to Right
    //https://en.cppreference.com/w/cpp/language/operator_precedence

    int a {6};
    int b {3};
    int c {8};
    int d {9};
    int e {3};
    int f {2};
    int g {5};

    int result {a + b * c - d / e - f + g};
    std::cout << result << std::endl;

    result = a / b * c + d - e + f;             //result var is overwritten, cannot use brased initilization again
    std::cout << result << std::endl;

    result = a + (b * c) - (d / e) - f + g;     //parenthesis is NOT just a convention, operator precedence works even without (),
                                                //() HAS AN effect on operator precedence and operator precedence is the default, else () rules will be followed
    std::cout << result << std::endl;

    return 0;
}