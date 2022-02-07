#include<iostream>
#include<iomanip>
#include<bitset>

int main(int argc, char **argv){
    const int COLUMN_WIDTH {20};
    std::cout << "Compound bitwise assignment operators" << std::endl;

    unsigned char sandbox {0b00110100};

    std::cout << "Initial Value: " << std::endl;

    std::cout << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << std::endl;

    //Compound Left Shift
    std::cout << std::setw(COLUMN_WIDTH) << "Compound left shift operator: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << (sandbox <<=2) << std::endl;

    //Compound Right Shift
    std::cout << std::setw(COLUMN_WIDTH) << "Compound right shift operator: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << (sandbox >>=2) << std::endl;

    //Compound OR
    std::cout << std::setw(COLUMN_WIDTH) << "Compound OR operator: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << (sandbox |= 0b00000010) << std::endl;

    //Compound AND
    std::cout << std::setw(COLUMN_WIDTH) << "Compound AND operator: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << (sandbox &= 0b00001100) << std::endl;

    //Compound XOR
    std::cout << std::setw(COLUMN_WIDTH) << "Compound XOR operator: " << std::setw(COLUMN_WIDTH) << std::bitset<8>(sandbox) << (sandbox ^= 0b00000011) << std::endl;

    //compound negation will not work as it needs binary operands

    return 0;
}