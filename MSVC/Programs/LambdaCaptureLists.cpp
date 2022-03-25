#include<iostream>

//CAPTURE LISTS IS USED TO PASS PARAMS / ARGS WHICH ARE OUTSIDE THE SCOPE OF THE LAMBDA FUNCTION

int main(int argc, char **argv){
    double d1 {10.99};                                                                              //this variable exists outside the scope of the lambda function
    double d2 {11.99};                                                                              //this variable exists outside the scope of the lambda function

    //capture list is passed with two params which exist beyond the scope of the below lambda function => please note while passing the params to capture lists of
    //lambda functions, the names of the params MUST BE THE SAME AS THE ORIGINAL variables, else compiler error
    auto func1 = [d1, d2](){std::cout << "Using Capture Lists: " << std::endl; return (d1 + d2);};
    //while calling lambda function with capture lists, no need to pass the capture list values as params, OMLY REGULAR PARAMS / ARGS MUST BE PASSED WHILE CALING LAMBDAS
    std::cout << "func1() value is: " << func1() << std::endl;

    //DIFFERENT WAYS OF CAPTURING VALUES IN LAMBDA FUNCTIONS
    //CAPTURE BY VALUE => WHAT WE PASS IN LAMBDA FUNCTION'S CAPTURE LIST WILL BE A COPY, HENCE ANY CHANGES TO THE VARIABLE INSIDE THE LAMBDA FUNCTION WILL NOT CAUSE THE
    //ORIGINAL VARIALBE'S VALUE TO CHANGE
    int int1 {10};
    auto func2 = [int1](){std::cout << "This is captured by value (copy of original variable) and its address: " << int1 << " " << &int1 << std::endl;};

    for(size_t i {}; i < 5; ++i){                                                                   //this local variable is entirely different than the one present in
        std::cout << "Original valueand its address: " << int1 << " " << &int1 << std::endl;        //the lambda function
        func2();                                                                                    //calling lambda inside the loop will not affect the original value
        ++int1;                                                                                     //modifying the value inside the loop will only modify the local
    }                                                                                               //copy of the variable inside the loop

    //CAPTURE BY REFERENCE => WHAT WE PASS IN LAMBDA FUNCTION'S CAPTURE LIST WILL BE A REFERENCE, HENCE ANY CHANGES TO THE REFERENCE VARIABLE INSIDE THE LAMBDA FUNCTION
    //WILL AFFECT THE ORIGINAL VALUE OUTSIDE THE LAMBDA FUNCTION
    int int2 {20};
    //int &int_ref {int2};                                                                          //this is in-correct logic, this does not have any effect inside lambda

    //the capture list of the below lambda function is taking a reference variable of the original value present outside the scope of the lambda functions
    auto func3 = [&int2](){std::cout << "This is a reference capture value and its address: " << int2 << " " << &int2 << std::endl;};

    for(size_t i {}; i < 5; ++i){                                                                   //this loop is having the reference of the original variable
        std::cout << "Value of int2 and its address: " << int2 << " " << &int2 << std::endl;        //this is referring the reference varable of the original variable
        func3();                                                                                    //this also is reffering the reference variable of the original variable 
        ++int2;                                                                                     //any modifications to the variable value will also affect the original
    }                                                                                               //variable, which is passed as capture list value to the lambda function,
    //hence changing the value of the lambda functon's capture list => in other words, its a two way connection of variables, changing the reference variable's value will
    //affect its value everyhere else

    return 0;

}