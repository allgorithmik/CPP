#include<iostream>

//decltype IS USED TO DEDUCE THE TYPE OF THE RESULT FROM AN EXPRESSION BASED ON THE MEMORY SIZES OF THE PARAMS / ARGS INVOLVED => GREATER MEMORY SPACE WILL BE DEDUCED
//SYNTAX: decltype(<expression>)


//WE CANNOT USE decltype AS RETURN TYPE TO A FUNCTION TEMPLATE => COMPILER ERROR
//template<typename T, typename P> decltype((a > b)? a : b) maximum(T a, P b){
//        return (a > b)? a : b;
//    }
//THIS HAPPENS BECAUSE THE PRAMS ARE DECLARED AFTER THE decltype, AS THE EXPRESSIONS IN C++ ARE PROCESSED LEFT-RIGHT, THE COMPILER CANNOT DEDUCE THE TYPE OF THE PARAMS
//WHICH IT HAS NOT YET SEEN => HENCE COMPILER ERROR

//THE SOLUTION TO USE decltype AS RETURN TYPE OF A FUNCTION TEMPLATE IS TO USE decltype AS A TRAILING RETURN TYPE
//COMMENTING THIS OUT TO AVOID RE-DEFINITION COMPILE TIME ERROR
//template<typename T, typename P> auto maximum(T a, P b) -> decltype((a > b)? a : b){    //auto is just for placeholder => syntax sake => the real returntype
//    return (a > b)? a : b;                                                              //deduction is done by trailing returntype (-> decltype)
//}

//ALSO TEMPLATES WITH auto RETURNTYPE CANNOT BE SPLIT INTO PROTOTYPE AND DEFINITIONS(WE ALREADY KNEW THIS), BUT FUNCTION TEMPLATES WITH -> decltype(TRAILING RETURNTYPE) CAN
//BE SPLIT INTO PROTOTYPES AND DEFINITIONS
template<typename T, typename P> auto maximum(T a, P b) -> decltype((a > b)? a : b);    //FUNCTION TEMPLATE PROTOTYPE WITH -> decltype(TRAILING RETURNTYPE)

int main(int argc, char **argv){

    int a {200};
    double b {100};

    std::cout << "Using decltype to deduce the type of result of an expression: " << sizeof(decltype((a > b)? a : b)) << std::endl; //return type deduces as double
    //YES CONFIREMD => TYPE DEDUCTION IS BASED ON THE MEMORY SIZE => decltype DEDUCES THE RETURN TYPE OF AN EXPRESSION BASED ON THE MEMORY SIZE OF THE PARAMS / ARGS INVOLVED

    //WE CAN ALSO USE DECLARE OTHER VARIABLES WHOSE TYPE IS SAME AS THAT OF THE TYPE DEDUCED BY decltype
    decltype((a > b)? a : b) c {55};
    std::cout << "Type of C: " << sizeof(c) << std::endl;                               //deduces as double as this larger in memory space than int

    return 0;
}

template<typename T, typename P> auto maximum(T a, P b) -> decltype((a > b)? a : b){    //FUNCTION TEMPLATE DEFINITION WITH  -> decltype (trailing returntype)
    return (a > b)? a : b;
}