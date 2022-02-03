#include <iostream>

const int value1 {10};
constexpr int value2 {55};

int value3 {100};

constinit int age1 = 50;                            //CONSTINIT CANNOT BE USED IN MAIN, THE MAIN GOAL OF CONSTINIT IS TO SOLVE GLOBAL INITS BEFORE MAIN GETS EXECUTED
const constinit int age2 {value1};                  //const and constinit can be combined

//constinit int age2 {age1};                        //As age is not const, cannotbe combined with constinit

//constinit int age3 {value3};                      //value3 is evaluated at runtime, hence cannot be used on constinit

//contexpr constinit int some_value {100};          //constexpr and continit cannot be combined, as they both essentially mean the same. only one at a time can be used.
                                                    //constinit values can be changed, but they can be of const as well     



int main(int argc, char **argv){                    //CONSTINIT IS A C++20 FEATURE

    //constinit int somevalue {100};                //constinit cannot be used in main thread
                            
    return 0;

}