#include<iostream>

int main(int argc, char **argv){         //Range loops with initializer is a C++20 feature
    auto product {5};
    for(size_t value: {1,2,3,4,5,6,7,8,9,10}){                                                              //This is WITHOUT init
        std::cout << value << " multiplied with " << product << " is " << (value * product) << std::endl;
    }

    std::cout << "With for loop init" << std::endl;
    for(auto product1 {5}; size_t value: {1,2,3,4,5,6,7,8,9,10}){                                           //This is WITH init, this product1 variable is scoped only for
        std::cout << value << " multiplied with " << product << " is " << (value * product) << std::endl;   //this for loop
    }
    return 0;
}