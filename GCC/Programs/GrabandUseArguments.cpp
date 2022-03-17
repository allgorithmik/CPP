#include<iostream>

//WE CAN PASS ARGS TO main(int argc, char** argv) => int argc -> NUMBER OF ARGS, char** argv -> MEANS POINTER TO POINTER OF CHARS HOLDING ACTUAL ARG VALUES
//SYNTAX: => command_prompt> .\main.exe option1 option2 option3.....option n

int main(int argc, char **argv){    //=>ALTERNATE SYNTAX IS: int main(int argc, char* argv[]){} => THIS IS ALSO A LEGAL C++ SYNTAX

    std::cout << "We have " << argc << " number of arguments" << std::endl;

    //POINTS TO NOTE WHEN EXECUTING THE BELOW CODE BLOCK:
    //0th arg is the current directory, hence there is always atleast 1 arg and that is the program name
    //how many ever we pass the params / args during executing the program via command prompt, it keeps storing the values in the array and returns them when needed
    for(size_t i {}; i < argc; ++i){
        std::cout << "Arg " << i << " is " << argv[i] << std::endl;
    }

    return 0;
    
}