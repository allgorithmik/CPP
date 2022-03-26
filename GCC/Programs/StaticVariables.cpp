#include<iostream>

//STATIC VARIABLES ARE THOSE WHOSE LIFETIME IS VALID UNTIL THE WHOLE APPLICATION IS TERMINATED. THERE ARE TWO TYPES OF STATIC VARIABLES IN C++, GLOBAL WHICH ARE DECLARED
//OUTSIDE OF EVERY FUNCTION/CLASS, INCLUDING main(). THE OTHER IS A STATIC VARIABLE WHICH CAN LIVE INSIDE A FUNCTION BUT ITS LIFETIME IS BEYOND THE LIFETIME OF THE FUNCTION
//ITS DECLARED. THE STATIC VARIABLE DEFINED INSIDE A FUNCTION WILL HAVE THE LIFETIME OF THE APPLICATIONS, THAT IS IT GETS DESTROYED ONLY WHEN THE APPLICATION TERMINATES

/*                                                          GLOBAL VARIABLES vs STATIC VARIABLES
1) Both global and static variables have static storage duration. They live throughout the applicatin's lifetime.
2) Static variables are scoped to the function in which they are declared and defined. If we try to access them outside of their home function, we'll get compiler error
3) Global variables are scoped to the global scope of the file where they are declared. They can be accessed and used throughout the entire code file
*/

//ONE USE CASE WHERE LOCAL STATIC VARIABLES ARE USED WHERE WE REQUIRE THE VARIABLE'S VALUE STICK AROUND TO CONTINUE USING THE VARIALBE'S VALUE FROM WHERE IT WAS LEFT-OFF

int global_student_count {100};             //global static variable => its called static only because of its lifetime
int global_var {};

int one_add_student(){
    static int local_student_count {50};    //function static variable => its scope is limited to the function but its lifetime is same as the applicaton's lifetime
    ++local_student_count;
    return local_student_count;
}

int no_static(){
    int local_student_count {50};           //the value of this variable will NOT persist accross subsequent calls of this function
    ++local_student_count;
    return local_student_count;
}

int with_static(){
    static int local_student_count {50};    //the value of this variable WILL persist accross subsequent calls of this function=>this variable will be application's lifetime
    return local_student_count;             //same behaviour can be achieved with global scope variables
}

int two_add_student(){
    ++global_student_count;                 //"global_student_count" variable is global, hence can be accessed anywhere in the program and its having application lifetime
    //++local_student_count;                //COMPILER ERROR => even though "local_student_count" variable is static, its SCOPE is limited to its home function
    return global_student_count;
}

int main(int argc, char **argv){

    std::cout << "Checking the accessability of global variable: " << global_student_count << std::endl;
    std::cout << "Calling one_add_student() to check value of its local static variable: " << one_add_student() << std::endl;
    std::cout << "Again calling one_add_student() to see if its local static variable is maintaining its value even after function exit: " << one_add_student() << std::endl;
    std::cout << "Calling two_add_student() to see if its global variable can be accessed from within a function: " << two_add_student() << std::endl;
    std::cout << "Again calling two_add_student() to see if its global variable can maintain its value for susequent calls: " << two_add_student() << std::endl;

    std::cout << "Checking if the non-static variable in no_static() will be able to persist the value for subsequent calls:" << std::endl;
    for(size_t i {}; i < 10; ++i){
        std::cout << "Value in no_static() for " << i << " iteration: " << no_static() << std::endl; //same value gets printed hence proving variable value NOT PERSISTANT
    }

    std::cout << "Checking if the static variable in with_static() will be able to persist the value for subsequent calls:" << std::endl;
    for(size_t i {}; i < 10; ++i){
        std::cout << "Value in with_static() for " << i << " iteration: " << with_static() << std::endl;//value IS PERSISTING accross multiple calls of the function
    }                                                                                                   //statc variables will have application's lifetime

    std::cout << "Proving even the global variable can achieve the same behaviour as a static local variable" << std::endl;
    for(size_t i {}; i < 10; ++i){
        global_var += 1;
        std::cout << "Value of global_var: " << global_var << std::endl;
    }

    //last value AFTER modification is persisting, hence proving static local variable behaviour of persisting values can be achieved using global variables
    //global variables will have applicaton's lifetime
    std::cout << "Value of global_var WILL persist even after exiting the loop where global_var was modified: " << global_var << std::endl;
    return 0;
}