#include <iostream>

int main(){
    int number1 {100};

    number1 += 1;
    std::cout << "Compound assignment for addition: " << number1 << std::endl;           //compound operator is not accepted as expression in cout statement???

    number1 -= 1;
    std::cout << "Compound assignment for subtraction: " << number1 << std::endl;

    number1 *= 2;
    std::cout << "Compound assignment for multiplication: " << number1 << std::endl;

    number1 /= 10;
    std::cout << "Compound assignment for division: " << number1 << std::endl;

    number1 %= 1;
    std::cout << "Compound assignment for modulus: " << number1 << std::endl;

    return 0;
}