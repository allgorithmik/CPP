#include<iostream>

int add(int a, int b){
    int result = a + b;
    return result;
}

int main(int argc, char **argv){
    int first {5};                              // modern way of initialising variables
    int second {10};                            // modern way of initialising variables

    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << first + second << std::endl;   //another result of sum

    int sum = add(55, 55);                      //calling function

    std::cout << sum << std::endl;

    std::cout << add(45,45) << std::endl;       //calling function within cout -> possible

    return 0;
}