#include<iostream>

//CAPTURE LISTS CAN ALSO BE USED TO ACCESS ALL THE OTHER VARIABLES PRESENT IN A PROGRAM WHICH EXISIT BEYOND THE SCOPE OF THE LAMBDA FUNCTION. PREVIOUSLY ONLY THE VARIABLES
//EXPLICITLY MENTIONED WITHIN THE [] OF THE LAMBDA FUNCTION CAN BE ACCESSED BY THE LAMBDA FUNCTION, BUT CAPTURE LISTS CAN BE MADE TO ACCESS ABSOLUTELY EVERYTHING PRESENT
//IN THE PROGRAM. THIS CAN BE ACHIEVED BY USING [=] or [&] SYNTAX IN THE LAMBDA FUNCTION. [=] CAPTURES EVERY VARIABLE BY VALUE, WHEREAS [&] CAPTURES EVERY VARIABLE BY
//REFERENCE

int main(int argc, char **argv){

    //CAPTURE BY VALUE:
    int a {10};
    int b {20};
    auto func1 = [=](){std::cout << "Value Variables present are: " << a  << " " << b << std::endl;};   //pass by value
    for(size_t i ; i < 5; ++i){
        std::cout << "func1 values BEFORE modification: " << a << " " << b << std::endl;
        ++a;                                                                                            //as func2() is accessing variables by reference, any modifications
        ++b;                                                                                            //will affect the original variable outside the scope of the lambda()
        func1();                                                                                        //lambda function call
    }

    //CAPTURE BY REFERENCE ==>> STRANGE BEHAVIOUR, ABOVE BLOCK EXECUTING BUT NOT BELOW BLOCK, NOT UNLESS ABOVE BLOCK IS COMMENTED OUT
    int c {30};
    int d {40};
    auto func2 = [&](){std::cout << "Reference Variables present are: " << c << " " << d << std::endl;};//pass by reference
    for(size_t i ; i < 5; ++i){
        std::cout << "func2 values BEFORE modification: " << c << " " << d << std::endl;
        ++c;                                                                                            //as func2() is accessing variables by reference, any modifications
        ++d;                                                                                            //will affect the original variable outside the scope of the lambda()
        std::cout << "func2 values AFTER modification: " << c << " " << d << std::endl;
        func2();                                                                                        //lambda function call
    }

    return 0;

}