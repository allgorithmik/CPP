#include <iostream>

int main(){
    int number1 {100};

    number1 += 1;                                                                       //compound operator is not accepted as expression in cout statement???
    std::cout << "Compound assignment for addition: " << number1 << std::endl;          //->PUT THE EXPRESSION IN ()         

    number1 -= 1;                                                                       //The REAL CONCEPT name is COMPOUND ASSIGNMENT OPERATOR, which means it preforms the
    std::cout << "Compound assignment for subtraction: " << number1 << std::endl;       //operation and then ASSIGNS the new value to the variables.

    number1 *= 2;
    std::cout << "Compound assignment for multiplication: " << number1 << std::endl;

    number1 /= 10;
    std::cout << "Compound assignment for division: " << number1 << std::endl;

    number1 %= 1;
    std::cout << "Compound assignment for modulus: " << number1 << std::endl;

    return 0;
}