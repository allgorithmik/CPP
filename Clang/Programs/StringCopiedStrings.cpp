#include<iostream>
#include<string>

int main(int argc, char **argv){
    //below approach stores same data in two different addresses (same data two places)
    std::string message1 {"This is a std::string string"};                      //initial std::string stored in memory
    std::string message2 {message1};                                            //copy of the same above std::string stored in memory, hence wasting memory

    std::cout << "Address of message1: " << &message1 << std::endl;
    std::cout << "Address of message2: " << &message2 << std::endl;

    char *pointer1 = message1.data();                                           //pointing to an address in memory
    char *pointer2 = message2.data();                                           //pointing to a different address in memory

    std::cout << "message1[0]: " << (void*)pointer1 <<std::endl;
    std::cout << "message2[0]: " << (void*)pointer2 << std::endl;

    //now making two addresses point to the same data (same data two addresses)
    std::string message3 {"This is a std::string string"};
    std::string &message4 {message3};

    std::cout << "Address of message3: " << &message3 << std::endl;
    std::cout << "Address of message4: " << &message4 << std::endl;

    char *pointer3 = message3.data();
    char *pointer4 = message4.data();

    std::cout << "message3[0]: " << (void*)pointer3 <<std::endl;
    std::cout << "message3[0]: " << (void*)pointer4 << std::endl;

    return 0;
}