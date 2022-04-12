#include<iostream>

//Constructors are special kind of functions which are  called when an instance of a class is created
//Constructors have no return method
//Same name as the class
//Can have params / args, can also have empty params / args list
//Usually used to initialize a member variables of a class
//if no constrctor is defined in a class => the compiler will setup an empty constructor and call this empty constructor while creating an instance of a class

const double PI {3.141592653589793238462643383279502884197};

class Cylinder{
    double base_radius {1};                                 //no access specifier specified => private by default
    double height {1};

    public:                                                 //public access specifier specified => hence public => constructors must be public else objects cannot be created
        Cylinder(){                                         //constructor function =< SAME NAME AS CLASS AND NO RETURN TYPE AND NO PARAMS / ARGS
            base_radius = 2;
            height = 2;
        }

        Cylinder(double base_param, double height_param){   //constructor function with params list / args list BUT NO return type
            base_radius = base_param;
            height = height_param;
        }

        double volume(){
            return PI * base_radius * base_radius * height;
        }
};

int main(int argc, char **argv){
    Cylinder cylinder1;                                     //creating an instance of a class without any params / args
    //THIS WILL INVOKE THE CONSTRUCTOR WITH NO PARAMS / ARGS AS WE HAVE NOT PASSED ANY PARAMS / ARGS WHILE CREATING THE CLASS'S INSTANCE (CAN USE DEBUGGER TO VERIFY)
    std::cout << "cylinder1's volume: " << cylinder1.volume() << std::endl;

    //THIS WILL INVOKE THE CONSTRUCTOR WHICH TAKES PARAMS / ARGS AS WE HAVE PASSED PARAMS / ARGS WHILE CREATING THE CLASS'S INSTANCE (CAN USE DEBUGGER TO VERIFY)
    Cylinder cylinder2(10, 20);
    std::cout << "cylinder2's volume: " << cylinder2.volume() << std::endl;
    return 0;
}