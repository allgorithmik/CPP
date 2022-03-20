#include<iostream>

int *max_pointer(int *a, int *b);
int *sum_pointer_bad(int *a, int *b);
int *max_pointer_bad(int a, int b);

int main(int argc, char **argv){

    int a {100};
    int b {200};

    std::cout << "Value of a is " << a << " and value of b is " << b << " before calling max_pointer()" << std::endl;

    //pointer must be initialized with only pointers and addresses of data must be passed where pointers are expected to be passed
    int *max_res = max_pointer(&a, &b);
    std::cout << "Result of max_pointer(): " << *max_res << std::endl;  //dereference the pointer while performing operations and when actual result is needed

    //POINT TO NOTE:
    //max_pointer() returns a pointer, this pointer is nothing but the result of the function after it processes its code within it. If this result is stored in a pointer
    //variable (as in line 13), and any modifications to this variable(as in line 16) will affect the resultant pointer variable returned by the function    
    ++(*max_res);                                                       //beware of syntax => <operation>(*<pointer_variable_name>) => DEREFERENCE FIRST BEFORE OPERATIONS
    std::cout << "Value of a is " << a << " and value of b is " << b << " after calling max_pointer()" << std::endl;

    int *res_bad1 = sum_pointer_bad(&a, &b);
    std::cout << "res_bad1 value: " << *res_bad1 << std::endl;          //PROGRAM CRASHES! => WARNING BUT BUILD SUCCEEDED

    int *res_bad2 = max_pointer_bad(a, b);
    std::cout << "res_bad2 value: " << *res_bad2 << std::endl;          //PROGRAM CRASHES! => WARNING BUT BUILD SUCCEEDED
    
    return 0;
}

//POINT TO NOTE:
//max_pointer() returns a pointer, this pointer is nothing but the result of the function after it processes its code within it. If this result is stored in a pointer
//variable (as in line 13), and any modifications to this variable(as in line 16) will affect the resultant pointer variable returned by the function
int *max_pointer(int *a, int *b){
    if(*a > *b){                                                        //dereference the pointer while performing operations
        return a;                                                       //no need to insert * after return statement because * is already inserted in function signature
    }                                                                   //hence compiler returns a pointer
    else{
        return b;                                                       //no need to insert * after return statement because * is already inserted in function signature
}                                                                       //hence compiler returns a pointer
}

//RETURNNG POINTERS OF LOCAL VARIABLES:
//RETURNING A POINTER OF A LOCAL VARIABLE IS DANGEROUS AS THE LOCAL VARIABLE WILL BE DESTROYED ONCE THE CONTROL EXITS THE FUNCTION BLOCK. THIS CAUSES THE MEMORY
//OF THE VAIABLE TO BE RELEASED AND WRITTEN WITH NEW VALUE. WHEN WE AGAIN USE THIS MEMORY USING THE RETURNED POINTER, IT MAY CAUSE UNDESIRED BEHAVIOUR
//=> BASICALLY USING MEMORY WHICH DOES NOT BELONG TO US
int *sum_pointer_bad(int *a, int *b){                                   //THIS FUNCTION RETURNS THE POINTER OF THE LOCAL VARIABLE CREATED INSIDE THE FUNCTION
    int res_bad = *a + *b;                                              //DO NOT ASSIGN A RESULT OF POINTER EXPRESSION TO A POINTER VARIABLE => COMPILER ERROR
    return &res_bad;                                                    //WARNING BUT BUILD SUCCEEDED
}

int *max_pointer_bad(int a, int b){                                     //THIS FUNCTION RETURNS THE POINTER OF THE LOCAL VARIABLE WHICH ARE PASSED AS PARAMS / ARGS
    if(a > b){                                                          //THIS CAUSES THE SAME ISSUES AS ABOVE
        return &a;                                                      //WHEN A POINTER IS BEING RETURNED, WE HAVE TO RETURN THE ADDRESS
    }
    else{
        return &b;                                                      //WHEN A POINTER IS BEING RETURNED, WE HAVE TO RETURN THE ADDRESS
    }                                                                   //WARNING BUT BUILD SUCCEEDED
}