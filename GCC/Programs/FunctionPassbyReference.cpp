#include<iostream>

void determine_age(int &age);                                                           //function prototype

int main(int argc, char **argv){
    int age{100};

    std::cout << "Value of global age BEFORE determine_age(): " << age << std::endl;

    std::cout << "Address of global age BEFORE determine_age(): " << &age << std::endl;

    //as a reference variable will point to the SAME address as its original variable, any modifications to a reference WILL affect the ORIGINAL variable
    determine_age(age);                                                                 //&<variable_name>is enough as compiler will automatically take the reference as param

    std::cout << "Value of global age AFTER determine_age(): " << age << std::endl;     //value of original(global) variable will be modified via its reference variable
    
    std::cout << "Address of global age AFTER determine_age(): " << &age << std::endl;  //same address as original(global) variable as its reference variable
    
    return 0;
}
void determine_age(int &age){                                                           //function definition
    ++age;                                                                              //no need to dereference the variable as in pointers => directly perform modifications
    std::cout << "The value of function age: " << age << std::endl;                     //value of ORIGINAL variable WILL be modified as it references the original variable 
    std::cout << "The address of function age is: " << &age << std::endl;               //references point to the same address as their original variables => same address
}