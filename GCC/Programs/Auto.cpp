#include <iostream>

int main(int argc, char **argv){

    //auto lets compiler to deduce the datatype
    auto auto1 {1};     //int
    auto auto2 {2.5f};  //float
    auto auto3 {4.5L};  //long
    auto auto4 {55ll};  //Long Long -> no floating point numbers
    auto auto5 {'T'};   //char
    auto auto6 {55u};   //unsigned int
    auto auto7 {100ul}; //unsigned long

    //using std::cout to varify if compiler deduced the correct types
    std::cout << sizeof(auto1) << std::endl;
    std::cout << sizeof(auto2) << std::endl;
    std::cout << sizeof(auto3) << std::endl;
    std::cout << sizeof(auto4) << std::endl;
    std::cout << sizeof(auto5) << std::endl;
    std::cout << sizeof(auto6) << std::endl;
    std::cout << sizeof(auto7) << std::endl;

    return 0;
}