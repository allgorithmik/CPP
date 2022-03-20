#include<iostream>

//RETURNS JUST A COPY OF THE RESULT OF THE FUNCTION PROCESSING
auto max_non_ref(int &a, int &b){
    if(a > b){
        return a;                                                   //common misconception to think this return statement returns a reference as value passed is
    }                                                               //a reference, but it returns a copy
    else{
        return b;                                                   //common misconception to think this return statement returns a reference as value passed is
    }                                                               //a reference, but it returns a copy
}

//FOR TRUE RETURNING OF REFERENCE FROM A FUNCTION
auto &max_ref(int &a, int &b){
    if(a > b){
        return a;                                                   //now this will return a reference
    }
    else{
        return b;                                                   //now this will return a reference
    }
}

int main(int argc, char **argv){

    int a {10};
    int b {20};

    //COMPILER ERROR! => cannot treat the return value as reference, its just another variable with a value
    //int &res = max_non_ref(a, b);

    //works fine as the function returns a copy of the data => a copy of result of the function process is returned
    int res1 = max_non_ref(a, b);

    std::cout << "res1 before modification: " << res1 << std::endl;
    ++res1;
    std::cout << "res1 after modification: " << res1 << std::endl;

    //using the auto deducing of reference from function
    auto &res2 = max_ref(a, b);                                     //no compiler error

    std::cout << "res2 before modification: " << res2 << std::endl;
    ++res2;
    std::cout << "res2 after modification: " << res2 << std::endl;
    return 0;
}