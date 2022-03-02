#include<iostream>
#include<string>

int main(int argc, char **argv){
    std::string str1 {"Mars is home"};
    std::string str2 {"Earth is home"};

    //replace
    str1.replace(0, 4, str2);                                       //replace a std::string with another std::string

    std::cout << str1 << std::endl;

    std::string str3 {"This is a string"};
    str1.replace(0, 5, str3, 10, 15);                               //replace a std::string with another partial std::string
    std::cout << str1 << std::endl;

    //copying
    std::string str4 {"We are colonizing Mars!"};
    char txt[15] {};                                                //empty C-string => equivalent to \0

    str4.copy(txt, 7, 15);                                          //copy string from str4 and paste to txt from the specified index to spcified number of characters
    std::cout << str4 << std::endl;
    std::cout << txt << std::endl;

    std::string str5 {"Mars is a red planet"};
    std::cout << "Size: " << str5.size() << std::endl;
    std::cout << "Capacity: " << str5.capacity() << std::endl;

    str5.resize(5);                                                 //resizes the string and fills the rest with \0 => but we cannot see the null character, so looping
    std::cout << "Size: " << str5.size() << std::endl;
    std::cout << "Capacity: " << str5.capacity() << std::endl;

    for(size_t i {}; i < str5.size(); ++i){
        std::cout << str5[i] << std::endl;
    }

    //we can choose what character to be autofilled by specifying it
    str5.resize(10, 'A');                                           //resizes the string to 10 and fills the rest with 'A' => instead of null character \0
    
    //swapping
    std::string str6 {"Mars is our immediate next neighbor"};
    std::string str7 {"Mars is almost the size of Earth"};

    std::cout << "str6: " << str6 << std::endl;
    std::cout << "str7: " << str7 << std::endl;
    std::cout << "str6 Size: " << str6.size() << std::endl;
    std::cout << "str7 Size: " << str7.size() << std::endl;
    std::cout << "str6 Capacity: " << str6.capacity() << std::endl;
    std::cout << "str7 Capacity: " << str7.capacity() << std::endl;

    str6.swap(str7);                                                //swaps the one std::string with another std::string along with their meta-data(size, capacity.....)
    std::cout << "Swapping....." << std::endl;

    std::cout << "str6: " << str6 << std::endl;
    std::cout << "str7: " << str7 << std::endl;
    std::cout << "str6 Size: " << str6.size() << std::endl;
    std::cout << "str7 Size: " << str7.size() << std::endl;
    std::cout << "str6 Capacity: " << str6.capacity() << std::endl;
    std::cout << "str7 Capacity: " << str7.capacity() << std::endl;
    return 0;
}