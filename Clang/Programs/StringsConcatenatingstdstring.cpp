#include<iostream>
#include<string>

int main(int argc, char **argv){
    //CONCATENATING STRINGS USING THE <string> library
    //the + operator
    std::string word1 {"Hello"};
    std::string word2 {"Mars"};
    std::string message = word1 + " my " + word2;           //strings can be concatenated using the + operator and the expression can be assigned to a std::string variable

    std::cout << message << std::endl;
    std::cout << word1 + " my " + word2 << std::endl;       //expression can be directly plugged into the std::cout statement

    //CANNOT CONCATENATE STRING LITERALS => COMPILER ERROR
    //std::string {"Word1" + "Word2"};                      compiler error => this is because internally compiler will convert std::strings into const strings
    //std::string combined = "Word1" + "Word2";             compiler error => this is because internally compiler will convert std::strings into const strings

    //BUT THE FOLLOWING WAYS OF STRING CONCATENATION ARE POSSIBLE
    std::string combined1 {"Word1" "Word2"};                //this is legal C++ code
    std::string combined2 {std::string {"Word1"} + "Word2"};//this is also legal C++ code

    using namespace std::string_literals;                   //WE HAVE TO IMPORT std::string_literals NAMESPACE IN ORDER FOR THE FOLLOWING CODE TO WORK
    std::string combined3 {"Hello"s + " Mars"};             //s SUFFIX IS NECESSARY ELSE ERROR => BUT THIS KIND OF NAMESPACE IMPORT POLLUTES THE NAMESPACE => GLOBAL SCOPE

    //BETTER WAY TO IMPORT NAMESPACES WITHOUT POLLUTING THE NAMESPACE
    {                                                       //THIS APPROACH OF IMPOTING NAMESPACES WILL NOT POLLUTE THE NAMESPACE => LOCAL SCOPE
        using namespace std::string_literals;
        std::string combined4 {"Hello"s + " Mars"};
    }

    //WE CAN str.append() METHOD TO CONCATENATE STRINGS IN C++
    std::cout << "Using the str.append() method:" << std::endl;

    std::string combined5 {"I am a "};
    std::string combined6 {"Martian"};
    std::string combined7 = combined5.append(combined6);

    std::cout << combined7 << std::endl;

    //ANOTHER WAY OF USING str.append()
    std::string combined8 = std::string{"Hello "}.append(std::string{"Martian"});

    std::cout << std::string{"Hello "}.append(std::string{"Martian"});
    std::cout << combined8 << std::endl;

    //MORE WAYS TO CONCATENATE STRINGS USING str.append()
    std::string combined9 {"Hello "};
    std::string combined10 {combined9.append(5, '?')};              //can also use other std::string() methods in combination with str.append() => string(int, 'char')

    std::cout << combined10 << std::endl;

    std::string combined11 {"Mars is our second home"};
    std::string combined12 {"Hello "};
    std::string combined13 {combined12.append(combined11, 5, 10)};  //append a substring of another string => starting with index 5 and taking 10 characters

    //ALSO POSSIBLE TO CONCATENATE CHARACTERS
    std::string combined14 {"Hello"};
    std::string combined15 {"Mars"};
    std::string combined16 = combined14 + ' ' + combined15;                                 //expression or direct plugging into std::cout

    std::cout << combined14 + ' ' + combined15 << std::endl;
    std::cout << combined16 << std::endl;

    //compound operations can also be done
    std::string combined17 {"Hello"};
    combined17 += ',' + ' ';                                                                //COMPLETELY LEGAL C++ CODE => CAN BE DONE!=>BUT BUT BUT, OUTPUT IS NOT 'HELLO, '
    std::cout << combined17 << std::endl;                                                   //COMPILER JUST MAPS THE ASCII TABLE EQUIVALENT OF ',' AND ' '

    (combined17 += ',') += ' ';                                                             //WORKS AS EXPECTED
    std::cout << combined17 << std::endl;

    //ALSO POSSIBLE TO CONCATENATE C-STRINGS
    char message1[] {"Hello"};                                                              //char array
    const char *char_pointer {"Mars"};                                                      //char pointer

    std::cout << "+ char array: " << std::string{"Hola"} + message1 << std::endl;
    std::cout << "+ char pointer: " << char_pointer + std::string{"Hola"} << std::endl;
    std::cout << "Append also Possible!" << std::endl;
    std::cout << "+ char array: " << std::string{"Hola"}.append(message1) << std::endl;
    std::cout << "+ char pointer: " << std::string{"Hola"}.append(char_pointer) << std::endl;

    //CAN ALSO CONCATENATE std::string WITH NUMBERS
    std::string string1 {"Hello"};
    string1 += 55;                                                                          //COMPILER TREATS THE NUMBER AS AN INTEGER AND MAPS IT TO THE ASCII TABLE AND 
    std::cout << string1 << std::endl;                                                      //ASCII TABLE EQUIVALENT CHARACTER IS CONCATENATED

    string1 += std::to_string(55);                                                          //WORKS
    std::cout << string1 << std::endl;                                                      //WORKS

    string1 += std::to_string(55.5f);                                                       //ALSO WORKS
    std::cout << string1 << std::endl;                                                      //ALSO WORKS

    return 0;
    
}