#include<iostream>

void determine_age(int *age);                                               //function prototype

int main(int argc, char **argv){
    int age {100};

    std::cout << "age BEFORE calling determine_age(): " << age << std::endl;
    
    //WHILE DECLARING FUNCTION => PASS A POINTER AS PARAM. WHILE CALLING A FUNCTION => PASS THE ADDRESS OF THE VARIABLE (TYPE COMPATIBLE) AS THE ARGUMENT
    //WHILE PERFORMING OPERATIONS WITHIN A FUNCTION => USE THE DEREFERENCED POINTER TO ALL OPERATIONS
    determine_age(&age);                                                    //pass the address of the variable, because the function takes a pointer as its param
    std::cout << "age AFTER calling determine_age(): " << age << std::endl; //as the param is passed as a pointer, the value pointed by the address is changed => NO COPY    

    std::cout << "Address of global age: " << &age << std::endl;            //the address of both function variable and global variable will be the same as we are passing
    return 0;                                                               //the SAME address via pointer to the variable
}

void determine_age(int *age){                                               //function definition
    ++(*age);                                                               //if modifying a VALUE represented by a pointer, a dereferenced pointer must be used to perform
    std::cout << "Age is: " << *age << std::endl;                           //operations
    std::cout << "Address of function age is: " << age << std::endl;        //when querying for address of a pointer, just use the pointer name => NOT &pointer_identifier
}