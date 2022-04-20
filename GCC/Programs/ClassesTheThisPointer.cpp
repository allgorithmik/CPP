#include<iostream>

//THE this POINTER:
//EACH CLASS MEMBER FUNCTION CONTAINS A HIDDEN POINTER CALLED this. IT CONTAINS THE ADDRESS OF THE CURRENT OBJECT FOR WHICH THE METHOD IS BEING EXECUTED. this ALSO APPLIES TO
//CONSTRUCTORS AND DESTRUCTORS => this POINTER CALLS A SPECIAL FUNCTION WHICH RETURNS THE CURRENT OBJECTS ADDRESS OR DOES THE this IMPLEMENTATION

class Dog{
    std::string dog_name;
    std::string dog_breed;
    int *age {nullptr};

    public:
        Dog();
        Dog(std::string name_param, std::string breed_param, int age_param);

        //FUNCTION PROTOTYPES FOR CHAINED FUNCTION CALLS USING POINTERS
        Dog *dog_behave();
        Dog *set_name(const std::string &dog_param);
        Dog *set_breed(const std::string &dog_breed);

        //FUNCTION PROTOTYPES FOR CHAINED FUNCTION CALLS USING REFERENCES
        Dog &dog_behave_ref();
        Dog &set_name_ref(const std::string &dog_param);
        Dog &set_breed_ref(const std::string &dog_breed);

};

//USING this TO REFER TO CONSTRUCTORS
Dog::Dog(){
    std::cout << "This is a normal constructor from " << this << std::endl;         //this POINTS TO THE CURRENT ADDRESS OF NORMAL Dog() CONSTRUCTOR
}

//USING this TO REFER TO CONSTRUCTORS
Dog::Dog(std::string name_param, std::string breed_param, int age_param){
    dog_name = name_param;
    dog_breed = breed_param;
    age = new int;
    *age = 10;
    std::cout << "This is a parameterized constructor from " << this << std::endl;  //this POINTS TO THE CURRENT ADDRESS OF PARAMETERIZED Dog(<params>) CONSTRUCTOR
}

//FUNCTION DEFINITIONS FOR CHAINED CALL OF FUNCTIONS USING POINTERS
Dog *Dog::dog_behave(){                                                             //NOTE THAT THIS FUNCTON RETURNS A POINTER
    std::cout << "This dog behaves" << std::endl;
    return this;                                                                    //return this IS MANDATORY FOR USING THIS FUNCTION FOR CHAINED CALLS USING POINTERS
}

Dog *Dog::set_name(const std::string &dog_name){                                    //NOTE THAT THIS FUNCTON RETURNS A POINTER
    this -> dog_name = dog_name;                                                    //HERE A MEMBER VARIABLE WITH SAME NAME IS RESOLVED BY THE this -> POINTER
    //dog_name = dog_name;                                                            //COMPILER ERROR => COMPILER DOES NOT KNOW WHICH dog_name WE ARE REFERRING TO
    return this;                                                                    //return this IS MANDATORY FOR USING THIS FUNCTION FOR CHAINED CALLS USING POINTERS
}

Dog *Dog::set_breed(const std::string &dog_breed){                                  //NOTE THAT THIS FUNCTON RETURNS A POINTER
    this -> dog_breed = dog_breed;                                                  //HERE A MEMBER VARIABLE WITH SAME NAME IS RESOLVED BY THE this -> POINTER
    return this;                                                                    //return this IS MANDATORY FOR USING THIS FUNCTION FOR CHAINED CALLS USING POINTERS
}

//FUNCTION DEFINITIONS FOR CHAINED CALL OF FUNCTIONS USING REFERENCES
Dog &Dog::dog_behave_ref(){                                                         //NOTE THAT THIS FUNCTON RETURNS A REFERENCE
    std::cout << "This dog behaves" << std::endl;
    return *this;                                                                   //DEREFERENCING *this IS MANDATORY FOR USING FUNCTION IN CHAINED CALLS USING REFERENCES
}

Dog &Dog::set_name_ref(const std::string &dog_name){                                //NOTE THAT THIS FUNCTON RETURNS A REFERENCE
    this -> dog_name = dog_name;                                                    //HERE A MEMBER VARIABLE WITH SAME NAME IS RESOLVED BY THE this -> POINTER
    //dog_name = dog_name;                                                            //COMPILER ERROR => COMPILER DOES NOT KNOW WHICH dog_name WE ARE REFERRING TO
    return *this;                                                                   //DEREFERENCING *this IS MANDATORY FOR USING FUNCTION IN CHAINED CALLS USING REFERENCES
}

Dog &Dog::set_breed_ref(const std::string &dog_breed){                              //NOTE THAT THIS FUNCTON RETURNS A REFERENCE
    this -> dog_breed = dog_breed;                                                  //HERE A MEMBER VARIABLE WITH SAME NAME IS RESOLVED BY THE this -> POINTER
    return *this;                                                                   //DEREFERENCING *this IS MANDATORY FOR USING FUNCTION IN CHAINED CALLS USING REFERENCES
}

int main(int argc, char **argv){

    Dog dog1("Canine1", "Dog", 10);
    Dog *p_dog = new Dog("Canine2", "Wolf", 10);

    std::cout << "USING POINTER NOTATION TO PERFORM CHAINED CALLS USING POINTERS" << std::endl;
    p_dog -> dog_behave();                                                          //USING POINTER NOTATION TO ACCESS MEMBERS OF A CLASS

    //CHAINED CALLS USNG POINTERS:
    //*****PLEASE NOTE***** => FOR A FUNCTION TO BE USED IN CHAINING USING POINTERS:
    //IT MUST RETURN A POINTER
    //IT MUST BE OF TYPE POINTER CLASS / OBJECT
    //IT MUST RETURN THE PONTER => return this
    p_dog->dog_behave()->set_name("Hello")->set_breed("Canine");                    //CHAINED CALL OF FUNCTIONS USING POINTERS => -> NOTATION
    delete p_dog;

    //CHAINED CALLS USING REFERENCES:
    //*****PLEASE NOTE***** => FOR A FUNCTION TO BE USED IN CHAINING USING REFERENCES:
    //IT MUST RETURN A POINTER TO this
    //IT MUST BE OF REFERENCE TYPE OF ITS CLASS / OBJECT
    //IT MUST RETURN THE PONTER => return *this
    Dog *p_dog1 = new Dog("Canine2", "Wolf", 10);
    p_dog1->dog_behave_ref().set_name_ref("Hello").set_breed_ref("Canine");         //CHAINED CALL OF FUNCTIONS USING REFERENCES => . NOTATION

    return 0;
}