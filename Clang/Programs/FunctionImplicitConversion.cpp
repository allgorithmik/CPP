#include<iostream>

//WHEN WE PASS A PARAM / ARG OF A TYPE DIFFERENT THAN WHAT IS DECLARED IN THE FUNCTION SIGNATURE, THE COMPILER TRIES TO IMPLICITLY CAST THE VALUES TO MATCH THE DECLARED
//PARAM / ARGS TYPES = > IF THE IMPLCIT CAST FAILS, COMPILER ERROR WILL OCCUR
int sum(int a, int b);                                                                                                              //function prototype

int main(int argc, char **argv){
    int a {10};
    int b {20};
    double c {30.99};
    double d {35.99};
    char e {'A'};
    char f {'Z'};
    std::string g {"Hello"};
    std::string h {" C++"};
    std::cout << "Calling sum()" << std::endl;
    
    std::cout << "Calling sum() with correct data types: " << sum(a, b) << std::endl;
    std::cout << "Calling sum() with incorrect data types but implicitly casted (losing data): " << sum(c, d) << std::endl;
    std::cout << "Calling sum() with incorrect data types but implicitly casted but undesired result: " << sum(e, f) << std::endl;  //taking ASCII equivalent of integers
    //std::cout << "Calling sum() with incorrect data types but implicitly casted but cast fails: " << sum(g, h) << std::endl;      //COMPILER ERROR => CAST FAILS

    return 0;
}

int sum(int a, int b){                                                                                                              //function definition
    int res = a + b;
    return res;
}