#include<iostream>

//-> NOTATION IS USED TO MANAGE OBJECTS IN BOTH STACK AND HEAP MEMORIES

class Cylinder{
    double base {};
    double height {};

    public:
        Cylinder() = default;

        Cylinder(double base_param, double height_param){
            base = base_param;
            height = height_param;
    }

        double volume(){
            return 3.14 * base * base * height;
        }
};

int main(int argc, char **argv){
    double a {100.99};
    double b {200.99};

    //CREATES AN OBJECT IN STACK MEMORY
    Cylinder cylinder1(a, b);                               //INVOKES THE CONSTRUCTOR WHICH TAKES IN TWO double VALUES
    auto res1 = cylinder1.volume();                         //USING . NOTATION TO ACCESS MEMBERS OF AN OBJECT CREATED IN STACK
    std::cout << "(Accessing STACK object members using . Notation)Volume is: " << res1 << std::endl;

    //WE CAN ALSO MANAGE STACK OBJECTS USING POINTERS
    Cylinder *p_cylinder1 = &cylinder1;
    //PLEASE NOTE THE -> NOTATION WHILE ACCESSING MEMBERS OF OBJECTS, ITS AUTO-GENERATED BY INTELLISENSE SUGGESTING THAT USING -> NOTATION IS BETTER THAN USING DEREFERENCING
    auto res2 = p_cylinder1->volume();                      //USING -> NOTATION TO ACCESS MEMBERS OF AN OBJECT
    auto res3 = (*p_cylinder1).volume();                    //USING POINTER DEREFERENCING AND . NOTATION TO ACCESS MEMBERS OF AN OBJECT (-> NOTATION IS RECOMMENDED)
    std::cout <<"(Accessing STACK object members using -> (Arrow)Notation)Volume is: " << res2 << std::endl;
    std::cout << "(Accessing HEAP object members using (*<object_name>) and . Notation)Volume is: " << res3 << std::endl;

    //CREATES AN OBJECT IN HEAP MEMORY => DO NOT FORGET THE * POINTER NOTATION WHILE USING new TO CREATE OBJECTS IN HEAP => IF NOT COMPILER ERROR => * IS MANDATORY
    Cylinder *cylinder2 = new Cylinder(a, b);
    auto res4 = (*cylinder2).volume();                      //USING POINTER DEREFERENCING AND . NOTATION TO ACCESS MEMBERS OF AN OBJECT CREATED IN HEAP MEMORY
    auto res5 = cylinder2 -> volume();                      //USING -> (ARROW) NOTATION TO ACCESS MEMBERS OF AN OBJECT CREATED IN HEAP MEMORY
    //NOTE: . NOTATION WILL NOT WORK FOR HEAP OBJECTS
    //auto res6 = cylinder2.volume();                       //COMPILER ERROR WHILE USING . NOTATION TO ACCESS MEMBERS OF AN OBJECT CREATED IN HEAP / USNG new OPERATOR

    std::cout <<"(Accessing HEAP object members using (*<object_name>) and . Notation)Volume is: " << res4 << std::endl;
    std::cout << "(Accessing HEAP object members using -> (Arrow) Notation)Volume is: " << res5 << std::endl;

    delete cylinder2;                                       //DO NOT FORGET (ITS A GOOD PRACTICE) TO RELEASE THE HEAP MEMORY TO BE REUSED BY OF AFTER OUR USAGE
    return 0;
}