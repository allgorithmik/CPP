#include<iostream>
//                          ONLY WHEN THE PROGRAM IS COMPILED THE ERRORS SHOW UP NOT WITH INTELLISENSE WHILE COMPOSING THE CODE

//WE CAN HAVE MULTIPLE TEMPLATE PARAMETERS INSTEAD OF JUST ONE:
//template<typename T, typename P, ...typename<param_name>> P <template_name(T param, P param, ...<param_name><param>)> => NOTICE the return type, its dependent on the order,
//this is not feasible as the return type keeps changing as per the the order in which the params / args are passed
//THE ELEGANT SOLUTION IS TO HAVE A SEPERATE PARAM EXCLUSIVELY FOR THE RETURN TYPE:
//template<typename RETURNTYPE, typename T, typename P...typename N> RETURNTYPE <template_name>(T param, P param...N param);

template<typename ReturnType, typename T, typename P> ReturnType maximum(T a, P b); //function template prototype with ReturnType as FIRST explicit type argument
template<typename T, typename ReturnType, typename P> ReturnType maximum(T a, P b); //function template prototype with ReturnType as SECOND explicit type argument
template<typename T, typename P, typename ReturnType> ReturnType maximum(T a, P b); //function template prototype with ReturnType as THIRD explicit type argument

int main(int argc, char **argv){
    int a {100};
    int b {200};

    double c {10.99};
    double d {20.99};

    char e {'A'};
    char f {'T'};

    //WE HAVE TO EXPLICITLY (FUNCTION TEMPLATE TYPE DEDUCTION BY EXPLICIT TYPE ARGUMENTS CHAPTER) MENTION THE PARAM / ARGS TO HELP THE COMPILER DEDUCE THE RETURN TYPE AS IT
    //HAS NO WAY OF DEDUCING IT BY ITSELF => ELSE COMPILER ERROR => THE POINT IS THE FIRST EXPLICIT TYPE ARGUMENT MUST MATCH THE DECLARED RETURN TYPE => ORDER MATTERS
    //int res1 = maximum<int, int, double>(a, c);                                     //compiler type deduction => int => ReturnType, int => T, double => P
    //int res2 = maximum<int, double, double>(c, d);                                  //compiler type deduction => int => ReturnType, double => T, double => P
    //int res3 = maximum<int>(c, d);                                                  //compiler type deduction=>int => ReturnType, T and P will be deduced as per function call
    //SO IF THE FIRST EXPLICIT TYPE ARGUMENT MUST ALWAYS MATCH THE DECLARED RETURN TYPE, CAN WE LEAVE THE REST OF PARAMS/ ARGS EMPTY?????

    //COMPILER ERROR AS WE ARE NOT HELPING THE COMPILER DEDUCE THE RETURN TYPE BY EXPLICIT TYPE ARGUMENTS => NO maximum<>
    //int res4 = maximum(a, b);

    //std::cout << res1 << std::endl;
    //std::cout << res2 << std::endl;
    //std::cout << res3 << std::endl;

    //ORDER OF EXPLICIT TYPE ARGUMENTS MATTERS: => THE FURTHER THE RETURNTYPE PARAM IS IN THE PARAM LIST, THE MORE CONSTRAINED IT BECOMES FOR THE COMPILER TO DEDUCE THE
    //RETURN TYPE
    //POSSIBLE CALLS FOR maximum() FOR TEMPLATE template<typename ReturnType, typename T, typename P> ReturnType maximum(T a, P b)
    int max1 = maximum<int, char, long>('T', 12L);                                      //OK => DEDUCES T => char, P => long
    int max2 = maximum<int, char>('T', 100L);                                           //OK => DEDUCES T => char, P => long
    int max3 = maximum<int>(100.99, 'T');                                               //OK => DEDUCES T => double, P => char
    //int max4 = maximum(100, 200);                                                     //COMPILER ERROR AS WE HAVE NOT MENTIONED THE EXPLICIT TYPE DEDUCTION ARGUMENT

    //POSSIBLE CALLS FOR maximum() FOR TEMPLATE template<typename T, typename ReturnType, typename P> ReturnType maximum(T a, P b)
    int max5 = maximum<char, int, long>('T', 12L);                                      //OK => DEDUCES T => char, P => long
    int max6 = maximum<char, int>('T', 100L);                                           //OK => DEDUCES T => char, P => long
    int max7 = maximum<char>('T', 15L);                                                 //OK => DEDUCES T => char, P => long => BUT NOT SHOWING COMPILER ERROR ?
    //int max8 = maximum(100, 200);                                                     //COMPILER ERROR AS WE HAVE NOT MENTIONED THE EXPLICIT TYPE DEDUCTION ARGUMENT

    //POSSIBLE CALLS FOR maximum() FOR TEMPLATE template<typename T, typename P, typename ReturnType> ReturnType maximum(T a, P b)
    int max9 = maximum<char, long, int>('T', 12L);                                      //OK => DEDUCES T => char, P => long
    int max10 = maximum<char, long>('T', 100L);                                         //OK => DEDUCES T => char, P => long
    int max11 = maximum<char>('T', 15L);                                                //OK => DEDUCES T => char, P => long => BUT NOT SHOWING COMPILER ERROR ?
    //int max12 = maximum(100, 200);                                                    //COMPILER ERROR AS WE HAVE NOT MENTIONED THE EXPLICIT TYPE DEDUCTION ARGUMENT

    std::cout << "Template: template<typename ReturnType, typename T, typename P> ReturnType maximum(T a, P b)" << std::endl;
    std::cout << "maximum(): with maximum<int, char, long>: " << max1 << std::endl;
    std::cout << "maximum(): with maximum<int, char>: " << max2 << std::endl;
    std::cout << "maximum(): with maximum<int>: " << max3 << std::endl;

    std::cout << "Template: template<typename T, typename ReturnType, typename P> ReturnType maximum(T a, P b)" << std::endl;
    std::cout << "maximum(): with maximum<char, int, long>: " << max5 << std::endl;
    std::cout << "maximum(): with maximum<char, int>: " << max6 << std::endl;
    std::cout << "maximum(): with maximum<char>: " << max7 << std::endl;

    std::cout << "Template: template<typename T, typename P, typename ReturnType> ReturnType maximum(T a, P b)" << std::endl;
    std::cout << "maximum(): with maximum<char, long, int>: " << max9 << std::endl;
    std::cout << "maximum(): with maximum<char, long>: " << max10 << std::endl;
    std::cout << "maximum(): with maximum<char>: " << max11 << std::endl;
    return 0;
}
//COMMENT THE APPROPRIATE TEMPLATE FUNCTION BASED ON WHICH TEMPLATE FUNCTION TO DEMO
template<typename ReturnType, typename T, typename P> ReturnType maximum(T a, P b){
    return (a > b)? a : b;
}

template<typename T, typename ReturnType, typename P> ReturnType maximum(T a, P b){
    return (a > b)? a : b;
}

template<typename T, typename P, typename ReturnType> ReturnType maximum(T a, P b){
    return (a > b)? a : b;
}