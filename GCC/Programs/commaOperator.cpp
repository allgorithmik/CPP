#include<iostream>

int increment {5};
int number1 {10};
int number2 {20};
int number3 {30}; 

int main(int argc, char **argv){                                                            //WHATS THE USE OF COMMA OPERATOR IF RIGHT MOST OPERAND WILL BE THE RESULT?????

    int result = (number1 *= ++increment, number2 - (++increment), number3 += ++increment); //comma operator allows multiple expressions to be combined into one
    std::cout << "Number1: " << number1 << std::endl;                                       //comma operator is left to right associative
    std::cout << "Number2: " << number2 << std::endl;                                       //so the right most operand will be the result of the whole
    std::cout << "Number3: " << number3 << std::endl;                                       //expression

    std::cout << "Result: " << result << std::endl;

    return 0;
}