#include<iostream>

//INLINE FUNCTIONS IS USED TO AVOID FUNCTION CALL OVERHEAD. INLINE FUNCTIONS MUST BE SIMPLER. ANY COMPLEX TASKS MUST BE STILL IMPLEMENTED IN REGULAR FUNCTIONS

//regular non-inline function
/*                                                      //temporarily commenting this out to avoid redefinition compiler error
int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
} */

//inline function
//WHEN COMPILER COMES ACROSS THE inline KEYWORD, IT TRIES TO REPLACE THE FUNCTION CALL WITH FUNCTION DEFINTION INPLACE => inlines ARE COMPLETELY UNDER COMPILER'S DESCRETION
//COMPILER CAN CHOOSE TO IGNORE inline STATEMENT AND CHOOSE TO CALL THE FUNCTION IN REGULAR MANNER => USING inline EXTENSIVELY CAN INCREASE THE SIZE OF THE BINARY
//SIGNIFICANTLY AS ITS inline IS JUST COPYING THE ENTIRE FUNCTION DEFINITION AND PASTING THE SAME INPLACE WHEREVER THE FUNCTION IS CALLED 
inline int max(int a, int b){                           //INLINE FUNCTIONS CAN BE IMPLEMENTED BY INSERTING THE KEYWORD "inline" IN THE FUNCTION SIGNATURE
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int main(int argc, char **argv){

    int a {100};
    int b {200};
    std::cout << "max():" << max(a, b) << std::endl;
    return 0;
}