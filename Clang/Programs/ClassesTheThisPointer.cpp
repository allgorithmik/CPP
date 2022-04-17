#include<iostream>

//THE this POINTER:
//EACH CLASS MEMBER FUNCTION CONTAINS A HIDDEN POINTER CALLED this. IT CONTAINS THE ADDRESS OF THE CURRENT OBJECT FOR WHICH THE METHOD IS BEING EXECUTED. this ALSO APPLIES TO
//CONSTRUCTORS AND DESTRUCTORS

class Dog{
    std::string name;
    std::string breed;
    int *age {nullptr};

    public:
        Dog();
        Dog(std::string name_param, std::string breed_param, int age_param);
        void dog_behave();
        void set_name(const std::string &dog_param);
};

//USING this TO REFER TO CONSTRUCTORS
Dog::Dog(){
    std::cout << "This is a normal constructor from " << this << std::endl;         //this POINTS TO THE CURRENT ADDRESS OF NORMAL Dog() CONSTRUCTOR
}

//USING this TO REFER TO CONSTRUCTORS
Dog::Dog(std::string name_param, std::string breed_param, int age_param){
    name = name_param;
    breed = breed_param;
    age = new int;
    *age = 10;
    std::cout << "This is a parameterized constructor from " << this << std::endl;  //this POINTS TO THE CURRENT ADDRESS OF PARAMETERIZED Dog(<params>) CONSTRUCTOR
}

void Dog::set_name(const std::string &dog_name){
    
}

int main(int argc, char **argv){

    Dog dog1("Canine1", "Dog", 10);
    Dog dog2;
    return 0;
}