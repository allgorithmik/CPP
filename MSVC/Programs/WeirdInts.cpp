#include <iostream>

int main(){
    short value1 {10};
    short value2 {20};
    auto result {value1 + value2};     //result implicitly gets converted to int, as no operations are possible on datatypes less than 4 bytes

    std::cout << result << std::endl;
    std::cout << "The sizes of int and result will be same: " << sizeof(int) << " " << sizeof(result) << std::endl;

    return 0;
}