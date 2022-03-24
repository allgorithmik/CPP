#include<iostream>
//OVERLOADING FUNCTIONS WITH DEFAULT PAAMS / ARGS IS NOT POSSIBLE BECAUSE IF WE DO NOT PASS ANY PARAMS / ARGS TO THE FUNCTION, THE COMPILER WILL BE CONFUSED AS TO WHICH
//FUNCTION TO CALL, HENCE GIVING RISE TO COMPILER ERROR
//DEFAULT PARAMS / ARGS MUST BE PRESENT ONLY IN THE FUNCTION PROTOTYPES, NOT IN DEFINTIONS => ELSE COMPILER ERROR => NO SUCH RESTRCITIONS WHEN DIRECT FUNCTION IS DECLARED
//AND DEFINED
void age(int age = 100);                                        //prototype of int param / args function
//DEFAULT PARAMS / ARGS MUST BE PRESENT ONLY IN THE FUNCTION PROTOTYPES, NOT IN DEFINTIONS => ELSE COMPILER ERROR => NO SUCH RESTRCITIONS WHEN DIRECT FUNCTION IS DECLARED
//AND DEFINED
void age(long int age = 1000);                                  //prototype of long int param / args function

int main(int argc, char **argv){

    int a {10};
    long int b (1000);
    std::cout << "Calling age(): " << std::endl;
    //as age() is of void type, assigning its result to a variable or plugging it into std::cout not works?
    age(a);                                                     //invokes the int variant of age() as are passing an int param / args
    age(b);                                                     //invokes the long int variant of age() as are passing a long int param / args      
    //age();                                //COMPILER ERROR AS THE COMPILER DOES NOT KNOW WHICH DEFINITON OF age() TO INVOKE AS BOTH VARIANTS HAVE DEFAULT PARAMS / ARGS

    return 0;
}

void age(int age){                                              //definition of long int param / args function => default params / args must be present only
    std::cout << "int varriant" << std::endl;                   //in protype ONLY else compiler error
    std::cout << "Age is: " << age << std::endl;
}

void age(long int age){                                         //definition of long int param / args function => default params / args must be present only
    std::cout << "long int variant" << std::endl;               //in protype ONLY else compiler error
    std::cout << "Age is: " << age << std::endl;
}