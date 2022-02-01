#include <iostream>

int main(int argc, char **argv){
    bool value1 {true};
    bool value2 {false};

    std::cout << "AND Operator: " << (value1 & value2) << std::endl;
    std::cout << "OR Operator: " << (value1 | value2) << std::endl;
    std::cout << "NOT Operator: " << (! value2) << std::endl;
    std::cout << "Shortcircuit AND Operator: " << (value1 && value2) << std::endl;
    std::cout << "Shortcircuit OR Operator: " << (value1 || value2) << std::endl;

    std::cout << std::boolalpha;

    std::cout << "AND Operator: " << (value1 & value2) << std::endl;
    std::cout << "OR Operator: " << (value1 | value2) << std::endl;
    std::cout << "NOT Operator: " << (! value2) << std::endl;
    std::cout << "Shortcircuit AND Operator: " << (value1 && value2) << std::endl;      //Shortcircuit
    std::cout << "Shortcircuit OR Operator: " << (value1 || value2) << std::endl;

    return 0;
}