#include<iostream>
#include<string>

//EXPLICIT TEMPLATE ARGUMENTS IS USED TO FORCE THE PARAMS / ARGS TO BE IMPLICTLY CASTED TO THE REQUIRED TYPE => THIS ALLOWS TO PASS PARAMS / ARGS OF DIFFERENT TYPES TO BE
//PASSED AS PARAMS / ARGS => THIS IS ONLY POSSIBLE IF THE IMPLICIT CAST IS POSSIBLE => ELSE COMPILER ERROR
//VISIT: https://cppinsights.io/ FOR SEEING THE FUNCTION TEMPLATE GENERATION DURING RUNTIME AND DEEP UNDERSTANDING FOR THE BELOW CONCEPT
//<<template_function_name>><typename>(<params>)

template<typename T> T maximum(T a, T b);

int main(int argc, char **argv){

    int a {10};
    int b {20};
    double c {30.99};
    double d {40.99};
    std::string s1 {"Hello "};
    std::string s2 {"Mars"};

    std::cout << "maximum(int): " << maximum(a, b) << std::endl;                //invokes the maximum(int, int) variant of maximum()
    std::cout << "maximum(double): " << maximum(c, d) << std::endl;             //invokes the maximum(double, double) variant of maximum()
    //std::cout << "maximum(int, double): " << maximum(a, c) << std::endl;        //COMPILER ERROR WITHOUT EXPLICIT TEMPLATE ARGUMENTS
    std::cout << "maximum(string, string): " << maximum(s1, s2) << std::endl;   //invokes the maximum(std::string, std::string) variant of maximum()
    //std::cout << "maximum(int, string): " << maximum(a, s1)  << std::endl;      //COMPILER ERROR

    //USING EXPLICIT TEMPLATE ARGUMENTS
    auto d1 = maximum<double>(a, b);                                            //implicitly casts int to double
    auto d2 = maximum<double>(c, d);                                            //no effect as params / args are already of double type
    auto d3 = maximum<double>(a, c);                                            //implicitly casts int param / arg to double
    //auto d = maximum<double>(s1, s2);                                           //COMPILER ERROR AS std::string CANNOT BE CASTED TO double

    std::cout << "int to double implicit cast: " << d1 << std::endl;
    std::cout << "double to double no effect: " << d2 << std::endl;
    std::cout << "int param / arg implicit cast to double: " << d3 << std::endl;
    std::cout << "Compiler error for casting std::string to double" << std::endl;
    return 0;
}

template<typename T> T maximum(T a, T b){
    return (a > b)? a : b;
}