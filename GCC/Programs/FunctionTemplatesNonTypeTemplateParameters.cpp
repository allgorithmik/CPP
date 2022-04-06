#include<iostream>

//When it comes non-typed template params in C++, there are some points to be noted:
//As of C++20, non-typed params can be of any built-in types(int, double, bool etc), enumeration, pointer or reference type
//Any class with only public members can also be used. Such class types can be nested and be used as non-type template params as well
//In C++17 and below, only int like types could be used as non-type template params
//Floating point and class type non-type template params can be handy in some applications

//prototype of NON-TYPE function template => typenames are just placeholders for TYPES where they can hold ANY valid type calling the function template instance
template<typename T, typename P> auto maximum(T a, P b);

//prototype of TYPED function template => Here the type is directly declared into the template => this can hold only the value of the type declared and NOT the type

template<int threshold, typename T> auto maximumTyped(T collection[], size_t size){
    T sum {};
    for(size_t i; i < size; ++i){
        sum += collection[i];
    }
    return (sum > threshold)? true : false;
}

//REMEBER THE ORDER OF PARAMS MATTER IN OVERLOADING TEMPLATE FUMCTIONS => GOT COMPILER ERROR AND WASTED A LOT OF TIME BECAUSE THE OVERLOADED TEMPLATE (LINE 14 AND 37(CALL))
//WAS COMMENTED AND HAS FORGOTTEN TO UNCOMMENT THE SAME
//USE https://wandbox.org/ TO TRY LATEST C++ COMPILERS TO TRY REMOVING "'double' is a non-standard template param error"
template<typename T, double limit> auto maximumTyped(T collection[], size_t size){          //WARNING=>saying 'double' is non-standard template param=>look NOTES from line 3
    T sum {};
    for(size_t i; i < size; ++i){
        sum += collection[i];
    }
    return (sum > limit)? true : false;
}

int main(int argc, char **argv){

    double nums[] {10.99, 11.99, 12.99, 13.99, 14.99, 15.99, 16.99, 17.99, 18.99, 19.99};

    std::cout << "Calling TYPED function template:" << std::endl;
    auto res1 = maximumTyped<200, double>(nums, 10);                                        //passing an int VALUE as non-type param
    std::cout << "Result is: " << res1 << std::endl;

    auto res2 = maximumTyped<double, 99.99>(nums, 10);                                      //IGNORE THE ERROR => IT IS CAUSED DUE TO double NON-TYPE PARAM NOT BEING
    std::cout << "Result of res2 is: " << res2 << std::endl;                                //SUPPORTED STILL

    return 0;
}

template<typename T, typename P> auto maximum(T a, P b){
    return (a > b)? a : b;
}