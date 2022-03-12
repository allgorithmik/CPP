#include<iostream>

int increment(int &value);                                                          //function prototype
int increment_const(const int &value);                                              //function prototype

int main(int argc, char **argv){

    int val1 {10};
    int val2 {20};
    double val3 {30.55};

    int res1 = increment(val1);                                                     //automatically passed as reference by compiler
    int res2 = increment_const(val2);                                               //automatically passed as reference by compiler

    std::cout << "increment(): " << res1 << std::endl;
    std::cout << "Value of val1 after calling increment(): " << val1 << std::endl;  //original value has been affected as increment() arg / param is a reference
    std::cout << "increment_const(): " << res2 << std::endl;

    //COMPILER ERROR => WHEN A MISMATCHED TYPE IS PASSED AS REFERENCE VARIABLE, IMPLICIT CASTING WILL NOT TAKE PLACE => GIVES COMPILER ERROR
    //THIS HAPPENS BECAUSE THE COMPILER CREATES A TEMPORARY VARIABLE AND MAKES THE IMPLCIT CAST(LOSES DATA) TO THAT TEMPORARY VARIABLE AND THE REFERENCE OF THIS TEMPORARY
    //VARIABLE IS PASSED TO THE CONTROL, AND WHEN THE CONTROL TRIES TO MODIFY THE VALUE, THE COMPILER CANNOT TRACE THE OWNER OF THE MODIFICATION, IS IT THE TEMPORARY
    //VARIABLE OR THE ORIGINAL VARIABLE FOR WHICH THE TEMPORARY VARIABLE WAS CREATED IN THE FIRST PLACE => COMPILER THROWS AN ERROR => THIS PROBLEM DOES NOT ARISE FOR
    //CONST VARIALBES AS THERE ARE NO MODIFICATIONS THAT NEED TO BE DONE
    //std::cout << "Passing mismatched type as param / arg to increment(): " << increment(val3) << std::endl;

    //WHEN A MISMATCHED TYPE IS PASSED AS A REFERENCE TO A CONST VARIABLE AND NO MODIFICATIONS ARE MADE TO THE VARIABLE, IMPLICIT CASTING WILL TAKE PLACE
    //THIS IS POSSIBLE BECAUSE THE COMPILER CREATES A TEMPORARY VARIABLE AND MAKES THE IMPLCIT CAST(LOSES DATA) TO THAT TEMPORARY VARIABLE AND THE REFERENCE OF THIS TEMPORARY
    //VARIABLE IS PASSED TO THE CONTROL
    std::cout << "Passing mismatched type as param / arg to increment(): " << increment_const(val3) << std::endl; //NO ERROR EVEN IF IMPLICITLY CASTED

    return 0;
}

int increment(int &value){                                                          //function definition
    return ++value;                                                                 //modifying the reference variable which affects the original variable
}

int increment_const(const int &value){                                              //function definition
    return value;
}