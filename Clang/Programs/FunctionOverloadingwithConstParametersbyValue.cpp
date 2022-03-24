#include<iostream>

//IN FUNCTIONS WHERE PARAMS / ARGS ARE PASSED BY VALUE, const IN THE FUNCTION SIGNATURE DOES NOT QUALIFY FOR FUNCTION OVERLOADING CRITERIA
int max(int a, int b);                                          //function prototype with non const params / args
int max(const int a, const int b);                              //function prototype with const params / args => ALSO MENTIONING const IN THE PROTOTYPE HERE IS USELESS

int main(int argc, char **argv){
    int a {100};
    int b {200};

    std::cout << "calling max(): " << max(a, b) << std::endl;   //COMPILER ERROR => REDEFINITION
    return 0;
}

//FOR THE COMPILER, BELOW TWO FUNCTIONS ARE THE SAME, WHETHER THEIR PARAMS / ARGS ARE const OR non-const => THIS IS BECAUSE COMPILER MAKES COPIES OF THE PARAMS / ARGS AS
//WE ARE PASSING THE PARAMS / ARGS AS VALUES, HENCE ANY CHANGES TO THE VALUES WILL NOT AFFECT THE ORIGINAL VARIABLES, SO MENTIONING const DOES NOT MAKE A DIFFERENCE
int max(int a, int b){                                          //function defintion of non const params / args
    std::cout << "non const variant" << std::endl;
    return (a > b)? a : b;
}
//REMOVING THIS FUNCTION TO SOLVE THE REDIFINTION COMPILER ERROR OCCURED IN LINE 11
//int max(const int a, const int b){                              //function defintion of const params / args => ANY const IF REQUIRED MUST BE MENTIONED HERE IRRESPCTIVE
//   std::cout << "const variant" << std::endl;                  //OF WHETHER ITS MENTIONED IN ITS PROTOTYPE OR NOT => MENTIONING const IN PROTOTYPE DOES NOT HAVE ANY EFFECT
//    return (a > b)? a : b;
//}