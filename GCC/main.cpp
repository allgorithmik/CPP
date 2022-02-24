#include<iostream>

int main(int argc, char **argv){    //SO WORKING WITH REFERENCE IS SAME AS WORKING WITH A VARIABLE DIRECTLY, REFERENCES ARE JUST ALIAS'
    //REFERENCES ARE ALIAS' TO VARIABLES => WE CAN ASSIGN AN ALIAS TO A VARIABLE AND USE THAT ALIAS AS IF WE ARE WORKING WITH THE ORIGINAL VARIABLE
    //THIS ALIAS IS WHAT WE CALL AS REFERENCES => ESSENTIALLY WE ARE READING/WRITING VALUES FROM THE SAME MEMORY ADDRESS

    //VARIABLE DECLARATIONS
    int variable1 {100};
    double variable2 {55.55};

    //REFERENCES OF VARIABLES ABOVE
    int &variable1_reference {variable1};                                               //declaring references by initialization
    double &variable2_reference = variable2;                                            //declaring references by assignment

    //int &variable_dummy;  ERROR => declaring references always requires initialization, either initialization or assignment

    std::cout << "-----------------VALUES------------------" << std::endl;

    std::cout << "Normal variable1 value: " << variable1 << std::endl;
    std::cout << "Normal variable2 value: " << variable2 << std::endl;

    //REFERENCES                                                                        As references point TO THE SAME ADDRESS of original variables, they contain the
    std::cout << "REFERENCE variable1 value: " << variable1_reference << std::endl;     //same values as their parent variables => hence the name REFERENCES
    std::cout << "REFERENCE variable2 value: " << variable2_reference << std::endl;

    std::cout << "-----------------ADDRESSES---------------" << std::endl;

    //NORMAL VARIABLE ADDRESSES
    std::cout << "Normal variable1 address: " << &variable1 << std::endl;
    std::cout << "Normal variable2 address: " << &variable2 << std::endl;

    //REFERENCE VARIABLE ADDRESSES
    std::cout << "Reference variable1 address: " << &variable1_reference << std::endl;  //As references point TO THE SAME ADDRESS of original variables, they contain the
    std::cout << "Reference variable2 address: " << &variable2_reference << std::endl;  //same addresses as their original variables from where they are being referenced

    //MODIFYING VALUES USING REFERENCES
    int variable3 {1000};
    int &ref_variable3 {variable3};

    std::cout << "variable3 value is: " << variable3 << std::endl;
    std::cout << "ref_variable3 value is: " << ref_variable3 << std::endl;

    //CHANGING VALUE OF variable3 directly to check if its reference also picks up the new value
    variable3 = 2000;                                                                   //variable3 value has been changed
    std::cout << "variable3 value after changing is: " << variable3 << std::endl;       //changed value is reflecting
    std::cout << "ref_variable3 value after changing is: " << ref_variable3 << std::endl;//reference also is picking up the new value of variable3

    int variable4 {3000};
    int &ref_variable4 = variable4;
    std::cout << "variable4 value is: " << variable4 << std::endl;
    std::cout << "ref_variable4 value is: " << ref_variable4 << std::endl;

    //CHANGING VALUE OF REFERENCE TO CHECK IF ITS VARIABLE ALSO PICKS UP THE NEW VALUE
    ref_variable4 = 5000;
    std::cout << "variable4 value after changing referencing is: " << variable4 << std::endl;       //if value is changed using reference, the value is picked up even by
    std::cout << "ref_variable4 value after changing referencing is: " << ref_variable4 << std::endl;//its original variable => SO WORKING WITH REFERENCE IS SAME AS 
    //WORKING WITH A VARIABLE DIRECTLY, REFERENCES ARE JUST ALIAS'
    return 0;
}