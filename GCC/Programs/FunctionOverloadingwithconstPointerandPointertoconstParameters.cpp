#include<iostream>

int max(int *a, int *b);                                    //function prototype with non const pointer params / args => valid overloading
int max(const int *a, const int *b);                        //function prototype with const pointer params / args => valid overloading
int max(const int *const a, const int *const b);            //function prototype with const pointer pointing to const param / args => NOT a valid overload

int main(int argc, char **argv){
    int a {100};                                            //non const variable
    int b {200};                                            //non const variable

    const int c {300};                                      //const variable
    const int d {400};                                      //const variable

    const int *p_c {&c};
    const int *p_d {&d};

    std::cout << "max(): " << max(&a, &b) << std::endl;     //INVOKES THE non-const VARIANT OF max() AS non-const ARGS ARE PASSED => VALID OVERLOAD
    std::cout << "max(): " << max(&c, &d) << std::endl;     //INVOKES THE const VARIANT OF max() AS const ARGS ARE PASSED => VALID OVERLOAD

    //REDEFINITION COMPILER ERROR => THIS HAPPENS BECAUSE THE POINTER IS ITSELF PASSED BY VALUE, IF WE MODIFY THE POINTER, IT WILL POINT TO SOMEWHERE ELSE, BUT HERE WHEN
    //POINTER IS DECLARED AS const, THE COMPILER INTERPRETS SUCH THAT THE POINTER CANNOT BE CHANGED, THIS GIVES RISE TO THE SAME PROBLEM AS WORKING WITH TEMPORARIES, HENCE
    //THIS IS A REDEFINITION COMPILER ERROR
    std::cout << "max(): " << max(&a, &b) << std::endl;

    std::cout << "Address of p_c: " << &p_c << std::endl;
    std::cout << "Address of p_d: " << &p_d << std::endl;
    std::cout << "max(): " << max(p_c, p_d) << std::endl;
    return 0;
}

int max(int *a, int *b){                                    //definition of non const pointer params / args function
    std::cout << "non const pointer" << std::endl;
    return (*a > *b)? *a : *b;
}

//const pointer
//COMMENTING THIS TEMPORARILY
//int max(const int *a, const int *b){                        //defintition of const pointer params / args function
//    std::cout << "const pointer" << std::endl;
//    return (*a > *b)? *a : *b;
//}

//const pointer pointing to const
//REDEFINITION COMPILER ERROR => THIS HAPPENS BECAUSE THE POINTER IS ITSELF PASSED BY VALUE, IF WE MODIFY THE POINTER, IT WILL POINT TO SOMEWHERE ELSE, BUT HERE WHEN
//POINTER IS DECLARED AS const, THE COMPILER INTERPRETS SUCH THAT THE POINTER CANNOT BE CHANGED => IN OTHER WORDS, THE const AFTER THE int IS USELESS, WHICH MAKES IT SAME
//AS THE FUNCTION WITH const pointer params / args
//SOLVING THIS REDEFINITION COMPILER ERROR IN LINE 14, 15 AND 25 - 27
int max(const int *const a, const int *const b){            //defintition of const pointer pointing to const params / args function => NOT a valid overload
    std::cout << "const pointer const value" << std::endl;
    return (*a > *b)? *a : *b;
}