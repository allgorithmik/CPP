#include<iostream>

//decltype auto => A MECHANISM IS C++ TO AVOID CODE REPETITION WHICH OCCURS WHILE USING -> decltype (TRAILING RETURNTYPE)
//template<typename T, typename P> auto maximum(T a, P b) -> decltype((a > b)? a : b){  //commenting this out to avoid re-definition compiler error
//    return (a > b)? a : b;
//}
//AS WE CAN SEE => THE EXPRESSION (a > b)? a : b IS REPEATED IN LINES 4 & 5 => decltype auto IS USED TO AVOID THIS KIND OF CODE REPETITION

//USING decltype auto:
//Syntax: template<<typename T, typename P>> decltype(auto) <template_name>(T param, P param)

template<typename T, typename P> decltype(auto) maximum(T a, P b){  //declaration and definition of function template with decltype(auto)
    return (a > b)? a : b;                                          //as auto is involved, function template CANNOT be split into prototype and definition
}

int main(int argc, char **argv){
    int a {100};
    double b {55.99};

    //deduced as double(size:8) as double memory size is higher than int memory size => decltype deduces return types based on memory sizes of params / args involved
    std::cout << "The return type of maximum() deduced by decltype(auto) is: " << sizeof(maximum(a, b)) << std::endl;
    return 0;
}