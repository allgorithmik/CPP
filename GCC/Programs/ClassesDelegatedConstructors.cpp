#include<iostream>

class Square{
    public:
        Square() = default;
        explicit Square(const double side_param);
        Square(double side_param, std::string color_param, int shading_param);
        double get_param() const;
        ~Square();

    private:
        double side;
        std::string color;
        int shade;
        double position;
};
    //INITIALIZER LIST INILIALIZED CONSTRUCTOR / THIS IS A REWORK OF ASSIGNING SAME PARAMS AGAIN AND AGAIN IN MULTIPLE CONSTRUCTORS => HENCE CONSTRUCTOR DELEGATION
    //USING CONSTRUCTOR DELEGATION
    //THE DELEGATED CONSTRUCTOR BELOW DELEGATES THE ASSIGNMENT OF A SINGLE PARAM CONSTRUCTOR TO THE CONSTRUCTOR WITH THREE PARAM CONSTRUCTOR => DETERMINED BY THREE
    //ARGS CONSTRUCTOR => ONCE THE DELEGATION IS DONE, THE CONTROL HITS THE BODY OF THE CONSTRUCTOR WITH SINGLE PARAM => SEQUENCE OF EVENTS IS IMPORTANT IN CONSTRUCTOR
    //DELEGATION => THESE SEQUENCE OF EVENTS CAN BE VERIFIED USING THE DEBUGGER CALL STACK
    Square::Square(const double side_param) : Square(side_param, "RED", 10){            //DELEGATED CONSTRUCTORS MUST BE DEFINED BEFORE THE CONSTRUCTOR WHICH IT IS DELAGATED
        std::cout << "This is a delegated constructor with SINGLE param" << std::endl;  //FROM
    }
    //INITIALIZER LIST INILIALIZED CONSTRUCTOR
    Square::Square(double side_param, std::string color_param, int shading_param) : side{side_param}, color{color_param}, shade{shading_param}{ //position is left out
        std::cout << "This is a delegated constructor with THREE params" << std::endl;
    }

    //Square::Square(const double side_param) : Square(side_param, "RED", 10){
    //    std::cout << "This is a delegated constructor" << std::endl;
    //}

    //CONSTRUCTOR DELEGATION IS ONLY POSSIBLE WITH INITIALIZER LIST INITIALIZATION SYNTAX => COMMENTING OUT THE BELOW CODE TO AVOID REDEFINITION CMPILER ERROR
    /*Square::Square(const double side_param){
        std::cout << "This is a delegated constructor" << std::endl;
        Square(side_param, "RED", 10);                              //THIS IS NOT CONSTRUCTOR DELEGATION, THIS WILL JUST CASE A LOCAL OBJECT OF Square TO BE CREATED
    }                                                               //AND WILL BE DISCARDED ONCE THE CONTROL EXITS THIS BLOCK
    */
    //COMPILER ERROR => AS NO FURTHER INITIALIZATION IS ALLOWED AFTER / BEFORE DELEGATION CALL
    /*
    Square::Square(const double side_param) : Square(side_param, "RED", 10), position(1, 1){    //COMPILER ERROR
    Square::Square(const double side_param) : position(1, 1), Square(side_param, "RED", 10){}   //COMPILER ERROR
        std::cout << "This is a delegated constructor" << std::endl;
    }*/

    double Square::get_param() const{
        return side;
    }

    Square::~Square(){
        std::cout << "This Object is Destroyed" << std::endl;
    }

int main(int argc, char **argv){

    Square square1(10);
    auto var1 = square1.get_param();
    std::cout << var1 << std::endl;
    return 0;
}