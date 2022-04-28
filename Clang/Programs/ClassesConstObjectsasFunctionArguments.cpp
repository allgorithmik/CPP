#include<iostream>

class Animal{
    public:
    Animal(const std::string_view name_param, const std::string_view breed_param, const int age_param);
    void set_name(const std::string_view name);
    void set_breed(const std::string_view breed);
    void set_age(const int age);
    void print_info();
    std::string_view get_name();
    std::string_view get_breed();
    int get_age();

    private:
    std::string_view animal_name;
    std::string_view animal_breed;
    int animal_age;
};

Animal::Animal(const std::string_view name_param, const std::string_view breed_param, const int age_param){
    animal_name = name_param;
    animal_breed = breed_param;
    animal_age = age_param;
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

std::string_view Animal::get_name(){
    return animal_name;
}

std::string_view Animal::get_breed(){
    return animal_breed;
}

int Animal::get_age(){
    return animal_age;
}

void Animal::print_info(){
    std::cout << "The name of animal is: " << animal_name  << std::endl;
    std::cout << "The breed of " << animal_name << " is: " << animal_breed  << std::endl;
    std::cout << "The age of " << animal_name << " is: " << animal_age  << std::endl;
}

//PASSING A const OBJECT AS PASS BY VALUE
void some_func1(Animal animal);

//PASSING A const OBJECT AS PASS BY non-const REFERENCE
void some_func2(Animal &animal);

//PASSING A const OBJECT AS PASS BY const REFERENCE
void some_func3(const Animal &animal);

//PASSING A const OBJECT AS PASS BY POINTER
void some_func4(Animal *animal);

//PASSING A const OBJECT AS PASS BY POINTER TO const
void some_func5(const Animal *animal);

//OPTIONS FOR PASSING A const OBJECT AS PARAMS / ARGS TO A FUNCTION:
//Pass by value
//Pass by reference
//Pass by const reference
//Pass by pointer (to non const)
//Pass by pointer to const

int main(int argc, char **argv){

    const Animal animal1("Animal", "Breed", 100);

    //PASSING A const OBJECT AS PASS BY VALUE
    some_func1(animal1);                            //THIS WILL WORK AS WE ARE PASSING A const OBJECT BY VALUE -> PASS BY VALUE => HENCE NOT THE SAME AS const animal1

    //PASSING A const OBJECT AS PASS BY non-const REFERENCE => COMPILER ERROR => PLEASE REFER ClassesConstObjetcs lESSON
    //some_func2(animal1);                            //THIS WILL NOT WORK AS THE COMPILER THINKS WE CAN MODIFY THE MEMBERS OF OBJECT => REFER ClassesConstObjetcs lESSON

    //PASSING A const OBJECT AS PASS BY POINTER => COMPILER ERROR => PLEASE REFER ClassesConstObjetcs lESSON
    //some_func4(&animal1);                           //THIS WILL NOT WORK AS THE COMPILER THINKS WE CAN MODIFY THE MEMBERS OF OBJECT => REFER ClassesConstObjetcs lESSON

    //PASSING A const OBJECT AS PASS BY POINTER TO const => COMPILER ERROR => PLEASE REFER ClassesConstObjetcs lESSON
    //some_func5(animal1);                            //THIS WILL NOT WORK AS THE COMPILER THINKS WE CAN MODIFY THE MEMBERS OF OBJECT => REFER ClassesConstObjetcs lESSON

    return 0;
}

void some_func1(Animal animal){                     //PASSING A const OBJECT AS PASS BY VALUE TO A FUNCTION WORKS AS WE ARE WORKING WITH A CAOPY AND NOT THE ACTUAL OBJECT
    animal.print_info();
    animal.get_name();
    animal.set_name("NAME");
}

void some_func2(Animal &animal){                    //THIS WILL NOT WORK AS THE COMPILER THINKS WE CAN MODIFY THE MEMBERS OF OBJECT => REFER ClassesConstObjetcs lESSON
    animal.print_info();
    animal.get_name();
    animal.set_name("NAME");
}

/*
void some_func3(const Animal &animal){              //THIS WILL NOT WORK AS THE COMPILER THINKS WE CAN MODIFY THE MEMBERS OF OBJECT => REFER ClassesConstObjetcs lESSON
    animal.print_info();
    animal.get_name();
    animal.set_name("NAME");
}
*/

void some_func4(Animal *animal){                    //THIS WILL NOT WORK AS THE COMPILER THINKS WE CAN MODIFY THE MEMBERS OF OBJECT => REFER ClassesConstObjetcs lESSON
    animal->print_info();
    animal->get_name();
    animal->set_name("NAME");
}

/*
void some_func5(const Animal *animal){              //THIS WILL NOT WORK AS THE COMPILER THINKS WE CAN MODIFY THE MEMBERS OF OBJECT => REFER ClassesConstObjetcs lESSON
    animal->print_info();
    animal->get_name();
    animal->set_name("NAME");
}
*/