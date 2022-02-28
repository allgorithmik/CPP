#include<iostream>
#include<string>

int main(int argc, char **argv){
    std::string str1 {"Hello Mars"};
    std::cout << "Size of str1: " << str1.size() << std::endl;  //std::string has a function str.size() which returns the number of characters in a string excluding null char

    //accessing individual characters using index method via for loop
    for(size_t i {}; i < str1.size(); ++i){
        std::cout << "Character " << i << " " << str1[i] << std::endl;
    }

    //accessing individual characters using index method via range based for loop
    for(char value: str1){                                      //char must be the datatype not int, as the iterator directly points to the values inside the string
        std::cout << "Character " << value << std::endl;        //and str[i] index notation is NOT necessary as the iterator directly hold the value
    }

    //accessing individual characters using index method via for loop using str.at() method
    for(size_t i {}; i < str1.size(); ++i){
        std::cout << "Character " << str1.at(i) << std::endl;
    }

    //modifying values in std::string using index notation and str.at()
    std::string str2 {"Modifying value"};
    str2[0] = 'B';
    str2.at(10) = 'B';

    std::cout << "Modified str2: " << str2 << std::endl;

    //front() and back() copying
    std::string str3 {"Rivendell is very nice"};
    char front_char = str3.front();                                                             //str.front() will return the first character of a string
    char back_char = str3.back();                                                               //str.back() will return the last character of a string

    std::cout << "Front: " << front_char << std::endl;
    std::cout << "Back: " << back_char << std::endl;

    //modifying the values in copies will not affect the main string
    front_char = '.';                                                                           //only the copy of the original string will be modified
    back_char = '=';                                                                            //only the copy of the original string will be modified

    std::cout << "Front: " << front_char << std::endl;
    std::cout << "Back: " << back_char << std::endl;
    std::cout << str3 << std::endl;                                                             //original string will remain the same

    //if need to modify the original value, need to use references
    char &front_char_ref {front_char};
    char &back_char_ref {back_char};

    front_char_ref = 'A';
    back_char_ref = 'B';

    std::cout << "Front reference: " << front_char_ref << std::endl;
    std::cout << "back reference: " << back_char_ref << std::endl;

    //checking if original string has changed
    std::cout << "Front value after changing reference: " << front_char << std::endl;           //original value has changed => references as we saw before
    std::cout << "Back value after changing reference: " << back_char << std::endl;             //original value has changed => references as we saw before

    //can aslo use str.front() and str.back() calls to modify values directly
    str3.front() = 'Z';                                                                         //directly we can modify the values using front() and back()
    str3.back() = 'A';
    std::cout << "str3 after modifying front() and back() directly: " << str3 << std::endl;

    //can use const references if we do not want original string to be modified using references
    const char const_ref_front = str3.front();
    const char const_ref_back = str3.back();

    //const_ref_front = 'X';                                                                    //ERROR => trying to change a const reference
    //const_ref_back = 'Z';                                                                     //ERROR => trying to change a const reference

    //accessing a pointer of the underlying C-String of a std::string using str.c_str
    std::string str4 {"This is the string for pointer"};
    const char *char_pointer = str4.c_str();                                                    //must be declared as const else error => underlying is a const string array

    std::cout << "Dereferencing: " << *char_pointer << std::endl;                               //only the first character is printed
    std::cout << char_pointer << std::endl;                                                     //entire string is printed

    //using the str.data()
    std::string str5 {"Hello Mars"};
    char *pointer_data = str5.data();

    std::cout << "Using data() to access the characters in str5: " << pointer_data << std::endl;

    //using str.data() to modify characters in string
    pointer_data[0] = 'B';                                                                      //changes the original string as well
    std::cout << "Using data() to modify the characters in str5: " << pointer_data << std::endl;

    return 0;
}