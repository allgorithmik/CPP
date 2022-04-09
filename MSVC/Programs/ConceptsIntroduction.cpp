#include<iostream>
#include<concepts>                                                  //DO NOT FORGET TO #include WHILE USING CONCEPTS

//Concepts are available only in C++20
//Concepts are a mechanism to place constraints on our template type parameters => CONCEPTS WILL ONLY CHECK FOR SYNTAX COMPATIBLE OPERATIONS UNLESS std::is_<type_traits> USED
//There are two types of concepts avaialble in C++20 => Standard Concepts, which come with standard library and Custom Concepts to create our own concepts

//IMPLEMENTING CUSTOM CONCEPTS:
//syntax for implementing custom concepts: template<typename T> concept <concept_name> = <expression / statement / code block>
template<typename T> concept integral = std::is_integral<T>::value; //concept with type trait using std::is_integral<T>::value method (boolean)

template<typename T> concept integral_v = std::is_integral_v<T>;    //concept with type trait using std::is_integral_v<T> method

template<typename T> concept multiplier = requires(T a, T b){       //concept with requires clause with a code block
    a * b;                                                          //no return statement because this is still just a custom concept implementation => return wll be needed
};                                                                  //only while using this concept

template<typename T> concept increment = requires(T a){             //concept with requires clause with a code block
    ++a;                                                            //no return statement because this is still just a custom concept implementation => return wll be needed
    a++;                                                            //only while using this concept
    a += 10;
};

//USING THE CUSTOM CONCEPTS:
//syntax for using custom concepts: template<typename T> requires <custom_concept_name<datatype>> <teturn_type> <template_name>(T param1, T param2...T param n){<code block>}
template<typename T> requires integral<T> T add_1(T a, T b){        //using custom concept as requires clause in a function template => integral is the custom concept
    return a + b;                                                   //requires BEFORE FUNCTION
}

template<integral T> T add_2(T a, T b){                             //using custom concept as typename in a function template => integral is the custom concept
    return a + b;
}

//template<typename T> T add_2(T a, T b) requires integral<T>{        //using custom concept as typename in a function template => integral is the custom concept
//  return a + b;                                                   //requires AFTER FUNCTION
//}

integral auto add_3(integral auto a, integral auto b){              //using custom concept as return type and typename in a function
    return a + b;
}

template<typename T> requires multiplier<T> T add_4(T a, T b){      //using custom concept with multiple lines with a function template
    return a + b;
}

template<multiplier T> T add_5(T a, T b){                           //using custom concept with multiple line as a typename in a function template
    return a *  b;
}

multiplier auto add_6(multiplier auto a, multiplier auto b){        //using custom concept with multiple lines as return type and typename in a function
    return a + b;
}

template<typename T> requires increment<T> T incre1(T a, T b){
    return a + b;
}

template<increment T> T incre2(T a, T b){
    return a + b;
}

increment auto incre3(increment auto a, increment auto b){
    return a + b;
}

int main(int argc, char **argv){
    int a {100};
    int b {200};
    double c {300.99};
    double d {400.99};

    auto res1 = add_1(a, b);                                        //capturing the result of add_1() with std::is_integral concept to res1              
    std::cout << "add_1() with is_integral : " << res1 << std::endl;
    //add_1(c, d);                                                  //AS EXPECTED A COMPILER ERROR WHILE PASSING double PARAMS / ARGS TO AN std::is_integral CUSTOM CONCEPT

    auto res2 = add_2(a, b);                                        //capturing the result of add_2() with std::is_integral concept to res2
    std::cout << "add_2() with is_integral : " << res2 << std::endl;
    //add_2(c, d);                                                  //AS EXPECTED A COMPILER ERROR WHILE PASSING double PARAMS / ARGS TO AN std::is_integral CUSTOM CONCEPT

    auto res3 = add_4(a, b);                                        //capturing the result of add_3() with std::is_integral concept to res3
    std::cout << "add_4() with multiplying concept: " << res3 << std::endl;

    auto res4 = add_4(c, d);                                        //NO COMPILER ERROR AS THERE IS NO RESTRCTION OF TYPE TRAITS, ONLY ENFORCING OF * OPERATOR => WHICH WORKS
    std::cout << "add_4() with multiplying concept: " << res4 << std::endl;//EVEN FOR ALL COMPATIBLE TYPES INCLUDING double AS THE CASE HERE

    auto res5 = add_5(a, b);                                        //NO COMPILER ERROR AS THERE IS NO RESTRCTION OF TYPE TRAITS, ONLY ENFORCING OF * OPERATOR => WHICH WORKS
    std::cout << "add_5() with multiplying concept: " << res5 << std::endl;//EVEN FOR ALL COMPATIBLE TYPES INCLUDING double AS THE CASE HERE

    auto res6 = add_5(a, b);                                        //NO COMPILER ERROR AS THERE IS NO RESTRCTION OF TYPE TRAITS, ONLY ENFORCING OF * OPERATOR => WHICH WORKS
    std::cout << "add_5() with multiplying concept: " << res6 << std::endl;//EVEN FOR ALL COMPATIBLE TYPES INCLUDING double AS THE CASE HERE

    auto res7 = incre1(a, b);                                       //NO COMPILER ERROR AS THERE IS NO RESTRICTION OF TYPE TRAITS, ONLY ENFORCING OF ++ / += OPERATORS
    std::cout << "incre1() with multiple lines concept: " << res7 << std::endl;//=> WHICH WORKS FOR ALL COMPATIBLE TYPES INCLUDING int AS THE CASE HERE

    auto res8 = incre2(c, d);                                       //NO COMPILER ERROR AS THERE IS NO RESTRICTION OF TYPE TRAITS, ONLY ENFORCING OF ++ / += OPERATORS
    std::cout << "incre2() with multiple lines concept: " << res8 << std::endl;//=> WHICH WORKS FOR ALL COMPATIBLE TYPES INCLUDING double AS THE CASE HERE

    auto res9 = incre3(a, b);                                       //NO COMPILER ERROR AS THERE IS NO RESTRICTION OF TYPE TRAITS, ONLY ENFORCING OF ++ / += OPERATORS
    std::cout << "incre3() with multiple lines concept: " << res9 << std::endl;//=> WHICH WORKS FOR ALL COMPATIBLE TYPES INCLUDING int AS THE CASE HERE
    return 0;
}