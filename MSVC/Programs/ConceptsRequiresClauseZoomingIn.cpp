#include<iostream>
#include<concepts>                                              //DO NOT FORGET TO #include<concepts> WHILE USING CONCEPTS

//ZOOMING IN ON REQUIRES CLAUSE:
//REQUIRES CLAUSE CAN TAKE FOUR TYPES OF REQUIREMENTS:
//SIMPLE REQUIREMENTS
//NESTED REQUIREMENTS
//COMPOUND EQUIREMENTS
//TYPE REQUIREMENTS

//SIMPLE REQUIREMENT: => ONLY CHECKS FOR SYNTAX
template<typename T> concept tinytype = requires(T t){          //THIS CONCEPT ONLY CHECKS FOR SYNTAX
    sizeof(T) <= 4;                                             //THIS STATEMENT ONLY CHECKS FOR SYNTAX
};

//NESTED REQUIREMENT:
template<typename T> concept tinytype_nested = requires(T t){   //THIS CONCEPT CHECKS FOR SYNTAX AND ALSO CHECKS IF THE EXPRESSION IS TRUE
    sizeof(T) <= 4;                                             //THIS STATEMENT ONLY CHECKS FOR SYNTAX
    requires sizeof(T) <= 4;                                    //THIS STATEMENT CHECKS IF THE EXPRESSION IS TRUE
};

//COMPOUND REQUIREMENT:
template<typename T> concept Addable = requires(T a, T b){
    {a + b} noexcept -> std::convertible_to<int>;               //THIS STATEMENT IS A COMPUND REQUIREMENT => HERE noexcept IS OPTIONAL
};                                                              //CHECKS IF a + b IS A VALID SYNTAX (DOES NOT THROW EXCEPTIONS(noexcept)) AND CONVERTS RESULT TO int

tinytype auto add1(tinytype auto a, tinytype auto b){            //FUNCTION WITH CONCEPT WHICH ONLY CHECKS FOR SYNTAX
    return a + b;                                               //TOTAL MUST BE LESS THAN 256 AS char SIZE IS 256 => NOT RELATED TO CONCEPT AS IT JUST CHECKS FOR SYNTAX
}

tinytype_nested auto add2(tinytype_nested auto a, tinytype_nested auto b){  //FUNCTION WITH CONCEPT WHICH ENFORCES BOTH SYNTAX AND EXPRESSION
    return a + b;
}

Addable auto add3(Addable auto a, Addable auto b){              //FUNCTION WITH CONCEPT WITH COMPOUND REQUIRES CLAUSE
    return a + b;
}

int main(int argc, char **argv){

    char x {100};
    char y {55};

    double a {10.99};
    double b {20.00};

    std::string c {"Hello "};
    std::string d {"Mars"};

    auto res1 = add1(x, y);                                     //add1() IS A FUNCTION WITH CONCET WHICH ONLY ENFORCES SYNTAX
    std::cout << "add1() with char: " << res1 << std::endl;     //EVALUATES TO TRUE AND SYNTAX ALSO HOLDS GOOD

    auto res2 = add1(a, b);                                     //add1() IS A FUNCTION WITH CONCEPT WHICH ONLY ENFORCES SYNTAX
    std::cout << "add1() with double: " << res2 << std::endl;   //EVALUATS TO FALSE BUT SYNTAX HOLDS GOOD => CONCEPTS ONLY CHECK FOR SYNTAX UNLESS std::is_<type_trait> USED

    auto res3 = add2(x, y);                                     //add2() IS A FUNCTION WITH CONCEPT WHICH ENFORCES FOR BOTH SYNTAX AND EXPRESSION
    std::cout << "add2() with char: " << res3 << std::endl;

    //auto res4 = add2(a, b);                                     //AS EXPPECTED COMPILER ERROR AS THE EXPRESSON IN add2()'s CONCEPT EVALUATES TO FALSE

    auto res4 = add3(a, b);                                     //add3() IS A FUNCTION WITH CONCEPT WITH COMPOUND REQUIRES CLAUSE WITH + OPERATOR (WHICH IS COMPATIBLE WITH
    std::cout << "add3() with double: " << res4 << std::endl;   //double PARAMS AS PASSED HERE) AND noexcept -> std::convertible_to<int> CLAUSE WHICH ALSO IS COMPATIBLE

    auto res5 = add3(x, y);                                     //add3() IS A FUNCTION WITH CONCEPT WITH COMPOUND REQUIRES CLAUSE WITH + OPERATOR (WHICH IS COMPATIBLE WITH
    std::cout << "add3() with char: " << res3 << std::endl;     //char PARAMS AS PASSED HERE) AND noexcept -> std::convertible_to<int> CLAUSE WHICH ALSO IS COMPATIBLE

    //AS EXPECTED COMPILER ERROR AS std::string PARAMS FAIL THE std::convertible_to<int> CLAUSE EVEN IT PASSES THE + OPERATOR CLAUSE
    //auto res6 = add4(c, d);
    return 0;
}