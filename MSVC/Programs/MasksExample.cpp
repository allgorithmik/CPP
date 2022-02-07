#include<iostream>
#include<iomanip>
#include<bitset>

const unsigned char mask_bit_0 {0b00000001};
const unsigned char mask_bit_1 {0b00000010};
const unsigned char mask_bit_2 {0b00000100};
const unsigned char mask_bit_3 {0b00001000};
const unsigned char mask_bit_4 {0b00010000};
const unsigned char mask_bit_5 {0b00100000};
const unsigned char mask_bit_6 {0b01000000};
const unsigned char mask_bit_7 {0b10000000};

void use_options_v0(unsigned char flags /*bool flag0, bool flag1, bool flag2, bool flag3, bool flag4, bool flag5, bool flag6, bool flag7*/){
    std::cout << "Bit0 is: " << ((flags & mask_bit_0) >> 0) << " do something" << std::endl;
    std::cout << "Bit1 is: " << ((flags & mask_bit_1) >> 1) << " do something" << std::endl;
    std::cout << "Bit2 is: " << ((flags & mask_bit_2) >> 2) << " do something" << std::endl;
    std::cout << "Bit3 is: " << ((flags & mask_bit_3) >> 3) << " do something" << std::endl;
    std::cout << "Bit4 is: " << ((flags & mask_bit_4) >> 4) << " do something" << std::endl;
    std::cout << "Bit5 is: " << ((flags & mask_bit_5) >> 5) << " do something" << std::endl;
    std::cout << "Bit6 is: " << ((flags & mask_bit_6) >> 6) << " do something" << std::endl;
    std::cout << "Bit7 is: " << ((flags & mask_bit_7) >> 7) << " do something" << std::endl;

    /*std::cout << "Flag1 is: " << flag1 << ", do something" << std::endl;
    std::cout << "Flag2 is: " << flag2 << ", do something" << std::endl;
    std::cout << "Flag3 is: " << flag3 << ", do something" << std::endl;
    std::cout << "Flag4 is: " << flag4 << ", do something" << std::endl;
    std::cout << "Flag5 is: " << flag5 << ", do something" << std::endl;
    std::cout << "Flag6 is: " << flag6 << ", do something" << std::endl;
    std::cout << "Flag7 is: " << flag7 << ", do something" << std::endl;*/
}

int main(int argc, char **argv){

    use_options_v0(mask_bit_2 | mask_bit_3 | mask_bit_4 | mask_bit_6);

    return 0;
}