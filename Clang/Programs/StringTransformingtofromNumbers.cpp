#include<iostream>
#include<string>

int main(int argc, char **argv){

    //std::to_string() => casting number into std::string
    int num1 {10};
    double num2 {55.5};
    float num3 {65.9};

    //numbers to std::string:
    //std::to_string, std::to_wstring()
    std::string int_string {std::to_string(num1)};
    std::string double_string {std::to_string(num2)};
    std::string float_string {std::to_string(num3)};

    std::cout << "Int to std::string: " << int_string << std::endl;
    std::cout << "Double to std::string: " << double_string << std::endl;
    std::cout << "Float to std::string: " << float_string << std::endl;

    //std::string to numbers:
    //std::stoi             => std::string -> integer
    //std::stol             => std::string -> long integer
    //std::stoll            => std::string -> long long integer
    //std::stoul            => std::string -> unsigned long integer
    //std::stoull           => std::string -> unsigned long long integer
    //std::stof             => std::string -> float
    //std::stod             => std::string -> double
    //std::stold            => std::string -> long double

    std::string str1 {"11"};                                                                                //arguments must be std::string obviously
    std::string str2 {"15"};                                                                                //arguments must be std::string obviously
    std::string str3 {"50"};                                                                                //arguments must be std::string obviously

    int int_num {std::stoi(str1)};
    long long_int_num {std::stol(str2)};
    long long long_long_int_num {std::stoll(str3)};
    unsigned long unsigned_long_int_num {std::stoul(str1)};
    unsigned long long unsigned_long_long_int_num {std::stoull(str2)};
    float float_num {std::stof(str3)};
    double double_num {std::stod(str1)};
    long double long_double_num {std::stold(str2)};

    std::cout << "Integer to std::string: " << int_num << std::endl;
    std::cout << "Long Integer to std::string: " << long_int_num << std::endl;
    std::cout << "Long Long Integer to std::string: " << long_long_int_num << std::endl;
    std::cout << "Unsigned long Integer to std::string: " << unsigned_long_int_num << std::endl;
    std::cout << "Unsigned Long Long Integer to std::string: " << unsigned_long_long_int_num << std::endl;
    std::cout << "Float to std::string: " << float_num << std::endl;
    std::cout << "Double to std::string: " << double_num << std::endl;
    std::cout << "Long Double to std::string: " << long_double_num << std::endl;
    
    return 0;
}