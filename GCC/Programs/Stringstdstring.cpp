#include<iostream>

int main(int argc, char **argv){
    std::string name {};                                            //empty string
    std::string place {"Mars, in Solar System"};                    //initialize with string literal
    std::string favorite_place {place};                             //initialize with existing string
    std::string message {"Hello Martian", 5};                       //initialize with part of string => substring contains specified number of characters => contains Hello
    std::string weird_message {'E', 5};                             //initialize with multiple copies of specified character => contains EEEEE
    std::string welcome_message {"Hello Milky Way"};                //
    std::string hello_message {welcome_message, 5, 10};             //initialize with substring of an existing std::string starting with index 5, taking 10 characters => 

    std::cout << "Name: " << name << std::endl;
    std::cout << "Planet: " << place << std::endl;
    std::cout << "Favorite Place: " << favorite_place << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "Weird Message: " << weird_message << std::endl;
    std::cout << "Welcome Message: " << welcome_message << std::endl;
    std::cout << "Hello Message: " << hello_message << std::endl;

    //std::string supports changing data at runtime
    place = "This is a new place in the universe";                  //C++ std::string automatically handles the logic to change the data at runtime => NOT POSSIBLE USING
    std::cout << "New Place: " << place << std::endl;               //POINTERS AND CHAR => RELEASING THE MEMORY BACK TO SYSTEM AND OTHER HOUSKEEPING LOGIC OF STRINGS

    return 0;
}