#include<iostream>

enum class Month {                              //please note this enum is declared outside main() which is legal in C++
    Jan, Feb, Mar,
    Apr, May, Jun,
    Jul, Aug, Sep,
    Oct, Nov, Dec
};

std::string_view str_month_old(Month month);    //function prototype
std::string_view str_month_new(Month month);    //function prototype

int main(int argc, char **argv){

    Month month1 {Month::Jan};
    Month month2 {Month::Sep};

    //COUPLE OF POINTS TO REMEMEBR: 1) DO NOT FORGET TO CAST enumerators 2) PASS THE enum TYPE TO FUNCTION AND NOTHING ELSE (OBVIOUSLY)
    std::cout << "Calling str_month_old() with " << static_cast<int>(month1) << " value and its result is: " << str_month_old(month1) << std::endl;

    std::cout << "Calling str_month_new() with " << static_cast<int>(month2) << " value and its result is: " << str_month_new(month2) << std::endl;
    return 0;
}

std::string_view str_month_old(Month month){    //a function with return type std::string_view and which takes in an enum as param / args
        switch (month){
            case Month::Jan : return "January";
            case Month::Feb : return "February";
            case Month::Mar : return "March";
            case Month::Apr : return "April";
            case Month::May : return "May";
            case Month::Jun : return "June";
            case Month::Jul : return "July";
            case Month::Aug : return "August";
            case Month::Sep : return "September";
            case Month::Oct : return "October";
            case Month::Nov : return "November";
            case Month::Dec : return "December";
            default : return "NONE";
        }
    }

std::string_view str_month_new(Month month){    //a function with return type std::string_view and which takes in an enum as param / args
        switch (month){
            using enum Month;                   //this is a feature introduced in C++20(gcc 10 - No, gcc 11 - Yes, MSVC 2019 - Yes), this enables us to remove the
            case Jan : return "January";        //<enum_name> whenever we need to access the enum' enumerators
            case Feb : return "February";       //PLEASE NOTE THE REDUNDANT USE OF <enum_name>::enumerator ARE REMOVED AND WE CAN DIRECTLY ACCESS THE 
            case Mar : return "March";          //enum' enumerator
            case Apr : return "April";          //=> SAME LIKE namespaces!
            case May : return "May";
            case Jun : return "June";
            case Jul : return "July";
            case Aug : return "August";
            case Sep : return "September";
            case Oct : return "October";
            case Nov : return "November";
            case Dec : return "December";
            default : return "NONE";
        }
    }