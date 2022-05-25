#include<iostream>

//Aggregate Initialization were introduced in C++20 => This technique was introduced to be super selective about which member variables must be initialized during
//class object creation

struct Component{
    double x;
    double y;
    double z;
};

void print_component(const Component &c){
    std::cout <<  "Components: " << c.x << " " << c.y << " " << c.z << std::endl;
}

int main(int argc, char **argv){

    Component c1 {.x = 10.99, .y = 11.99, .z = 15.99};      //SPECIFIC MEMBER VARIABLE CAN BE INITIALIZED USING THIS SYNTAX
    Component c2 {.x = 19.99, .y = 21.99, .z = 15.99};      //SPECIFIC MEMBER VARIABLE CAN BE INITIALIZED USING THIS SYNTAX
    Component c3 {.x = 100.99, .y = 101.99, .z = 105.99};   //SPECIFIC MEMBER VARIABLE CAN BE INITIALIZED USING THIS SYNTAX
    Component c4 {.x = 100.99, .z = 105.99};                //SPECIFIC MEMBER VARIABLE CAN BE INITIALIZED USING THIS SYNTAX => WE CAN EVEN SKIP MEMBERS (.y MISSING)
    //Component c5 {.x = 100.99, .z = 101.99, .y = 105.99}; //COMPILER ERROR => WE CANNOT FLIP / JUMBLE UP THE MEMBERS
    Component c6 {.x = 100.99, .y = 101.99};                //WE CAN EVEN SKIP MEMBERS (.z MISSING) => MEMEBRS NOT INITIALIZED / SKIPPED WILL BE INITIALIZED TO ZERO

    print_component(c1);
    print_component(c2);
    print_component(c3);
    print_component(c4);
    print_component(c6);
    return 0;
}