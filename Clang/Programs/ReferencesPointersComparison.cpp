#include<iostream>

int main(int argc, char **argv){
    double value1 {55.5};
    double &ref_value1 {value1};
    //double &ref_value1_un;                                                                => ERROR => references CANNOT BE DECLARED WITHOUT initialization
    double *pointer_value1 {&value1};
    double *pointer_value1_un;                                                              //pointers can be DECLARED WITHOUT initialization => GARBAGE VALUE

    //READING
    std::cout << "Reading value1: " << value1 << std::endl;
    std::cout << "Reference reading: " << ref_value1 << std::endl;
    std::cout << "Pointer reading: " << pointer_value1 << std::endl;                        //prints out the address of varible
    std::cout << "Dereferencing the pointer and reading: " << *pointer_value1 << std::endl; //VERY BAD TO READ A VALUE USING POINTER DEREFERENCING => USE REFERENCES

    //re-assigning references
    //REFERENCES ARE STICKY, CHANGING A REFERENCE VARIABLE WILL CHANGE THE VALUE OF ITS ORIGINAL VARIABLE EVERYWHERE => ONLY DECLARATIONS CAN CHANGE
    double value2 {35.55};
    double &value2_ref {value2};
    double value3 {99.100};                                                                 //CHANGING THE VALUE OF THE REFERENCING VARIABLE CHANGES THE VALUE OF ITS
    value2_ref = value3;                                                                    //ORIGINAL VARIABLE => BASICALLY ITS AS IF WE ARE WORKING WITH ORIGINAL VARIABLE
    value2_ref = 95.55;                                                                     //VIA ITS REFERENCE VARIABLE

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "value2 value: " << value2 << std::endl;
    std::cout << "value2 reference: " << value2_ref << std::endl;                           //LATEST VALUE IS REFLECTED
    std::cout << "value3 value: " << value3 << std::endl;
    std::cout << "value2 reference after changing: " << value2_ref << std::endl;            //LATEST VALUE IS REFLECTED

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "But pointers can be made to point somewhere else" << std::endl;
    std::cout << "Pointer1 address before change in address: " << pointer_value1 << std::endl;

    pointer_value1 = &value2;

    std::cout << "Pointer1 address after change in address: " << pointer_value1 << std::endl;

    return 0;
} 