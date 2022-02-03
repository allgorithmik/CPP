#include <iostream>

int main(int argc, char **argv){

    unsigned char unsigned_char {55u};
    short short_var {-32758};
    short int short_int {455};
    signed short signed_short {122};
    signed short int signed_short_int {-456};
    unsigned short int unsigned_short_int {5678U};

    const int int_var {55};
    signed signed_var {65};
    signed int signed_int {75};
    unsigned int unsigned_int {85U};                                    //U or u does not matter

    signed long int signed_long_int {45L};
    unsigned long int unsigned_long_int {555UL};

    long long long_long {885ll};
    long long int long_long_int {999LL};
    signed long long signed_long_long {555LL};
    signed long long int signed_long_long_int {1111ll};

    unsigned int prize_amount {1'50'000u};                              //quotes do not matter to compiler, just for readability

    std::cout << "The prize is won: " << prize_amount << std::endl;

    std::hex;                                                           //Set to print in hexadecimal, default is decimal
    std::dec;                                                           //Set it back to decimal
    std::oct;                                                           //Binary
    


    return 0;
}