#include<iostream>

//while passing an aray as params for a functions in C++, IT IS MANDATORY to pass the count variable which denotes the number of elements in the array. This is done
//because, std::size(array) / size_of(array) functions will not work because the array will get decayed to a pointer if the array is passed as params for a function, hence
//it loses the size info => BUT std::size(array) / size(array) WILL work if used on regular / normal array ex. std::size(numbers) as below (line 13)

double sum(double scores[], size_t count);                                                   //function prototype

int main(int argc, char **argv){

    double numbers[] {10.55, 55.10, 45.15, 20.15, 40.50, 60.70, 80.90, 30.20, 10.20, 35.45};

    double result = sum(numbers, std::size(numbers));                                       //capturing the return value of function in a type compatible variable

    std::cout << "The result of sum(): " << result << std::endl;

    return 0;
}

double sum(double scores[], size_t count){                                                  //function definition
    double sum {};                                                                          //uniform initialized to 0

    scores[5] = 100.90;                                                                     //possible as the array is not const

    //size(scores) WILL GIVE "sizeof' on array function parameter 'scores' will return size of 'double*' [-Wsizeof-array-argument]" ERROR => but .exe executes successfully
    //the sizeof(array) WILL not change no matter the number of elements in the array
    std::cout << "Size of array(gets decayed to pointer): " << sizeof(scores) << std::endl; //WASTED A LOT OF TIME ON THIS ERROR => but build works
    std::cout << "Size of pointer: " << sizeof(int *) << std::endl;                         //the fact that all the results of sizeof() is 8 proves that the array gets
    std::cout << "Size of long int: " << sizeof(long int *) << std::endl;                   //decayed to a pointer and that the size of pointers is fixed for a system

    for(size_t i {}; i < count; ++i){
        sum += *(scores++);
    }
    return sum;
}