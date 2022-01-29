#include <iostream>

int main(int args, char **argv){
    int var1 {10};
    int var2 {20};

    //Addition
    int sum {var1 + var2};
    std::cout << "The sum is: " << sum << std::endl;

    //Subtraction
    int diff {var1 - var2};
    std::cout << "The diff is: " << diff << std::endl;

    //Multiplication
    int product {var1 * var2};
    std::cout << "The product is: " << product << std::endl;

    //Division
    int div {var1 / var2};
    std::cout << "The division is: " << div << std::endl;

    //Modulus
    int mod {var1 % var2};
    std::cout << "The modulus is: " << mod << std::endl;

    return 0;
}