#include<iostream>

//SOMETIMES ITS BETTER TO SPLIT THE FUNCTION INTO ITS HEADER AND BODY TO KEEP THE CODE FOR EACH IN DIFFERENT PLACES

//A FUNCTION PROTOTYPE / DECLARATION
//A FUNCTION PROTOTYPE CAN BE USED / CALLED ANYWHERE IN THE CODE BEFORE ITS DEFINITION IS PROVIDED => BUT A MUST DURING LINKER PHASE
//A FUNCTION'S PROTOTYPE MUST EXIST BEFORE THAT FUNCTION CAN BE CALLED / USED, ELSE COMPILATION FAILS
int max_number(int a, int b);                                       //FUNCTION PROTOTYPE
int min_number(int, int);                                           //A LEGAL C++ FUNCTION PROTOTYPE => FUNCTION PROTOTYPES DO NOT REQUIRE PARAM NAMES, ONLY DATATYPES

int main(int argc, char **argv){
    int result {max_number(10, 20)};
    std::cout << "max_number result is: " << result << std::endl;
    //std::cout << "min_number result is: " << min_number(10, 20) << std::endl; //ERROR AS ONLY FUNCTION PROTOTYPE EXISTS BUT NO FUNCTION DEFINTION => LINKER FAILS

    return 0;
    
}

//A FUNCTION DEFINITION => A FUNCTION DEFINITION CAN BE IMPLEMENTED AFTER ITS PROTOTYPE => DURING COMPILE TIME, THE COMPILER ONLY LOOKS FOR THE FUNCTION PROTOTYPE,
//ITS ONLY DURING THE LINKING PHASE THE LINKER NEEDS THE FULL FUNCTION DEFINITION / BODY OF A FUNCTION
int max_number(int a, int b){                                       //FUNCTION DEFINITION
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}