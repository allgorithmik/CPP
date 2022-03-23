#include<iostream>

//POINTERS POINTING TO DIFFERENT TYPES ARE CONSIDERED AS DIFFERENT TYPES

int max(int *numbers, size_t count);                                                    //function prototype with an int pointer and size_t params / args => valid overload
double max(double *numbers, size_t count);                                              //function prototype with a double pointer and size_t params / args => valid overload

//BE CAREFUL ABOUT THE BELOW FUNCTION DECLARATIONS AS THEY CANNOT BE CONSIDERED AS OVERLOADED FUNCTIONS:
//a valid function declaration for comparison with below functions:
int _max(int *numbers, size_t count);

//cannot be considered as an overload of line 9 function because aarays get decomposed to first element
int _max(int numbers[], size_t count);

//cannot be considered as an overload of line 9 function because its the same as line 10 function but just with a array size
int _max(int numbers[10], size_t count);

int main(int argc, char **argv){

    int inums[] {1,2,3,4,5,6,7,8,9,10};                                                 //DO NOT DECLARE AS POINTER ARRAY => COMPILER ERROR
    double dnums[] {1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1};                 //DO NOT DECLARE A SPOINTER ARRAY => COMPILER ERROR

    std::cout << "max() on int array: " << max(inums, std::size(inums)) << std::endl;   //use std::size(<array>) to make code more dynamic instead of hard-coding size values
    std::cout << "max() on double array: " << max(dnums, std::size(dnums)) << std::endl;//use std::size(<array>) to make code more dynamic instead of hard-coding size values

    return 0;
}

int max(int *numbers, size_t count){                                                    //function overloaded with int pointer size_t param / args
    int m {};
    std::cout << "Invoking int variant" << std::endl;
    for(size_t i {}; i < count; ++i){
        if(numbers[i] > m){
            m = numbers[i];
        }
    }
    return m;
}

double max(double *numbers, size_t count){                                              //function overloaded with double pointer size_t param / args
    int m {};
    std::cout << "Invoking double variant" << std::endl;
    for(size_t i {}; i < count; ++i){
        if(numbers[i] > m){
            m = numbers[i];
        }
    }
    return m;
}