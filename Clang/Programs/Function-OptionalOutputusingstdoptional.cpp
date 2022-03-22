#include<iostream>
#include<optional>

//int char_find(std::string &str1, char c);                                                             //function prototype with normal datatype return type
std::optional<int> opt_char_find(std::string &str1, char c);                                            //function prototype with std::optional<<datatype>> return type
std::optional<int> opt_char_find_def(std::string &str1, std::optional<char> o = std::nullopt); //function prototype with std::optional<<datatype>> as default param

int main(int argc, char **argv){

    std::string str1 {"This is C++20"};
    char x = '+';

    std::optional<int> res1 = opt_char_find(str1, x);

    if(res1 == std::nullopt){                                                                           //std::nullopt method of checking value
        std::cout << x << " is NOT found in " << str1 << std::endl;
    }
    else{
        std::cout << x << " has been found at " << res1.value() << " in " << str1 << std::endl;
    }

    char y = 'C';

    std::optional<int> res2 = opt_char_find(str1, y);

    if(res2.has_value()){                                                                           //<std::optional>.has_value() method of checking value
        std::cout << x << " is found in " << str1  << " at " << *res2 << std::endl;                 // *<std::optional_identifier> => DEREFERENCING method to read value
    }
    else{
        std::cout << x << " has NOT been found in " << str1 << std::endl;
    }

    char z = ' ';

    std::optional<int> res3 = opt_char_find(str1, z);

    if(res3 != std::nullopt){                                                                       //std::nullopt method of checking value
        std::cout << x << " has been found at " << res3.value() << " in " << str1 << std::endl;
    }
    else{
        std::cout << x << " is NOT found in " << str1 << std::endl;
    }

    return 0;
}

std::optional<int> opt_char_find(std::string &str1, char c){
    for(size_t i {}; i < str1.size(); ++i){
        if(str1[i] == c){
            return i;
        }
    }

    return {};                                                                                      //equivalent to returning std::nullopt;
}

std::optional<int> opt_char_find_def(std::string &str1, std::optional<char> o = std::nullopt){
    char def = o.value_or('Z');
    for(size_t i {}; i < str1.size(); ++i){
        if(str1[i] == def){
            o = i;
            return o;
        }
    }
    return def;
}