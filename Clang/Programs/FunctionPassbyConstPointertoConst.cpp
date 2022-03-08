#include<iostream>

void age_determine(const int *const age);                                   //function prototype

int global_var {100};

int main(int argc, char **argv){

    int age {100};

    std::cout << "age BEFORE calling age_determine(): " << age << std::endl;

    age_determine(&age);

    std::cout << "age AFTER calling age_determine(): " << age << std::endl;

    std::cout << "Address of age: " << &age << std::endl;

    return 0;
}

void age_determine(const int *const age){                                   //function definition

    //++(*age)                                                              //ERROR => as pointer is pointing to a const value, it CANNOT be modified
    std::cout << "Value of Function age is: " << *age << std::endl;
    std::cout << "Address of Function age is: " << age << std::endl;
    //age = &global_var;                                                    //ERROR => as this is a const pointer it CANNOT point to any other location in memory
    
}