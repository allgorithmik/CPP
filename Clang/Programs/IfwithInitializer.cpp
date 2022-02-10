#include<iostream>

int main(int argc, char **argv){
    //if with initializer
    bool go = true;                                         //functional () or uniform {} initializer
    if(int high_speed {30};go){                             //high_speed variable is only available only within the if scope
        if(high_speed > 5){                                 //go also is taken into account, and this 'go' condition can be removed 
            std::cout << "Please slow down" << std::endl;   //go acts like a multiple conditions of if block
        }
        else{
            std::cout << "All good" << std::endl;
        }
    }
    else{
        std::cout << "This is highspeed" << std::endl;
    }
    return 0;
}