#include<iostream>

int main(int argc, char **argv){
    //POINTERS AND ARRAYS
    int array[] {1,2,3,4,5,6,7,8,9,10};             //normal array declaration
    int *pArray {array};                            //if we initialize a pointer with an array name, the pointer will point to the address of first element in the array

    std::cout << "Getting address:" << std::endl;
    std::cout << pArray << std::endl;               //to get address, only call pointer name WITHOUT *
    std::cout << array << std::endl;                //both point ot he same address, to get address, only call pointer name WITHOUT *

    //dereferencing
    std::cout << *pArray << std::endl;              //dereferencing a pointer pointing to an array, returns the first element of the array 
    std::cout << array[0] << std::endl;             //gives the same output as above

    //POINTERS AND ARRAYS - DIFFERENCES
    int array2[] {1,2,3,4,5,6,7,8,9,10};            //A pointer already pointing to an array cannot be made to point to an address of another array, in this case it is as if 
    int *pArray2 {array2};                          //the pointer is const => which cannot be pointed to another address of same type
    //pArray = &array2;                             COMPILER ERROR

    //std::cout << std::size(pArray) << std::endl;  COMPILER ERROR => std::size() will not work on raw pointers ==>> the reason for this is, WHEN WE ASSIGN AN ARRAY NAME TO
    //A POINTER, THE ARRAY NAME UNDERGOES POINTER DECAY, THAT IS IT LOSES SOME INFORMATION ABOUT THE ARRAY, HENCE std::size() WILL NOT WORK

    return 0;
}