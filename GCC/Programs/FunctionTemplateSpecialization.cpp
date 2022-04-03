#include<iostream>
#include<cstring>

//FUNCTION TEMPLATE SPECIALIZATION IS A MECHANISM TO BYPASS THE DEFAULT BEHAVIOUR OF FUNCTION TEMPLATES

//NORMAL FUNCTION TEMPLATE
template<typename T>T maximum(T a, T b);                                    //normal function template prototype

//TEMPLATE SPECIALIZATION
template<>const char *maximum<const char*>(const char *a, const char *b);   //specialized function template prototype

int main(int argc, char **argv){

    int a {100};
    int b {200};

    double c {100.99};
    double d {200.99};

    std::string str1 {"Hello "};
    std::string str2 {"Mars"};

    const char *e {"Mars is "};
    const char *f {"Awesome"};

    auto res1 = maximum(a ,b);                                              //maximum<int> variant of maximum() will be invoked
    auto res2 = maximum(c, d);                                              //maximum<double> variant of maximum() will be invoked
    auto res3 = maximum(str1, str2);                                        //maximum<std::string> variant of maximum() will be invoked

    const char *res4 = maximum(e, f);                                       //SPECIALIZED TEMPLATE => maximum<const char*> variant of maximum() will be invoked
    //auto *res4 = maximum(e, f);                                           //auto type deduction can also will be used => ITS RECOMMENDED ACTUALLY

    std::cout << "Int variant of maximum(): " << res1 << std::endl;
    std::cout << "double variant of maximum(): " << res2 << std::endl;
    std::cout << "std::string variant of maximum(): " << res3 << std::endl;

    std::cout << "Specialized Template Function:" << std::endl;
    std::cout << "const char* variant of maximum(): " << res4 << std::endl;

    return 0;
}

template<typename T>T maximum(T a, T b){                                    //normal function prototype definition
    return (a > b)? a : b;                                                  //IF PASSED WITH const char* => POINTER COMPARISON WILL TAKE PLACE INSTEAD OF ACTUAL
}                                                                           //string COMPARISON => UNWANTED BEHAVIOUR => BELOW IMPLEMENTATON IS BETTER FIT

template<>const char *maximum<const char*>(const char *a, const char *b){   //specialized function template defintion
    return (std::strcmp(a, b) > 0)? a : b;                                  //PLEASE DO NOT FORGET TO INCLUDE <cstring> AS std::strcmp IS NOT AVAILABLE IN std NAMESPACE
}                                                                           //string comparison will happen laxicograpically (negative : 0 : positive)