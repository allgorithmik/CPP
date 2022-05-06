#include<iostream>

class Square{
    private:
        double side {};

    public:
        Square() = default;
        explicit Square(const double side_param);                           //explicit DECLARATION OF CONSTRUCTOR MUST BE DONE OUTSIDE OF CLASS => ELSE COMPILER ERROR
        //explicit Square(const double side_param, std::string color = "Orange");//explicit DECLARATION WILL ALSO WORK FOR PARAMS WITH DEFAULT ARGS => ELSE IMPLICIT CASTING
        ~Square();
        double squareArea() const;
};

//Initializer List Initialization
Square::Square(const double side_param) : side{side_param}{

}

Square::~Square(){
    std::cout << this << "Object is destroyed" << std::endl;
}

double Square::squareArea() const{
    return side * side;
}

std::string compareSquare(const Square &square1, const Square &square2){
        return (square1.squareArea() > square2.squareArea()) ? "S1" : "S2";
}

int main(int argc, char **argv){

    Square s1(100);                                                         //TEMPORARILY COMMENTING OUT SECOND CONSTRUCTOR AS MULTIPLE CONSTRUCTORS MATCH THE
    Square s2(200);                                                         //CONSTRUCTOR WITH SINGLE PARAM / ARGS

    //ALL IS GOOD AS LONG AS WE PASS TWO OBJECTS AS PARAMS / ARGS TO compareSquare FUNCTION
    auto var1 = compareSquare(s1, s2);
    std::cout << "The bigger square is: " << var1 << std::endl;

    //BUT WHEN WE PASS ONE OBJECT AND ONR INT LITERAL AS AS PARAM / ARGS FOR compareSquare FUNCTION, IMPLICIT CASTING WILL TAKE PLACE => INT LITERAL WILL BE CASTED AS
    //OBJECT => WHICH IS NOT WHAT WE WANT => IMPLICIT CASTING OF PARAMS / ARGS WILL HAPPEN BECAUSE WE HAVE NOT MARKED THE Square() AS EXPLICIT
    //auto var2 = compareSquare(s1, 55.55);                                   //AS EXPECTED WE WILL GET COMPILER ERROR AS WE HAVE MARKED THIS CONSTRUCTOR AS explicit
    //NOW THERE IS NO COMPILER ERROR BECAUSE explicit HAS BEEN REMOVED FOR CONSTRUCTOR WITH DEFAULT ARGS => PUT BACK explicit
    //auto var3 = compareSquare(s1, 55.55);
    //std::cout << "The bigger square is: " << var2 << std::endl;

   return 0;
}