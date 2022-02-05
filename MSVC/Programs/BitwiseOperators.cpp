#include<iostream>
#include<bitset>

int main(int argc, char **argv){
    unsigned short int data {0b11111110};

    std::cout << data << " in decimal: " << std::showbase << std::dec << data << std::endl;
    std::cout << data << " in hexadecimal: " << std::showbase << std::hex << data << std::endl;
    std::cout << data << " in binary: " << std::showbase << std::bitset<16>(data) << data << std::endl;                 //std::bitset for binary representation of data

    return 0;
}