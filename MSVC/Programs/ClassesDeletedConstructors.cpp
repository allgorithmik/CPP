#include<iostream>

//Deleted Constructors => Disable a Constructor from being used to create objects => this is required when we do not want our objecs to be copied

class Person{
    private:
        std::string name {};
        int age {};

    public:
        Person() = delete;                                                                  //this is the DEFAULT constructor
        Person(const Person &source_person) = delete;                                       //this constructor is deleted and hence cannot be called for created an object
        Person(Person &&source_person) = delete;                                            //this constructor is deleted and hence cannot be called for created an object
        Person(std::string name_param, int age_param);                                      //this constructor CAN be called to create an object
        void print_info();
};

Person::Person(std::string name_param, int age_param) : name(name_param), age(age_param){}  //implementation of NON-DELETED constructor
//DELETED / DISABLED CONSTRUCTORS NEED NOT BE IMPLEMENTED

void Person::print_info(){
    std::cout << "Name of Person is: " << this->name << " and age is: " << this->age << std::endl;
}

int main(int argc, char **argv){
    
    //Person();                                                                               //COMPILER ERROR =>default constructor is deleted / disabled=>hence not callable
    Person p1("Some_name", 100);                                                            //calling a copy constructor to create an object
    p1.print_info();
    return 0;
}