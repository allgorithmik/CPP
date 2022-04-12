#include<iostream>

const double PI {3.145};

class Cylinder{
    double base {1};
    double height {1};

    public:
        Cylinder() = default;

        Cylinder(double base_param, double height_param){   //if we provide our own constructor, compiler will not generate a default empty constructor => we will lose
            base = base_param;                              //the ability to create an object with no parameters => If we need the ability to create an object with NO
            height = height_param;                          //params / args, we need to provide a default constructor as shown in line 10
        }

        double volume(){
            return PI * base * base * height;
        }
};

int main(int argc, char **argv){

    //NO PARENTHESES () FOR DEFAULT CONSTRUCTORS => PLEASE REMEMBER HAD MADE A MISTAKE
    Cylinder cylinder1;                                     //Object with NO params / args => takes the default constructor as provided in line 10
    Cylinder cylinder2(10, 20);                             //Object WITH params / args => takes the user defined constructor as provided in line 12

    double res1 = cylinder1.volume();
    double res2 = cylinder2.volume();

    std::cout << "cylinder1 volume(): " << res1 << std::endl;
    std::cout << "cylinder2 volume(): " << res2 << std::endl;
    
    return 0;
}