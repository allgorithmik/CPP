#include<iostream>

//THE this POINTER:
//EACH CLASS MEMBER FUNCTION CONTAINS A HIDDEN POINTER CALLED this. IT CONTAINS THE ADDRESS OF THE CURRENT OBJECT FOR WHICH THE METHOD IS BEING EXECUTED. this ALSO APPLIES TO
//CONSTRUCTORS AND DESTRUCTORS

class Dog{
    std::string dog_name;
    std::string breed;
    int *age {nullptr};

    public:
        Dog();
        Dog(std::string name_param, std::string breed_param, int age_param);
        void dog_behave();
        Dog *set_name(const std::string &dog_param);
        void *set_age(int &age);
};

//USING this TO REFER TO CONSTRUCTORS
Dog::Dog(){
    std::cout << "This is a normal constructor from " << this << std::endl;         //this POINTS TO THE CURRENT ADDRESS OF NORMAL Dog() CONSTRUCTOR
}

//USING this TO REFER TO CONSTRUCTORS
Dog::Dog(std::string name_param, std::string breed_param, int age_param){
    dog_name = name_param;
    breed = breed_param;
    age = new int;
    *age = 10;
    std::cout << "This is a parameterized constructor from " << this << std::endl;  //this POINTS TO THE CURRENT ADDRESS OF PARAMETERIZED Dog(<params>) CONSTRUCTOR
}

//USING this TO RESLVE CONFLICTING NAMES / IDENTIFEIRS
Dog Dog::*set_name(const std::string &dog_name){
    this -> dog_name = dog_name;                                                    //this CAN RESOLVE CONFLICTS WHERE THE NAMES OF VARIABLES ARE SAME
    //dog_name = dog_name;                                                            //=> REMOVING "this ->" WILL RESULT IN COMPILER ERROR (COMMENTED OUT)
    return this;
}

Dog Dog::*set_age(int &age){
    this -> age = &age;
    return this;
}

int main(int argc, char **argv){

    Dog dog1("Canine1", "Dog", 10);
    Dog dog2;

    //USING this TO PERFORM CHAINED CALLS USING POINTERS
    Dog *dog3 = new Dog("Milo", "Dog", 10);
    std::cout << "Performng Chained Calls" << std::endl;
    dog3 -> set_name("Mill") -> set_age(10)


    return 0;
}