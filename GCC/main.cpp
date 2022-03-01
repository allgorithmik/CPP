#include<iostream>
#include<string>

int main(int argc, char **argv){
    
    std::string str1 {"I am a Martian"};

    std::cout << "BEFORE using str.clear() on str1" << std::endl;
    std::cout << "str1 is: " << str1 << std::endl;                                              //"I am a Martian"
    std::cout << "str1 size: " << str1.size() << std::endl;                                     //14
    std::cout << "str1 capacity: " << str1.capacity() << std::endl;                             //15

    //str.clear() => clears everything in std::string
    str1.clear();

    std::cout << "AFTER using str.clear() on str1" << std::endl;
    std::cout << "str1 is: " << str1 << std::endl;                                              //EMPTY
    std::cout << "str1 size: " << str1.size() << std::endl;                                     //0
    std::cout << "str1 capacity: " << str1.capacity() << std::endl;                             //15 => capacity is still 15 because std::string is ready to take values

    //str.insert() => inserting characters at index => str.insert(index, number/count of chars, chars)
    std::string str2 {"12345"};

    std::cout << "str2 BEFORE using str.insert()" << std::endl;
    std::cout << str2 << std::endl;

    str2.insert(1, 1, '5');                                                                     //str.insert(index, number/count of chars, chars)

    std::cout << "str2 AFTER using str.insert()" << std::endl;
    std::cout << str2 << std::endl;

    //insert C-String at index
    std::string str3 {"Hello "};
    const char *str3_pointer {"Mars"};

    std::cout << "Inserting const char pointer to std::string using str.insert()" << std::endl; //we can insert C-String pointers into str.insert() along with the
    str3.insert(6, str3_pointer);                                                               //index at which the C-string must be inserted                               

    std::cout << str3 << std::endl;                                                             //Hello Mars

    //inserting partial C-Strings
    std::string str4 {"Hello "};

    const char *str4_pointer {"String to be appended"};                                         //inserts specified number of characters(partial string)
    str4.insert(6, str4_pointer, 5);                                                            //at the index of the std::string

    std::cout << str4 << std::endl;

    //insert string at position index
    std::string str5 {"Hello Mars"};
    std::string str6 {" Here we come"};

    str5.insert(5, str6);                                                                       //inserts std::string at the specifies index position

    std::cout << str5 << std::endl;

    //insert part of std::string at the specified index
    std::string str7 {"Hello Mars"};
    std::string str8 {"We are going to pollute you as well"};                                   //str.insert(start_index, std::string, start_index, number_of_characters)
    str7.insert(5, str8, 10, 5);                                                                //inserts partial string at the specifies index and number of characters

    std::cout << str7 << std::endl;

    //str.earse() => Erase => erases the characters from specified index upto number of characters
    std::string str9 {"Hello Mars but this string will be erased using str.erase()"};

    str9.erase(10, str9.size() - 10);                                                           //str.erase(start_index, number_of_characters_to_erase)

    std::cout << str9 << std::endl;

    std::string str10 = "Hello Mars but this string will be erased using str.erase()";
    std::cout << str9.erase(10, str10.size() - 10) << std::endl;                                //this is possible as str.erase() returns a reference to the modified string

    //push_back() / pop_back()
    std::string str11 {"Hello Mars"};

    std::cout << "str11 BEFORE push_back(): " << str11 << std::endl;

    str11.push_back('!');                                                                       //str.pop_back() appends a character at the END of std::string

    std::cout << "str11 AFTER push_back(): " << str11 << std::endl;

    str11.pop_back();                                                                           //str.pop_back() removes the LAST character at the END of std::string

    std::cout << "str11 AFTER pop_back(): " << str11 << std::endl;

    return 0;

}