#include<iostream>
#include<cstring>

int main(int argc, char **argv){
    //<cstring> documentation link: https://en.cppreference.com/w/cpp/header/cstring
    //USING VARIOUS FUNCTIONS FROM <cstring> LIBRARY:
    //std::strcat()
    //std::strncat()
    //std::strcpy()
    //std::strncpy()

    //std::strcat()
    char first[] {"Hello \0"};
    char second[] {"CPP Language\0"};
    std::strcat(first, second);                                     //when two strings are concatenated using std::strcat(), the second string will be APPENDED TO THE FIRST
    std::cout << "Concatenated string is: " << first << std::endl;  //STRING, hence the array of first string must be sufficiently big => hence this is compiler dependent

    char *first1 = new char[] {'L', 'O', 'R', 'D', '\0'};                                               //DO NOT FORGET NULL CHARACTER notice this is  DYNAMIC ARRAY
    char *second1 = new char[] {' ', 'O', 'F', ' ', 'T', 'H', 'E', ' ', 'R', 'I', 'N', 'G', 'S', '\0'}; //DO NOT FORGET NULL CHARACTER notice this is DYNAMIC ARRAY
    std::strcat(first1, second1);
    std::cout << "Concatenated string: " << std::endl;
    std::cout << first1 << std::endl;

    //std::strncat()                                                                                    //concatenates only the specified size of characters
    std::strncat(first, second, 2);
    std::cout << "Concatenated string using std::strncat: " << first << std::endl;

    //std::strcpy()
    const char *copy1 = "This is the destination";
    char *copy2 = new char[std::strlen(copy1) + 1];

    std::strcpy(copy2, copy1);                                                                          //copies the contents of SECOND ARGUMENT to FIRST ARGUMENT
    std::cout << copy2 << std::endl;

    //std::strncpy()
    const char *third = "std::strncpy with number of elements to copy";                                 //COPIES THE SPECIFIED NUMBER OF CHARACTERS INTO THE SECOND
    char fourth[] {'T', 'O', ' ', 'C', 'O', 'P', 'Y', '\0'};                                            //ARGUMENT BY OVERRIDING THE CHARACTERS IN SECOND ARGUMENT BY THE
    std::strncpy(fourth, third, 5);                                                                     //EXACT NUMBER OF SPECIFIED SIZE OF ELEMENTS => SECOND ARGUMENT
    std::cout << "std::strncpy copied string: " << fourth << std::endl;                                 //LOSES SOME VALUES=>REPLACED BY FIRST ARGUMENTS SPECIFIED ELEMENTS
    return 0;
}