#include<iostream>
#include<string>
#include<string_view>

int main(int argc, char **argv){
    //std::string wastes a LOT of memory => hence use std::string view
    std::string str1 {"Mars is just awesome"};
    std::string str2 {str1};
    std::string str3 {str1};

    std::cout << "Address of str1: " << &str1 << std::endl;
    std::cout << "Address of str2: " << &str2 << std::endl;
    std::cout << "Address of str3: " << &str3 << std::endl;

    //STRING VIEW
    //std::string_view will just point to the data from various addresses

    std::string_view str_view1 {"Mars is just another planet"};
    std::string_view str_view2 {str_view1};
    std::string_view str_view3 {str_view1};

    std::cout << "Addresses of std::string_view:" << std::endl;
    std::cout << "Size of std::string_view: " << sizeof(std::string_view) << std::endl; //16 => sizeof() std::string_view
    std::cout << "Address of std::str_view1: " << &str_view1 << std::endl;              //EVEN THOUGH THERE ARE THREE DIFFERENT MEMORY LOCATIONS, THE DATA IN THEM IS ONLY
    std::cout << "Address of std::str_view2: " << &str_view2 << std::endl;              //ONE SINGLE COPY WHICH IS INITIALIZED, NO DUPLICATE COPIES OF DATA ARE PRESENT,
    std::cout << "Address of std::str_view3: " << &str_view3 << std::endl;              //HENCE SAVING A LOT OF MEMORY SPACE

    std::cout << "str_view1 data: " << str_view1 << std::endl;                          //data is the same in all three variables, but single copy
    std::cout << "str_view2 data: " << str_view2 << std::endl;
    std::cout << "str_view3 data: " << str_view3 << std::endl;

    //std::string_view can be initialized using std::strings, const char, char array, char pointers, C-strings
    std::string str4 {"Mars will have a human colony soon"};                            //std::string
    const char str5[] {"Mars here we come"};                                            //const char array => null character terminated
    const char *str6 {"Mars has low pressure"};                                         //C-String
    char str7[] {'M', 'A', 'R', 'S'};                                                   //char array => non null character terminated
    std::string_view str8 {"Mars is very cold"};                                        //std::string_view

    //no matter how a std::string_view() is initialized, its propoerty will remain the same
    std::string_view string_init {"Next planet to Mars is Jupiter"};                    //direct std::string initialization
    std::string_view string_init_passing_variable_init {str4};                          //passing std::string variable initialization
    std::string_view const_char_init {str5};                                            //const char initialization
    std::string_view cstring_init {str6};                                               //C-String initialization
    std::string_view char_array_init {str7};                                            //char array initialization => WE SHOULD AVOID DOING THIS
    std::string_view str_view_init {str8};                                              //another std::string_view initialization

    std::cout << string_init << std::endl;
    std::cout << string_init_passing_variable_init << std::endl;
    std::cout << const_char_init << std::endl;
    std::cout << cstring_init << std::endl;
    std::cout << char_array_init << std::endl;                                          //DO NOT USE non-null terminated STRINGS IN std::string_view
    std::cout << str_view_init << std::endl;
    
    //CHANGING THE ORIGINAL STRING WILL REFLECT IN ALL THE VIEWS CONTAINING THE ORIGINAL STRING
    std::string str9 {"Earth is very polluted"};
    std::string_view change_view {str9};

    std::cout << "string_view BEFORE change: " << change_view << std::endl;             //No change (obviously)

    str9[0] = 'T';

    std::cout << "string_view AFTER change: " << change_view << std::endl;              //changed in the view

    //std::string_view IS VERY POWERFUL => string_view ACTS A WINDOW TO THE ORIGINAL STRING, HIDING THE STRING WE WANT AND ONLY EXPOSING A PARTIAL VIEW OF THE 
    //STRING FROM A LARGER STRING, WE CAN CONTROL THE VIEW WINDOW FROM BOTH LEFT AND RIGHT SIDE OF THE STRING

    std::string str_original {"Earth and Mars human colonies can co-exist and make humans technologically advanced multiplanetary species"};
    std::string_view str10 {str_original};

    //left window control
    str10.remove_prefix(5);

    std::cout << "With prefix removal (left): " << str10 << std::endl;

    //right window control
    str10.remove_suffix(10);

    std::cout << "With suffix removal (right): " << str10 << std::endl;

    //removing prefix() or suffix() will not change the original string => however, if the string is initialized directly as a std::string_view, any pefix or suffix
    //change will directly affect the data => better to create a separate original string and then initialize the std::string_view with this original string

    std::cout << str_original << std::endl;

    //std::string_view CANNOT OUT LIVE (SCOPE/LIFE SPAN) the original string it is viewing
    std::string_view str_scope;
    {
        std::string str11 {"People who go to Mars will be called Martians"};
        str_scope = str11;
        std::cout << "str_scope BEFORE str11 goes out of scope: " << str_scope << std::endl;
    }
    //str11.append(); => compiler error as str11 went out of scope as it was local variable
    std::cout << "str_scope AFTER str11 goes out of scope: " << str_scope << std::endl; //std::string_view still is available because it was declared globally, but the
    //sring it was viewing went out of scope and no methods of it can be invoked

    //str.data() with std::string_view => data() can be invoked on string_view as long as view HAS NOT been modified via prefix() / suffix() and the original string is
    //null terminated => all literals are automatically inserted with \0

    std::string str12 {"Going to Mars will be expensive"};
    std::string_view str12_view {str12};

    std::cout << "str12 data(): " << str12_view.data() << std::endl;                    //works as data is NOT modified using prefix() / suffix()

    str12_view.remove_prefix(5);
    str12_view.remove_suffix(5);

    std::cout << "atr12_view data AFTER modifying: " << str12_view.data() << std::endl; //not recommended to use str_view.data() after modifying the view=>length info is lost

    //many of std::string functions are applicable to std::string_view as well
    std::cout << "front(): " << str12_view.front() << std::endl;
    std::cout << "back(): " << str12_view.back() << std::endl;
    std::cout << "length(): " << str12_view.length() << std::endl;
    std::cout << "npos: " << str12_view.npos << std::endl;
    std::cout << "data(): " << str12_view.data() << std::endl;
    std::cout << "And many more methods/functions of std::string are applicable....." << std::endl;

    return 0;

    }