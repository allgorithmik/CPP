#include<iostream>

int min(int &a, int &b);                                            //function prototype of reference params / args
int min(const int &c, const int &d);                                //function prototype of const reference params / args

int main(int argc, char **argv){

    int a {100};
    int b {200};

    const int &c {a};
    const int &d {b};

    std::cout << "min(): " << min(a, b) << std::endl;               //invokes non-const reference variant of min() as we are passing non-const reference params / args
    std::cout << "min(): " << min(c, d) << std::endl;               //invokes const reference variant of min() as we are apssing const reference params / args

    return 0;
}

int min(int &a, int &b){                                            //definition of reference params / args function
    a = 500;
    std::cout << "Reference Prarams / Args" << std::endl; 
    return (a < b)? a : b;
}

int min(const int &a, const int &b){                                //definition of const reference params / args function
    //c = 500;                                                        //compiler error => cannot modify a const value
    std::cout << "Const Reference Prarams / Args" << std::endl;
    return (a < b)? a : b;
}