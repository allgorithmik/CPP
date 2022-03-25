#include<iostream>
/*
LAMBDA FUNCTIONS is a technique to set up anonymous functions(without names). Once we have them set up, we can either assign them names and invoke them or call them
directly without assgning any names
LAMBDA FUNCTION SIGNATURE:
[capture_list] (parameters) -> return type(optional) {
      function body    
};
[](){std::cout << "This is a lambda function";};

ASSIGNING A NAME FOR A LAMBDA FUNCTION
auto <function_name> = [](){<function_body>};         (this lambda function is having auto as its type because return type is not mentioned)
if we do not provide any return type, the compiler will automatically deduce the return type of the lambda function
CALLING A LAMBDA FUNCTION WITH NAME
<lambda_function_identifier>();                       (this lambda function has a name)

CALLING A LAMBDA FUNCTION WITHOUT NAME
[](){<function_body>}();                              (nameless lambda function must be called using a () after the ending })

DECLARING AND CALLING A NAMELESS LAMBDA FUNCTION WITH PARAMS / ARGS
[](param_list){<function_body>}(<args_list>); => [](double a, double b){std::cout << "sum is:" << (a + b) << std::endl;}(55.99, 100.99);

DECLARING AND CALLING A NAMED LAMBDA FUNCTION WITH PARAMS / ARGS
DECLARING => auto <function_identifier> = [](param_list){<function_body>};
CALLING => <function_identifier>(<args_list>);
EXAMPLE:
auto sum_lambda = [](double a, double b){std::cout << "sum is:" << (a + b) << std::endl;};
sum_lambda(55.99, 10.99);

DECLARING AND CALLING A NAMELESS LAMBDA FUNCTION WITH RETURN STATEMENT
[](){<function_body>; return<expression>}();
EXAMPLE:
DECLARING / CALLING => [](int a, int b){return (a + b)}(<10, 20>);

DECLARING AND CALLING A NAMED LAMBDA FUNCTION WITH RETURN STATEMENT
DECLARING => auto <function_identifier> = [](){<function_body>; return<expression>};
CALLING => <function_identifier>();
EXAMPLE: auto sum = [](int a, int b){return (a + b);};
sum(10, 20);

PLUGGING IN A LAMBDA FUNCTION INTO A std::cout STATEMENT
std::cout << "Lambda Function" << [](int a, int b){return (a + b);}(10, 20) << std::endl;

DECLARING / CALLING A NAMELESS LAMBDA FUNCTION WITH RETURN TYPE
[](int a, int b)->int{return (a + b);}(<args_list>);
EXAMPLE: [](int a, int b)->int{return (a + b);}(10, 20);

DECLARING / CALLING A NAMED LAMBDA FUNCTION WITH RETURN TYPE
DECLARING => auto res = [](int a, int b)->int{return (a + b);};
CALLING => res(<args_list>);
EXAMPLE: auto sum = [](int a, int)->int{return (a + b);};
sum(10, 20);
*/

int main(int argc, char **argv){

    //DECLARING / CALLING A NAMELESS LAMBDA FUNCTION
    [](){std::cout << "This is a NAMELESS LAMBDA function" << std::endl;};                      //valid C++ lambda function => just declared but NOT called => compiles fine
    [](){std::cout << "This is a NAMELESS LAMBDA function" << std::endl;}();                            //valid C++ lambda function => declared AND called => compiles fine

    //DECLARING / CALLING A NAMED LAMBDA FUNCTION
    //DECLARING:
    auto func1 = [](){std::cout << "This is a NAMED LAMBDA function" << std::endl;};            //valid C++ lambda function => just declared but NOT called => compiles fine
    //CALLING:
    func1();                                                                                            //calling the lambda function by its identifier

    //DECLARING / CALLING A NAMELESS LAMBDA FUNCTION WITH PARAMS / ARGS
    [](double a, double b){std::cout << "LAMBDA with params: " << (a + b) << std::endl;};       //lambda function with params => just declared but NOT called => compiles fine
    [](double a, double b){std::cout << "LAMBDA with params: " << (a + b) << std::endl;}(10, 20);       //lambda function with args => declared AND called => compiles fine

    //DECLARING / CALLING A NAMED LAMBDA FUNCTION WITH PARAMS / ARGS
    //DECLARING:
    auto func2 = [](double a, double b){std::cout << "LAMBDA with params: " << (a + b) << std::endl;};  //lambda function => just declared but NOT called => compiles fine
    //CALLING:
    func2(100, 200);                                                                                    //calling the lambda function by its identifier and its args list

    //DECLARING / CALLING A NAMELESS LAMBDA FUNCTION WITH RETURN STATEMENT
    [](int a, int b){std::cout << "NAMELESS LAMBDA with RETURN" << std::endl; return (a + b);};
    [](int a, int b){std::cout << "NAMELESS LAMBDA with RETURN" << std::endl; return (a + b);}          //return values are NOT BEING shown in output because we are not
    (50, 55);                                                                                           //capturing the returned value in a variable and calling that variable

    //DECLARING / CALLING A NAMED LAMBDA FUNCTION WITH RETURN STATEMENT
    //DECLARING:
    auto func3 = [](int a, int b){std::cout << "NAMED LAMBDA with RETURN" << std::endl; return (a + b);};//return values are NOT BEING shown in output because we are not
    //CALLING:
    func3(200, 200);                                                                                    //capturing the returned value in a variable and calling that variable
    int res1 = func3(200, 200);
    std::cout << "Captured value from func3(): " << res1 << std::endl;                                  //value captured and displayed

    //DECLARING / CALLING A NAMELESS LAMBDA FUNCTION WITH RETURN TYPE
    [](float a, float b)->float{std::cout << "NAMELESS LAMBDA with RETURN TYPE" << std::endl; return (a + b);}; //lambda function with return type declared but NOT called
    [](float a, float b)->float{std::cout << "NAMELESS LAMBDA with RETURN TYPE" << std::endl; return (a + b);}; //lambda function with return type declared AND called
    (1.99, 2.99);

    //DECLARING / CALLING A NAMED LAMBDA FUNCTION WITH RETURN TYPE
    //DECLARING:
    auto func4 = [](float a, float b)->float{std::cout << "NAMED LAMBDA with RETURN TYPE"<< std::endl; return (a + b);};
    //CALLING:
    func4(1.99, 2.99);                                                                                  //value is not captured hence not being displayed when called
    float res2 = func4(1.99, 2.99);
    std::cout << "Captured value from func4: " << res2 << std::endl;                                    //value captured and displayed

    //FORCING THE LAMBDA FUNCTION TO RETURN VALUES OF OUR CHOICE
    double d1 {99.99};
    double d2 {55.99};
    //LAMBDA FUNCTIONS IMPLICITLY CAST THE RESULTS AS PER THE DECLARED TYPE IN LAMBDA FUNCTION DECLARATION
    auto func5 = [](double a, double b)->int{std::cout << "Forcing the LAMBDA to return int even though passed with double params / args" << std::endl; return (a + b);};
    auto func6 = [](double a, double b){std::cout << "Making the LAMBDA to return the same type as the parms passed to it: " << std::endl; return (a + b);};

    auto res3 = func5(d1, d2);
    auto res4 = func6(d1, d2);
    
    std::cout << "Size of func5() WITH -> int return type: " << sizeof(res3) << std::endl;              //size is 4 => int IS returned as per our return type declaration
    std::cout << "Size of func6() WITHOUT any return type: " << sizeof(res4) << std::endl;              //size is 8=>double IS returned as we did not specify any return type

    return 0;

    
}