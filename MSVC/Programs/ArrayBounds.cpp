#include<iostream>

int main(int argc, char **argv){                        //REALLY NOT RECOMMENDED TO READ/WRITE TO POSITIONS OUT OF BOUNDS OTHER THAN DECLARED
    int array[] {1,2,3,4,5,6,7,8,9,10};
    int array_length {sizeof(array) / sizeof(array[0])};                                                //THIS IS PRE C++17 METHOD TO DETERMINE LENGTH OF AN ARRAY
    std::cout << "Length of array is: " << array_length << std::endl;                                   //WE CAN ALSO USE std::size(array) TO DETERMINE LENGTH => C++17 FEATURE

    //TRYING TO ACCESS VALUE BEYOND ARRAY LENGTH
    std::cout << "Accessing out of bounds of array: " << array[15] << std::endl;                        //GETTING GARBAGE VALUE

    //TRYING TO WRITE VALUE BEYOND ARRAY LENGTH
    array[20] = 10;
    std::cout << "Writing value to out of bounds of array: " << array[20] << std::endl;                 //GETTING CORRECT VALUE => 10, BUT ACCESSING OUT OF BOUNDS

    //TRYING TO WRITE TO A POSITION AT REALLY HIGH OUT OF BOUNDS
    array[1599999] = 10000;
    std::cout << "Writing value to really large out of bounds of array: " << array[1599999] << std::endl;//PROGRAM IS CRASHING

    std::cout << "Testing the program" << std::endl;                                                    //THIS STATEMENT DOES NOT EXECUTE AS PROGRAM IS CRASHING

    return 0;
}