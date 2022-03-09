#include<iostream>

void age_determine(const int &age);                                                 //function prototype

int main(int argc, char **argv){
    int age {100};

    std::cout << "Value of global age BEFORE age_determine(): " << age << std::endl;

    age_determine(age);                                                             //<variable_name>is enough as compiler will automatically take the reference as param

    std::cout << "Value of global age AFTER age_determine(): " << age << std::endl; //value wiil remain the same as its not modifiable becaue its const value

    return 0;
}

void age_determine(const int &age){                                                 //function definition
    //++age;                                                                        //ERROR! as the reference variable is a const => original variable cannot be modified
    std::cout << "Value of function age: " << age << std::endl;
}