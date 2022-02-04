#include <iostream>

int main(int argc, char **argv){

    //Implicit type conversions happend without human intervention -- small -> big
    int unit {10};
    double price {55.55};

    double result {unit * price};                   //auto also dynamically determines the type as double as one of the operand is double.

    std::cout << "The result gets converted to double implicitly: " << result << std::endl;
    std::cout << sizeof(unit) << std::endl;
    std::cout << sizeof(price) << std::endl;
    std::cout << sizeof(result) << std::endl;

    //Narrow conversion -> explicit data casting

    double x {45.55};
    int y {99};

    y = x;                                          //Data gets lost, as double is assigned to int.
    std::cout << y << std::endl;

    return 0;
}