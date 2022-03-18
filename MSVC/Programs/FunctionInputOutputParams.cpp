#include<iostream>

//Output params / args should be passed in such a way that if we modify the params / args within the function, it should affect the value of the param / args outside
//the function. The options to do this in C++ are by using references or pointers, references are recommended in C++

//Input params/args should NOT be modifiable from inside the function. The function must just read the input from the args. We enforce this using the const keyword.
//Options to do this include passing b const reference, passing by pointer to const and passing a const pointer to const value

void max_string(const std::string& input1, const std::string input2, std::string& output);
void max_int(int input1, int input2, int& output);
void max_double(double input1, double input2, double* output);

int main(int argc, char **argv){

    std::string outputstr {};
    int outputint {};
    double outputdouble {};

    std::cout << "Outputstr val before calling max_string(): " << outputstr << std::endl;
    max_string("Hello", "Mars", outputstr);                                                     //pass the variable itself to output param / args as its the reference
    std::cout << "Outputstr val before calling max_string(): " << outputstr << std::endl;       //variable, passing direct literals will result in compiler error (obviously)

    std::cout << "Outputint val before calling max_int(): " << outputint << std::endl;
    max_int(10, 20, outputint);                                                                 //pass the variable itself to output param / args as its the reference
    std::cout << "Outputint val after calling max_int(): " << outputint << std::endl;           //variable, passing direct literals will result in compiler error (obviously)

    std::cout << "Outputdouble val before calling max_double(): " << outputdouble << std::endl;
    max_double(55.55, 100.9, &outputdouble);                                                    //pass the variable address(obviously) to output param/args as its the pointer
    std::cout << "Outputdouble val before calling max_double(): " << outputdouble << std::endl; //variable, was right in passing address (but misleading compiler error)

    return 0;
}

void max_string(const std::string& input1, const std::string input2, std::string& output){      //as the output variable is a reference variable, it will affect the value    
    if(input1 > input2){                                                                        //outside the function
        output = input1;
    }
    else{
        output = input2;
    }                                                                                           //as value is already taken effect outside the function via its
}                                                                                               //reference variable, no return statement is required to get the value out

void max_int(int input1, int input2, int& output){                                              //as the output variable is a reference variable, it will affect the value
    if(input1 > input2){                                                                        //outside the function
        output = input1;
    }
    else{
        output = input2;
    }                                                                                           //as value is already taken effect outside the function via its
}                                                                                               //reference variable, no return statement is required to get the value out

void max_double(double input1, double input2, double* output){
    if(input1 > input2){
        *output = input1;                                                                       //do not forget to dereference the variable while performing operations
    }
    else{
        *output = input2;
    }                                                                                           //as value is already taken effect outside the function via its
}                                                                                               //pointer variable, no return statement is required to get the value out