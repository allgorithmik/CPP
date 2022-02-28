#include<iostream>
#include<string>

int main(int argc, char **argv){
    //std::string IS ACTALLY IMPLEMENTED USING CHAR ARRAYS INTERNALLY => C-STRING
    std::string str1;
    std::string str2 {};
    std::string str3 {"Hello Mars"};

    //str.empty() => checking for emptyness => bool
    std::cout << "checking std::string str.empty()" << std::endl;
    std::cout << "str1 is empty?: " << std::boolalpha << str1.empty() << std::endl;                             //true
    std::cout << "str2 is empty?: " << std::boolalpha << str2.empty() << std::endl;                             //true
    std::cout << "str2 is empty?: " << std::boolalpha << str3.empty() << std::endl;                             //false

    //str.size() => checking the size of a string
    std::cout << "checking std::string str.size()" << std::endl;
    std::cout << "str1 size: " << str1.size() << std::endl;                                                     //0
    std::cout << "str2 size: " << str2.size() << std::endl;                                                     //0
    std::cout << "str3 size: " << str3.size() << std::endl;                                                     //10

    //str.length() => checking the length of a string => returns the number of elements in a string excluding \0
    std::cout << "checking std::string str.length()" << std::endl;
    std::cout << "str1 length: " << str1.length() << std::endl;                                                 //0
    std::cout << "str2 length: " << str2.length() << std::endl;                                                 //0
    std::cout << "str3 length: " << str3.length() << std::endl;                                                 //10

    //str.max_size() => checking the max size a string can hold
    std::cout << "std::string can hold: " << str1.max_size() << " characters" << std::endl;                     //if we go beyond capacity, program crashes

    //str.capacity() => curent max number of characters you can store in the string. A capacity is allocated by default, when we try to store more characters than the
    //currently allocated capacity, std::string automatically allocates new and larger memory to store the new string
    std::cout << "checking std::string str.capacity()" << std::endl;
    std::cout << "str1 capacity: " << str1.capacity() << std::endl;                                             //15
    std::cout << "str2 capacity: " << str2.capacity() << std::endl;                                             //15
    std::cout << "str3 capacity: " << str3.capacity() << std::endl;                                             //15

    //increasing str3' characters to check if its allocated larger capacity
    std::cout << "trying to increase the capacity of str3" << std::endl;
    str3 = "Hello Mars, we have come to colonize you. We will make you our new home, if its alright with you";
    std::cout << "str3 capacity: " << str3.capacity() << std::endl;                                             //96 => new capacity => dynamically allocated

    //str.reserve() => update the capacity
    //reserving capacity of str3 to 500
    std::cout << "checking str.reserve()" << std::endl;
    std::cout << "str3 capacity BEFORE reserve: " << str3.capacity() << std::endl;                              //96
    str3.reserve(500);
    std::cout << "str3 capacity AFTER reserve: " << str3.capacity() << std::endl;                               //500
    std::cout << "str3 size: " << str3.size() << std::endl;                                                     //96

    //str.shrink_to_fit()
    std::cout << "checking str.shrink_to_fit()" << std::endl;
    std::cout << "str3 capacity BEFORE shrink_to_fit: " << str3.capacity() << std::endl;
    str3.shrink_to_fit();                                                                                       //reduces the size of memory to exactly the number
    std::cout << "str3 capacity AFTER shrink_to_fit: " << str3.capacity() << std::endl;                         //of characters => hence 96

    return 0;

}