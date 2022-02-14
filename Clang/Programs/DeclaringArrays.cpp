#include<iostream>

int main(int argc, char **argv){                                                                                    //declaring an array using [], this array holds 10 values of
    int array [10] {};                                                                                              //integers undar name 'array'                                                                              

    double array1[] {1.1, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5, 10.5};                                            //array declaration with initialization
    double array2[] {10};                                                                                           //array declaration for adding values using for loop
    int array3[] {1,2,3};                                                                                           //array initialization can be less than declared array size
    int array4[10] {};
    const int array5[] {1,2,3,4,5};                                                                                 //the values of this array cannot be changed, read only


    std::cout << "Value of 1st index of array: " << array[0] << std::endl;                                          //random value as its not initialized => now its initialized to 0
    std::cout << "Value of 1st index of array: " << array[100] << std::endl;                                        //somehow even out-of-bound indexing is also giving correct values
    std::cout << "Size of array: " << sizeof(array) << std::endl;                                                   //sizeof(array) will give 4 * 10, NOT length of array

    for(size_t i {}; i < 10; ++i){
        std::cout << "Reading values from array using for loop " << array1[i] << std::endl;
    }

    for(size_t i {}; i< 10; ++i){
        std::cout << "Adding values to array using for loop " << (array2[i] = i * 5.5) << std::endl;
        std::cout << "Reading values from array2 using for loop " << array2[i] << std::endl;
    }

    for(size_t value: array1){
        std::cout << "Reading values from array using ranged for loop: " << value << std::endl;                     //this will implicitly cast to int leaving out decimal parts
    }

    for(size_t i {}; size_t value1: array4){
        std::cout << "Writing values to an array4 using ranged for loop: " << (array4[value1] = i * 10) << std::endl;
        std::cout << "Reading values from array4 using ranged for loop: " << array4[value1] << std::endl;
        std::cout << value1 << std::endl;
        ++i;
    }
    return 0;
}