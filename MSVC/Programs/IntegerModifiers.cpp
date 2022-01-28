#include<iostream>

int main(){
    signed int integer1 {10};
    signed int integer2 {-350};
    //unsigned int integer3 {-40};                      //unsigned cannot have sign, is functional initializer used, casts implicitly
    unsigned int integer4 {50};
    //signed float float1 {};                           //signed unsigned will not work n data types other than int
    short integer5 {10};                                //short can be applied to signed and unsigned integers
    long int integer6 {20};                             //long can be applied to signed and unsigned
    long long int integer7 {30};                        //long long can be applied to signed and unsigned

    std::cout << sizeof(integer1) << std::endl;
    std::cout << sizeof(integer2) << std::endl;
    std::cout << integer1 << std::endl;
    std::cout << integer2 << std::endl;
    std::cout << "Short " << sizeof(integer5) << std::endl;
    std::cout << "Long " << sizeof(integer6) << std::endl;
    std::cout << "Long Long " << sizeof(integer7) << std::endl;
    
    return 0;
}