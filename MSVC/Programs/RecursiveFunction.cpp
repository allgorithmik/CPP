#include<iostream>

//RECURSIVE FUNCTION IS A TECHNIQUE WHEREIN A FUNCTION REPEATEDLY CALLS ITSELF TO ACHIEVE A GOAL. A FUNCTION WHICH CALLS ITSELF IS CALLED A RECURSIVE FUNCTION

int sum_recur(int a){
    if(a != 0){
        return a += sum_recur(a -1);                                            //the function sum_recur() calls itself until the if condition returns false
    }                                                                           //THE BASE CONDITION LOGIC AND FUNCTION EXIT LOGIC IS VERY VITAL TO IMPLEMENT
    return 0;                                                                   //RECURSIVE FUNCTION ELSE THE LOGIC WILL BE CONFUSING AND FUNCTION MIGHT GO INTO AN
}                                                                               //INFINITE LOOP

int main(int argc, char **argv){

    int val1 {100};

    std::cout << "sum() recursive function: " << sum_recur(val1) << std::endl;  //calling the recursive function sum_recur()

    return 0;
}