#include<iostream>
#include<string>

int main(int argc, char **argv){
    
    std::string str1 {"Mars will be colonized in a dacade and occupied by human settlers"};

    //str.find()
    std::string search_str {"Mars"};

    size_t pos = str1.find(search_str);

    std::cout << "The position of " << search_str << " in " << "'" << str1 << "'" << " is: " << pos << std::endl;

    //search for something which isn't there
    //search_str = "Titan";
    std::cout << "The position of " << search_str << " in " << "'" << str1 << "'" << " is: " << pos << std::endl;

    //std::string::npos                                                                                         //very large number
    std::cout << "std::string::npos: " << std::string::npos << std::endl;                                       //very larger number

    //checking for a string using if else statement against std::string::npos
    if(str1.find(search_str) == std::string::npos){
        std::cout << search_str << " was not found!" << std::endl;
    }
    else{
        std::cout << search_str << " found in position: " << str1.find(search_str) << std::endl;
    }

    //search using find() along with starting position => str.find(str, start_pos)
    std::string str2 {"Humans are going to be multi-planetary species"};
    size_t pos2 = str2.find("multi" , 100);

    std::string search_str2 {"multi"};

    std::cout << "Using str.find(str, position) to find the position of " << search_str2 << " in " << "'" << str2 << "'" << " is: " << str2.find(search_str2, 10) << std::endl;

    //str.find() works even for C-String
    std::string str3 {"Mars will be advanced"};
    const char *search_str3 {"advanced"};

    std::cout << "C-string search: " << str3.find(search_str3 ,10) << std::endl;                                //works even for C-string style search strings

    return 0;
}