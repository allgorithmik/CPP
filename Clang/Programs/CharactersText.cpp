#include <iostream>

int main(){

    char char1 {'a'};
    char char2 {'b'};
    char char3 {'c'};
    char char4 {'h'};
    char char5 {'e'};
    char char6 {'l'};
    char char7 {'l'};
    char char8 {'o'};

    char value {65};                                                                                        //If passed an integer / decimal to a char, its ASCII equivalent as per
                                                                                                            //ASCII table will be printed
                                                                            
    std::cout << "the size of char is: " << sizeof(char) << std::endl;
    std::cout << "ASCII table equivalent of " << static_cast<int>(value) << " is: " << value << std::endl;
    std::cout << "Char value converted to actual int: " << static_cast<int>(value) << std::endl;            //If wanted actual ints displayed, use static_cast
    std::cout << char4 + char5 + char6 + char7 + char8 << std::endl;                                        //adds ASCII values instead of actual values

    return 0;
}