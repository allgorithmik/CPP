#include<iostream>

const int ellipse {10};                                                     //Better to declare as global variables
const int hammer {20};
const int screwdriver {30};
const int wrench {40};
const int pliers {50};

int main(int argc, char **argv){
    
    bool condition {true};                                                  //switch only accepts integral or enum types
    int tool {ellipse};

    switch(double value1 {10.55}; tool){
        case pliers:{                                                       
            std::cout << "This is a pliers tool " << value1 << std::endl;   //value1 variable can be accessed anywhere in switch block, its local to switch block
        }
        break;                                                              

        case wrench:{
            std::cout << "This is a wrench tool " << value1 << std::endl;
        }
        break;                                                              

        case screwdriver:{
            std::cout << "This is a screwdriver tool " << value1 << std::endl;
        }
        break;

        case hammer:{
            std::cout << "Thisi s a hammer tool " << value1 << std::endl;              
        }
        break;

        case ellipse:{
            std::cout << "This is an ellipse tool " << value1 << std::endl;
        }
        break;

        default:{
            std::cout << "No tool matches" << std::endl;
        }
    }

    return 0;
}