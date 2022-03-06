#include<iostream>


    /*
    A FUNCTION IS A REUSABLE UNIT OF CODE WITH OPTION TO TAKE INPUTS AND PRODUCE DESIRABLE OUTPUT
    C++ function syntax:
    
    return_type function_name(parameter_list, param1, param2, param3, .....param n){
        code for processing/business logic
        return return_type;
    }

    void function syntax: => void functions take NO INPUT AND RETURN NO OUTPUT
    void function_name(){
        code for processing/business logic
        return return_type;
    }

    FUNCTION SIGNATURE => FUNCTION_NAME + FUNCTION_PARAMETERS
    NO TWO FUNCTIONS WITH EXACT SAME FUNCTION SINGNATURES CAN EXIST TOGETHER
    
    Calling a function:
    function_name(arguement_list, arg1, arg2, arg3, .....arg n);        => calling a function directly
    var = function_name(arguement_list, arg1, arg2, arg3, .....arg n);  => calling a function by assigning its return value to a variable
    function_name()                                                     => calling a function without any arguments
    */

void age_determine(int age){                                                        //function with one param and NO explcit return value
    if(age > 18){
        std::cout << "Person is a major" << std::endl;
    }
    else{
        std::cout << "Person is a minor" << std::endl;
    }
}

int max_number(int a, int b){                                                       //function with multiple params and explcit integer return value
    if(a > b){
        return a;
    }
    else{
        return b;
}
}

void hello_func(){                                                                  //void function => function with NO params and NO explcit return value
    std::cout << "Hello this is C++" << std::endl;
    return;                                                                         //this return is OPTIONAL and can be omitted
}



int some_return(){                                                                  //function with NO params but some explcit return value
    return 1100;
}

//ARGS PASSED TO A FUNCTION ARE COPIES AND ARE SCOPED LOCALLY TO THAT FUNCTION, CHANGES TO PARAMS ARE NOT REFLECTED OUTSIDE THE FUNCTION. WHAT WE HAVE INSIDE THE
//FUNCTION ARE ACTUALLY COPIES OF THE ARGS PASSED TO THE FUNCTION
double scope_demo_func(double x, double y){
        std::cout << "num7 and num8 BEFORE increment/decrement:" << std::endl;
        std::cout << x << " " << y << std::endl;

        double result = ((x++) * (y++));

        std::cout << "num7 and num8 AFTER increment/decrement:" << std::endl;
        std::cout << x << " " << y << std::endl;

        return result;
    }

//C++ COMPILERS REQUIRE ALL THE FUNCTONS BE DEFNED OUTSIDE OF main() => NO FUNCTION CAN BE DECLARED WITHIN main() AS ALL FUNCTIONS MUST BE DEFINED BEFORE CALLING IN MAIN 

int main(int argc, char **argv){
    int num1 {20};
    int num2 {10};

    age_determine(num1);                                                            //calling a function directly without assigning its result to any variable

    int age {5};
    age_determine(age);                                                             //params and args CAN HAVE same name

    int max {max_number(num1, num2)};                                               //initializing a variable with a function call, also passing args

    int max2 = max_number(num1, num2);                                              //assigning a variable with value which is the result returned from a function processing

    std::cout << "Hello function call: " << std::endl;
    hello_func();                                                                   //CANNOT PLUG THIS FUNCTION IN std::cout STATEMENT AS ITS A void TYPE FUNCTION

    std::cout << "Direct function call: " << max_number(num1, num2) << std::endl;   //can directly plug a function call to a std::cout statement=>provided a non void function

    std::cout << "Direct function call without params: " << some_return();          //can directly plug a function call to a std::cout statement=>provided a non void function

    int num3 {55};                                                                  //functions can be reused number of time with any valid args which matches the
    int num4 {100};                                                                 //function signature
    std::cout << "Direct function call: " << max_number(num3, num4) << std::endl;   //a function has to be mantained only once

    double num5 {55.155};
    double num6 {25.99};

    std::cout << "Be careful of implicit casting of args while calling functions: " //compiler WILL IMPLICITLY CAST the args as per the declared param list in function
    << max_number(num5, num6) << std::endl;                                         //signature => be careful of info/precision loss

    double num7 {45.99};
    double num8 {35.99};
    std::cout << "Function param/args demo function:" << std::endl;
    scope_demo_func(num7, num8);                                                    //notice the return result is not displayed because its not captured

    std::cout << "Values outside function are not affected: " << num7 << " " <<
    num8 << std::endl;

    double capture = scope_demo_func(num7, num8);                                   //return result is captured now into a variable 
    std::cout << capture << std::endl;                                              //now the captured esult can be displayed

    return 0;
}