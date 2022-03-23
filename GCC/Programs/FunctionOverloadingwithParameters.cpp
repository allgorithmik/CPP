#include<iostream>

//FUNCTION OVERLOADING IS A TECHNIQUE WHEREIN DIFFERENT FUNCTIONS WITH SAME NAME CAN BE PASSED WITH DIFFERENT PARAMS / ARGS DURING RUNTIME.
//FUNCTION OVERLOADING IS NOT DEPENDENT ON RETURN TYPE => IF TWO FUNCTIONS WITH SAME NAME AND SAME PARAM / ARGS LIST EXIST BUT WITH A DIFFERENT RETURN TYPE, THIS IS NOT
//CONSIDERED AS FUNCTION OVERLOADING AND WILL RESULT IN COMPILER ERROR

//RULES FOR OVERLOADING A FUNCTION IN C++:
//FUNCTION NAME MUST BE SAME BUT PARAM / ARGS LIST MUST DIFFER
//PARAMS / ARGS LIST MUST DIFFER IN TERMS OF DATA TYPE, NUMBER OF PRAMS / ARGS, ORDER OF PARAMS / ARGS OR ANY COMBINATIONS OF THESE
//RETURN TYPE OF THE FUNCTION DOES NOT PLAY A ROLE IN FUNCTION OVERLOADING

int max(int a, int b);                                                                  //function prototype with int params and int return type with name max
double max(double a, double b);                                                         //function prototype with double params and double return type with name max
std::string max(std::string a, std::string b);                                          //function prototype with std::string params and std::string return type with name max
double max(int a, double b);                                                            //function prototype with a mix of params / args of different data types 
double max(double a, int b);                                                            //function prototype with a mix of params / args with different order
int max(int a, int b, int c);                                                           //function prototype with varying number of params / args

//cannot overload functions distinguished by return type alone => below function only the return type is differing but function name and param / args list are same as
//function in line 7, => this cannot be considered as overloaded function
//double max(int a, int b);                                                             //COMPILER ERROR    

int main(int argc, char **argv){
    int int1 {100};
    int int2 {500};
    int int3 {550};

    double do1 {55.99};
    double do2 {99.55};

    std::string str1 {"Hello"};
    std::string str2 {" Mars"};

    std::string_view strv1 {"Mars"};
    std::string_view strv2 {" Earth"};

    max(int1 , int2);
    max(do1 , do2);
    max(str1 , str2);
    max(strv1, strv2);                                                                  //implicitly std::string_view gets casted to std::string
    max(int1, do1);
    max(do2, int2);
    max(int1, int2, int3);

    std::cout << "Passing int params / args: " << max(int1 , int2) << std::endl;
    std::cout << "Passing double params / args: " << max(do1 , do2) << std::endl;
    std::cout << "Passing string params / args: " << max(str1 , str2) << std::endl;
    std::cout << "Passing string view params/args: " << max(strv1 , strv2) << std::endl;
    std::cout << "Passing int double params/args: " << max(int1, do1) << std::endl;
    std::cout << "Passing double int params/args: " << max(do2, int2) << std::endl;
    std::cout << "Passing three int params/args: " << max(int1, int2, int3) << std::endl;
    return 0;
}

int max(int a, int b){                                                                  //overloaded using data type
    std::cout << "Taking the int overloaded max()" << std::endl;
    return (a > b)? a : b;
}

double max(double a, double b){                                                         //overloaded using data type
    std::cout << "Taking the double overloaded max()" << std::endl;
    return (a > b)? a : b;
}

std::string max(std::string a, std::string b){                                          //overloaded using data type
    std::cout << "Taking the std::string overloaded max()" << std::endl;
    return (a > b)? a : b;
}

std::string_view max(std::string_view a, std::string_view b){                           //overloaded using data type
    std::cout << "Taking the std::string_view overloaded max()" << std::endl;
    return (a > b)? a : b;
}

double max(int a, double b){                                                            //overloaded using different data types to a single function
    std::cout << "Taking the int double overloaded max()" << std::endl;
    return (a > b)? a : b;
}

double max(double a, int b){                                                            //overloaded using order
    std::cout << "Taking the double int overloaded max()" << std::endl;
    return (a > b)? a : b;
}

int max(int a, int b, int c){                                                           //overloaded using number of params / args
    std::cout << "Taking the three int overloaded max()" << std::endl;
    int m = a;
    if(m > b){
        m = b;
    }
    else{
        m = c;
    }
    return m;
}