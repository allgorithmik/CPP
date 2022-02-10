#include<iostream>

int main(int argc, char **argv){
    //Ternary expression => result = (condition) ? option1 : option2;
    //The above statement in equivalent to
    /*
    if(condition){
        option1
    }
    else{
        option2
    }
    */
    int a {10};
    int b {20};
    int max = (a > b) ? a : b;                                  //both options a and b must be of same type

    std::cout << "The Maximum number is: " << max << std::endl;

    //Ternary initialization                                    //What we initialize here will determine the option selected in ternary expression
    bool fast = false;                                          //based on the condition, the options below will be picked up
    int speed {fast ? 500 : 350};                               //In this case, 350 will be picked as the above condition is set to false

    std::cout << "The speed is: " << speed << std::endl;
    return 0;
}