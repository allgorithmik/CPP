#include<iostream>

int main(int argc, char **argv){
    //POINTER ARITHMATIC:
    //A SET OF OPERATIONS WE CAN DO ON THE POINTER REPRESENTING THE ARRAY TO MANIPULATE THE ARRAY. THESE OPERARIONS CAN INCLUDE NAVIGATING FROM ELEMENT TO ELEMENT, COMPUTING
    //THE DISTANCE BETWEEN ELEMENTS AND COMPARING THE ADDRESSES OF ELEMENTS => INCREMENT/DECREMENT
    int numbers[] {1,2,3,4,5,6,7,8,9,10};                                       //IF WE INCREMENT A POINTER, IT WILL FIRST LOOK AT THE DATATYPE OF THE ARRAY AND MOVE AS PER
    int *pNumbers {numbers};                                                    //THE LENGTH OF THE DATATYPE => IN THIS CASE IT WILL MOVE  BYTES, AS THE ARRAY DATATYPE IS INT

    //numbers++;                                                                compiler error because the array pointing location cannot be changed

    std::cout << "Next value in numbers[]: " << *pNumbers << std::endl;         //dereferencing he pointer to get the value
    ++pNumbers;                                                                 //increment the pointer to point to next BYTE => INCREMENT

    std::cout << "Next value in numbers[]: " << *pNumbers << std::endl;         //dereferencing he pointer to get the value
    --pNumbers;                                                                 //decrement the pointer to point to next BYTE => DECREMENT

    std::cout << "Next value in numbers[]: " << ++pNumbers << std::endl;        //IT WILL MOVE BYTES WHEN ++pNumbers IS EXECUTED => TO NEXT BYTE
    std::cout << "Next value in numbers[]: " << *(pNumbers + 4) << std::endl;   //AS POINTER WILL MOVE AS PER THE LENGTH OF DATATYPE, WE WRITE AN EXPRESSION BY ADDING THE
    std::cout << "Next value in numbers[]: " << *(pNumbers - 4) << std::endl;   //POINTER TO THE NUMBER OF BYTES OF THE DATATYPE => 4 BYTES (INT) + POINTER_NAME
    //INCREMENT OR DECREMENT USING EXPRESSION METHOD

    //loops can also be used to increment/decrement
    //POINTER INCRMENTING LOOPS WITH EXPRESSION *(pointer + i)
    for(size_t i {}; i < std::size(numbers); ++i){
        std::cout << "Element is: " << *(pNumbers + i) << std::endl;
    }

    //POINTER INCRMENTING LOOP WITH *++pointer
    for(size_t i {}; i < std::size(numbers); ++i){
        std::cout << "Element is: " << *(++pNumbers) << std::endl;
    }

    //POINTER INCRMENTING LOOP WITH INDEX NOTATION arrya[i+1]
    for(size_t i {}; i < std::size(numbers); ++i){
        std::cout << "Element is: " << numbers[i + 1] << std::endl;
    }

    //DECREMENTING POINTER LOOPS
    //DECREMENTING POINTER LOOPS WITH EXPRESSION *(pointer + i -1)              -1 because pointer is already pointing to the initial variable
    for(size_t i {std::size(numbers)}; i > 0; --i){                             //DO NOT FORGET TO INITIALIZE(START) THE ITERATOR FROM std::size(array)
        std::cout << "Element is: " << *(pNumbers + i - 1) << std::endl;
    }

    //DECREMENTING POINTER LOOPS WITH *pointer--
    for(size_t i {std::size(numbers)}; i > 0; --i){                             //DO NOT FORGET TO INITIALIZE(START) THE ITERATOR FROM std::size(array)
        std::cout << "Element is: " << *(pNumbers--) << std::endl;
    }

    //POINTER DECREMENTING LOOP WITH INDEX NOTATION array[i-1]
    for(size_t i {std::size(numbers)}; i > 0; --i){                             //DO NOT FORGET TO INITIALIZE(START) THE ITERATOR FROM std::size(array)
        std::cout << "Element is: " << numbers[i - 1] << std::endl;
    }

    //WE CAN ALSO MODIFY ARRAY ELEMENTS USING POINTER ARITHMATIC
    int numbers1[] {1,2,3,4,5,6,7,8,9,10};
    int *pNumbers1 {numbers1};
    numbers1[0] = 100;                                                          //NORMAL INDEX WISE MODIFICATION
    *(numbers1 + 1) = 500;                                                      //EQUIVALENT TO numbers[1] = 500     
    *(pNumbers1 + 2) = 200;                                                     //EQUIVALENT TO numbers[2] = 200

    //PRINTING OUT MODIFIED ELEMENTS
    for(size_t i {}; i < std::size(numbers1); ++i){
        std::cout << numbers1[i] <<std::endl;
    }

    return 0;

}