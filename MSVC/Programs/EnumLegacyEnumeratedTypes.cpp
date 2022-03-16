#include<iostream>

//OLD ENUMs => Legacy enums
//Legacy enums implicitly transform enumerator represention to ints, which is good for std::cout, but that introduces many problems which arise when we start comparing
//different enum types leading to confusion
//LEGACY ENUMS APART FROM BEING UNSAFE => THEY SUPPORT ALL FEATURES SUPPORTED BY MODERN ENUM CLASSES LIKE, CUSTOM INDEXING, REPRESENTNG ENUMERATORS WITH OTHER ENUMERATORS,
//NEGATIVE ENUMERATOR REPRESENTATION, MULTIPLE ENUMERATORS WITH SAME REPRESENTATION, CUSTOM ENUMARATOR DATATYPES etc
enum Direction {                                                                             //LEGACY ENUM
    Left,
    Right,
    Center,
    Top,
    Down
};

enum class DirectionClass {                                                                  //MODERN ENUM CLASS
    Left,
    Right,
    Center,
    Top,
    Down
};

enum Tools {                                                                                 //LEGACY ENUM
    Screwdriver,
    Spanner,
    Wrench,
    Hammer,
    Drill
};

enum class ToolsClass {                                                                      //MODERN ENUM CLASS
    Screwdriver,
    Spanner,
    Wrench,
    Hammer,
    Drill
};

int main(int argc, char **argv){
    Direction directon {Left};
    Tools tool {Screwdriver};

    std::cout << std::boolalpha;
    std::cout << "Comparing two enumerators: " << (directon > tool) << std::endl;            //build finishes with warnings => but result is very confusing => problem with 
    std::cout << directon << std::endl;                                                      //LEGACY ENUMs
    std::cout << tool << std::endl;

    DirectionClass directionclass {DirectionClass::Left};
    ToolsClass toolclass {ToolsClass::Drill};

    //std::cout << "Comparing two enum classes: " << (directionclass > toolclass) << std::endl;//COMPILER ERROR => THIS EXPESSION IS NOT POSSIBLE IN MODERN enum classes
    return 0;
}