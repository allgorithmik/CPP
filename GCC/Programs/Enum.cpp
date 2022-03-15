#include<iostream>

int main(int argc, char **argv){
    //enum IS A DATA STRUCTURE DESIGNED TO HOLD SIMILAR VALUES INTO SINGLE UNIT. THE VALUES INSIDE A enum ARE CALLED enumarators. enumerators CANNOT BE ACCESSED DIRECTLY,
    //INSTEAD THEY NEED TO BE ACCESSED BY CASTING THE RESPECTIVE enumerator INTO INT AS EACH ENUMERATION IS REPRESENTED BY AN INTEGRAL VALUE UNDER THE HOOD.
    //ex. static_cast<int>(<enumerator>)
    //syntax for declaring enum class:
    //enm class <enum_name> {enumerators};
    enum class Month {
        January, February, March,                                                   //EACH ENUMERATION IS REPRESENTED BY AN INTEGRAL VALUE UNDER THE HOOD
        April, May, June, July,                                                     //THE INTEGRAL REPRESENTATION STARTS FROM 0, SO THERE ARE 11 enumerators IN THIS
        August, September, October,                                                 //enum class
        November, December
    };                                                                              //NOTE: enum classes CAN ALSO BE DECLARED OUTSIDE OF main()

    //using declared enum class:
    //<enum_name> enum_variable_name {enum_name :: enumerator};
    Month month {Month::July};
    std::cout << "Accessing enumerators: " << static_cast<int>(month) << std::endl; //PLEASE NOT THE CASTING OF enumerator TO INT => RESULT WILL BE 6 INSTEAD OF JULY

    //CUSTOMIZING enumerator INTEGER REPRESENTATION
    enum class Month1 {
        January = 1, February, March,                                               //EACH ENUMERATION IS REPRESENTED BY AN INTEGER VALUE UNDER THE HOOD AND THE INTEGER 
        April, May, June, July,                                                     //REPRESENTATION STARTS FROM 0 BY DEFAULT, BUT WE CAN CUSTOMIZE IT TO START FROM WHATEVER
        August, September, October,                                                 //INTEGER WE NEED, BUT, WHATEVER INTEGER WE START THE FIRST enumerator WITH, THE
        November, December                                                          //SUBSEQUENT enumerators TAKE THE INCREMENTAL VALUES BY 1 AUTOMATICALLY UNTILL ALL THE
    };                                                                              //enumarators IN enum class ARE COMPLETE
    Month1 month1 {Month1::September};
    std::cout << "Accessing enumerators: " << static_cast<int>(month1) << std::endl;//PLEASE NOTE NOW THE RESULT IS 9 INSTEAD OF n-1 WHICH IS THE DEFAULT BEHAVIOUR

    //CUSTOMIZING enumerator INTEGER REPRESENTATION USING NEGATIVE VALUES
    enum class Month2 {
        January = -1, February, March,                                              //WE CAN EVEN CUSTOMIZE enumerator REPRESENTATION USING NEGATIVE VALUES, BUT WHATEVER 
        April, May, June, July,                                                     //NEGATIVE VALUE WE STAT WITH, THE SUBSEQUENT enumerators WILL TAKE THE INCREMENTAL
        August, September, October,                                                 //VALUES BY 1, BUT IN NEGATIVE DIRECTION AUTOMATICALLY UNTILL ALL THE enumarators
        November, December                                                          //IN enum class ARE COMPLETE
    };
    Month2 month2 {Month2::September};
    std::cout << "Accessing enumerators: " << static_cast<int>(month2) << std::endl;//RESULT IS 7, PLEASE CHECK

    //MULTIPLE enumerators FOR SAME INTEGER VALUE WITH ONE enum class
    enum class Month3 {                                                             //WE CAN CUSTOMIZE TO HAVE MULTIPLE enumerators TO HAVE SAME INTEGER VALUES TO REPRESENT
        January = 1, JAN = 1, Jan = 1, February, March,                             //THEM, BUT SUBSEQUENT enumerators WILL FOLLOW THE DEFAULT BEHAVIOUR OF INCREMENTING
        April, May, June, July,                                                     //BY 1 UNLESS WE MANUALLY CHANGE THE INTEGER REPRESENTATION VALUES
        August, September, Sep, October,
        November, December
    };
    Month3 month3 {Month3::Sep};
    std::cout << "Accessing enumerators: " << static_cast<int>(month3) << std::endl;

    //enumeraots IN TERMS OF OTHER enumerators
    enum class Month4 {                                                             //MULTIPLE enumerators CAN HAVE OTHER enumerators REPRESENTING THEM, AND ALL enumerators
        January = 1, JAN = January,                                                 //HAVING THE SAME REPRESENTATIONS WILL BE VIRTULLY GROUPED TOGETHER AND CAN BE ACCESSED
        February = 2, FEB = February,                                               //VIA ITS OTHER ENUMERATOR
        March = 3, MAR = March,                                                     //HOWEVER, ASSIGNING CUSTOM INTEGER VALUES FOR EACH OF THEM IS A MANUAL TASK
        April = 4, APR = April,                                                     //BUT THE BEHAVIOUR OF THE FIRST enumerator BEING INITIALIZED WITH A INTEGER VALUE
        May = 5, MAY = May,                                                         //(POSITIVE AND NEGATIVE) AND SUBSEQUENT enumerators HAVING BEEN AUTOMATICALLY
        June = 6, JUN = June,                                                       //INCREMENTED WILL STILL BE AVAILABLE, BUT HERE WE HAVE DEFINED MANUALLY FOR
        July = 7, JUL = July,                                                       //COMPLETENESS
        August = 8, AUG = August,
        September = 9, SEP = September,
        October = 10, OCT = October,
        November = 11, NOV = November,
        December = 12, DEC = December
    };
    Month4 month4 {Month4::SEP};
    std::cout << "Accessing enumerators: " << static_cast<int>(month4) << std::endl;//PLEASE NOTE THE enumerator REPRESENTED BY ANOTHER enumerator IS HAVING ORIGINAL VALUE

    //size of enum class
    Month month5 {Month::February};
    //int is the default type of enums in C++
    std::cout << "Size of an enum by default is: " << sizeof(month5) << std::endl;  //RESULT IS 4 BYTES => OBVIOUSLY AS enumerators ARE REPRESENTED BY INTEGERS

    //exceeding the size of enumerators
    enum class Month6 {
        January = 1, JAN = January,
        //February = 3'000'000'000, FEB = February,                                 //COMPILER ERROR HERE AS THE VALUE EXCEEDS THE MAXIMUM VALUE OF AN INTEGER, BUT
        March = 3, MAR = March,
        April = 4, APR = April,
        May = 5, MAY = May,
        June = 6, JUN = June,
        July = 7, JUL = July,
        August = 8, AUG = August,
        September = 9, SEP = September,
        October = 10, OCT = October,
        November = 11, NOV = November,
        December = 12, DEC = December
    };

    //custom type to represent the enumerators => change from integers to custom types
    //custom type to represent the enumerators syntax:
    //enum class <enum_name> : <custom data type(char, unsigned char etc)>
    enum class Month7 : unsigned char{                                              //THIS enum HAS CUSTOM TYPE TO REPRESENT ITS enumerators
        January = 1, JAN = January,                                                 //THE CUSTOM TYPE IS unsigned char, THIS TYPE AFFECTS THE enumerators SIZE AND
        February = 2, FEB = February,                                               //THEREBY THE RANGE OF VALUES THEY CAN REPRESENT => 0 - 255
        March = 3, MAR = March,
        April = 4, APR = April,
        May = 5, MAY = May,
        June = 6, JUN = June,
        July = 7, JUL = July,
        August = 8, AUG = August,
        September = 9, SEP = September,
        October = 10, OCT = October,
        November = 11, NOV = November,
        December = 12, DEC = December
    };

    Month7 month7 {Month7::September};
    std::cout << "Size of custom type enumerators: " << sizeof(month7) << std::endl;//RESULT IS 1 BYTE => THE SIZE OF unsigned char WHICH IS THE CUSTOM TYPE REPRESENTING
    return 0;                                                                       //THE enumerators OF THIS enum
}