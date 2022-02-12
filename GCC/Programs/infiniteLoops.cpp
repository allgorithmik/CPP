#include<iostream>

int main(int argc, char **argv){                        //INFINITE LOOPS OCCUR DUE TO INCORRECT BASE CONDITIONS
    size_t i {};

    //infinite for loop
    for(; true; ++i){                                                       //replace condition with boolean true
        std::cout << "Infinite for loop" << i << std::endl;
    }

    //another way of infinite for loop
    for(; ; ++i){                                                           //completely ommit the condition
        std::cout << "Infinite for loop-another variant!" << i << std::endl;
    }

    //infinite while loop
    while(true){
        std::cout << "Infinite while loop" << i << std::endl;               //no i for while separately, takes the global i
    }

    //infinite do while loop
    do{
        std::cout << "Infinite do while loop" << i << std::endl;            //no i for do while separately, takes the global i
    }while(true);

    return 0;
}