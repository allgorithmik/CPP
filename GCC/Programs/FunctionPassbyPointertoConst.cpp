#include<iostream>

void determine_age(const int *age);                                          //function prototype

int main(int argc, char **argv){

    int age {100};

    std::cout << "age BEFORE calling age_determine(): " << age << std::endl;

    determine_age(&age);                                                    //pass the address of the variable, because the function takes a pointer as its param

    std::cout << "age AFTER calling age_determine(): " << age << std::endl;
    std::cout << "Address of global age is: " << &age << std::endl;

    return 0;
}

void determine_age(const int *age){                                         //function definition
    //++(*age);                                                             //ERROR as this pointer is a const => value NOT modifiable
    std::cout << "Age is: " << *age << std::endl;
    std::cout << "Address of function age is: " << age << std::endl;
}