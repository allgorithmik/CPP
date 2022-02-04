#include<iostream>

int main(int argc, char **argv){
    //Underflow -> when a variable tries to hold a value less than its type
    //Overflow -> when a variable tries to hold a value more than its type

    unsigned char char_var1 {135};
    unsigned char char_var2 {155};
    unsigned char sum {char_var1 + char_var2};                  //Narrowing conversion compile time warnings! - Overflow

    //unsigned char char_var3 {-1};
    unsigned char char_var3 {0};

    std::cout << static_cast<int>(sum) << std::endl;            //Undefined value as output - Overflow

    //std::cout << char_var3 << std::endl;                      //Underflow - Compiler error

    --char_var3;
    std::cout << static_cast<int>(char_var3) << std::endl;      //Underflow - 255 clearly started from reverse - undefined value

    return 0;
}