#include<iostream>

int main(int argc, char **argv){
    char *char_pointer {nullptr};
    char value {'A'};
    char_pointer = &value;

    std::cout << "Address of value: " << &value <<std::endl;        //garbage value ?????
    std::cout << "Dereferencing: " << *char_pointer << std::endl;

    //COMPILE TIME ERROR => ADD CONST TO FIX ERROR
    const char *char_string {"This is a string literal"};           //if a string literal (C-String) is initialized to a char pointer, the string literal will be converted
    const char *char_literal {"Hello Pointers"};                    //to char array, and the pointer will point to the first letter of the char array
    //WHEN THE STRING LITERAL ARRAY GETS CONVERTED TO A CHAR ARRAY, IT WILL BE CONVERTED TO AN ARRAY OF CONST CHAR, BUT THE POINTER IS NOT A CONST, HENCE POINTER CAN BE USED
    //TO MODIFY THE VALUES OF THE ARRAY => AS A RESULT, SOME COMPILERS WILL REFUSE TO COMPILE THIS STATEMENT => COMPILE TIME ERROR AS EXPECTED

    std::cout << "char_string: " << char_string << std::endl;       //=> prints the content of the char array

    //DEREFERENCING
    std::cout << "dereferening: " << *char_literal << std::endl;    //IF WE DEREFERENCE A CHAR ARRAY WITH STRING LITERAL, ONLY THE FIRST LETTER WILL BE RETURNED => H

    //char_literal[0] = 'A';                                        //THIS IS ILLEGAL IN C++ AS WE ARE MODIFYING A CONST CHAR ARRAY

    //IF WE NEED TO MODIFY THE ARRAY => POSSIBLE
    char string[] {"Modifiable"};                                   //use normal char arrays, instead of pointer char array
    string[0] = 'B';
    
    return 0;
}