#include<iostream>

int main(int argc, char **argv){
    
    unsigned long long int number {19'445'755'075'709'551ull};  //a really really long data type declaration

    //using type aliases to overcome cumbersome long data type declarations

    using longnumber = unsigned long long int;                  //ASSIGNING A TYPE ALIAS TO A LONG TYPE DECLARATION

    longnumber number1 {19'445'755'075'709'551ull};             //same as declaring => unsigned long long int number {19'445'755'075'709'551ull};

    std::cout << "Alias check: " << number1 << std::endl;
    std::cout << "Original check: " << number << std::endl;

    longnumber number2 {19'445'755'075'719'551ull};

    std::cout << "Alias check: " << number2 << std::endl;       //type aliases can be used as many number as times

    //ALTERNATIVE(OLDER, LEGACY) WAY OF TYPE ALIAS -> typedef => BUT NOT RECOMMENDED TO USE IN MODERN C++
    typedef unsigned long long int hugenumber;
    hugenumber number3 {19'445'755'075'709'551ull};
    std::cout << "Using typedef: " << number3 << std::endl;     //same as type aliases
    return 0;
}