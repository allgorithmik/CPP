#include<iostream>
#include<cstring>

int main(int argc, char **argv){
    //<cstring> documentation link: https://en.cppreference.com/w/cpp/header/cstring
    //USING VARIOUS FUNCTIONS FROM <cstring> LIBRARY:
    //std::strlen()
    //std::strcmp()
    //std::strncmp()
    //std::strchr()
    //std::strrchr()

    //std::strlen => STRING LENGTH
    const char message1[] {"Hello, This is C++, its a very powerful programming language"};
    const char *message1_pointer {"This is a pointer to a string"};                                                 //ARRAYS DECAY INTO A POINTER WHEN DECLARED AS const char*

    //std::strlen()
    std::cout << "Length of message1: " << std::strlen(message1) << std::endl;                                          //std::strlen() ignores the null character => \0
    std::cout << "Length of message1_pointer: " << std::strlen(message1_pointer) << std::endl;                      //std::strlen() works even there there is pointer decay

    //normal sizeof()
    std::cout << "Length of message1 with sizeof(): " << sizeof(message1) << std::endl;
    std::cout << "Length of message1_pointer with sizeof(): " << sizeof(message1_pointer) << std::endl;                 //returns the size of the pointer

    //std::strcmp()
    //Returns negative if LHS(LEFT HAND STRING) appears before RHS(RIGHT HAND STRING) in lexicographical order
    //Returns 0 if LHS and RHS are equal
    //Returns positive if LHS appears after RHS in lexicographical order
    const char *message2 {"This is a string to compare"};
    const char *message2_compare {"This is another string to compare"};

    std::cout << "String comparison using std::strcmp(): " << std::strcmp(message2, message2_compare) << std::endl;     //Returns -1 => Lexicographically BEFORE case

    message2 = "BBBBB";
    message2_compare = "AAAAA";
    std::cout << "String comparison using std::strcmp(): " << std::strcmp(message2, message2_compare) << std::endl;     //Returns 1 => Lexicographically AFTER case

    message2 = "Bangalore";
    message2_compare = "Bangalore";
    std::cout << "String comparison using std::strcmp(): " << std::strcmp(message2, message2_compare) << std::endl;     //Returns 0 => Lexicographically EQUAL case

    //std::strncmp()
    //compares the characters of only the specified size/length
    //Returns negative if LHS(LEFT HAND STRING) appears before RHS(RIGHT HAND STRING) in lexicographical order
    //Returns 0 if LHS and RHS are equal
    //Returns positive if LHS appears after RHS in lexicographical order
    size_t n {5};                                                                                                       //number/size of first n characters to compare

    const char *message3 {"AAAAAHelloWorld"};
    const char *message3_compare {"AAAAAWorldHello"};

    std::cout << "String comparison using std::strncmp(): " << std::strncmp(message3, message3_compare, n) << std::endl;//Returns 0 => Lexicographically EQUAL case

    message3 = "BBBBBHelloWorld";
    message3_compare = "AAAAAWorldHello";
    std::cout << "String comparison using std::strncmp(): " << std::strncmp(message3, message3_compare, n) << std::endl;//Returns 1 => Lexicographically AFTER case

    message3 = "AAAAAHelloWorld";
    message3_compare = "BBBBBWorldHello";
    std::cout << "String comparison using std::strncmp(): " << std::strncmp(message3, message3_compare, n) << std::endl;//Returns -1 => Lexicographically BEFORE case

    //std::strchr()
    //To find all characters one at a time / first occurance of a character in whole string
    const char *message4 {"This is string to find first occurances"};                                                   //WORK ON LOGIC
    char target = 's';                                                                                                  //Case sensitive
    const char *result = message4;
    int iterations {};

    while((result = std::strchr(result, target)) != nullptr){                                                           //WORK ON LOGIC
        std::cout << "Found: " << target << " at " << result << "'\n";
        ++result;
        ++iterations;
    }
    std::cout << "Total Iterations: " << iterations << std::endl;

    //std::strrchr
    //find last occurance
    char input[] {"A:/directory1/diectory2/directory3/file1.cpp"};                                                      //WORK ON LOGIC
    char *output = std::strrchr(input, '/');

    if(output){                                                                                                         //ponters can implicitly resolve to boolean
        std::cout << "/ is found at " << output << std::endl;
    }
    return 0;
}