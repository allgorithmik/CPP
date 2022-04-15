#include<iostream>

//DESTRUCTORS ARE SPECIAL METHODS WHICH ARE CALLED WHEN AN OBJECT / INSTANCE OF CLASS NEEDS TO BE DESTROYED FROM MEMORY. THEY ARE NEEDED FOR PURPOSES OF CLEANING UP THE
//MEMORY OR TO RELEASE THE DYNAMIC MEMORY DURING RUNTIME
//DESTRUCTORS ARE CALLED DURING BELOW (BUT NOT LIMITED TO) SITUATIONS:
//WHEN AN OBJECT IS PASSED BY VALUE TO A FUNCTION
//WHEN A LOCAL OBJECT IS RETURNED FROM A FUNCTION (ONLY IN SOME COMPILERS)
//WHEN A LOCAL STACK OBJECT GOES OUT OF SCOPE
//WHEN A HEAP OBJECT IS RELEASED BY USING delete OPTION 

class Animal{
    std::string animal_name;
    std::string animal_breed;
    int *p_age {nullptr};

    public:
        Animal();

        Animal(std::string name_param, std::string breed_param, int age_param);

        ~Animal();                                                  //THIS IS THE DESTRUCTOR OF Animal CLASS AND WILL BE CALLED BY THE COMPILER WHEN A OBJECT IS DESTROYED

        void animal_behave();
};

Animal::Animal(){                                                   //IF IMPLEMENTATION FOR default CONSTRUCTOR PROVIDED, default KEYWORD MUST BE REMOVED IN PROTOTYPE
    std::cout << "This is the default constructor without params" << std::endl;
}

Animal::Animal(std::string name_param, std::string breed_param , int age_param){
        animal_name = name_param;
        animal_breed = breed_param;
        p_age = new int;
        *p_age = age_param;
        std::cout << "This is the parameterized constructor" << std::endl;
}

Animal::~Animal(){                                                  //IMPLEMENTATION OF Animal CLASS DESTRUCTOR AND THE CODE WITHIN THIS BLOCK WILL BE EXECUTED WHEN THE
    delete p_age;                                                   //DESTRUCTOR IS CALLED *****DESCTRUCTORS ALWAYS DO NOT HAVE PARAMS / ARGS*****
    std::cout << "Animal instance / object destroyed" << std::endl;
}

void Animal::animal_behave(){
    std::cout << animal_name << " is an animal and its of " << animal_breed << " breed with age " << *p_age << std::endl;
}

void some_func(){
    Animal animal1("Tiger", "Cat", 10);
    animal1.animal_behave();
}

void some_func_param(Animal ani){
    std::cout << "Passing an object as param / arg to function via pass by value" << std::endl;
}

void some_func_pointer(){
    Animal *p_animal3 = new Animal("Tiger", "Cat", 10);
    delete p_animal3;
}

int main(int argc, char **argv){

    Animal animal1("Tiger", "Cat", 10);
    animal1.animal_behave();
    //PLEASE NOTE: ONLY CONSTRUCTOR IS CALLED BUT NOT DESTRUCTOR => THIS IS BECAUSE AS WE HAVE CREATED THE OBJECT USING new OPERATOR AND OBJECT AS POINTER, WE HAVE TO
    //EXPLICITLY CALL THE delete TO DESTRY THE OBJECT => ONLY THEN ITS DESTRUCTOR WILL BE CALLED (delete IS INCLUDED NOW => HENCE DESTRUCTOR IS CALLED)
    some_func_pointer();
    Animal animal2("Tiger", "Cat", 10);
    some_func();                                                    //WE CAN EVEN HAVE A FUNCTION CREATE AN OBJECT OF A CLASS => WHEN THIS FUNCTION IS EXITED, DESTRUCTOR
    return 0;                                                       //IS CALLED
}