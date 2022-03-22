#include<iostream>
#include<optional>                                                                                  //INCLUDE <optional> HEADER TO MAKE USE OF std::optional

//std::optional TYPE WAS INTRODUCED IN C++17 TO HELP HANDLE OPTIONAL OUTPUT FROM FUNCTIONS AMONG OTHER THINGS

//DECLARE AND INITIALIZE EMPTY std::optional
//SYNTAX: => std::optional<<data_type>> identifier {<initialization_value or std::nullopt>};
//std::optional MUST ALWAYS BE EITHER INITIALIZED WITH A VALUE OF ITS TYPE OR INITIALIZED WITH std::nullopt FOR AN EMPTY std::optional
//INITIALIZATION CAN BE DONE EITHER USING UNIFORM INITIALIZATION {}, ASSIGNMENT INITIALIZATION = OR FUNCTIONAL INITIALIZATION ()
std::optional<int> intoptional {std::nullopt};                                                      //uniform {} initialization
std::optional<std::string> stringoptional = std::nullopt;                                           //assignment = initialization
std::optional<bool> booloptional (std::nullopt);                                                    //functional () initialization
std::optional<double> doubleoptional = {};                                                          //EQUVIVALENT TO std::optional<double> doubleoptional {std::nullopt}
std::optional<long double> longoptional = {};                                                       //EQUVIVALENT TO std::optional<double> longoptional {std::nullopt}
std::optional<long long int> longintoptional = {};                                                  //EQUVIVALENT TO std::optional<double> longintoptional {std::nullopt}

//DECLARE AND INITIALIZE std::optional WITH A VALUE OF ITS CORRESPONDING TYPE
std::optional<int> intoptionalval {100};                                                            //uniform {} initialization
std::optional<std::string> stringoptionalval = "Hello Mars";                                        //assignment = initialization
std::optional<double> doubleoptionalval (100.99);                                                   //functional () initialization
std::optional<char> charoptionalval {'A'};
std::optional<long double> longoptionalval  = 100.55;
std::optional<bool> booloptionalval (true);

int main(int argc, char **argv){

    //READING VALUES FROM EMPTY std::optional DECLARED ABOVE
    //BUT BUT READING FROM AN EMPTY std::optional THROWS AN EXCEPTION AND CRASHES THE PROGRAM
    //std::cout << "Reading EMPTY std::optional: " << intoptional.value() << std::endl;             //<std::optional_identifier>.value() => value method => PROGRAM CRASH
    //std::cout << "Reading EMPTY std::optional: " << *stringoptional << std::endl;                 // *<std::optional_identifier> => dereference method => PROGRAM CRASH

    //READING VALUES FROM std::optional DECLARED ABOVE
    std::cout << "Reading std::optional with value: " << booloptionalval.value() << std::endl;      //<std::optional_identifier>.value() => value method
    std::cout << "Reading std::optional with value: " << *charoptionalval << std::endl;             // *<std::optional_identifier> => dereference method

    //WAYS TO WORK AROUND THE CRASH WHILE READING FROM AN EMPTY std::optional (APART FROM EXCEPTION HANDLING)
    //CONDITIONAL READING std::optional TO CHECK IF ITS EMPTY (VARIOUS METHODS)

    //using <std::optional_identifier>.has_value() method to read empty std::optional
    if(doubleoptional.has_value()){
        std::cout << "Reading std::optional with value: " << *doubleoptional << std::endl;          //NOTE THE DEREFERENCING METHOD USED TO READ VALUE FROM std::optional
    }
    else{
        std::cout << "std::optional has no value" << std::endl;
    }

    //using <std::optional_identifier> != std::optional method to read empty std::optional
    if(longintoptional != std::nullopt){
        std::cout << "Reading std::optional with value: " << longintoptional.value() << std::endl;  //NOTE THE <std::optional_identifier>.value() METHOD
    }
    else{
        std::cout << "std::optional has no value" << std::endl;
    }

    //using <std::optional_identifier>.has_value() method to read from a std::optional
    if(stringoptionalval.has_value()){
        std::cout << "Reading std::optional with value: " << *stringoptionalval << std::endl;       //NOTE THE DEREFERENCING METHOD USED TO READ VALUE FROM std::optional
    }
    else{
        std::cout << "std::optional has no value" << std::endl;
    }

    //using <std::optional_identifier> != std::optional method to read from a std::optional
    if(charoptionalval != std::nullopt){
        std::cout << "Reading std::optional with value: " << charoptionalval.value() << std::endl;  //NOTE THE <std::optional_identifier>.value() METHOD TO READ std::optional
    }
    else{
        std::cout << "std::optional has no value" << std::endl;
    }

    //<std::optional_identifier>.has_value() RETURNS A BOOLEAN => HENCE READING IT
    std::cout << "Is std::optional containg value?: " << booloptional.has_value() << std::endl;     //<std::optional_identifier>.has_value() method

    std::cout << "Is std::optional containg value?: " << *booloptionalval << std::endl;             // *<std::optional_identifier> method

    std::cout << std::boolalpha;
    std::cout << "Is std::optional containg value?: " << booloptional.has_value() << std::endl;     //<std::optional_identifier>.has_value() method

    std::cout << "Is std::optional containg value?: " << *booloptionalval << std::endl;             // *<std::optional_identifier> method
    return 0;
}