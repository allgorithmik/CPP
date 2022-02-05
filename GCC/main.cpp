#include<iostream>
#include<bitset>

int main(int argc, char **argv){
    unsigned short int data {0b11111110};
    unsigned short int value1 {0xff0u};

    std::cout << data << " in decimal: " << std::showbase << std::dec << data << std::endl;
    std::cout << data << " in hexadecimal: " << std::showbase << std::hex << data << std::endl;             //Bit shifting will only work for integral types
    std::cout << data << " in binary: " << std::showbase << std::bitset<16>(data) << data << std::endl;     //std::bitset for binary representation of data

    //Left shift
    value1 = static_cast<unsigned short int>(value1 << 1);                                                  //<< for left shift, >> for right shift
    std::cout << "Value after left shift: " << std::bitset<16>(value1) << value1 << std::endl;              //the number specifies how many places a bit must shift

    //Right shift                                                                                           //GOLDEN RULE FOR BIT SHIFTING
    value1 = static_cast<unsigned short int>(value1 >> 1);                                                  //Shifting left multiplies by 2^n (bit shift number)
    std::cout << "Value after right shift: " << std::bitset<16>(value1) << value1 << std::endl;             //Shifting right divides by 2^n (bit shift number),

    //shifting by 5 positions
    value1 = static_cast<unsigned short int>(value1 >> 5);                                                  //these two rules will break if we start popping 1s
    std::cout << "Value after right shifting 5 positions: " << std::bitset<16>(value1) << value1 << std::endl;

    return 0;
}