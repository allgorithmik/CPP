#include<iostream>

//Constructors ae a window to customize how our own class objects are built during execution

const double PI {3.142};

class Cylinder{
    public:
    //HAVING A DEFAULT CONSTRUCTOR WITH NO PARAMS / ARGS ALONG WITH A CONSTRUCTOR WITH DEFAULT VALUES FOR ALL ITS PARAMS WILL RESULT IN A COMPILER ERROR AS THE
    //CONSTRUCTOR WITH DEFAULT VALUES FOR ITS PARAMS CAN BE CALLED WITH NO ARGUMENTS DURING CLASS INSTANTIATION => HENCE COMPILER WILL BE CONFUSED RESULTING IN A
    //COMPILE TIME ERROR
        Cylinder() = default;
        Cylinder(const double base_param = 200.5, const double height_param = 100.99);  //default value for constructor params given during constructor declaration
        double CylinderVolume();
        double get_base() const;
        double get_height() const;

    private:
        double cylinder_base;
        double cylnder_height;
};

Cylinder::Cylinder(const double base_param, const double height_param){         //default value for constructor params given during constructor declaration and implementation
    cylinder_base = base_param;
    cylnder_height = height_param;
}

double Cylinder::CylinderVolume(){
    return cylinder_base * cylinder_base * cylnder_height * PI;
}

double Cylinder::get_base() const{
    return cylinder_base;
}

double Cylinder::get_height() const{
    return cylnder_height;
}

int main(int argc, char **argv){

    //Cylinder cylinder0;                                                         //COMPILER ERROR AS THE COMPILER IS CONFUSED AS TO WHICH COMPILER TO CALL(REFER LINE 9 - 11)
    Cylinder cylinder1(55);                                                     //second param need not be given as it has a default value in the constructor declaration
    std::cout << "Cylinder_base value: " << cylinder1.get_base() << std::endl;
    std::cout << "Cylinder_height from default value: " << cylinder1.get_height() << std::endl; //takes the default value

    Cylinder cylinder2(200.99, 300.99);                                         //user given value will override the default param value in constructor declaration
    std::cout << "Cylinder_base value: " << cylinder2.get_base() << std::endl;
    std::cout << "Cylinder_height from user given value: " << cylinder2.get_height() << std::endl;  //takes the user given value
    return 0;
}