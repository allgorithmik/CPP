#include<iostream>

struct Point{
    double x;
    double y;
};

void print_point(const Point &p){
    std::cout << "The Co-Ordinates are: " << p.x << " " << p.y << std::endl;
}

int main(int argc, char **argv){

    Point p1 {10.99,                                    //INVOKES THE DEFAULT std::initializer_list AGGREGATE CONSTRUCTOR FOR INITIALIZING THE STRUCT => IF CUSTOM
        11.99};                                         //INITIALIZATION REQUIRED USE std::initializer_list AS DUSCUSSED IN "InitializerListConstrctor" LESSON

    double array[] {10.99, 11.99, 14.99, 15.99, 19.99}; //INVOKES THE DEFAULT std::initializer_list AGGREGATE CONSTRUCTOR FOR INITIALIZING THE ARRAY

    print_point(p1);
    return 0;
}