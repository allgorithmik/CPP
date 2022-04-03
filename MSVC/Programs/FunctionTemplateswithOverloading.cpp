#include<iostream>
#include<cstring>

//WHEN FUNCTION TEMPLATES ARE OVERLOADED => THERE IS A PRECEDENCE INVOLVED => A RAW OVERLOAD WILL TAKE PRECEDENCE OVER ANY TEMPLATE INSTANCE IF
//const char* IS PASSED TO FUNCTION TEMPLATES
//WHEN A POINTER IS PASSED TO AN OVERLOADED TEMPLATE => POINTER WILL TAKE PRECEDENCE OVER RAW T TYPE
//ALSO THE COMPILER TAKES INTO ACCOUNT THE COMPUTE OVERHEAD=>IT PREFERS THE RAW FUNCTIONS OVER FUNCTION TEMPLATES AS THERE IS NO NEED TO CREATE FUNCTION INSTANCES AT RUNTIME

//THE POINT OF THIS CODE IS => ASSUMING WE PASS cstrings AS PARAMS / ARGS TO A FUNCTION, THE COMPILER LOOKS FOR EITHER A MATCHING RAW FUNCTION OR A FUNCTON TEMPLATE (IN THIS
//CASE WE HAVE A MATCHING RAW FUNCTION IN LINE 52), AND CHOOSES THE RAW FUNCTION => ASSUMING THE RAW FUNCTION DOES NOT EXIST, THEN IT CHOOSES THE OVERLOADED FUNCTION
//TEMPLATE (WHICH ALSO EXISTS AT LINE 47) AND IT CHOOSES THE OVERLOADED FUNCTION TEMPLATE => ASSUMING EVEN THE OVERLOADED FUNCTION TEMPLATEDOES NOT EXIST, THEN IT CHOOSES
//NORMAL FUNCTION TEMPLATE (WHICH ALSO EXISTS AT LINE 42 FOR THE SAKE OF THIS LESSON)

template<typename T> T maximum(T a, T b);                                           //normal function template prototype
template<typename T> T *maximum(T *a, T *b);                                        //OVRLOADED FUNCTION TEMPLATE PROTOTYPE => YES FUNCTION TEMPLATES CAN ALSO BE OVERLOADED
const char *maximum(const char *a, const char *b);                                  //normal function prototype

int main(int argc, char **argv){
    int a {100};
    int b {200};

    double c {100.99};
    double d {200.99};

    std::string s1 {"Hello "};
    std::string s2 {"Mars"};

    const char *e {"Hello "};
    const char *f {"Mars"};

    std::cout << "Passing ints to maximum(): " << maximum(a, b) << std::endl;       //invokes the normal function template 
    std::cout << "Passing double to maximum(): " << maximum(c, d) << std::endl;     //invokes the normal function template
    std::cout << "Passing string to maximum(): " << maximum(s1, s2) << std::endl;   //invoked the normal function template
    std::cout << "Passing address to maximum(): " << maximum(&a, &b) << std::endl;  //invoked the overloaded function template as we pass pointers as its equvivalent(address)
    //function template is exists
    std::cout << "Passing const char* to maximum(): " << maximum(e, f) << std::endl;//RAW FUNCTION INVOKED => OVERLOADED FUNCTION IS NOT INVOKED BECAUSE OF PRECEDENCE i.e
    //BECAUSE THE RAW FUNCTION WITH APPROPRIATE FUNCTION SIGNATURE EXISTS, PRECEDENCE IS GIVEN TO THIS FUNCTION ELSE OVERLOADED FUNCTION TEMPLATE WOULD BE INVOKED
    //IF RAW FUNCTION IS COMMENTED OUT, THEN THE OVERLOADED FUNCTION TEMPLATE INSTACE IS CALLED
    return 0;
}

template<typename T> T maximum(T a, T b){                                           //normal function template definition
    std::cout << "Normal Function Template Invoked(T)" << std::endl;
    return (a > b)? a : b;
}

template<typename T> T *maximum(T *a, T *b){                                        //OVRLOADED FUNCTION TEMPLATE DEFINITION => YES FUNCTION TEMPLATES CAN ALSO BE OVERLOADED
    std::cout << "Overloaded Function Template Invoked(T*)" << std::endl;
    return (*a > *b)? a : b;
}

const char *maximum(const char *a, const char *b){                                  //normal function definition (commenting this out to invoke overloaded function template)
    std::cout << "Raw Function Invoked" << std::endl;
    return (std::strcmp(a, b) > 0)? a : b;                                          //lexicographical string comparison (negative : 0 : positive)
}