#include<iostream>
#include"Cylinder.h"                                //ALWAYS INCLUDE THE .cpp FILE => THATS WHERE THE IMPLEMENTATION IS
#include"PI.h"                                      //EVEN THOUGH PI.h IS INCLUDED IN Cylinder.h FILE, ITS INCLUDED EVEN HERE, WHICH MAKES IT A MULTIPLE INCLUDED FILE WHICH
//IDEALLY SHOULD RESULT IN A COMPILE TIME ERROR => BUT NO ERROR NOW BECAUSE OF INCLUDE GUARDS IMPLEMENTED IN THEIR RESPECTIVE .h FILES, WHICH TAKES CASE OF MULTIPLE
//INCLUSIONS

//THE PURPOSE OF SPLITTING A PROJECT INTO DIFFERENT FILES IS JUST GOOD DESIGN

int main(int argc, char **argv){

    double base_value {10.99};
    double height_value {20.99};

    Cylinder cylinder(base_value, height_value);

    std::cout << "Volume of the Cylinder is: " << cylinder.volume() << std::endl;

    return 0;
}