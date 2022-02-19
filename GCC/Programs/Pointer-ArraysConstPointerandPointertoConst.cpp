#include<iostream>

int main(int argc, char **argv){

    const char *strings []{                 //we can iterate over this array using ranged for loop to get the elements
        "REINFORCEMENT LEARNING",           //THE PROBLEM IS AS THIS strings[] IS CONST, WE CANNOT CHANGE THE ELEMENTS
        "MACHINE LEARNING",
        "ARTIFICIAL INTELLIGENCE",
        "ROBOTICS",
        "MATHEMATICS",
        "COMPUTER VISION",
        "MATERIAL SCIENCES",
        "PHYSICS",
        "CONTROL THEORY",
        "ELECTRONICS"
    };

    for(const char *string: strings){       //using a ange based for loop to print out content of strings[] 
        std::cout << string << std::endl;   //BEFORE REPLACING THE ELEMENTS
    }

    //IF WE NEED TO CHANGE THE ELEMENTS WITHIN A CONST CHAR ARRAY, WE NEED TO FIRST CREATE A NEW CONST CHAR ARRAY AND THE NREPLACE THE OLD ELEMENT WITH NEW ONE
    //*strings[0] = 'H';                    COMPILER ERROR AS NOTED ABOVE
    const char *newString [] {"CYBORGS"};
    strings[0] = newString [0];             //REPLACED AN OLD ELEMENT WITH NEW CONST CHAR ELEMENT => MODIFYING

    std::cout << std::endl;

    for(const char *string: strings){       //using a ange based for loop to print out content of strings[] 
        std::cout << string << std::endl;   //AFTER REPLACING THE ELEMENTS
    }

    return 0;
    
}