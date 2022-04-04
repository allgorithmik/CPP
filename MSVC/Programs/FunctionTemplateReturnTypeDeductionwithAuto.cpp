#include<iostream>

//FUNCTION TEMPLATES WERE HAVING AN EXCLUSIVE PARAM SOLELY FOR THE RETURN TYPE => THIS GAVE RISE TO THE COMPLICATION OF THE PARAM ORDER BEING IMPORTANT => THAT IS THE
//FURTHER THE RETURN TYPE PARAM IS IN THE FUNCTION TEMPLATE'S PARAM / ARGS LIST, THE MORE CONSTRAINED IT IS FOR THE COMPILER TO DEDUCE THE RETURN TYPE OF THE TEMPLATE
//ANOTHER STRAIGHT FORWARD SOLUTION FOR THIS IS TO USE auto TYPE DEDUCTION
//auto TYPE DEDUCTION OF RETURN TYPE OF FUNCTION TEMPLATES
//template<typename T, typename P> auto <template_name>(T a, P b)

template<typename T, typename P> auto maximum(T a, P b);                                        //PROTOTYPE OF FUNCTION TEMPLATE WITH AUTO RETURN TYPE

template<typename T, typename P> auto maximum(T a, P b){                                        //function template's definition must be BEFORE main() as auto is involved
    return (a > b)? a : b;                                                                      //whichever param / arg is greater (as per function logic), its respective
}                                                                                               //type will be deduced as the function template's type
//OBVIOUSLY THIS DEPENDS ON THE FUNCTON TEMPLATE'S LOGIC AS IS THE CASE WITH maximum()'s LOGIC

int main(int argc, char **argv){

    int a {10};
    int b {20};

    double c {10.99};
    double d {11.00};

    auto res1 = maximum(a, c);
    auto res2 = maximum<int, float>(b, c);                                                      //we can also force the return type by using explicit return type arguments
    auto res3 = maximum(b, c);
    std::cout << "Result of maximum(int, double) is: " << res1 << std::endl;
    std::cout << "maximum()'s return type has been deduced as: " << sizeof(res1) << std::endl;  //return type deduced as double as double is greater
    std::cout << "Result of maximum(int, double) is: " << res2 << std::endl;
    std::cout << "maximum()'s return type has been deduced as: " << sizeof(res2) << std::endl;  //return type deduced as int as int is greater(explicit type deduction args)
    return 0;
}