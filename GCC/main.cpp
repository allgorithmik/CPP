#include<iostream>

//Aggregates group together entities in a container like data structure. These containers are initialized using INITIALIZER LIST CONSTRUCTORS. Some of the aggregates we
//already use are arrays, structs. In this lesson we use structs to initialize the aggregates as arrays are built in and we do not want to mess with it using our own
//constructors. USING INITIALIZER LIST CONSTRUCTORS, WE CAN MODIFY THE DEFAULT BEHAVIOUR OF INITIALIZERS WHICH INITIALIZE THE AGGREGATES

struct Point{                                                       //struct members are PUBLIC by default
public:
    Point(std::initializer_list<double> list){
        std::cout << "Initializer List Constrctor called" << std::endl;
        std::cout << "List size is: " << list.size()  << std::endl;
        std::cout << "First Element is: " << **(list.begin())  << std::endl;    //Dereference it
        std::cout << "List size is: " << *(list.begin() + 1)  << std::endl;     //Dereference it
        list.x = list.begin();
    }

    void print_info() const{
        std::cout << "X: " << x << " Y: " << y  << std::endl;
    }

private:
    double x;
    double y;
};

int main(int argc, char **argv){
    Point p1 {10.99, 11.99};                                        //default initializer list for initializing the struct
    //std::cout << "X: " << p1.x << " Y: " << p1.y  << std::endl;   //COMPILER ERROR => x and y are no longer public => they have been made private
    return 0;
}