#include<iostream>

const double PI {3.14};

class Cylinder{
    public:
        Cylinder() = default;
        Cylinder(const double base_param, const double height_param);
        double cylinderVolume();
        double get_base() const;
        double get_height() const;

    private:
        double cylinder_base;
        double cylinder_height;
};

//NORMAL WAY OF NITIALIZATION IN CLASS CONSTRUCTORS => MEMBER WISE ASSIGNMENT INITIALIZATION => COMPLER ERROR IF BOTH THIS AND INITIALIZER LIST INITIALIZED CONSTRCTORS
//ARE PRESENT => HENCE COMMENTING THIS OUT
/*
Cylinder::Cylinder(const double base_param, const double height_param){
    cylinder_base = base_param;
    cylinder_height = height_param;
}*/

//INITIALIZER LIST INITIALIZATION
//INITIALIZER LIST INITIALIZATION BENEFITS:
//THEY AVOID UNNECESSARY COPIES OF MEMBER VARIABLES
//IN SOME CASES ITS THE ONLY WAY TO NTIALIZE AN OBJECT => SUPPOSE WE ARE HAVING OBJECTS / STRINGS AS MEMBER VARIABLES AND WE ASSIGN THOSE VARIABLES AS INITIALIZER VALUES
//IN A CONSTRUCTOR, WE WILL BE CREATING UNNECESSARY CPIES OF THOSE OBJECTS / STRINGS, THEREBY WASTING MEMORY SPACE => HENCE THE ONLY SOLUTION IS TO INITIALIZE THEM USING
//INITIALIZER LIST INITIALIZATION => AS THEY DO NOT CREATE COPIES => MOE ON THIS IN LATER LESSONS
Cylinder::Cylinder(double param_base, double param_height) : cylinder_base(param_base), cylinder_height(param_height){
    //EMPTY BODY
}

double Cylinder::cylinderVolume(){
    return cylinder_base * cylinder_base * cylinder_height * PI;
}

double Cylinder::get_base() const{
    return cylinder_base;
}

double Cylinder::get_height() const{
    return cylinder_height;
}

int main(int argc, char **argv){

    Cylinder cylinder1(100.99, 100.99);
    cylinder1.get_base();
    cylinder1.get_height();
    std::cout << "Volume of Cylinder is: " << cylinder1.cylinderVolume() << std::endl; 
    return 0;
}