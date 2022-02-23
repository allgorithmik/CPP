#include<iostream>

int main(int argc, char **argv){
    //MEMORY LEAK IS WHEN WE LOSE ACCESS TO DYNAMICALLY ALLOCATED MEMORY => SCENERIOS LEAD TO MEMORY LEAKS INADVERTANTLY, SOME SCENARIOS ARE BELOW:
    int *pointer1 {new int {100}};      //ideally we must delete and reset this pointer address1
    int number1 {200};
    pointer1 = & number1;               //now, pointer1 is pointing to number1 variable, pointer1 was before pointing to address1 which was dynamically allocated using
    //new operator, but now as pointer1 is pointing to number1, we have lost access to address1 => NOW MEMORY IS LEAKED AND THERE IS NO WAY WE CAN RELEASE THE ADDRESS1

    //DOUBLE ALLOCATION
    int *pointer2 {new int {500}};      //here, pointer2 was pointing to new int {500},
    pointer2 = new int(100);            //but now it is pointing to new int {100}, memory which was allocated to new int {500} is now lost => leaked

    //pointer in local scope
    {                                   //pointer3 is declared within {} and when control exits this block, pointer3 goes out of scope and will no longer be 
        int *pointer3 {new int {500}};  //available for use => memory leaked
    }

    return 0;
}