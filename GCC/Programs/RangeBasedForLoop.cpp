#include<iostream>

int main(int argc, char **argv){

    int range_of_values [] {1,2,3,4,5,6,7,8,9,10};

    for (int value : range_of_values){                                                      //range based for loop
        std::cout << value << " : is the value in range_of_values" << std::endl; 
    }

    for(auto value : {1,2,3,4,5,6,7,8,9,10}){                                               //range based for loop with auto type detection and initialization within for loop
        std::cout << value << " : is the value in range_of_values" << std::endl;            //this value variable is scoped only within this for loop, cannot be accessed outside
    }

    //normal for loop with same functionality
    std::cout << "Using normal style for loop to achieve same functionality" << std::endl;
    for(int i {}; i < 10; ++i)                                                              //please note, no curly braces for  this for loop as its body has only one statement
        std::cout << range_of_values[i] << " : is the value in range_of_values" << std::endl;

    return 0;
}