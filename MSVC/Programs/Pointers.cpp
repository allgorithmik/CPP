#include<iostream>

int main(int argc, char **argv){                                                            //A POINTER CAN ONLY POINT TO A VARIABLE WHOSE TYPE IS COMPATIBLE TO ITS OWN TYPE
    int *int_pointer {};                                                                    //=> AN INT POINTER CAN ONLY POINT TO A VARIABLE WHOSE TYPE IS ALSO OF TYPE INT
    double *double_pointer {};                                                              //this pointer can only point to a variable whole type is also double

    int *int_pointer_ini {nullptr};                                                         //just like a variable is initilized, a pointer can also be initialized to a nullptr
    double *double_pointer_ini {nullptr};                                                   //nullptr is the default value for a pointer

    std::cout << "The value of int_pointer is " << int_pointer << std::endl;                //printing 0, but initialized pointers can give garbge values
    std::cout << "The value of double_pointer is " << double_pointer << std::endl;

    std::cout << "The value of int_pointer_ini is " << int_pointer_ini << std::endl;        //printing 0 as its initialzed to a nullprt
    std::cout << "The value of double_pointer_ini is " << double_pointer_ini << std::endl;

    //sizeof(pointers)
    std::cout << "Size of int_pointer is " << sizeof(int_pointer) << std::endl;             //ALL POINTERS WILL HAVE THE SAME SIZE IRRESPECTIVE OF THIER TYPE BECAUSE
    std::cout << "Size of double_pointer is " << sizeof(double_pointer) << std::endl;       //THEY STORE THE ADDRESS OF A VARIABLE, AND THEY ARE OF SAME TYPE IRRESPECTIVE
    std::cout << "Size of int_pointer_ini is " << sizeof(int_pointer_ini) << std::endl;     //OF THE TYPE OF VARIABLES THEY STORE, IN THE SAME SYSTEM
    std::cout << "Size of double_pointer_ini is "<< sizeof(double_pointer_ini) << std::endl;

    int value {45};                                                                         //we can a variable normally and initialize it, and then assign the address of the
    int *pointer_int {&value};                                                              //value to a pointer, NOTE: A POINTER CANNOT TAKE NON-ADDRESS VALUES AS THEY ARE
    double value2 {55.5};                                                                   //ONLY ACCEPT ADDRESSES AS THEIR VALUES, NOTHING ELSE => ADDRESSES OF SAME TYPE
    double *pointer_double {&value2};                                                       //OF VARIABLES AS THAT OF POINTER TYPES

    std::cout << "The address is: " << &value << std::endl;                                 //we can print out the address of a value using &

    int value7 {55};
    pointer_int = &value7;                                                                  //we can re-assign a pointer to a different address of same type, BUT NO *

    double value8 {100.55};                                                                 //CANNOT CROSS-ASSIGN AN ADDRESS OF A VARIABLE WHOSE TYPE IS DIFFERENT THAN 
    //pointer_int = &value8; THAT OF THE POINTER TYPE,ONLY VARIABLES OF SAME TYPE AS POINTERS CAN BE COMPATIBLE => COMPILER ERROR

    //DEREFERENCING => TECHNIQUE OF GETTING A VALUE OF A VARIABLE VIA ITS POINTER

    int *pointer_derefer {nullptr};                                                         //we can derefer the pointer in order to get back the value of a variable
    int value9 {100};                                                                       //by calling the pointer itself, for address & is used
    pointer_derefer = &value9;

    std::cout << "Value of value9 is: " << *pointer_derefer << std::endl;

    int *value3 {}, value4 {};                                                              //there is only one pointer here => *value3, value4 is just an integer variable
    int *value5 {};                                                                         //declare pointer variables and normal variables seperately, NOT A GOOD PRACTICE
    int value6 {};                                                                          //to declare them in a single line even though they will be different

    return 0;
    
}