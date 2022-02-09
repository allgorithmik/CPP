#include<iostream>

const int ellipse {10};                 //Better to declare as global variables
const int hammer {20};
const int screwdriver {30};
const int wrench {40};
const int pliers {50};
const int dummy {};

int main(){
   
int tool {hammer};

    switch (tool){                                                          //Conditions can only be integral or enums(int, long, short, unsigned etc) No strings
        case pliers:{                                                       //curly braces are optional, only case and break are required
            std::cout << "This is a pliers tool" << std::endl;
        }
        break;                                                              //break means the control will exit the switch block, else it will check all other cases?????

        case wrench:{
            std::cout << "This is a wrench tool" << std::endl;
        }
        break;                                                              //BREAK IS VERY IMPORTANT

        case screwdriver:
            std::cout << "This is a screwdriver tool" << std::endl;
        break;

        case hammer:{
            std::cout << "Thisi s a hammer tool" << std::endl;              //removed break, it executes the matching case
        }                                                                   //AS WELL AS ALL THE OTHER BELOW CASES EVEN THOUGH NO CASES MATCH

        case ellipse:{
            std::cout << "This is an ellipse tool" << std::endl;
        }

        default:{
            std::cout << "No tool matches" << std::endl;
        }

        //Grouping of cases is also possible, if any one case matches, that block will be executed
        /*case hammer:
        case ellipse:
        case pliers:{
            std::cout << "This is grouping of cases" << std::endl;
        }
        break;*/

    }

    return 0;
}