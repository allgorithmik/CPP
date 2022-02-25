#include<iostream>

int main(int argc, char **argv){
    
    int values [] {1,2,3,4,5,6,7,8,9,10};                   //normal array of ints
    for(size_t i: values){                                  //normal range based for loop
        std::cout << "Value is: " << i << std::endl;        //i is local and whatever changes we make will only be limited within this for loop block
    }

    for(auto &value: values){                               //using references will modiy the values as per the expression in original array
        value = value * 10;                                 //modify the values and assign it back to it => expression was wrong before
    }

    for(auto j: values){                                    //changes now reflecting in original array because of references
        std::cout << "New: " << j << std::endl;
    }

    return 0;
}