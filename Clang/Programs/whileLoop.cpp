#include<iostream>

int main(int argc, char **argv){
    /*
    while loop syntax
    while(condition){
        loop body
        condition increment/decrement => base condition
    }
    */
    const int limit {10};
    size_t i {};                                                        //iterator
    while(i < limit){                                                   //only while condition is true control enters loop body, exits once condition is false
        std::cout << "while loop iteration number: " << i << std::endl; //this is same for ALL loop types => for, while, do while
        ++i;                                                            //increment/decrement => base condition
    }
    return 0;
}