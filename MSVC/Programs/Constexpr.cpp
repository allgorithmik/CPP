#include<iostream>

int main(){
    //constexpr is a C++17 feature
    constexpr bool condition {false};                           //constexpr will precompute at compile time
    if constexpr (condition){                                   //based on the condition at compile time, the branch which does not match with the condition will be
        std::cout << "This gets executed" << std::endl;         //eliminated from the binary at compile time
    }
    else{
        std::cout << "This does not get executed" << std::endl; //compile time programming is a very interesting toopic
    }
    return 0;
}