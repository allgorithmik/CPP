#include<iostream>

int main(int argc, char **argv){            //RANGE BASED LOOP WILL ALWAYS INCREMENT AS WE DO NOT HAVE CONTROL OVER ITERATOR
    //decementing for loop                  ITS RECOMMENDED TO ALWAYS CHECK FOR RANGE OF A TYPE BEFORE USING THAT TYPE AS ITERATOR
    const size_t COUNT {};                  //ALWAYS REMEMBER ABOUT OVERFLOW AND UNDERFLOW WHILE USING ITERATORS IN LOOPS
    size_t i {100};
    for(; i > COUNT; --i){                                                              //why not working for i >= 0 but works for i > 0
        std::cout << "This is decrementing for loop with iteration: " << i << std::endl;//the above problem is because size_t is an unsigned int, hence i >= 0 WILL NOT WORK
    }                                                                                   //BE VERY CAREFUL ABOUT TYPES, IT WILL CAUSE TO UNDERFLOW, THE SAME HAPPENED ABOVE

    //decrementing while loop
    while(i > COUNT){                                                                       //why not working for i >= 0 but works for i > 0?????
        std::cout << "This is decrementing while loop with iteration: " << i << std::endl;  //the above problem is because size_t is an unsigned int, hence i >= 0
        --i;                                                                                //WILL NOT WORK
    }                                                                                       //BE VERY CAREFUL ABOUT TYPES, IT WILL CAUSE TO UNDERFLOW, THE SAME HAPPENED ABOVE
    std::cout << "While loop done" << std::endl;

    //decrementing do while loop
    size_t i1 {100};
    const size_t COUNT1 {};                 //BE VERY CAREFUL ABOUT SILLY MISTAKES => TYPED i INSTEAD OF i1 BELOW
    do{                                                                                         //why not working for i >= 0 but works for i > 0?????
        std::cout << "This is decrementing do while loop with iteration: " << i1 << std::endl;  //the above problem is because size_t is an unsigned int, hence i >= 0
        --i1;                                                                                   //WILL NOT WORK
    }while(i1 > 0);                                                                             //BE VERY CAREFUL ABOUT TYPES, IT WILL CAUSE TO UNDERFLOW,
    std::cout << "Do While loop done" << std::endl;                                             //THE SAME HAPPENED ABOVE
    
    return 0;
}