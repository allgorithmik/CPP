#include<iostream>

//DEFAULT IS RETURN BY VALUE BUT MODERN C++ COMPILERS HAVE AN INBUILT OPTIMIZATION
//IN MODERN COMPILERS, RETURN BY VALUE IS COMMONLY OPTIMIZED BY THE COMPILER WHENEVER POSSIBLE AND THE FUNCTION IS AUTOMATICALLY MODIFIED INTERNALLY TO RETURN BY
//REFERENCE, THEREBY AVOIDING UNECESSARY COPIES OF DATA

//THIS OPTIMIZATON IS DONE ONLY std::string TYPES AS THE COST OF MEMORY FOR std::string IS MUCH HGHER THAN int OR ANY OTHER TYPES(CHECK THIS)

//POINT TO REMEMEBR IS BACUASE OF THIS SILENT OPTIMIZATION OF CODE DURING COMPILE TIME, WE SHULD NOT RELY ON RETURN BY VALUE FROM FUNCTIONS

int sum(int a, int b);
std::string add_strings(std::string str1, std::string str2);

int main(int argc, char **argv){
    int result = sum(10, 20);
    std::cout << "The address of result inside main(): " << &result << std::endl;           //BOTH ADDRESSES OF RESULT (INSIDE AND OUTSIDE main()) ARE DIFFERENT HENCE PROVING
    std::cout << "The sum via value is: " << result << std::endl;                           //MULTIPLIE COPIES EXIST OF SAME DATA (PASS BY VALUE) => UNOPTIMIZED

    //COMPILER OPTIMIZATION function
    std::string result_string = add_strings("Hello", " Mars");
    std::cout << "The address of main() string result is: " << &result_string << std::endl; //THE ADDRESSES OF STRING_RESULT (INSIDE AND OUTSIDE main()) ARE EXACTLY THE SAME
    std::cout << "The string result via value is: " << result_string << std::endl;          //PROVING THAT COMPILER HAS MADE SOME OPTIMIZATIONS INTERNALLY TO AVOID UNNCESSARY
    return 0;                                                                               //COPIES OF THE SAME DATA
}

int sum(int a, int b){
    int result = a + b;
    std::cout << "The address of result outside main(): " << &result << std::endl;

    return result;                                                                          //return by value(copy)
}

//COMPILER OPTIMIZATION AT WORK
std::string add_strings(std::string str1, std::string str2){
    std::string result = str1 + str2;
    std::cout << "The string address is: " << &result << std::endl;
    
    return result;
}