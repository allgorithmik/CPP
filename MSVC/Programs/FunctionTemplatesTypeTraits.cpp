#include<iostream>
#include<type_traits>                                                       //DO NOT FORGET TO INCLUDE TYPE TRAITS HEADER WHILE USING TYPE TRAITS

//TYPE TRAITS ARE A MECHANISM TO QUERY INFORMATION ABOUT A TEMPLATED TYPE AT COMPILE TIME
//Type Traits Link: https://en.cppreference.com/w/cpp/header/type_traits

//USING TYPE TRAITS WE CAN PERFORM CONDITIONAL COMPILE TIME PROGRAMMING
template<typename T> void print(T n){
    //stdtic_assert syntax: static_assert(<condition / expression / statement to resolve to boolean>, "<Error Meesage if the condition on the left fails>");
    static_assert(std::is_integral<T>::value, "Must pass an integral arg"); //static_assert is a statement / mechanism to check somehng at compile time
    std::cout << "n: " << n << std::endl;
}

//ALTERNATE SYNTAX FOR => std::is_integral<<type>>::value ==>> std::is_integral_v<<type>> => THIS IS AVAILABLE ONLY ON C++17 AND ABOVE
//TEMPLATE WITH ALTERNATE SYNTAX:
template<typename T> void print_one(T n){                               //JUST NAME OF TEMPLATE CHANGED TO AVOID RE-DEFINTION ERROR
    //stdtic_assert syntax: static_assert(<condition / expression / statement to resolve to boolean>, "<Error Meesage if the condition on the left fails>");
    static_assert(std::is_integral_v<T>, "Must pass an integral arg"); //static_assert is a statement / mechanism to check somehng at compile time
    std::cout << "n: " << n << std::endl;
}

int main(int argc, char **argv){

    int a {100};

    std::cout << std::boolalpha;
    std::cout << "is_integral<int>: " << std::is_integral<int>::value << std::endl;
    std::cout << "is_integral<double>: " << std::is_integral<double>::value << std::endl;
    std::cout << "is_floating_point<int>: " << std::is_floating_point<int>::value << std::endl;
    //std::cout << "is_integral<a>: " <<std::is_integral<a>::value << std::endl;                  //COMPILER ERROR => ONLY TYPES CAN BE PASSED NOT VARIABLES OR VALUES

    //std::cout << "The result of print(): " << print(a) << std::endl;                          //static_assert cannot be plgged along with std::cout?
    int b {10};
    print(b);                                                                                   //YES WHILE COMPILING static_assert IS WORKING AS EXPECTED AND GIVES ERROR
    //IF CONDITION FAILS AT COMPILE TIME

    //TYPE TRAITS WITH ALTERNATE SYNTAX ==>> std::is_integral_v<<type>>
    std::cout << std::boolalpha;
    std::cout << "is_integral_v<int>: " << std::is_integral_v<int> << std::endl;
    std::cout << "is_integral_v<double>: " << std::is_integral_v<double> << std::endl;
    std::cout << "is_floating_point_v<int>: " << std::is_floating_point_v<int> << std::endl;
    //std::cout << "is_integral<a>: " <<std::is_integral_v<a> << std::endl;                       //COMPILER ERROR => ONLY TYPES CAN BE PASSED NOT VARIABLES OR VALUES

    auto func = []<typename T>(T a, T b){
        static_assert(std::is_integral_v<T>, "Only integral values will be accepted");
        return a + b;
    };

    int var1 {10};
    int var2 {20};
    auto res2 = func(var1, var2);                                                               //if type trait static_assert conditon fails, compiler error will occur
    std::cout << "Result of func(): " << res2 << std::endl;
    return 0;
}