#include<iostream>

class Animal{
    public:
    Animal();

    Animal(const std::string name_param, const std::string breed_param, const int age_param);

    void set_animal_name(const std::string  name);
    void set_animal_breed(const std::string breed);
    void set_animal_age(const int age);
    std::string get_animal_name();
    std::string get_animal_breed();
    int get_animal_age();
    void print_info();

    private:
    std::string animal_name;
    std::string animal_breed;
    int animal_age;
};

Animal::Animal(const std::string name_param, const std::string breed_param, const int age_param){
    animal_name = name_param;
    animal_breed = breed_param;
    animal_age = age_param;
}

void Animal::set_animal_name(const std::string name){
    animal_name = name;
}

void Animal::set_animal_breed(const std::string breed){
    animal_breed = breed;
}

void Animal::set_animal_age(const int age){
    animal_age = age;
}

std::string Animal::get_animal_name(){
    return animal_name;
}

std::string Animal::get_animal_breed(){
    return animal_breed;
}

int Animal::get_animal_age(){
    return animal_age;
}

void Animal::print_info(){
    std::cout << "The name of the animal: " << animal_name << std::endl;
    std::cout << "The breed of " << animal_name << " is: " << animal_breed << std::endl;
    std::cout << "The age of " << animal_name << " is: " << animal_age << std::endl;
}

int main(int argc, char **argv){

    //IF WE FLAG THE OBJECT AS const => NONE OF THE METHODS WILL WORK (setters / getters / normal) NO MATTER HOW WE TRY ACCESS THE MEMBERS / FUNCTIONS (pointer / reference)
    const Animal animal("animal", "breed", 10);         //DECLARING A const OBJECT WITH PARAMS / ARGS

    //animal.set_animal_name("some name");                //CANNOT MODIFY VALUE AS ITS A const VALUE => COMPILER ERROR
    //animal.print_info()                                 //CANNOT READ EITHER!!!!! => COMPILER ERROR
    //animal.get_animal_name();                           //CANNOT READ EITHER!!!!! => COMPILER ERROR

    //std::string var1 = animal.get_animal_name();        //CANNOT READ EITHER!!!!! => COMPILER ERROR

    //THE REASON WHY EVEN THE getters (WHICH ONLY READ VALUES AND NOT MODIFY VALUES) WILL GIVE COMPILER ERRORS IS BECAUSE WE HAVE NO WAY TO DIFFERENTIATE AND TELL
    //COMPILER THE DIFFERENCE BETWEEN METHODS THAT JUST READ THE VALUES (getters) AND METHODS THAT MODIFY THE VALUES (setters) SOLUTION IN SUBSEQUENT CHAPTERS

    //WHAT IF WE TRY MODIFYING / RETRIEVING VALUES VIA POINTERS => BOTTOM LINE IS NOT POSSIBLE EITHER
    Animal *animal1;
    animal1->print_info();                              //PROGRAM CRASHES! => THIS PROVES WE CANNOT READ / MODIFY VALUES EVEN VIA POINTERS
    //Animal *animal2 = &animal;                          //FIRST OF ITS COMPILER ERROR BECAUSE OF non-const ASSIGNING TO const OBJECT=>BUT EVEN IF const OBJECT NOT POSSIBLE
    //animal2->set_animal_breed("BREED");                 //CANNOT READ VIA POINTERS EITHER!!!!! => COMPILER ERROR

    //WHAT IF WE TRY MODIFYING / RETRIEVING VALUES VIA REFERENCES => BOTTOM LINE IS NOT POSSIBLE EITHER
    //Animal &animal3 = &animal;                          //FIRST OF ITS COMPILER ERROR BECAUSE OF non-const ASSIGNING TO const OBJECT=>BUT EVEN IF const OBJECT NOT POSSIBLE
    const Animal &animal4 = animal;
    //animal4.get_animal_age();                           //COMPILER ERROR => CANNOT READ / MODIFY EITHER

    //GOING THROUGH POINTER TO CONST
    const Animal *animal2 = &animal;
    //animal2->get_animal_age();                          //COMPILER ERROR => CANNOT READ / MODIFY EITHER

    return 0;
}