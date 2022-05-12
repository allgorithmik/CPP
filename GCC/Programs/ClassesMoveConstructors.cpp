#include<iostream>

//Move Constructors Steal Data From Temporary Objects

class Point{
    private:
        double *x_point {};
        double *y_point {};

        void invalidate(){                      //CALLING A PRIVATE FUNCTION IS POSSIBLE AS WE ARE CALLING FROM WITHIN THE CLASS AND CLASS HAS ACCESS TO PRIVATE MEMBERS
            x_point = nullptr;                  //THIS FUNCTION IS CALLED WITHIN MOVE CONSTRUCTOR AND IT INITIALIZES THE POINTERS TO nullptr
            y_point = nullptr;
        }

    public:
        Point() = default;                      //default constructor
        Point(double x_param, double y_param);  //copy constructor => constructor with params
        Point(Point &&source_point);            //constructor for MOVE CONSTRUCTOR (prototype)
        void set_x(double xPoint);
        void set_y(double yPoint);
        double *get_x() const;
        double *get_y() const;
        double *steal_x();                      //this function is used to copy data into new memory space and initialize the OLD pointer to nullptr in ONE GO
        double *steal_y();                      //this function is used to copy data into new memory space and initialize the OLD pointer to nullptr in ONE GO
        void print_info();
        ~Point();
};

//MOVE CONSTRUCTOR SYNTAX & DEFINTION => PLEASE NOTE THE && SYNTAX => ITS MANDATORY TO USE IN MOVE CONSTRUCTORS IMPLEMENTATION
Point::Point(Point &&source_point) : x_point(source_point.steal_x()), y_point(source_point.steal_y()){
    source_point.invalidate();                  //invalidate() is called to point the OLD pointers to nullptr => but can be done in ONE GO as in steal_x & steal_y functions 
    std::cout << "This is the body of MOVE CONSTRUCTOR" << this << std::endl;
}

//NORMAL COPY CONSTRUCTOR USING INITIALIZER LIST INITIALIZATION => PERFORMS DEEP COPY
Point::Point(double x_param, double y_param) : x_point(new double(x_param)), y_point(new double(y_param)){
    std::cout << "This is the body of COPY (DEEP COPY) Constructor" << this << std::endl;
}

void Point::set_x(double xPoint){
    *(this->x_point) = xPoint;
}

void Point::set_y(double yPoint){
    *(this->y_point) = yPoint;
}

double *Point::get_x() const{
    return x_point;
}

double *Point::get_y() const{
    return y_point;
}

double *Point::steal_x(){                       //this function is used to copy data into new memory space and initialize the OLD pointer to nullptr in ONE GO
    double *new_x = x_point;
    x_point = nullptr;
    return new_x;
}

double *Point::steal_y(){                       //this function is used to copy data into new memory space and initialize the OLD pointer to nullptr in ONE GO
    double *new_y = y_point;
    y_point = nullptr;
    return new_y;
}

void Point::print_info(){
    std::cout << "The Co-ordinates are: " << "[" << *x_point << ", " << *y_point << "]" << std::endl;
}

Point::~Point(){
    delete x_point;                             //free the memory space in heap
    delete y_point;                             //free the memory space in heap
    std::cout << "Object is destroyed" << std::endl;
}

int main(int argc, char **argv){
    
    //Point p1(10.0, 20.99);
    //p1.print_info();

    //CREATE TEMPORARY OBJECTS 
    Point p2(std::move(Point(20.99, 30.99)));   //PLEASE NOTE THE std::move() => THIS FORCES THE COMPILER TO NOT USE COPY CONSTRUCTOR AND USE MOVE SEMANTICS INSTEAD
    p2.print_info();                            //ELSE THERE IS A CHANCE THE COMPILER MIGHT PERFORM OPTIMIZATIONS DURING COMPILATION AND INSTEAD USE COPY CONSTRUCTOR

    return 0;

}