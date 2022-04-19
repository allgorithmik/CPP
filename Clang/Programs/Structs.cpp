#include<iostream>

//Struct vs Class
//In Struct members are PBLIC by default whereas in Class members are PRIVATE by default

class Dog{
    std::string name;               //PRIVATE BY DEFAULT => BUT THIS BEHAVIOUR CAN BE OVERIDDEN BY USING ACCESS SPECIFIERS => public / private
};

struct Cat{
    std::string name;               //PUBLIC BY DEFAULT => BUT THIS BEHAVIOUR CAN BE OVERIDDEN BY USING ACCESS SPECIFIERS => public / private
};

struct Point{                       //One usecase of structs is to combine / club common members into one single entity
    double x {};                    //A good model for a struct is to put all related stuff into a relevant / respective struct and NOT to have methods
    double y {};                    //even though strcts DO support methods
};

void print_point(const Point &point){                                                                   //PASSING STRUCT AS PARAM TO FUNCTION
    std::cout << "The Co-Ordinate points are: (" << point.x << ", " << point.y << ") -> From Function"  << std::endl;   //takes x and y values from point object of type Point
}

int main(int argc, char **argv){

    Dog dog1;                       //Created a CLASS object

    Cat cat1;                       //Created a STRUCT object

    //dog1.name;                      //COMPILER ERROR => AS WE ARE TRYING TO ACCESS A PRIVATE VARIABLE OF A CLASS => MEMBERS ARE PRIVATE BY DEFAULR IN A CLASS

    cat1.name = "Pebble";           //NO COMPILER ERROR WHILE ACCESSING MEMBERS OF A SRUCT BECAUSE MEMBERS ARE PUBLIC BY DEFAULT IN A STRUCT
    std::cout << "Name of cat is: " << cat1.name << std::endl;

    Point point1;
    
    point1.x = 5;
    point1.y = 5;

    std::cout << "The Co-Ordinate points are: (" << point1.x << ", " << point1.y << ")"  << std::endl;

    print_point(point1);

    return 0;

}