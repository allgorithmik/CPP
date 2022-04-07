#include<iostream>

//WE CAN HAVE TEMPALTE PARAMS FOR LAMBDA FUNCTIONS
//Syntax: auto <function_name> = [] (auto param, auto param, auto param...n){<lambda_function_expression>};

//MULTIPLE TYPE LAMBDA FUNCTION TEMPLATES ARE C++20 ONLY FEATURE

int main(int argc, char **argv){
    auto func = [] (auto a, auto b) {return a + b;};                        //ths type of lambda function can accept any kind of data types which gives rise to unreadability

    //SINGLE TYPE param type Lamda Function Template:
    auto func1 = [] <typename T> (T a, T b) {return a + b;};                                        //a SINGLE TYPE declaration of LAMBDA FUNCTION TEMPLATE

    //MULTIPLE TYPE param type Lamda Function Template:
    auto func2 = [] <typename T, typename P> (T a, P b) {return a + b;};                            //a MULTIPLE TYPE declaration of LAMBDA FUNCTION TEMPLATE

    std::cout << "Lambda Function Output is: " << func(10, 20) << std::endl;
    std::cout << "Lambda Function Template ReturnType is: " << sizeof(func(10, 20)) << std::endl;   //4 return type is 4 as both ints

    //TAKES A SINGLE TYPE AS PARAMS / ARGS => GREATER MEMORY CONCEPT APPLIES => RETURN TYPE WILL BE OF GREATER MEMORY SIZE PARAM /ARGS TYPE
    std::cout << "Lambda Function Template Output is: " << func1(10, 20) << std::endl;
    std::cout << "Lambda Function Template ReturnType is: " << sizeof(func1(10, 20)) << std::endl;  //4 return type is 4 as both ints

    //TAKES MULTIPLE TYPES OF PARAMS / ARGS => GREATER MEMORY CONCEPT APPLIES => RETURN TYPE WILL BE OF GREATER MEMORY SIZE PARAM /ARGS TYPE => C++20 ONLY FEATURE
    std::cout << "Lambda Function Template Output is: " << func2(10, 20.99) << std::endl;
    std::cout << "Lambda Function Template ReturnType is: " << sizeof(func2(10, 20.99)) << std::endl;//return type is 8 as double type has more memory size among params/args

    return 0;
}