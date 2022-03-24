#include<iostream>

//AMBIGOUS FUNCTION CALLS
void name(const std::string &name);                 //function prototype with a reference param / args
void name(std::string name);                        //function prototype with a NON-reference param / args

//IMPLCIT CONVERSION WITH REFERENCES
int& max(int &a, int &b);                           //function prototype with a reference param / args and reference return type
double max(double a, double b);                     //function prototype with a NON-reference param / args and normal params / args



int main(int argc, char **argv){
    std::string str1 {"Opportunity Rover"};
    char a {10};
    char b {100};

    //AMBIGOUS CALLS => THE COMPILER KNOWS HOW TO TAKE TEMPORARY const *char STRINGS AND TURN IT INTO A REFERENCE VARIABLE (MORE EXPLANATION ON THIS LATER IN THE COURSE) 
    //name(str1);                                   //COMPILER ERROR => COMPILER DOES NOT KNOW WHICH FUNCTON TO CALL AS BOTH FUNCTION CALLS ARE VALID
    //name("Curiosity Rover");                      //COMPILER ERROR => COMPILER DOES NOT KNOW WHICH FUNCTON TO CALL AS BOTH FUNCTION CALLS ARE VALID

    //IMPLCIT CONVERSION WITH REFERENCES
    max(a, b);                                      //NORMALLY WE WOULD THINK THE int VERSION OF max() WILL BE CALLED, BUT IN THIS CASE double VERSION OF max() WIIL BE
    //INVOKED => BECAUSE WITH REFERENCES TEMPORARY VARIABLES ARE INVOLVED => NON REFERENCE PARAMS / ARGS CANNOT BE USED WITH TEMPORARIES AS COMPILER WILL STOP US FROM
    //DOING SO => PLEASE REFER CHAPTER OF IMPLICIT CASTING OF REFERENCES OF FUNCTION PARAM / ARGS
    //POTENTIAL SOLUTION TO THIS PROBLEM IS TO CREATE OUR OWN TEMPORARY VARIABLES AND THEN PASS THOSE VARIABLES AS PARAMS / ARGS TO OUR OVERLOADED FUNCTION => ANOTHER
    //POTENTIAL SOLUTION OF const REFERENCE PARAM / ARGS AND const REFERENCE RETURN TYPE IS DEFINED IN FUNCTION ON LINE 58

    int int_a {static_cast<int>(a)};
    int int_b {static_cast<int>(b)};
    max(int_a, int_b);                              //NOW int VARIANT OF max() WILL BE INVOKED AS PER OUR REQUIREMENT

    //ANOTHER POTANTIAL SOLUTION TO MAKE OUR PARAMS / ARGS const
    max(int_a, int_b);
    std::cout << "max(): " << max(int_a, int_b) << std::endl;  //now we get correct results
    return 0;
}

//AMBIGOUS CALLS
void name(const std::string &name){                 //definition of function with reference param / args => COMPILES FINE
    std::cout << "reference std::string variant" << std::endl;
    std::cout << "Name is: " << name << std::endl;
}

void name(std::string name){                        //definition of function with NON-reference param / args => COMPILES FINE
    std::cout << "non reference std::string variant" << std::endl;
    std::cout << "Name is: " << name << std::endl;
}

//IMPLCIT CONVERSION WITH REFERENCES
int& max(int &a, int &b){                           //function prototype with a reference param / args and reference return type
    std::cout << "Int variant" << std::endl;
    return (a > b)? a : b;
}

double max(double a, double b){                     //function prototype with a NON-reference param / args and normal params / args
    std::cout << "Double variant" << std::endl;
    return (a > b)? a : b;
}

//POTENTIAL SOLUTION OF const reference param / args and const reference return type
const int &max(const int &a, const int b){          //function prototype with const reference param / args and const reference return type
    std::cout << "const reference return type and const reference params/args variant" << std::endl;
    return (a > b)? a : b;
}