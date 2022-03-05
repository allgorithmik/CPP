#include<iostream>
#include<string>

int main(int argc, char **argv){
    //std::cout << "Mars!, earthlings love Mars, but Mars is saying, "do not spoil me as well", to earthlings" << std::endl;   //nested double quotes will not work

    //INCLUDING TABS IN OUTPUT FORMATTING
    std::cout << "TO DO TASKS:\n\tBuild Rockets\n\tMake rockets reliable\n\tLaunch more and more rockets\n\tConquer Mars" << std::endl;

    //INCLUDING / IN OUTPUT FORMATTING
    std::cout << "Path: Drive:\\Directory1\\Directory2\\Directory3\\File1" << std::endl;    //must add double \, else single \ will not work and also / will just get printed

    //DIFFERENCES BETWEEN \n AND std::endl;
    // \n JUST INSERTS A NEW LINE AND STARTS PRINTING FROM THE NEW LINE
    //std::endl WILL INSET A NEWLINE AND ALSO FLUSHES THE DATA TO THE OUTPUT TARGET FROM THE BUFFER => std::flush() => std::endl DEGRADES PERFORMANCE, BETTER TO USE \n
    //FOR REPEATED INSERTION OF NEW LINE LINES

    //INCLUDING "" IN OUTPUT FORMATTING \" \"
    std::cout << "Mars said to earthlings, \"please do not pollute and plunder me as well\"" << std::endl;
    std::cout << "\a" << std::endl;                                                         //DOES NOT WORK IN IDE TERMINAL, BUT WORKS IN ACTUAL COMMAND PROMPT (cmd)

    return 0;
}