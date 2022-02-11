#include<iostream>

int main(int argc, char **argv){
    /*
    for loop syntax:
    for (unisgned int initializer(iterator); condition; increment/decrement){
        loop body
        code to perform repetitively

    for (unisgned int initializer; condition; increment/decrement)
        loop body => if there is only one statement in loop body, we can leave out the curly braces

    iterator can live outside the loop
    size_t j {} => but now this j will be available outside the scope of loop and within the scope depending on where its declared
    for(j; condition; increment/decrement)

    size_t j {}
    for(; condition; incement/decrement) => we can completely leave out the iterator provided its declared before usage

    its good practice to declate the condition limit outside the loop, as its enough to change at only one place if it needs modification
    const size_t j {10}
    for (int i {}, i <= j; increment/decrement)
    */
    //components of any loop
    //iterator
    //initialization
    //Test condition
    //increment/decrement
    //loop body

    for(int i {}; i < 10; ++i){                                                                         //normal for loop with iterator, condition and increment/decrement
        std::cout << "I really Love C++, normal for loop" << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;

    size_t i {};                                                                                        //for loop with iterator declared outside
    for(; i < 10; ++i){                                                                                 //size_t is recommended in std library to use as iterator
        std::cout << "I really Love C++, for loop with iterator declared outside" << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;

    for(int i {}; i < 10; ++i)                                                                          //when iterator declared outside, loops did not execute?????                                                                          
        std::cout << "I really Love C++, with a single statement AND WITHOUT curly braces" << std::endl;//for loop with a single statement in loop body AND WITHOUT curly braces

    std::cout << "----------------------------------------" << std::endl;

    const int value {10};                                                                               //for loop with condition limit declared outside as a good practice
    for(int i {}; i < value; ++i){
        std::cout << "I really Love C++, with the condition limit declared outside as a good practice" << std::endl;
    }

    return 0;
}