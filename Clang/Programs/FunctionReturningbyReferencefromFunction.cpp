#include<iostream>

//syntax for returning a reference from function
//<datatype> &function_name(params / arg list){} => no need to insert & before return statement, as & is present in function signature, the function returns a reference
//instead of value 
int &max_reference(int &a, int &b);
int &sum(int &a, int &b);
int &max_reference_local_variable(int a, int b);

int main(int argc, char **argv){
    int a {100};
    int b {200};

    std::cout << "Value of a is " << a << " and value of b is " << b << " before calling max_reference()" << std::endl;

    //IF WE AE PASSING REFERENCES TO A FUNCTION, WE CANNOT USE LITERALS
    int &result_max = max_reference(a, b);  //result of max_reference() is stored in a reference variable (direct reference to function returned value)
    int val1 = max_reference(a, b); //result of max_reference() is stored in an ordinary variable (copy of function returned value)
    std::cout << "max_reference() reference variable result: " << result_max << std::endl;
    std::cout << "max_reference() ordinary variable result: " << val1 << std::endl;

    //POINT TO NOTE:
    //max_reference() returns a reference as per previously discussed(line 4), this reference is nothing but the result of the function after it processes its code within
    //it. If this result is stored in a reference variable (as in line 14), any modifications to this variable(as in line 22) will affect the resultant reference variable
    //returned by the function
    ++result_max;
    std::cout << "Value of a is " << a << " and value of b is " << b << " after calling max_reference()" << std::endl;

    //IF WE AE PASSING REFERENCES TO A FUNCTION, WE CANNOT USE LITERALS
    int &bad_res = sum(a, b);
    std::cout << "bad_res(): " << bad_res << std::endl;         //PROGRAM CRASHED! => COMPILER WARNING BUT BUILD SUCCEEDED

    int &bad_max_res = max_reference_local_variable(a, b);
    std::cout << "bad_max_res(): " << bad_max_res << std::endl; //PROGRAM CRASHED! => COMPILER WARNING BUT BUILD SUCCEEDED

    return 0;
}

int &max_reference(int &a, int &b){
    if(a > b){
        return a;                   //no need to insert & before return statement, as & is present in function signature, the function returns a reference instead of value
    }
    else{
        return b;                   //no need to insert & before return statement, as & is present in function signature, the function returns a reference instead of value
    }
}

//RETURNING REFERENCES TO LOCAL VARIABLES
int &sum(int &a, int &b){
    int result = a + b;             //RETURNING A REFERENCE TO A LOCAL VARIABLE IS DANGEROUS AS THE LOCAL VARIABLE WILL BE DESTROYED ONCE THE CONTROL EXITS THE FUNCTION
    return result;                  //BLOCK. THIS CAUSES THE MEMORY OF THE VAIABLE TO BE RELEASED AND WRITTEN WITH NEW VALUE. WHEN WE AGAIN USE THIS MEMORY USING THE
}                                   //RETURNED REFERNCE VARIABLE, IT MAY CAUSE UNDESIRED BEHAVIOUR => BASICALLY USING MEMORY WHICH DOES NOT BELONG TO US

int &max_reference_local_variable(int a, int b){    //NOTICE THE THE INPUT PARAMS / ARGS ARE NOT REFERENCES BUT PASS BY VALUES (COPY)
    if(a > b){
        return a;                                   //AS WE ARE RETURNING THE LOCAL VARIABLES OF THE FUNCTION (BECAUSE THE INPUT PARAMS / ARGS ARE PASSED BY VALUE), THIS
    }                                               //CAUSES THE SAME ISSUE AS ABOVE (RETURNING REFERENCES OF LOCAL VARIABLES)
    else{
        return b;
    }
}