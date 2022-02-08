#include<iostream>

int main(int argc, char **argv){

    int var1 {30};
    int var2 {40};
    bool result {var1 < var2};

    bool red {false};
    bool green {true};
    bool yellow {false};
    bool police_stop {true};

    //OR

    //bool result = (var1 < var2);                                           //Functional assignment also possible

    std::cout << std::boolalpha;

    std::cout << "Free standing if statement" << std::endl;

    if (result){
        std::cout << var1 << " is less than " << var2 << std::endl;
    }

    if (!result){
        std::cout << var1 << " is not less than " << var2 << std::endl;
    }

    if (var1 < var2){                                                   //Can directly use expressions which evaluate to boolean
        std::cout << var1 << " is less than " << var2 << std::endl;
    }

    //Can also be re-written in many different ways as shown below

    /*if (result == true){
        std::cout << var1 << " is less than " << var2 << std::endl;
    }

    if ((result != true) || (!(result == true))){
        std::cout << var1 << " is less than " << var2 << std::endl;
    }*/

    if (green){
        std::cout << "GO!" << std::endl;
    }
    if (red){
        std::cout << "STOP!" << std::endl;
    }
    if (yellow){
        std::cout << "Slow ahead" << std::endl;
    }

    if (green && police_stop){                      //logical operator with if statement
        std::cout << "GO!" << std::endl;
    }

    if (green){                                     //Nested if statements wuth else
        if (police_stop){
            std::cout << "GO!" << std::endl;
        }
        else{
            std::cout << "STOP!" << std::endl;
        }
    }
    return 0;
}