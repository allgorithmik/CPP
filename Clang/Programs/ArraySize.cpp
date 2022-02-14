#include<iostream>

int main(int argc, char **argv){            //std::size() is a C++17 feature => before C++17 (std::sizeof(array)/std::sizeof(array[0])) was used
    int array[] {1,2,3,4,5,6,7,8,9,10};
    int array2[25];
    int COUNT = {sizeof(array) / sizeof(array[0])};                                                 ////using pre-C++17 technique to determine the size of array

    std::cout << "The size of array is: " << std::size(array) << std::endl;                         //size of an array (or collection?) can be obtained by std::size()                 
    std::cout << "The size of array2 is: " << std::size(array2) << std::endl;                       //size of an array (or collection?) can be obtained by std::size()

    for(size_t i {}; i < std::size(array); ++i){                                                    //we can use range based loop, which is efficient
        std::cout << "The element at iteration " << i << " is: " << array[i] << std::endl;          //using std::size as condition in for loop (any loop works)
    }

    //same functionality as above
    for(int value: array){                                                                          //using range based loop
        std::cout << "The element at iteration " << value << " is: " << array[value] << std::endl;
    }

    //same functionality as above
    for(size_t i {}; i < COUNT; ++i){                                                               //using pre-C++17 technique to determine the size of array 
        std::cout << "The element at iteration " << i << " is: " << array[i] << std::endl;
    }

    return 0;
}