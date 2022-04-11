#include<iostream>

//POINTS TO BE NOTED ABOUT MEMBERS OF CLASS:
//Class member varables can be either raw stack or pointer variables
//Members cannot be references => THIS IS BECAUSE REFERENCES CANNOT BE LEFT UNINITIALZED BUT MEMBER VARIABLES CAN BE LEFT UNINITIALIZED
//Classes have functions (methods / behavours) that let them perform operations
//Class methods have access to member variables regardless of their access specifiers: private / public / protected
//Private members of classes (variables and functions) are not accesible outside of their respective class definiton

const double PI {3.142};

class Cylinder{
    //IF NO ACCESSS SPECIFIER IS MENTIONED => THE MEMBERS WILL BE PRIVATE
    //NO ACCESS SPECIFIER MENTIONED, HENCE => private => MEMBERS OF A CLASS IN C++ ARE private BY DEFAULT => THE public KEYWORD HERE MAKES THE MEMBERS OF THIS CLASS public
    double height {100};
    double base_radius {200};

    public:                                             //MEMBERS OF A CLASS IN C++ ARE private BY DEFAULT => THE public KEYWORD HERE MAKES THE MEMBERS OF THIS CLASS public
    double volume(){
        return PI * base_radius * base_radius * height;
    }
};

int main(int argc, char **argv){
    
    Cylinder cylinder1;
    std::cout << "Volume of cylinder with default values is: " << cylinder1.volume() << std::endl;

    Cylinder cylinder2;
    //COMMENTED BECAUSE THE MEMBERS HAVE BEEN DECLARED private FOR GOOD DESIGN
    //changing the values of members of a class is only possible if the members are public
    //cylinder2.height = 300;                             //changing the members of an object pointed by one variable will NOT affect the object pointed by another variable
    //cylinder2.base_radius = 400;                        //one object pointed by one variable will be independent of an object pointed by a whole another variable
    //std::cout << "Volume of cylinder with custom values is: " << cylinder2.volume() << std::endl;

    auto res1 = cylinder1.volume();
    std::cout << "cylinder1 will not change? " << res1 << std::endl;
    return 0;
}