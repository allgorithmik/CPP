#include<iostream>

int main(int argc, char **argv){
    char message [] [100] {
        "This is the first line",   //in this kind of 2-D initialization, the second dimension size is 100, but if the element's length is not 100, the remaining slots will
        "This is the second line",  //be filled up by null, this approach is very inefficient as it causes memory wastage
        "This is the third line",
        "This is the fourth line",
        "This is the fifth line"
    };

    const char *messages [] {
        "This is the first line",   //in this kind of 2-D initialization, there is only one dimension, the element's length is dynamically allocated, the remaining slots will
        "This is the second line",  //NOT be filled up by null, this approach is very efficient as the system allocates only the required amount of memory slots as per the
        "This is the third line",   //length of the (second dimension)element => declared as const char, if not compiler error,length of element is irrespective of fixed size
        "This is the fourth line",
        "This is the fifth line"
    };

    std::cout << "element is: " << messages[0] << std::endl;    //prints the first element in array

    return 0;
}