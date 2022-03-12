#include<iostream>

int sum(int *val1, int *val2);                      //function prototype

int main(int argc, char **argv){

    int int1 {10};
    int int2 {20};

    double double1 {55.55};
    double double2 {100.99};

    std::cout << "Calling sum()" << std::endl;

    int res1 = sum(&int1, &int2);                    //pass the address as values when passing values to pointers
    std::cout << "Result is: " << res1 << std::endl;

    //COMPILER ERROR => CANNOT CAST IMPLICITLY => THE REASON FOR THIS IS BOTH DOUBLE AND INT HAVE DIFFERENT SIZES OF MEMORY AND IF IMPLICIT CAST NEED TO TAKE PLACE,
    //POINTERS HAVE TO POINT TO A DIFFERENT SIZED MEMORY ALTOGETHER WHICH IS NOT POSSIBLE => POINTERS BEHAVE DIFFERENTLY AS PER THE VARIABLE TYPES IF POINTERS WORKED IN THE
    //SAME WAY FOR ALL DATATYPES, POINTER ARITHMATIC WOULD NOT WORK => HENCE COMPILER THROWS ERROR
    //double res2 = sum(&double1, &double2);

    return 0;
}

int sum(int *val1, int *val2){                      //function definition

    return (*val1 + *val2);                         //when we want to modify the values pointed by pointers, first dereference them and then modify them, use ()
}                                                   //better readability