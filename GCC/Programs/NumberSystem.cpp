#include<iostream>

int main(int argc, char **argv){
    int decimal_number {15};
    int octal_number {017}; 
    int hexadecimal_number {0x0F};
    int binary_number {0b00001111};
    std::cout << "Decimal representation of " << decimal_number << " is: " << decimal_number << std::endl;      //will get decoded to decimal itself
    std::cout << "Octal representation " << decimal_number << " is: " << octal_number << std::endl;             //will get decoded to decimal itself
    std::cout << "Hexadecimal representation " << decimal_number << " is: " << hexadecimal_number  << std::endl;//will get decoded to decimal itself
    std::cout << "Binary representation " << decimal_number << " is: " << binary_number << std::endl;           //will get decoded to decimal itself
    return 0;
}