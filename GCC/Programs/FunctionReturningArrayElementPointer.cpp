#include<iostream>

const int *array_max(const int scores[], size_t count);             //remember why count => because of pointer decay and array loses its size info=>std::size() not available

int main(int argc, char **argv){
    int array[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Calling array_max()" << std::endl;
    const int *res = array_max(array, 10);
    //const int *res = array_max(array, std::size(array));            //remember now we can use std::size(<array_name>) as we are not passing aray as param / args
    std::cout << "Result of array_max() is: " << *res << std::endl; //works fine
    return 0;
}

const int *array_max(const int scores[], size_t count){             //DO NOT FORGET TO MAKE FUNCTION const AS WE ARE PASSING const int ARRAY AS PARAM / ARG
    int max {};
    size_t max_index {};
    for(size_t i {}; i < count; ++i){
        if(scores[i] > max){
            max = scores[i];
            max_index = i;
        }
    }
    return &scores[max_index];
}