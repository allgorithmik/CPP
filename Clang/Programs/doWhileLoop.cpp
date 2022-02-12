#include<iostream>

int main(int argc, char **argv){

    //do while loop will run the loop body at least once
    //do while loop will execute the body first and then check for condition
    /*
    do while syntax
    do{
        loop body
        iterator => increment/decrement
    }(condition);
    */
    const size_t COUNT {1000};
    size_t i {};

    //do while loop will run the loop body at least once
    //do while loop will execute the body first and then check for condition

    do{                                                                 //begin do while loop
        std::cout << "This is do while iteration: " << i << std::endl;  //loop body
        ++i;                                                            //increment/decrement => iterator
    }while(i < COUNT);                                                  //condition

    std::cout << "Loop completed!" << std::endl;

    return 0;
}