#include<iostream>

int main(int argc, char **argv){

    //VERY IMPORTANT//
    //const <datatype> *<variable_name> => CANNOT MODIFY VARIABLE VALUE THROUGH ITS POINTER, BUT POINTER CAN POINT TO ANOTHER ADDRESS WITH SAME DATATYPE
    //<datatype>* const <variable_name> => CANNOT POINT TO ANOTHER ADDRESS WITH SAME DATATYPE, BUT CAN MODIFY THE VARIABLE VALUE THROUGH ITS POINTER, IF WE TRY COMPILER ERROR
    //const <datatype>* const <variable_name> => NIETHER CAN IT POINT TO ANOTHER ADDRESS OF SAME DATATYPE NOR CAN WE MODIFY THE VALUE OF THE VARIABLE THROUGH ITS POINTER

                                                    //GENERAL REFERENCE
    
    int var1 {55};                           
    int *p_var2 {&var1};                            //NON CONST POINTER TO VARIABLE
    const int *p_var3 {&var1};                      //POINTER TO CONST
    const int* const pvar4 {&var1};                 //CONST POINTER TO CONST VARIABLE
    int *const pvar5 {&var1};                       //CONST POINTER TO NON CONST VARIABLE

    //IF CONST SHOWS UP ON THE LEFT OF * => VARIABLE IS CONST
    //IF CONST SHOWS UP ON THE RIGHT OF * => POINTER IS CONST

    //NON CONST POINTER TO NON CONST VARIABLE
    int *pNumber1 {nullptr};                        //normal way of declaring pointer to a variable and assigning an address to a variable of same type
    int number1 {55};
    int number2 {200};
    pNumber1 = &number1;
    *pNumber1 = 100;                                //change the value of a variable through its pointer
    pNumber1 = &number2;                            //change the pointer to point to somewhere else with same datatype

    //POINTER TO CONST
    int number3 {500};
    const int* pNumber3 {&number3};                 //cannot modify the value of variable through the pointer
    //*pNumber3 = 600;                              COMPILER ERROR
    pNumber3 = &number2;                            //BUT WE CAN STILL MAKE THE POINTER POINT TO SOMEWHERE ELSE WITH SAME DATATYPE

    const int some_data {200};
    //int *p_some_data = &some_data;                not legal as we can try to change a const value through a non-cost point poining to it

    //CONST POINTER TO CONST VARIABLE
    const int both_cannot {1000};
    const int* const p_both_cannot {&both_cannot};  //NEITHER CAN WE CHANGE THE POINTER TO POINT SOMEWHERE ELSE NOR CAN WE CHANGE THE VARIABLE VALUE THROUGH ITS POINTER
    //*p_both_cannot = 555;                         NOT POSSIBLE AS WE TRYING TO CHANGE A CONST VALUE VARIABLE
    //p_both_cannot = &number3;                     NOT POSSIBLE AS WE ARE TRYING TO MAKE A CONST POINTER TO POINT SOMEWEHERE ELSE

    //CONST POINTER TO A NON CONST VARIABLE
    int number5 {1000};
    int *const pNumber5 {&number5};                 //we cannot point this pointer to another address of same type but we can change the value of the variable through it
    *pNumber5 = 2000;                               //possible as we are only changing the value but NOT making the pointer to point somewhere else

    //CONST APPLIES TO VARIABLE IDENTIFIER (NAME)
    int protected_var {100};                        //this is a pointer to const data, we cannot modify the data through this pointer: regardless of whether the data itself
    const int* p_protected_var {&protected_var};    //is declared const or not
    //*p_protected_var = 150;                       WE CANNOT CHANGE THE VARIABLE VALUE

    return 0;
}