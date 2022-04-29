#include<iostream>

class Animal{
    private:
    std::string animal_name;
    std::string animal_breed;
    int animal_age;

    public:
    Animal() = default;                             //DO NOT FORGET THIS => IF THIS IS DECLARED HERE => Animal(){} IS NOT REQUIRED TO BE IMPLEMENTED
    Animal(const std::string_view &name_param, const std::string_view &breed_param, const int &age_param);
    std::string &get_name();                        //no const in function signature because the function has to be able to modify the value of class member variables
    std::string &get_breed();                       //no const in function signature because the function has to be able to modify the value of class member variables
    int &get_age();                                 //no const in function signature because the function has to be able to modify the value of class member variables

    const std::string &get_name() const;            //As discussed in previous lesson(const member functions => solution for const objects) we can overload a function
    const std::string &get_breed() const;           //using const => const <<return_type> &<function_name>> const is DIFFERENT than <<return_type> &<function_name>>
    const int &get_age() const;                     //this type of overloaded function can be used for situations where the function need not modify the member variables
    ~Animal();
};

//Animal::Animal(){}                                  //this is not needed if Animal() = default is declared in class => I HAD FORGOTTEN IT DO NOT FORGET STUFF

Animal::Animal(const std::string_view &name_param, const std::string_view &breed_param, const int &age_param){
    animal_name = name_param;
    animal_breed = breed_param;
    animal_age = age_param;
}

std::string &Animal::get_name(){                    //this function returns a reference of the member variable => any modification to the member variable value will
    return animal_name;                             //affect the value returned by the function => hence acting as both setter and getter => NOTICE NO const
}

std::string &Animal::get_breed(){                   //this function returns a reference of the member variable => any modification to the member variable value will
    return animal_breed;                            //affect the value returned by the function => hence acting as both setter and getter => NOTICE NO const
}

int &Animal::get_age(){                             //this function returns a reference of the member variable => any modification to the member variable value will
    return animal_age;                              //affect the value returned by the function => hence acting as both setter and getter => NOTICE NO const
}

const std::string &Animal::get_name() const{        //Overloaded function for situations where the function need not modify the member variables
    return animal_name;                             //NOTICE THE const BEFORE AND AFTER FUNCTION SIGNATURE
}                                                   //COMPILER IS SMART ENOUGH TO CALL THE APPROPRIATE FUNCTION (const OR non-const FUNCTION) AS NEEDED

const std::string &Animal::get_breed() const{       //Overloaded function for situations where the function need not modify the member variables      
    return animal_breed;                            //NOTICE THE const BEFORE AND AFTER FUNCTION SIGNATURE
}                                                   //COMPILER IS SMART ENOUGH TO CALL THE APPROPRIATE FUNCTION (const OR non-const FUNCTION) AS NEEDED

const int &Animal::get_age() const{                 //Overloaded function for situations where the function need not modify the member variables
    return animal_age;                              //NOTICE THE const BEFORE AND AFTER FUNCTION SIGNATURE
}                                                   //COMPILER IS SMART ENOUGH TO CALL THE APPROPRIATE FUNCTION (const OR non-const FUNCTION) AS NEEDED

Animal::~Animal(){
    std::cout << "This object is destroyed" << std::endl;
}

int main(int argc, char **argv){

    Animal animal1;

    std::cout << "Calling get_name(), get_breed() and get_age() BEFORE changing member variable values" << std::endl;
    auto var1 = animal1.get_name();
    auto var2 = animal1.get_breed();
    auto var3 = animal1.get_age();
    std::cout << "Name of Animal is: " << var1 << std::endl;
    std::cout << "Breed of Animal is: " << var2 << std::endl;
    std::cout << "Age of Animal is: " << var3 << std::endl;

    animal1.get_name() = "NEW_NAME";                //ASSIGNING A VALUE TO FUNCTION => THIS SYNTAX IS POSSIBLE BECAUSE THE FUNCTION IS RETURNING A REFERENCE
    animal1.get_breed() = "NEW_BREED";              //ASSIGNING A VALUE TO FUNCTION => THIS SYNTAX IS POSSIBLE BECAUSE THE FUNCTION IS RETURNING A REFERENCE
    animal1.get_age() = 100;                        //ASSIGNING A VALUE TO FUNCTION => THIS SYNTAX IS POSSIBLE BECAUSE THE FUNCTION IS RETURNING A REFERENCE
    auto var4 = animal1.get_name();
    auto var5 = animal1.get_breed();
    auto var6 = animal1.get_age();
    std::cout << "Calling get_name(), get_breed() and get_age() AFTER changing member variable values" << std::endl;
    std::cout << "Name of Animal is: " << var4 << std::endl;
    std::cout << "Breed of Animal is: " << var5 << std::endl;
    std::cout << "Age of Animal is: " << var6 << std::endl;

    std::cout << "Calling memebr functions where modifying member variables is NOT needed" << std::endl;
    auto var7 = animal1.get_name();
    auto var8 = animal1.get_breed();
    auto var9 = animal1.get_age();
    std::cout << "Name of Animal is: " << var7 << std::endl;
    std::cout << "Breed of Animal is: " << var8 << std::endl;
    std::cout << "Age of Animal is: " << var9 << std::endl;
    return 0;
}