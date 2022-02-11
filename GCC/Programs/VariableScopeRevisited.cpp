#include <iostream>

int global_val {50};

int main(int argc, char **argv){
    bool green {false};

    if (green){
        int car_count {40};
        std::cout << "The car count is: " << car_count << " and light is green" << std::endl;
        std::cout << "Global variable is available here: " << global_val << std::endl;          //global variable is available everywhere in program 
    }
    else{
        //car_count ++ ;                                                                        //car_count is not available in this else scope
        std::cout << "Car is not moving as its not green" << std::endl;                         //as its local to if scope
        std::cout << "Global variable is available here as well: " << global_val << std::endl;
    }
    return 0;
}