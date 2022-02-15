#include<iostream>

int main(int argc, char **argv){                                        //normal declaration of a char array, BUT, THIS IS NOT A C STRING => IT HAS NO NULL TERMINATION \0
    char array[] {'H', 'E', 'L', 'L', 'O'};                             //CHARACTER => \0, IT IS INSERTED AT THE END OF THE STRING, ONLY THEN STD::COUT OF CHAR ARRAY
                                                                        //WITHOUT LOOPS IS POSSIBLE

    char array1[6] {'H', 'E', 'L', 'L', 'O'};                           //IF ARRAY SIZE IS GREATER THAN ACTUAL VALUES, NULL TERMINATION CHARACTER WILL BE APPENDED BY COMPILER
    char array2[] {'H', 'E', 'L', 'L', 'O', '\n'};                      //IF WE MANUALLY INSERT \n AT END OF ARRAY, NULL TERMINATION CHARACTER WILL NOT BE APPENDED
    char array3[] {"Hello"};                                            //IF THE ARRAY VALUE IS A SINGLE STRING, NULL TERMINATION CHARACTER WILL NOT BE APPENDED
    char array4[] {"Hello World!"};                                     //IF THE ARRAY VALUE IS A STRING WITH SPACE, NULL TERMINATION CHARACTER WILL NOT BE APPENDED**
    char array3[] {"Hello"};                                            //THIS IS A STRING LITERAL, COMPILER WILL AUTO APPEND \0 AT THE END TO STIRNG
    char array4[] {"Hello World!"};                                     //STRING LITERALS CAN ALSO HAVE SPACES, STRING LITERALS DO NOT NEED LOOPS TO PRINT VALUES
    char array5[] = {array1[1] = 'a'};                                  //Will not work, as its value is only array[1]
    char array6[] {'H', 'E', 'L', 'L', 'O', '\0'};                      //THIS IS A C STRING NOW AS ITS TERMINATED WITH \0, NOW POSSIBLE TO PRINT WITHOUT LOOPS
    array1[1] = 'a';
    for(size_t c: array1){
        std::cout << "The array contains: " << c << std::endl;
    }
    std::cout << "Without loops: " << array << std::endl;               //=> HELLOO, instead of HELLO as the output gets appended with NULL TERMINATION CHARACTER \0
    std::cout << "Greater Size: " << array1 << std::endl;               //=> HELLO, IF ARRAY SIZE IS GREATER THAN ACTUAL VALUES, THE ABOVE PROBLEM WILL NOT OCCUR
    std::cout << "With new line: " << array2 << std::endl;              //=> HELLO, IF WE MANUALLY INSERT \n AT THE END OF ARRAY, THE ABOVE PROBLEM WILL NOT OCCUR
    std::cout << "As a single string " << array3 << std::endl;          //IF THE ARRAY VALUE IS A SINGLE STRING, THE ABOVE PROBLEM WILL NOT OCCUR
    std::cout << "As single string with space " << array4 << std::endl; //IF THE ARRAY VALUE IS A STRING WITH SPACE, THE ABOVE PROBLEM WILL NOT OCCUR

    for(auto c: array1){                                                //HaLLO 
        std::cout << c;                                                 //There is a far easier way to achieve the same output as above 
    }

    //easier way to achieve the same output as above
    std::cout << std:: endl << "message is: " << array2;                //C++ supports direct printing of char arrays, provided its terminated by \0 => STRING LITERAL
}