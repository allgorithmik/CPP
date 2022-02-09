#include<iostream>

const int ellipse {10};                 //Better to declare as global variables
const int hammer {20};
const int screwdriver {30};
const int wrench {40};
const int pliers {50};

int main(int argc, char **argv){

    int tool {ellipse};

    if (tool == ellipse){
        std::cout << "This is an ellipse tool" << std::endl;
    }
    else if (tool == hammer){
        std::cout << "This is a hammer tool" << std::endl;
    }
    else if (tool == screwdriver){
        std::cout << "This is a screwdriver tool" << std::endl;
    }
    else if (tool == wrench){
        std::cout << "This is a wrench tool" << std::endl;
    }
    else if (tool == pliers){
        std::cout << "This is a pliers tool" << std::endl;
    }

    std::cout << "Code ahead gets executed" << std::endl;                   //after if else block gets executed the contol keeps executing further

    return 0;
}