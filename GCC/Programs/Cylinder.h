#ifndef CYLINDER_H                                          //THESE ARE INCLUDE GUARDS => THESE WILL GUARD AGAINST INCLUDING A HEADER FILE MULTIPLE TIMES
#define CYLINDER_H                                          //THESE ARE PRE-PROCESSOR DIRECTIVES WHICH GET EXECUTED DURING BEFORE COMPILATION
#include"PI.h"

class Cylinder{
    double base;
    double height;

    public:
    Cylinder(double base_param, double height_param);       //ONLY CONSTRUCTORS / FUNCTION PROTOTYPES MUST BE INSIDE THE .h FILES AND THEIR IMPLEMENTATIONS MUST BE
    double volume();                                        //INSIDE .cpp FILES
        
};

#endif