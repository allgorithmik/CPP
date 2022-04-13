 #include"Cylinder.h"
 //TO AVOID RE-DEFINITION COMPILER ERROR => PLEASE AVOID MULTIPLE DEFINITIONS OF CONSTRUCTORS / FUNCTIONS IN .h OR .cpp FILES => DEFINITIONS MUST BE IN EITHER FILES NOT BOTH

 Cylinder::Cylinder(double base_param, double height_param){    //IMPLEMENTATION OF CLASS CONSTRUCTOR => :: IS CALLED AS SCOPE RESOLUTION AS OPERATOR
            base = base_param;
            height = height_param;
    }

double Cylinder::volume(){                                      //PLEASE REMEMBER THAT THE RETURN TYPE MUST BE MENTIONED BEFORE THE CLASS NAME IN CASE OF MEMEBER FUNCTIONS
            return PI * base * base * height;                   //IMPLEMENTATION OF CLASS MEMBER FUNCTION => :: IS CALLED AS SCOPE RESOLUTION AS OPERATOR
        }