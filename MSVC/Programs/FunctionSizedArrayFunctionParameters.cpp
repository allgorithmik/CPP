#include<iostream>

double sum(double array[5], size_t count);                                                  //function prototype

int main(int argc, char **argv){
    double val[] {10.55};                                                                   //array with ust 1 element
    double value[] {10.55, 55.10, 45.15, 20.15, 40.50};                                     //array with 5 elements
    double values[] {10.55, 55.10, 45.15, 20.15, 40.50, 60.70, 80.90, 30.20, 10.20, 35.45}; //array with 10 elements

    double res1 = sum(value, 5);                                                            //COMPILER DOES NOT ENFORCE THE ARRAY SIZE VERY STRICTLY=>WILL ACCEPT == ELEMENTS
    std::cout << "Calling sum() with actual elements: " << res1 << std::endl;               //RECCOMENDED NOT TO MENTION ARRAY SIZE WHILE PASSING ARRAYS AS PARAMS / ARGS 

    double res2 = sum(values, 10);                                                          //COMPILER DOES NOT ENFORCE THE ARRAY SIZE VERY STRICTLY=>WILL ACCEPT > ELEMENTS
    std::cout << "Calling sum() with more elements: " << res2 << std::endl;                 //RECCOMENDED NOT TO MENTION ARRAY SIZE WHILE PASSING ARRAYS AS PARAMS / ARGS

    double res3 = sum(val ,1);                                                              //COMPILER DOES NOT ENFORCE THE ARRAY SIZE VERY STRICTLY=>WILL ACCEPT < ELEMENTS
    std::cout << "Calling sum() with less elements: " << res3 << std::endl;                 //RECCOMENDED NOT TO MENTION ARRAY SIZE WHILE PASSING ARRAYS AS PARAMS / ARGS

    return 0;
}

double sum(double array[5], size_t count){                                                  //function definition
    double result {};
    for(size_t i {}; i < count; ++i){
        result += i;                                                                        //possible because of non-const values
    }

    return result;
}