#include<iostream>

void age_determine(int age);                                                //function prototype

int main(int argc, char **argv){

    int age {10};

    std::cout << "age BEFORE calling age_determine(): " << age << std::endl;//all arguments passed to a function are COPIES of the variable, and all arguments passed to a   
    age_determine(age);                                                     //functon are LOCAL COPIES of the vaiable TO THAT function, hence, any modifications to the
    std::cout << "age AFTER calling age_determine(): " << age << std::endl; //variable WITHIN a function WILL NOT affect the original variable

    //another way to prove that function parameters are COPIES of variables is thier address: => same variable means they must reside in the same address, COPY means
    //the variable copy must reside in another address

    std::cout << "Address of global age: " << &age << std::endl;            //DIFFERENT THAN FUNCTION AGE

    return 0;
}

void age_determine(int age){
    ++age;
    std::cout << "Your age is: " << age << std::endl;                       //function definition
    std::cout << "Address of function age: " << &age << std::endl;          //DIFFERENT THAN GLOBAL AGE
}