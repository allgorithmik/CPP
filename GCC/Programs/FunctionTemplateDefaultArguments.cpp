#include<iostream>

template<typename ReturnType = double, typename T, typename P> ReturnType maximum(T a, P b);    //prototype of function template with default argument for ReturnType param

int main(int argc, char **argv){

    int a {100};
    int b {200};

    double c {99.55};
    double d {100.99};

    auto res1 = maximum(a, b);                                                                  //as NO explicit type arg is passed, compiler will deduce ReturnType as double
    auto res2 = maximum<int>(c, d);                                                             //as explicit type ard IS passed, compiler will obey as per the explicit arg
    auto res3 = maximum<int, int, int>(c, d);                                                   //as explicit type ard IS passed, compiler will obey as per the explicit arg

    std::cout << "ReturnType of maximum(a, b): " << sizeof(res1) << std::endl;                  //as per default arg, ReturnType is double(8)as no explicit type arg is passed
    std::cout << "ReturnType of maximum<int>(c, d): " << sizeof(res2) << std::endl;             //ReturnType is int(4) as explicit type arg is passed
    std::cout << "ReturnType of maximum<int, int, int>(c, d): " << sizeof(res3) << std::endl;   //ReturnType is int(4) as explicit type arg is passed
    return 0;
}

template<typename ReturnType, typename T, typename P> ReturnType maximum(T a, P b){             //definition of function template with default argument for ReturnType param
    return (a > b)? a : b;
}