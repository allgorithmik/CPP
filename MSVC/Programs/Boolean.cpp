#include <iostream>

int main(){
    bool yes {true};
    bool no {false};

    std::cout << std::boolalpha;                //By default c-outing bools will print 1/ 0, if std::boolalpha is set, it will print True / False

    std::cout << yes << std::endl;
    std::cout << no << std::endl;

    std::cout << sizeof(bool) << std::endl;    //Size of bool is 1 byte

    return 0;
}