#include<iostream>

//UNDERSTANDING THE CALL STACK:
//About Function Activation Record (FAR)
//Truly understanding how function local variable's lifecycle
//The need for inline functions become obvious
//Understanding the debug process of the program becomes easier

//BELOW SEQUENCE OF CODE INSERTS FUNCTIONS INTO A CALL STACK IN LIFO MANNER => STACKS ARE ALWAYS ONE-ENDED AND THEIR BEHAVIOUR IS LIFO OR FILO
//AFTER EVERY INSERT OF FUNCTION, THERE WILL A SPECIAL INSERT CALLED FUNCTION ACTIVATION RECORD (FAR), THIS WILL CONTAIN ALL THE INFO NEEDED FOR A SUCCESSFUL EXECUTION OF
//FUNCTION LIKE ARGS / PARAMS, FUNCTION ADDRESS, PARAMS ADDRESS, RESULT ADDRESS AND CONTROL RETURN ADDRESS AND SO ON
//BELOW CODE'S INSERTION AND POPPING OF FUNCTION'S CALL STACK IS A AS BELOW:
//INSERT main()
//INSERT sum()
//INSERT modify_res()
//EXECUTE modify_res() -> POP modify_res()
//EXECUTE sum() -> POP sum()
//EXECUTE main() -> POP main() => END OF EXECUTION

int modify_res(int &x);                                                                     //function protypes MUST exist or functions be declared and defined above main()
int sum(int a, int b);                                                                      //function protypes MUST exist or functions be declared and defined above main()

int main(int argc, char **argv){                                                            //FIRST FUNCTION TO BE INSERTED INTO THE FUNCTION CALL STACK
    
    int a {10};
    int b {20};
    std::cout << "Function call stack demonstration" << std::endl;
    std::cout << "sum() which in-turn calls another function: " << sum(a, b) << std::endl;

    return 0;

}

int modify_res(int &x){                                                                     //THIRD FUNCTION TO BE INSERTED INTO THE CALL STACK
    x += 10;
    return x;

}

int sum(int a, int b){                                                                      //SECOND FUNCTION TO BE INSERTED INTO THE CALL STACK
    int res1 = a + b;
    int res2 = modify_res(res1);
    return res2;
    
}