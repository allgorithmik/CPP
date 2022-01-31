#include <iostream>

int main(){
    int number1 {10};
    int number2 {20};

    std::cout << "number1 < number1: " << (number1 < number2) << std::endl;
    std::cout << "number1 <= number1: " << (number1 <= number2) << std::endl;
    std::cout << "number1 > number1: " << (number1 > number2) << std::endl;
    std::cout << "number1 >= number1: " << (number1 >= number2) << std::endl;
    std::cout << "number1 == number1: " << (number1 == number2) << std::endl;
    std::cout << "number1 != number1: " << (number1 != number2) << std::endl;

    std::cout << "Making Bool True/False" << std::endl;
    std::cout << std::boolalpha;                                                //use std::boolalpha to convert 1/0 -> True/False

    std::cout << "number1 < number1: " << (number1 < number2) << std::endl;
    std::cout << "number1 <= number1: " << (number1 <= number2) << std::endl;
    std::cout << "number1 > number1: " << (number1 > number2) << std::endl;
    std::cout << "number1 >= number1: " << (number1 >= number2) << std::endl;
    std::cout << "number1 == number1: " << (number1 == number2) << std::endl;
    std::cout << "number1 != number1: " << (number1 != number2) << std::endl;
    return 0;
}