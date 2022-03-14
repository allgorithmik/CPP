#include<iostream>

//constexpr FUNCTIONS WILL BE COMPUTED AT COMPILE TIME INSTEAD OF RUNTIME, HENCE REDUCING COMPUTE TIME AT RUNTIME, FOR constexpr FUNCTIONS TO BE EFFECTIVE THE
//FUNCTION, ITS PARAMS / ARGS AND ALSO THE VARIABLE WHICH CAPTURES THE RESULT OF THE FUNCTION (IF ANY) MUST BE DECLARED constexpr, IF THE PARAM / ARGS IS NOT DECLARED
//constexpr OR IF THE VALUE OF THE PARAM / ARGS CAN ONLY BE EVALUATED ONLY AT RUNTIME OR EVEN THE VARIABLE WHICH CAPTURES THE RESULT OF THE FUNCTION IS non-constexpr,
//THEN THE ENTIRE FUNCTION WILL COMPUTE AT RUNTIME EVEN IF THE FUNCTION IS DECLARED constexpr

constexpr int compute_value(int multiplier){                //constexpr FUNCTION DEFINITIONS MUST EXIST BEFORE USAGE IN main(), ELSE COMPILER ERROR
    return multiplier * 100;                                //GOT COMPILER ERROR WHEN SPLITTING THE FUNCTION INTO PROTOTYPE AND DEFINTION
}                                                           //THIS APPLIES ONLY FOR constexpr FUNCTIONS, VARIABLES AND PARAMS/ARGS

int main(int argc, char **argv){
    //DO NOT FORGET THAT EVEN THE PARAMS / ARGS PASSED TO constexpr FUNCTIONS AND THE VARIABLE WHICH CAPTURES THE RESULT OF THE FUNCTION MUST BE DECLARED constexpr
    //ELSE THE ENTIRE FUNCTION WILL EXECUTE AT RUNTIME INSTEAD OF COMPILE TIME
    constexpr int val1 {100};
    //THIS FUNCTION ASSIGNMENT EXECUTES AT COMPILE TIME AS THE FUNCTION, PARAMS AND ITS RESULT VARIABLE ARE ALL DECLARED constexpr
    constexpr int res1 = compute_value(val1);               //result variable, function and its param / args are all constexpr, hence true compile time evaluation

    std::cout << "compute_value(): " << res1 << std::endl;  //compile time

    //AS THE PARAMS / ARGS ARE NOT DECLARED constexpr, THE FUNCTION WHICH ACCEPTS THIS PARAM / ARG WILL EXECUE AT RUNTIME, EVEN IF THE FUNCTION IS DECLARED constexpr
    int val2 {100};
    //THIS FUNCTION ASSIGNMENT EXECUTES AT RUNTIME AS ITS PARAMS ARE AND RESULT VARIABLE ARE non-constexpr BUT FUNCTION IS constexpr
    int res2 = compute_value(val2);                         //result variable and param / args are non-constexpr but function is constexpr, hence runtime execution

    std::cout << "compute_value(): " << res2 << std::endl;  //runtime

    return 0;
}