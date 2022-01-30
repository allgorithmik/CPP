#include <iostream>

int main(int args, char **argv){
    int preincrment {1};
    int postincrement {5};

    int predecrement {1};
    int postdecrement {5};

    std::cout << "Pre incrementing value by 1: " << ++preincrment << std::endl;                      //prefix increment by 1
    std::cout << "Post incrementing value by 1: " << postincrement++ << std::endl;                   //postfix increment by 1
    std::cout << "Post increment value will be reflecting now: " << postincrement << std::endl;      //postfix value will be reflecting only after second call

    std::cout << "Pre decrementing value by 1: " << --predecrement << std::endl;                     //prefix decrement by 1
    std::cout << "Post decrementing value by 1: " << postdecrement-- << std::endl;                   //postfix decrement by 1
    std::cout << "Post decrement value will be reflecting now: " << postdecrement << std::endl;      //postfix value will be reflecting only after second call
                                                                                            
    return 0;
}