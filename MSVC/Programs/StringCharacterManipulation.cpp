#include<iostream>
#include<cctype>

//<cctype> header documentation is: https://en.cppreference.com/w/cpp/header/cctype
//USING VARIOUS FUNCTIONS FROM <cctype> LIBRARY:
//std::isalnum()
//std::isalpha()
//std::isblank()
//std::isupper()
//std::islower()
//std::isdigit()
//std::toupper()
//std::tolower()
//many more functionalities are avaialble => refer document in link CPP Reference

int main(int argc, char **argv){
    //CHECK IF CHARACTER IS ALPHANUMERIC
    char input1 {'A'};
    std::cout << input1 << " is alphanumeric " << std::isalnum(input1) << std::endl;

    char input2 {'#'};
    if(std::isalnum(input2)){
        std::cout << input2 << " is alphanumeric" << std::endl;
    }
    else{
        std::cout << input2 << " is not alphanumeric" << std::endl;
    }

    std::cout << input1 << " is alphanumeric " << std::isalnum(input1) << std::endl;

    //CHECK IF CHARACTER IS ALPHABETIC
    char input3 {'A'};
    std::cout << input3 << " is alphabetic " << std::isalpha(input3) << std::endl;

    if(std::isalpha(input3)){
        std::cout << input3 << " is alphabetic" << std::endl;
    }
    else{
        std::cout << input3 << " is not alphabetic" << std::endl;
    }

    //CHECK FOR BLANKS IN STRING
    char message[] {"This is a message to test blank in a sentence"};
    std::cout << "Checking for blanks in: " << message << std::endl;

    int blank_count {};
    for(size_t i {}; i < std::size(message); ++i){
        if(std::isblank(message[i])){
            std::cout << "Found a blank in message at index: " << i << std::endl;
            ++blank_count;
        }
    }
    std::cout << "Total blanks in message: " << blank_count << std::endl;

    //CHECK FOR UPPERCASE / LOWERCASE CHARACTERS IN A STRING
    char sentence[] {"AbCdEfGhIjKlMnOpQrStUvWxYz\0"};
    int upper {};
    int lower {};

    for(size_t i {}; i < std::size(sentence); ++i){
        if(std::isupper(sentence[i])){
            std::cout << "Uppercase letters are: " << sentence[i] << std::endl;
            ++upper;
        }
        else{
            std::cout << "Lowercase letters are: " << sentence[i] << std::endl;
            ++lower;
        }
    }

    std::cout << "Total uppercase letters: " << upper << std::endl;
    std::cout << "Total lowercase letters: " << lower << std::endl;

    //CHECKING IF A CHARECTER IS A DIGIT
    char numbers[] {"A1B2C3D4E5F6G7H8I9J10K11L12M13N14O15P16Q17R18S19T20U21V22W23X24Y25Z26"};
    int num_count {};
    for(size_t i {}; i < std::size(numbers); ++i){                                              //range based for loop giving wrong output, hence normal for loop
        if(std::isdigit(numbers[i])){
            std::cout << "Number at index: " << i << std::endl;
            ++num_count;
        }
    }
    std::cout << "Total Digits found: " << num_count << std::endl;

    //CONVERTING UPPERCASE => LOWERCASE & LOWERCASE => UPPERCASE
    char convert_sentence[] {"The Cases Will Be Converted In This Sentence\0"};
    char output_sentence[std::size(convert_sentence)];
    for(size_t i {}; i < std::size(convert_sentence); ++i){
        if(std::isupper(convert_sentence[i])){
            output_sentence[i] = std::tolower(convert_sentence[i]);                             //WORK ON LOGIC, HAD GOT LOGIC WRONG
        }
        else{
            output_sentence[i] = std::toupper(convert_sentence[i]);                             //WORK ON LOGIC, HAD GOT LOGIC WRONG
        }
    }
    std::cout << convert_sentence << std::endl;
    std::cout << output_sentence << std::endl;

    return 0;
}