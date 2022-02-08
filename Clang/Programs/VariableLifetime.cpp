#include<iostream>

//Three scopes of memory
//Local (Block, automatic)
//Static
//Dynamic

int static_var {50};                    //Ststic scope, lives until program terminates, can be accessed globally

void dummy_func(){
    int var1 {30};                      //Local variables, comes into effect when function is called and destroyed when
    int var2 {40};                      //function goes out of scope, can be accessed within function
    static int var3 {55};               //lives until program exists

}

int main(int argc, char **argv){

    int local_var1 {100};               //Lives until main function exists
    double dynamic_var1 {15.55};        //Dynamic variables can be controlled as to when they go out of scope

    {
        int local_var2 {200};           //Lives until this block exists
        double dynamic_var2 {3.55};     //Dynamic variables can be controlled as to when they go out of scope
    }

    return 0;
}