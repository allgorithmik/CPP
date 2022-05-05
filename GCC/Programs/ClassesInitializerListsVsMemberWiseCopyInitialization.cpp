#include<iostream>
/*
MEMBER WISE INITIALIZATION                                                  INILIALIZER LIST INITIALIZATION
INITIALIZATION HAPPENS IN TWO STEPS:                                        INITIALIZATION HAPPENS DURING REAL OBJECT CREATION
    Object Creation
    Member Variable assignment
Potential Unnessary Copies of Data                                          No Unnessary Copies of Data
Order of vaiables DOES NOT matter                                           Order of vaiables DOES matter

RECOMMENDATION: ALWAYS USE INITIALIZER LIST INITIALIZATION IF PERMITTED

THE DIFFERENCE IS DEMONSTRATED USING BREAK POINTS
*/
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

//COMMENT OUT EITHER OF THE CONSTRUCTORS DURNG COMPILATION => ELSE COMPILER ERROR => REDEFINTION ERROR
/*
//MEMBER WISE ASSIGNMENT INITIALIZATION CONSTRUCTOR
Cylinder::Cylinder(const double base_param, const double height_param){
    cylinder_base = base_param;
    cylinder_height = height_param;
}*/

//INITIALIZER LIST INITIALIZATION CONSTRUCTOR
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