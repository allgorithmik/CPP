#include<iostream>

//WHILE auto DEDUCING FUNCTION RETURN TYPES (RETURN TYPES MUST BE CONSISTENT), SPLITTING OF FUNCTIONS INTO PROTOTYPE AND DEFINITION WILL NOT WORK AS THE DEFINITION
//WILL COME AFTER main(), THIS WILL LEAD TO COMPILER ERROR AS THE COMPILER CANNOT DEDUCE THE RETURN TYPE OF THE FUNCTION WHILE COMPILING AS THE DEFINITION WILL STILL NOT BE
//VISIBLE TO THE COMPILER AS THE DEFINITION WILL BE LINKED TO THE FUNCTION DECLARATION BY THE LINKER DURING THE LINKING PHASE, WHICH COMES AFTER COMPILATION PHASE.
//HENCE SPLITTING OF FUNCTIONS TO PROTOTYPES AND DEFINITIONS WILL NOT BE POSSIBLE WHERE IT IS NECCESSARY TO USE auto TO DEDUCE THE RETURN TYPE OF THE FUNCTION
//SOLUTION IS TO DECLARE AND DEFINE THE FUNCTION BEFORE main() ONLY IN CASES OF auto DEDUCING REUTRN TYPE OF FUNCTIONS => THIS IS THE CASE FOR BOTH reference auto AND auto

//auto max(int a, int b);
auto max(int a, int b){                                                                         //THIS IS THE ONLY SOLUTION => TO DECLARE AND DEFINE THE FUNCTION BEFORE
    if(a > b){                                                                                  //main() => THIS IS THE CASE FOR BOTH auto& and auto
        return a;
    }
    else{
        return b;
    }
}

int main(int argc, char **argv){
    int a {100};
    int b {200};

    int max_res = max(a ,b);
    std::cout << "The max between " << a << " and " << b << " is: " << max_res << std::endl;
    return 0;
}

/*auto max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}*/