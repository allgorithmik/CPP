#include<iostream>

class Person{
    private:
        std::string f_name {};
        std::string l_name {};
        int *age {};

    public:
        Person() = default;
        Person(std::string l_name_param);                                           //ALL THESE HAVE TO BE UNCOMMENTED BECAUSE THEIR PROTOTYPES HAVE BEEN DECLARED
        Person(std::string f_name_param, std::string l_name_param);                 //ELSE => UNDEFINED REFERENCES COMPILER ERRORS
        Person(std::string f_name_param, std::string l_name_param, int age_param);

        //IN CASE OF USER DEFINED COPY CONSTRUCTORS USING INITIALIZER LIST INITIALIZATION => ONLY THE STATEMENT BEFORE ':' MUST BE DECLARED AS PROTOTYPE IN CLASS
        Person(const Person &source_person);
        void set_age(int age_param);
        void set_l_name(std::string lname_param);
        void set_f_name(std::string fname_param);
        std::string get_f_name() const;
        std::string get_l_name() const;
        int *get_age() const;                                                       //the function must return a pointer else compiler error
        void print_info();
        ~Person();
};

//INITIALIZER LIST INITIALIZATION
Person::Person(std::string l_name_param) : l_name(l_name_param){}
Person::Person(std::string f_name_param, std::string l_name_param) : f_name(f_name_param), l_name(l_name_param){}
Person::Person(std::string f_name_param, std::string l_name_param, int age_param) : f_name(f_name_param), l_name(l_name_param), age(&age_param){}

//IT IS POSSIBLE TO CREATE OUR OWN COPY CONSTRUCTOR. THIS IS DISABLE THE DEFAULT COPY CONSTRUCTOR PROVDED BY THE COMPILER AND OUR COPY CONSTRUCTOR WILL BE ACTIVE
//FIRST ATTEMPT => PASS OBJECT BY VALUE => COMPILER ERROR => CREATES AN ENDLESS CHAIN OF COPY CONSTRUCTORS AS THE OBJECT ITSELF IS PASSED BY VALUE
//Person::Person(const Person source_person) : l_name(source_person.get_l_name()), f_name(source_person.get_f_name()), age(source_person.get_age()){}

//SECOND ATTEMPT => PASS OBJECT BY REFERENCE => BETTER THAN FIRST ATTEMPT BUT STILL COPIES THE POINTER ADDRESS JUST LIKE DEFAULT CONSTRUCTOR
/*
Person::Person(const Person &source_person) : l_name(source_person.get_l_name()), f_name(source_person.get_f_name()), age(source_person.get_age()){
        std::cout << "Copy Constructor" << std::endl;
}

//THIRD ATTEMPT => PASS OBJECT BY REFERENCE => THIS COPIES THE DEREFERENCED DATA OF THE POINTER INTO A NEW HEAP MEMORY LOCATION => CORECT WAY OF DOING THINGS
Person::Person(const Person &source_person) : l_name(source_person.get_l_name()), f_name(source_person.get_f_name()), age(new int(*(source_person.get_age()))){
        std::cout << "Copy Constructor" << std::endl;
}
*/
//COPY CONSTRUCTOR USING CONSTRUCTOR DELEGATION
Person::Person(const Person &source_person) : Person(source_person.get_l_name(), source_person.get_f_name(), *(source_person.get_age())){
        std::cout << "Copy Constructor" << std::endl;
}

void Person::print_info(){
    std::cout << "Person name is: " << f_name << " " << l_name << std::endl;
    std::cout << f_name << " age is: " << *age << std::endl;
}

void Person::set_age(int age_param){
    age = &age_param;
}

void Person::set_l_name(std::string lname_param){
    this->l_name = lname_param;
}

void Person::set_f_name(std::string fname_param){
    this->f_name = fname_param;
}

std::string Person::get_f_name() const{
    return f_name;
}

std::string Person::get_l_name() const{
    return l_name;
}

int *Person::get_age() const{
    return age;
}

Person::~Person(){
    std::cout << this << " Object is Destroyed" << std::endl;
    delete age;
}

int main(int argc, char **argv){
    
    Person person1("FirstName", "LastName", 100);
    person1.print_info();

    //MAKING COPIES OF OBJECTS => DEFAULT COPY CONSTRUCTOR PROVIDED BY COMPILER
    //When an object is initialized with another object, the compiler creates a copy constructor by blindly performing member to member copy of member variables of
    //objects, this will also apply to pointers => copy the pointer value by dereferencing them => THIS IS THE DEFAULT BEHAVIOUR IF WE HAVE NOT PROVIDED OUR
    //OWN COPY CONSTRUCTOR => IF WE PROVIDE OUR OWN DEFAULT CONSTRUCTOR, THIS CONSTRUCTOR WILL TAKE PRIORITY OVER DEFAULT COPY CONSTRUCTOR PROVIDED BY THE COMPILER
    Person person2(person1);
    person2.print_info();
    person1.set_age(50);
    person1.print_info();
    person2.print_info();
    return 0;
}