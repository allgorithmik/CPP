#include<iostream>

//If we store Objects in Arrays, copies of objects will be stored. another place where copies of objects are created is in range based for loop. We can use references to
//avoid making copies of objects. Regular loops will NOT make any copies of objects

class Person{
    private:
        std::string name {};
        int age {};

    public:
        Person() = default;
        Person(std::string name_param, int age_param);
        void set_name(std::string name_param);
        void set_age(int age_param);
        std::string get_name();
        int get_age();
        void get_info();
        ~Person();
};
/* Commenting this out to use initializer list initialization constructor instead
Person::Person(std::string name_param, int age_param){
    std::cout << "Copy Constructor Called for " << name_param << std::endl;
    this->name = name_param;
    this->age = age_param;
}
*/

//Initializer List Initialization Constructor
Person::Person(std::string name_param, int age_param) : name(name_param), age(age_param){
    std::cout << "Copy Constructor called for " << name_param << std::endl;
}

void Person::set_name(std::string name_param){
    this->name = name_param;
}

void Person::set_age(int age_param){
    this->age = age_param;
}

std::string Person::get_name(){
    return this->name;
}

int Person::get_age(){
    return this->age;
}

void Person::get_info(){
    std::cout << "Person name is: " << name << " and their age is: " << " and address is: " << &age  << std::endl;
}

Person::~Person(){
    std::cout << "This object is destroyed for " << this->name << std::endl;
}

int main(int argc, char **argv){

    Person p1("Martian", 100);
    Person p2("Earthling", 100);
    Person p3("Human", 100);

    Person p_array[] {p1, p2, p3};

    for(size_t i {}; i < std::size(p_array); ++i){                          //copies of objects are not created
        p_array[i].get_info();
    }

    std::cout << "Range Based for Loop which creates copies" << std::endl;
    for(Person p : p_array){                                                //copies of objects are created
        p.get_info();
    }

    std::cout << "Range Based for Loop which DOES NOT create copies as we are using references" << std::endl;
    for(Person &p : p_array){                                               //copies of objects are NOT created object is called via reference
        p.get_info();
    }
    return 0;
}