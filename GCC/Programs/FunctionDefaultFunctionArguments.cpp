#include<iostream>

//function prototype => default values MUST BE given in the PROTOTYPE itself => IF PROTOTYPE IS NOT AVAILABLE (FUNCTION IS NOT SPLIT INTO POTOTYPE AND DEFINTION), THEN
//DEFAULT VALUES CAN BE PASSED IN THE FUNCTION SIGNATURE DIRECTLY
double area_rectangle(double length = 100, double breadth = 50, double height = 55.55); //function prototype

int main(int argc, char **argv){

    std::cout << "Calling the area_rectangle()" << std::endl;

    //CALLING THE FUNCTION WITH ALL PARAMS BEING DEFAULT => COMPILER ALWAYS READS PARAMS / ARGS FROM LEFT TO RIGHT => NO UNORDERED PARAMS / ARGS ARE SUPPORTED
    std::cout << "The area of the rectangle with all default args: " << area_rectangle() << std::endl;  //DIRECTLY PLUGGING IN THE FUNCTION INTO std::cout STATEMENT

    //CALLING THE FUNCTION WITH ALL PARAMS BEING DEFINED BY USER => COMPILER ALWAYS READS PARAMS / ARGS FROM LEFT TO RIGHT => NO UNORDERED PARAMS / ARGS ARE SUPPORTED
    double res1 = area_rectangle(10, 20, 30);
    std::cout << "The area of the rectangle with user defined args: " << res1 << std::endl;

    //CALLING THE FUNCTION WITH ONLY PARTIAL PARAMS BEING DEFINED BY USER => WHICHEVER PARAM IS MISSING, ITS RESPECTIVE DEFAULT PARAM WILL BE USED BY COMPILER
    //=> COMPILER ALWAYS READS PARAMS / ARGS FROM LEFT TO RIGHT => NO UNORDERED PARAMS / ARGS ARE SUPPORTED
    double res2 = area_rectangle(10, 30);
    std::cout << "The area of the rectangle with only some user defined args: " << res2 << std::endl;

    return 0;
}

double area_rectangle(double length, double breadth, double height){                    //function definition => default values MUST NOT BE given in the function definition
    double area {};
    area = length * breadth * height;
    return area;
}