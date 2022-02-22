#include<iostream>

int main(int argc, char **argv){            //PROGRAM CRASHING => DO NOT RUN MULTIPLE TIMES
    int *pointer1;                  //pointer declared => BUT IT CAN BE POINTING TO ANYTHING, EVEN TO ADDRESSES USED BY OTHER PROGRAMS => CAN CAUSE CRASH
    *pointer1 = 100;                //pointer initialized => BUT IT CAN WRITE TO ANY ADDRESSES, EVEN TO ADDRESSES USED BY OTHER PROGRAMS => CAN CAUSE CRASH

    int *pointer2 {nullptr};                                                        //ALSO BAD PRACTISE TO INITIALIZE A POINTER TO nullptr

    std::cout << "Uninitialized pointer: " << pointer1 << std::endl;
    std::cout << "Dereferencing uninitialized pointer: " << *pointer1 << std::endl;
    std::cout << "NULL pointer: " << pointer2 << std::endl;
    std::cout << "Dereferencing NULL pointer: " << *pointer2 << std::endl;

    int *ptr {};                    //INITIALIZING A POINTER TO 0 IS EQUIVALENT TO INITIALIZING TO nullptr
    *ptr = 55;                      //IF WE TRY TO INITIALIZE A 0 / nullptr, UNKNOWN BEHAVIOUR WILL OCCUR

    //ALL THIS WHILE WE WERE USING THE STACK MEMORY IN PROGRAM MEMORY MAP, VARIABLES WE DECLARED, VALUES WE INITIALIZED, FUNCTIONS, POINTERS, EVERYTHING HAPPENED ON THE
    //STACK, NOW WE WILL SEE HOW TO USE THE HEAP MEMORY FROM THE MEMORY MAP OF THE PROGRAM
    //ALLOCATING DYNAMIC MEMORY IN HEAP MEMORY IS DONE BY USING THE 'new' OPERATOR

    int *pointer3 {nullptr};        //DECLARING A nullptr
    pointer3 = new int;             //pointer3 IS NOW INITIALIZED TO new int OBJECT IN HEAP MEMORY => THE SIZE OF THE OBJECT IS SAME THE TYPE OF OBJECT (int)

    //RELEASING MEMORY AND RESETTING POINTER
    delete pointer3;                //NOW THE MEMORY IS RELEASED BACK TO THE SYSTEM
    pointer3 = nullptr;             //NOW POINTER IS AGAIN REFERRING TO nuLlptr => POINTING UNKNOWN LOCATION

    //IF WE USE new OPERATOR, SYSTEM WILL ALLOCATE A MEMORY FROM HEAP MEMORY, NOT STACK MEMORY IN THE MEMORY MAP

    //STACK MEMORY IS ALWAYS SCOPE BASED, HEAP MEMORY IS ALWAYS CONTROLLED BY THE DEVELOPER => WE CAN CREATE IT AND RELEASE IT WHENEVER WE WANT

    {
        int var1 {10};              //THIS VARIABLE AND ITS VALUE IS STORED IN STACK MEMORY, AND IT GOES OUT OF SCOPE ONCE THE CONTROL EXITS THE BLOCK
        int *pointvar {nullptr};
        pointvar = new int;         //THIS VARIABLE AND ITS VALUE IS STORED IN HEAP MEMORY, IT DOES GO OUT OF SCOPE IF THE CONTROL EXITS THE BLOCK, IT ONLY GOES OUT OF
        delete pointvar;            //SCOPE ONLY WHEN ITS RELEASED BY DEVELOPER USING THE delete OPERATOR
    }

    //DYNAMIC MEMORY ALLOCATION
    int *pointer4 {new int};
    int *pointer5 {new int (55)};   //FUNCTIONAL (DIRECT) INITIALIZATION
    int *pointer6 {new int {100}};  //UNIFORM INITIALIZATION

    //RELEASING MEMORY AND AND RESETTING POINTERS
    delete pointer4;
    pointer4 = nullptr;             //ALWAYS A GOOD PRACTICE TO POINT A POINTER TO A nullptr AS IT WILL NOT POINT TO AN UNKNOWN ADDRESS

    delete pointer5;
    pointer5 = nullptr;             //ALWAYS A GOOD PRACTICE TO POINT A POINTER TO A nullptr AS IT WILL NOT POINT TO AN UNKNOWN ADDRESS

    delete pointer6;                //ALWAYS A GOOD PRACTICE TO POINT A POINTER TO A nullptr AS IT WILL NOT POINT TO AN UNKNOWN ADDRESS
    pointer6 = nullptr;             //IF WE USE DELETE, ONLY THE MEMORY WILL BE GIVEN BACK TO SYSTEM, BUT POINTER IS STILL USABLE, AND IT CAN BE USED TO POINT SOMEWHERE
    pointer6 = new int(100);        //ELSE WITH DATA OF SAME TYPE AS POINTER => new <datatype>(value) => ANOTHER SYNTAX DYNAMIC MEMORY ALLOCATION

    int *var2 {new int {10}};
    delete var2;                    //NEVER EVER DELETE A POINTER MORE THAN ONCE, IT WILL CAUSE AN UNKNOWN BEHAVIOUR
    delete var2;                    //PROGRAM CRASHES IF WE DELETE TWICE, WORKS FINE IF SECOND DELETE IS COMMENTED OUT

    std::cout << var2 << std::endl;
    return 0;
}