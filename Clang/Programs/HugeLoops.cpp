#include<iostream>

int main(int argc, char **argv){

    const int COUNT {1000};
    size_t i {};

    //while loop
    while(i < COUNT){
        std::cout << "While Loop iteration number: " << i << std::endl; //std::cout will significantly slow down the loops
        ++i;                                                            //without std::cout loops are much much faster
    }

    //for loop
    for(int i {}; i < COUNT; ++i){
        std::cout << "For loop iteration: " << i << std::endl;          //std::cout will significantly slow down the loops
    }                                                                   //without std::cout loops are much much faster
    return 0;
}