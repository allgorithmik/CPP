#include<iostream>

//We can pass parameters to function templates by reference. The syntax is below:
//template<typename T> const T& <<template_name>>(const T& param1, const T& param2);

template<typename T> const T& maximum(const T& a, const T& b);                              //function tempate prototype with pass by reference params / args

//BUT WE CAN OVERLOAD TEMPLATES AS WELL BY CREATING TWO TEMPLATES => ONE WITH PASS BY VALUE PARAMS / ARGS AND ANOHER WITH PASS BY REFERENCES PARAMS / ARGS:
//THIS WLL GIVE RISE TO COMPILER ERROR ASTHE COMPILER DOES NOT KNOW WHICH FUNCTION TEMPLATE MUST BE INVOKED => FUNCTION TEMPLATE WITH PASS BY VALUE PARAMS / ARGS OR
//FUNCTION TEMPLATE WITH PASS BY REFERENCE PARAMS / ARGS => HENCE COMPILER ERROR 
//template<typename T> T maximum(T a, T b);                                                 //commenting this out as it gives rise to compiler error

int main(int argc, char **argv){
    double a {55.99};
    double b {45.00};

    std::cout << "Address of a and b outside maximum(): " << &a << " " << &b << std::endl; //address of a and b are same both outside of maximum() and from within maximum()
    std::cout << "Calling maximum(): " << maximum(a, b) << std::endl;                      //hence proving the params / args are passed via reference

    double res1 = maximum(a, b);
    std::cout << "maximum() result: " << res1 << std::endl;
    return 0;
}

template<typename T> const T &maximum(const T &a, const T &b){
    //++a;                                                                                    //CANNOT MODIFY THE VALUE AS WE ARE PASSING CONST REFERENCES
    std::cout << "Address of a and b inside maximum(): " << &a << " " << &b << std::endl;   //address of a and b are same both outside of maximum() and from within maximum()
    return (a > b)? a : b;                                                                  //hence proving the params / args are passed via reference
}

/*
template<typename T>T maximum(T a, T b){                                                    //defintion of template functon with pass by reference params / args
    return (a > b)? a : b;                                                                  //commenting this out as gives rise to compiler error
}
*/