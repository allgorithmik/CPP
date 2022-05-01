#include<iostream>

struct Point{
    double x {};
    double y {};
};

void func1(const Point p){                                                                  //SAME FUNCTIONALITY CAN BE ACHIEVED USING FUNCTIONS INTEAD OF REPEATED std::cout
    std::cout << "Value of x is: " << p.x  << " and value of y is: " << p.y << std::endl;   //BUT NOT USED HERE
}

int main(int argc, char **argv){

    Point point1 {10.99, 11.99};

    //STRUCTURED BINDING SYNTAX => a and b ARE JUST COPIES OF x and y FROM STRUCT => STRUCTURED BINDINGS WILL ONLY WORK IF THE MEMBERS ARE public
    auto [a, b] = point1;                                                                   //IT'S MANDATORY TO USE auto TYPE FOR STRUCTURED BINDINGS => ELSE COMPILER ERROR
    //auto [&a, &b] = point1;                                                               //COMPILER ERROR => STRUCTURED BINDINGS CANNOT USE REFERENCES etc.

    std::cout << "Value of a from structured binding: " << a << std::endl;                  //SAME FUNCTIONALITY CAN BE ACHIEVED USING FUNCTIONS INTEAD OF REPEATED std::cout
    std::cout << "Value of b from structured binding: " << b << std::endl;

    std::cout << "Value of x from struct Point: " << point1.x << std::endl;
    std::cout << "Value of y from struct Point: " << point1.y << std::endl;

    point1.x = 100.99;
    point1.y = 200.99;
    std::cout << "Values of a and b will be changed as they are just copies" << std::endl;
    std::cout << "Value of a from structured binding: " << a << std::endl;
    std::cout << "Value of b from structured binding: " << b << std::endl;
    std::cout << "But values of x and y will be changed" << std::endl;
    std::cout << "Value of x from struct Point: " << point1.x << std::endl;
    std::cout << "Value of y from struct Point: " << point1.y << std::endl;

    //CAPTURING STRUCTURED BINDING VALUES FROM WITHN A LAMBDA FUNCTION IS ONLY POSSIBLE FROM C++20
    auto func1 = [a](){std::cout << "Its possible to capture structured bindings from a lambda function => Value of a: " << a << std::endl;};
    func1();
    return 0;
}