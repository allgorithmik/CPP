#include<iostream>

int main(int argc, char **argv){
    //ARRAYS ARE ALLOCATED ON THE HEAP USING THE new OPERATOR, CAN ALSO USE std::nothrow VERSION OF new TO SUPPRESS ANY std::bad_alloc etc EXCEPTIONS
    int *pointer1 {new int[100]};                                   //normal integer array of size 100 => garbage values
    int *pointer2 {new int[100] {}};                                //normal integer array of size 100 => initialized to 0
    int *pointer3 {new int[5] {1,2,3,4,5}};                         //normal integer array of size 5 with values {1,2,3,4,5}
    int *pointer4 {new(std::nothrow) int[100] {}};                  //normal integer array of size 100 => garbage values => but with std::nothrow clause
    int *pointer5 {new(std::nothrow) int[5] {1,2,3,4,5}};           //normal integer array of size 5 => with values {1,2,3,4,5} => but with std::nothrow clause

    if(pointer5){
        for(size_t i {}; i < 5; ++i){                               //array index based looping
            std::cout << "Using normal array index to" << +
            " get values: " << pointer5[i] << std::endl;
        }
    }
    else{
        std::cout << "pointer cannot be used" << std::endl;
    }

    if(pointer5){                                                   //pointer arithmatic based looping
        for(size_t i {}; i < 5; ++i){
            std::cout << "Using pointer arithmatic to" << +
            " get values: " << *(pointer5 + i) << std::endl;
        }
    }
    else{
        std::cout << "pointer cannot be used" << std::endl;
    }

    int *pointer6 {new int[10] {}};
    delete[] pointer6;                                              //ARRAY VERSION of deleting/releasing the dynamic memory allocation in heap
    pointer6 = nullptr;                                             //ARRAY VERSION of resetting the pointer pointing to dynamic memory location in heap
    
    //STATIC ARRAYS AND DYNAMIC ARRAYS ARE QUITE DIFFERENT
    //THE REASON STATIC ARRAYS AND DYNAMIC ARRAYS ARE QUITE DIFFERENT IS BECAUSE DYNAMIC ARRAYS GET DECAYED TO A POINTER, LOSING INFORMATION NECESSARY FOR THE RANGE BASED
    //FOR LOOP OPERATIONS => NORMAL for loops WILL WORK => RESTRICTION ONLY FOR RANGE BASED LOOP
    double *pointer7 {new double[10] {}};                           //std::size() does NOT WORK for dynamic arrays
    //std::cout << "std::size() does NOT WORK for dynamic arrays" <<//ERROR
    // + << std::size(pointer7) << std::endl;
    
    /*for(size_t i: pointer7){                                      //RANGE BASED for loop DOES NOT WORK ON DYNAMIC ARRAYS
        std::cout << "Range based for loop DOES NOT WORK for " << + //ERROR
        "dynamic arrays" << std::endl;
    }*/

    delete[] pointer7;                                              //DELETE AND RESET MEMORY/POINTER LIKE A GOOD C++ CITIZEN!
    pointer7 = nullptr;

    return 0;
}