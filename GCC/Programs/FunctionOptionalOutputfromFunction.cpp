#include<iostream>

int find_char(std::string &str, char c);                                                            //function prototype
void find_char_bool(std::string &str, char c, bool &status);                                        //function prototype

int main(int argc, char **argv){
    
    std::string str1 {"This is C++20, the world's most powerfull programming language"};
    char x = '+';
    int res = find_char(str1, x);
    //direct approach
    std::cout << "Searching: " << res << std::endl;

    //another approach with more verbose
    if(res != -1){                                                                                  //if(<function_call> != -1) also works => if(find_char(str1, x) != -1)
        std::cout << x << " is found and in " << str1 << " and its index is: " << res << std::endl;
    }
    else{
        std::cout << x << " is not found in " << str1 << std::endl;
    }

    bool status {false};
    std::cout << "This is boolean style" << std::endl;
    find_char_bool(str1, x, status);
    if(status){                                                                                     //directly passing a variable which holds a boolean value works
        std::cout << x << " is found and in " << str1 << " and its index is: " << res << std::endl;
    }
    else{
        std::cout << x << " is not found in " << str1 << std::endl;
    }
    return 0;
}

//using integers to determine the output of function
int find_char(std::string &str, char c){                                                            //function definition
    int not_found {-1};
    for(size_t i {}; i < std::size(str); ++i){                                                      //<string>.size() works, BUT, std::size(<string>) (my approach) also works
        if(str.c_str()[i] == c){                                                                    //<string>.c_str()[<index i>] works, BUT, str[i] (my approach) also works
            return i;
        }                                                                                           //BE VERY CAREFUL WHILE USING if{} else{} INSIDE LOOPS, HAD A MAJOR BUG
    }
    return not_found;
}

//using boolean to determine the output of function
void find_char_bool(std::string &str, char c, bool &status){                                        //function definition
    for(size_t i {}; i < str.size(); ++i){                                                          //std::size(<string>) works, BUT, <string>.size() also works
        if(str[i] == c){                                                                            //str[i] works, BUT, <string>.c_str()[<index i>] also works
            status = true;
            return;
        }                                                                                           //BE VERY CAREFUL WHILE USING if{} else{} INSIDE LOOPS, HAD A MAJOR BUG
    }
    status = false;
}