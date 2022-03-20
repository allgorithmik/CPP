#include<iostream>

//THE COMPILER AUTO DEDUCES THE RETURN TYPE OF A FUNCTION, BY EVALUATING THE RETURN STATEMENTS IN THE FUNCTION
//THE RETURN TYPES MUST BE CONSISTENT => ELSE THERE WILL BE COMPILER ERROR IF THERE ARE CONFLICTS IN RETURN TYPES

//ITS BETTER NOT TO SPLIT THE FUNCTION INTO THEIR PROTOTYPE AND DEFINITION WHILE USING auto AS RETURN TYPE BECAUSE auto WILL NOT YET BE DEDUCED DURING COMPILE TIME
auto process_deduce(int a){                                         //NOTICE THE auto KEYWORD AS THE RETURN TYPE OF THE FUNCTION
    if(a > 100){
        return 55;                                                  //RETURNS int LITERAL
    }
    else{
        return 200;                                                 //RETURNS int LITERAL
    }
}

int main(int argc, char **argv){
    auto res = process_deduce(100);
    std::cout << "Result is: " << res << std::endl;
    std::cout << "Size of result is: " << sizeof(res) << std::endl;
    return 0;
}

//RESULTS IN COMPILER ERROR AS THERE IS A CONFLICT OF RETURN TYPES
//TO GET AROUND THIS PROBLEM, WE EITHER NEED TO CHANGE THE RETURN TYPE OF THE FUNCTION OR WE NEED TO EXPLICITLY CAST THE TYPES
/*auto process_deduce_mix(int a){
    if(a > 100){
        return 55;                                                  //RETURNS int LITERAL
    }
    else{
        return 200.99;                                              //RETURNS double LITERAL
    }
}*/

//CHANGING THE RETURN TYPE OF FUNCTION
//BUILDS SUCCESFULLY
double process_deduce_mix_return(int a){
    if(a > 100){
        return 55;                                                  //RETURNS int LITERAL
    }
    else{
        return 200.99;                                              //RETURNS double LITERAL
    }
}

//EXPLICITLY CAST THE DATA TO MAKE RETURN TYPES CONSISTENT
//BUILDS SUCCESFULLY
auto process_deduce_mix_cast(int a){
    if(a > 100){
        return 55;                                                  //RETURNS int LITERAL
    }
    else{
        return static_cast<int>(200.99);                            //RETURNS double LITERAL BUT EXPLICITLY CASTED TO int 
    }
}