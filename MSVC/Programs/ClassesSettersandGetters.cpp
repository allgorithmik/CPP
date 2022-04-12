#include<iostream>

//Setters and Getters are methods which are used to read and modify the member variables of a class

const double PI {3.145};

class Cylinder{
    double base {};
    double height {};

    public:
        Cylinder() = default;

        Cylinder(double baseParam, double heightParam){     //a user defined constructor for cases where setting base and height without setters
            base = baseParam;
            height = heightParam;
        }

        void set_base(double base_param){                   //sets the value of base (its pass by value please remember)
            base = base_param;
        }

        void set_height(double height_param){               //sets the value of height (its pass by value please remember)
            height = height_param;
        }

        double get_base(){                                  //gets the value of base (its pass by value please remember)
            return base;
        }

        double get_height(){                                //gets the value of height (its pass by value please remember)
            return height;
        }

        double volume(){                                    //calculates volume
            return PI * base * base * height;
        }
};

int main(int argc, char **argv){

    Cylinder cylinder1;
    Cylinder cylinder2(100, 200);                           //uses the user defined constructor which takes in params / args

    //cylinder1.base;                                         //compiler error as base and height are private => hence the point of using setters / getters
    //cylinder1.height;                                       //compiler error as base and height are private => hence the point of using setters / getters
    //cylinder2.base;                                         //compiler error as base and height are private => hence the point of using setters / getters
    //cylinder2.height;                                       //compiler error as base and height are private => hence the point of using setters / getters

    std::cout << "base value BEFORE setting its value: " << cylinder1.get_base() << std::endl;
    std::cout << "height value BEFORE setting its value: " << cylinder1.get_height() << std::endl;

    std::cout << "Setting Values of Base and Height" << std::endl;

    cylinder1.set_base(10.99);
    cylinder1.set_height(11.99);

    std::cout << "base value AFTER setting its value: " << cylinder1.get_base() << std::endl;
    std::cout << "height value AFTER setting its value: " << cylinder1.get_height() << std::endl;

    std::cout << "Getting the value of Cylinder1: " << cylinder1.volume() << std::endl;
    std::cout << "Getting the value of Cylinder2: " << cylinder2.volume() << std::endl;

    return 0;
}