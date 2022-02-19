#include<iostream>

int main(int argc, char **argv){
    //SUBTRACTING TWO POINTERS RESULTS IN AN INTEGER, REPRESENTING THE DISTANCE BETWEEN TWO POINTS
    int array[] {1,2,3,4,5,6,7,8,9,10};
    int *pointer1 {&array[0]};                                                                      //ARRAY INDEX WISE
    int *pointer11 {array + 0};                                                                     //POINTER ARITHMATIC WISE
    int *pointer2 {&array[9]};                                                                      //ARRAY INDEX WISE
    int *pointer22 {array + 9};                                                                     //POINTER ARITHMATIC WISE

    std::cout << "Distance between pointer1 and pointer2: " << (pointer2 - pointer1) << std::endl;  //GIVES THE DISTANCE BETWEEN array[0] AND array[9]
    std::cout << "Distance between pointer2 and pointer1: " << (pointer1 - pointer2) << std::endl;  //GIVES THE DISTANCE BETWEEN array[0] AND array[9] NEGATIVE

    //std::ptrdiff_t
    //c++ HAS A SPECIAL TYPE TO STORE POINTER DIFFERENCES => std::ptrdiff_t
    //THE REASON C++ HAS std::ptrdiff_t IS BECAUSE DIFFERENT COMPILERS HAVE DIFFERENT WAYS TO STORE POINTER DIFFERENCES, HENCE TO STANDARDIZE THIS, std::ptrdiff_t IS
    //AVAILABLE
    std::ptrdiff_t pos_diff {pointer22 - pointer11};
    std::ptrdiff_t neg_diff {pointer11 - pointer22};

    std::cout << "Positive Difference: " << pos_diff << std::endl;
    std::cout << "Negative Difference: " << neg_diff << std::endl;
    std::cout << "Size of std::ptrdiff_t is: " << sizeof(std::ptrdiff_t) << std::endl;
    return 0;
}