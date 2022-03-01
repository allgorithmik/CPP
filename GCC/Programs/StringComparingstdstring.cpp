#include<iostream>
#include<string>

int main(int argc, char **argv){
    //STRING EQUALITY => TWO STRINGS ARE CONSIDERED EQUAL IF THEY HAVE THE SAME SIZE AND HAVE THE SAME CHARACTERS IN ALL POSITIONS
    //COMPARISON IS DONE LEXICOGRAPHICALLY BY DEFAULT
    std::string str1 {"Mars"};
    std::string str2 {"Bars"};

    std::cout << "std::string comparison:" << std::endl;
    std::cout << str1 << " == " << str2 << " : " << (str1 == str2) << std::endl;
    std::cout << str1 << " != " << str2 << " : " << (str1 != str2) << std::endl;
    std::cout << str1 << " > " << str2 << " : " << (str1 > str2) << std::endl;
    std::cout << str1 << " >= " << str2 << " : " << (str1 >= str2) << std::endl;
    std::cout << str1 << " < " << str2 << " : " << (str1 < str2) << std::endl;
    std::cout << str1 << " <= " << str2 << " : " << (str1 <= str2) << std::endl;

    //comparing C-Strings
    const char *str_pointer {"Hello"};

    std::cout << std::endl;
    std::cout << "C-string comparison:" << std::endl;
    std::cout << str1 << " == " << str_pointer << " : " << (str1 == str_pointer) << std::endl;
    std::cout << str1 << " != " << str_pointer << " : " << (str1 != str_pointer) << std::endl;
    std::cout << str1 << " > " << str_pointer << " : " << (str1 > str_pointer) << std::endl;
    std::cout << str1 << " >= " << str_pointer << " : " << (str1 >= str_pointer) << std::endl;
    std::cout << str1 << " < " << str_pointer << " : " << (str1 < str_pointer) << std::endl;
    std::cout << str1 << " <= " << str_pointer << " : " << (str1 <= str_pointer) << std::endl;

    //BE CAREFUL OF NON null character TERMINATED C-STRINGS, COMPILER WILL READ PAST THE STRING
    //CAPACITY/SIZE UNTILL IT ENCOUNTERS A \0 AND OUR RESULTS/COMPARISON WILL BE ERRONOUS
    std::cout << std::endl;
    std::cout << "C-string comparison (null terminated and non null terminated):" << std::endl;
    const char error_str[] {'H', 'E', 'L', 'L', 'O'};                                           //non null terminated \0 string array => 0 but bad practice
    const char no_error_str[] {'H', 'E', 'L', 'L', 'O', '\0'};                                  //this is a safe bet and good practice

    std::cout << "Non null terminated string array comparison: " << str1 << " == " << error_str << " : " << (str1 == error_str) << std::endl;
    std::cout << "Null terminated string array comparison: " << str1 << " == " << error_str << " : " << (str1 == no_error_str) << std::endl;
    
    std::cout << std::boolalpha << std::endl;
    std::cout << "In terms of True/False" << std::endl;

    std::cout << std::endl;
    std::cout << "std::string comparison:" << std::endl;
    std::cout << str1 << " == " << str2 << " : " << (str1 == str2) << std::endl;
    std::cout << str1 << " != " << str2 << " : " << (str1 != str2) << std::endl;
    std::cout << str1 << " > " << str2 << " : " << (str1 > str2) << std::endl;
    std::cout << str1 << " >= " << str2 << " : " << (str1 >= str2) << std::endl;
    std::cout << str1 << " < " << str2 << " : " << (str1 < str2) << std::endl;
    std::cout << str1 << " <= " << str2 << " : " << (str1 <= str2) << std::endl;

    std::cout << std::endl;
    std::cout << "C-string comparison:" << std::endl;
    std::cout << str1 << " == " << str_pointer << " : " << (str1 == str_pointer) << std::endl;
    std::cout << str1 << " != " << str_pointer << " : " << (str1 != str_pointer) << std::endl;
    std::cout << str1 << " > " << str_pointer << " : " << (str1 > str_pointer) << std::endl;
    std::cout << str1 << " >= " << str_pointer << " : " << (str1 >= str_pointer) << std::endl;
    std::cout << str1 << " < " << str_pointer << " : " << (str1 < str_pointer) << std::endl;
    std::cout << str1 << " <= " << str_pointer << " : " << (str1 <= str_pointer) << std::endl;
    return 0;
}