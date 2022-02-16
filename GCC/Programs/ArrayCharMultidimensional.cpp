#include<iostream>

int main(int argc, char **argv){
    char char_array[][15]{
        {'V', 'I', 'S', 'H', 'W', 'A', 'S'},
        {'T', 'A', 'N', 'V', 'I'},
        {'S', 'A', 'M', 'S', 'U', 'N', 'G'},
        {'R', 'O', 'B', 'O', 'T', 'I', 'C', 'S'},
        {'M', 'L', ' ', 'A', 'N', 'D', ' ', 'A', 'I'}
    };

    char char_array_literal[][50]{                              //WE CAN ALSO USE STRING LITERALS AS IN CHAR ARRAYS CODE FILE
        "REINFORCEMENT LEARNING",
        "MACHINE LEARNING",
        "ARTIFICIAL INTELLIGENCE",
        "ROBOTICS",
        "MATHEMATICS"
    };

    for(size_t i {}; i < std::size(char_array); ++i){   //we can print directly the values by looping the outer dimension
        std::cout << char_array[i] << std::endl;        //PLEASE NOTE THE HIGHER SIZE DECLARATION OF CHAR ARRAYS AS IN CHAR ARRAYS CODE FILE, AS THE ARRAY SIZE DECLARATION IS
    }                                                   //HIGHER, COMILER WILL AUTO INSERT THE \0 NULL TERMINATION CHARACTER, ELSE CODE WILL PRINT GARBAGE VALUES IF NOT \0

    for(size_t i {}; i < std::size(char_array); ++i){
        for(size_t j {}; j < std::size(char_array[i]); ++j){    //PLEASE DO NOT FORGET TO TARGET THE OUTERDIMENSION[J], ELSE OUTPUT WILL BE UNEXPECTED
            std::cout << char_array[i][j] << std::endl;         //BUT GETTING LOT OF SPACES IN BETWEEN VALUES????? => REMOVE std::endl
        }
    }

    for(size_t i {}; i < std::size(char_array_literal); ++i){   //A FAR EFICIENT WAY TO GET VALUES FROM STRING LITERAL ARRAYS
        std::cout << char_array_literal[i] << std::endl;
    }

    return 0;
}