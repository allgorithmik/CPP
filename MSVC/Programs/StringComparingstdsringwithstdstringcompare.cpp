#include<iostream>
#include<string>

int main(int argc, char **argv){
    //std::string comparison will occur lexicograhically by default
    //OUTPUT OF std::string str.compare() WILL BE ONE OF THE BELOW THREE RETURN VALUE
    //negative value    :   if the std::string appears BEFORE the character sequence specified by the arguments => lexicographical order
    //zero              :   if both the characters sequences compae equivalent in size and position
    //positive value    :   if the std::string appears AFTER the character sequence specified by the arguments => lexicographical order
    std::string str1 {"Mars is our new home"};
    std::string str2 {"Earth is our old home"};

    std::cout << "Comparing " << "'" << str1 << "'" << " with " << "'" << str2 << "'" << " : " << str1.compare(str2) << std::endl;              //1
    std::cout << "Comparing " << "'" << str2 << "'" << " with " << "'" << str1 << "'" << " : " << str2.compare(str1) << std::endl;              //-1

    //comparing partial strings => str.compare(start_index, number_of_characters, string)
    std::string str3 {"Earth is true home"};
    std::cout << "Comparing " << "'" << str3 << "'" << " with " << "'" << str1 << "'" << " : " << str3.compare(5, 10, str1) << std::endl;       //-1

    //comparing std::string to C-string(null terminated)
    const char *string_var {"Earth is beautiful"};
    std::cout << "Comparing " << "'" << str3 << "'" << " with " << "'" << string_var << "'" << " : " << str3.compare(string_var) << std::endl;  //1

    return 0;
}