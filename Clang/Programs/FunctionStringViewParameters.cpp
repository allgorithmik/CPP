#include<iostream>
#include<string_view>

void string_func(std::string &name);                                //std::string function prototype
void string_view_func(std::string_view name);                       //std::string_view function prototype

int main(int argc, char **argv){

    std::string name {"C++"};
    string_func(name);                                              //works fine and as expected (automatically passed as reference)
    //COMPILER ERROR WHEN PASSED WITH A STRING LITERAL => REASON THIS HAPPENS IS WE ARE ACTUALLY PASSING CONST STRING ARRAY, BUT IF WE CHANGE THE FUNCTION FUNCTION
    //SIGNATURE TO CONST IT WILL WORK EVEN FOR STRING LITERALS => void string_func(const std::string &name);
    //string_func("C++");

    //BUT TO AVOID ALL THE ABOVE PROBLEMS, WE CAN USE std::string_view INSTEAD OF std::string, THIS WILL SOLVE ALL THE ABOVE PROBLEMS
    //IF WE NEED TO PASS STRINGS AS PARAMS / ARGS TO FUNCTIONS, ITS RECOMMENDED TO USE std::string_view IN MODERN C++
    //THE REASON WHY std::string_view WORKS IS BECAUSE std::string_view MAKES A COPY OF THE STRING INSTEAD OF PASSING AS VALUE =>THIS IS BECAUSE OF TEMPORARY VARIABLE CONCEPT
    std::string_view name2 {"Python"};
    string_view_func(name2);                                        //works fine and as expected (automatically passed as reference)
    string_view_func(std::string_view("Rust"));                     //works fine if passed as std::string_view("<string>")
    string_view_func("CUDA");                                       //works fine if passed as string literals

    return 0;
}

void string_func(std::string &name){                                //function definition
    std::cout << "Name is: " << name << std::endl;
}

void string_view_func(std::string_view name){                       //function definition => REMOVE THE REFERENCE SYMBOL &, ELSE COMPILER EXPECTS A const VALUE
    std::cout << "std::string_view Name is: " << name << std::endl;
}