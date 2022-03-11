#include<iostream>

//WHEN PASSING A SIZED ARRAY REFERENCE AS A PARAM/ARGS => THE COMPILER STRICTLY ENFORCES THE SIZE => NO MORE, NO LESS, THIS IS BECAUSE THE REFERENCE IS A TRUE REFERENCE
double sum(const double (&array)[10]);                                                      //function prototype

//reference array syntax:                                                                   //size is optional because when an array with size is passed as a param / arg
//(&<array_name>[<size>])                                                                   //compiler will NOT enforce the size strictly

double result {};                                                                           //global variable declaration

int main(int argc, char **argv){

    double values[] {10.55, 55.10, 45.15, 20.15, 40.50, 60.70, 80.90, 30.20, 10.20, 35.45}; //if array size is declared and less elements are initialized, the difference
    double values1[] {10.55, 55.10, 45.15, 20.15, 40.50};                                   //is filled by default values of array type in this case 0.0 until array is filled

    std::cout << "Calling sum()" << std::endl;

    double var1 = sum(values);

    std::cout << "Calling sum() with correct number of elements: " << var1 << std::endl;

    //double var2 = sum(values1);                                                           //this is illegal in C++ because when a sized array is passed as reference, the
    //std::cout << "Calling sum() with less number of elements: " << var2 << std::endl;     //compiler STRICTLY ENFORCES the array size while passing the array as param/args

    return 0;
}

//NORMALLY WHEN AN ARRAY IS PASSED BY VALUE, THE ARRAY TENDS TO DECAY INTO A POINTER AND LOSES ITS SIZE INFO AND WE CANNOT USE std::size() THE PASSED BY VALUE ARRAY
//=>BUT WHEN THE ARRAY IS PASSED AS A REFERENCE, IT IS A TRUE REFERENCE AND IT PRESERVES ALL THE INFO RELATED TO SIZE HENCE WE CAN USE std::size() and
//ALSO RANGED for LOOPS
double sum(const double (&array)[10]){                                                      //function definition

    double result_local {};

    for(size_t i {}; i < std::size(array); ++i){                                            //std::size() is possible as the array is passed as reference
        result_local += array[i] + 10;
        //++array[i];                                                                       //array elements cannot be modified as the array is CONST
    }

    for(size_t value : array){
        result += value;
    }

    return result;
}