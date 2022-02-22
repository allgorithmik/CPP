#include<iostream>

int main(int argc, char **argv){

    //A POINTER THAT DOES NOT POINT TO A VALID ADDRESS IS A DANGLING POINTER => TRYING TO USE A DANGLING POINTER WILL RESULT IN UNDEFINED BEHAVIOUR
    //THERE ARE THREE KINDS OF DANGLING POINTERS:
    //          1) UNINITIALIZED POINTERS
    //          2) DELETED POINTERS(MEMORY DELETED, NOT POINTER)
    //          3) MULTIPLE POINTERS POINTING TO SAME ADDRESS

    //1) UNINITIALIZED POINTERS
    int *pointer1;
    std::cout << "Uninitialized dangling pointer: " << pointer1 << std::endl;                   //undefined behaviour
    std::cout << "Dereferencing uninitialized dangling pointer: " << *pointer1 << std::endl;    //program crashes

    //SOLUTION FOR 1
    int *pointer11 {};                                                                           //Initialize the pointer => 0 / nullptr
    int *pointer111 {new int {100}};                                                              //Initialize the pointer using new operator

    if(pointer1 != nullptr){                                                                    //implement conditions to check for nullptr
        std::cout << "This is not a nullptr, we can use it" << std::endl;
        std::cout << "Dereferencing *pointer1: " << *pointer1 << std::endl;
    }

    //2) DELETED POINTERS(MEMORY DELETED, NOT POINTER)
    int *pointer2 {new int{100}};
    delete pointer2;
    std::cout << "Deleted dangling pointer: " << pointer2 << std::endl;
    std::cout << "Dereferencing deleted dangling pointer: " << *pointer2 << std::endl;

    //SOLUTION FOR 2
    int *pointer22 {new int{100}};
    delete pointer22;
    pointer2 = nullptr;                                                                         //initialize the deleted pointer to nullptr immediately after calling delete
    std::cout << "Dereferencing deleted nullptr initialized pointer: " << *pointer2 << std::endl;

    //3) MULTIPLE POINTERS POINTING TO SAME ADDRESS
    int *pointer3 {nullptr};
    int *pointer4 {nullptr};
    int var1 {100};
    int var2 {500};
    pointer3 = &var1;
    pointer4 = &var1;

    std::cout << "pointer3 address: " << pointer3 << std::endl;
    std::cout << "pointer4 address: " << pointer4 << std::endl;

    //3) MULTIPLE POINTERS POINTING TO SAME ADDRESS => BUT 1 ADDRESS IS DELETED
    int *pointer6 {new int {100}};
    int *pointer7 {pointer6};
    delete pointer6;
    pointer7;

    std::cout << "pointer3 address: " << pointer3 << std::endl;
    std::cout << "pointer4 address: " << pointer4 << std::endl;

    //SOLUTION FOR 3
    //THE SOLUTION FOR 3 IS TO DECIDE ON A SINGLE POINTER AS A MASTER POINTER THAT CONTROLS THE MEMORY AND IS RESPONSIBLE FOR RELEASING THE MEMORY AT AN APPROPRIATE TIME
    //THE REST ALL POINTERS ARE SLAVE POINTERS AND THEY CAN ONLY BE ABLE TO DEREFERENCE THE MASTER POINTER, BUT NOT DELETE THE POINTER => SLAVE POINTERS WILL BE READ ONLY
    int *pointer8 {new int{500}};                                                               //THIS IS THE MASTER POINTER
    int *pointer9 {pointer8};                                                                   //THIS IS THE SLAVE POINTER

    std::cout << "Dereferencing pointer8: " << *pointer8 << std::endl;
    std::cout << "Dereferencing pointer9: " << *pointer9 << std::endl;

    if(pointer8 != nullptr){                                                                    //ONLY USE SLAVE POINTERS IF MASTER POINTER IS VALID
        std::cout << "Dereferencing pointer9: " << *pointer9 << std::endl;
    }

    delete pointer8;                                                                            //DELETE AND RESET THE MASTER POINTER
    pointer8 = nullptr;

    if(pointer8 != nullptr){                                                                    //ONLY USE SLAVE POINTERS IF MASTER POINTER IS VALID
        std::cout << "Dereferencing pointer9: " << *pointer9 << std::endl;                      //IN THIS CASE pointer8 IS nullptr, HENCE pointer9 CANNOT BE USED
    }
    
    return 0;

}