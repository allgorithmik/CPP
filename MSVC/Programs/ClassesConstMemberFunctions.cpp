#include<iostream>

//THIS LESSON IS THE SOLUTION FOR const OBJECTS AND PASSING const OBJECTS AS FUNCTION PARAMS / ARGS LESSONS
//=> APPEND const TO MEMEBER FUNCTION SIGNATURES => COMPILER NOW KNOWS THAT THE MEMBER FUNCTION WILL NOT MODIFY THE MEMEBER VARIABLES
//CAN BE SPLIT INTO PROTOTYPES AND DEFINTIONS
//*****ACTUALLY, MEMBER FUNCTIONS WITH const CAN BE OVERLOADED => FUNCTIONS WITH const AND FUNCTIONS WITHOUT const ARE CONSIDERED TWO DIFFERENT FUNCTIONS*****

class Animal{
    public:
    Animal();
    Animal(const std::string_view name_param, const std::string_view breed_param, const int age_param);
    ~Animal();
    void set_name(const std::string_view name);
    void set_breed(const std::string_view breed);
    void set_age(const int age);
    std::string_view get_name() const;                  //SOLUTION FOR const OBJECTS AND PASSING const OBJECTS AS FUNCTION PARAMS / ARGS LESSONS
    std::string_view get_breed() const;                 //SOLUTION FOR const OBJECTS AND PASSING const OBJECTS AS FUNCTION PARAMS / ARGS LESSONS
    int get_age() const;                                //SOLUTION FOR const OBJECTS AND PASSING const OBJECTS AS FUNCTION PARAMS / ARGS LESSONS
    void print_info() const;                            //SOLUTION FOR const OBJECTS AND PASSING const OBJECTS AS FUNCTION PARAMS / ARGS LESSONS
    void print_info();                                  //OVERLOADED MEMEBER FUNCTION USING const => print_info() WITH const IS DIFFERENT THAN print_info() WIHOUT const

    private:
    std::string animal_name {};
    std::string animal_breed {};
    int animal_age {};

};

void some_func1(Animal animal);
void some_func2(Animal &animal);
void some_func3(const Animal &animal);
void some_func4(Animal *animal);

Animal::Animal(){

}

Animal::Animal(const std::string_view name_param, const std::string_view breed_param, const int age_param){
    animal_name = name_param;
    animal_breed = breed_param;
    animal_age = age_param;
}

Animal::~Animal(){
    std::cout << "This object is destroyed" << std::endl;
}

void Animal::set_name(const std::string_view name){
    animal_name = name;
}

void Animal::set_breed(const std::string_view breed){
    animal_breed = breed;
}

void Animal::set_age(const int age){
    animal_age = age;
}

std::string_view Animal::get_name() const{              //SOLUTION FOR const OBJECTS AND PASSING const OBJECTS AS FUNCTION PARAMS / ARGS LESSONS
    return animal_name;
}

std::string_view Animal::get_breed() const{             //SOLUTION FOR const OBJECTS AND PASSING const OBJECTS AS FUNCTION PARAMS / ARGS LESSONS
    return animal_breed;
}

int Animal::get_age() const{                            //SOLUTION FOR const OBJECTS AND PASSING const OBJECTS AS FUNCTION PARAMS / ARGS LESSONS
    return animal_age;
}

void Animal::print_info() const{
    std::cout << "The name of animal is: " << animal_name << std::endl;
    std::cout << "The breed of " << animal_name << " is " << animal_breed << std::endl;
    std::cout << "The age of " << animal_name << " is " << animal_age << std::endl;
}

void Animal::print_info(){                              //OVERLOADED MEMEBER FUNCTION USING const => print_info() WITH const IS DIFFERENT THAN print_info() WIHOUT const
    std::cout << "The name of animal is: " << animal_name << std::endl;
    std::cout << "The breed of " << animal_name << " is " << animal_breed << std::endl;
    std::cout << "The age of " << animal_name << " is " << animal_age << std::endl;
}

int main(int argc, char **argv){

    const Animal animal1("NAME", "BREED", 100);

    animal1.get_age();                                  //NOW READING MEMEBER VARIABLES FROM const OBJECTS WORKS => APPENDED const IN FUNCTION SIGNATURES
    animal1.print_info();                               //NOW READING MEMEBER VARIABLES FROM const OBJECTS WORKS => APPENDED const IN FUNCTION SIGNATURES
    //animal1.set_name("NAME");                         //SETTING IS NOT POSSIBLE AS WE ARE TRYNG TO MODIFY A const VARIABLE
    //animal1.set_breed("BREED");                       //SETTING IS NOT POSSIBLE AS WE ARE TRYNG TO MODIFY A const VARIABLE
    //animal1.set_age("100");                           //SETTING IS NOT POSSIBLE AS WE ARE TRYNG TO MODIFY A const VARIABLE
    animal1.print_info();                               //WHICH IMPEMENTATION OF print_info() WILL BE EXECUTED?

    some_func1(animal1);
    //some_func2(animal1);
    some_func3(animal1);
    //some_func4(&animal1);
    return 0;
}

void some_func1(Animal animal){
    animal.get_name();
    animal.print_info();
}

void some_func2(Animal &animal){
    animal.get_name();
    animal.print_info();
}

void some_func3(const Animal &animal){                  //NOW POSSIBLE TO PASS const OBJECTS AS const REFERENCE VARIABLES
    animal.get_name();
    animal.print_info();
}

void some_func4(Animal *animal){
    animal->get_name();
    animal->print_info();
}