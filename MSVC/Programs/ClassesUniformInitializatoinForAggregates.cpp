#include<iostream>

//Uniform Initialization: Initializing any object either through () or {} => It was first introduced in C++11
//{} DOES NOT SUPPORT NARROWING CONVERSION (IMPLICIT CONVERSION / CASTING)
//() DOES SUPPORT NARROWING CONVERSION (IMPLICIT CONVERSION / CASTING)

class Person{
    private:
        int age {};

    public:
        Person(const int age_param);
        void print_info() const;
};

Person::Person(const int age_param) : age(age_param){};

void Person::print_info() const{
    std::cout << "Age is: " << age << std::endl;
}

int main(int argc, char **argv){

    //Person p1 {100.99};                                 //COMPILER ERROR => AS {} DOES NOT SUPPORT NARROWING CONVERSION (IMPLICIT CONVERSION / CASTING)
    Person p2 (100.99);                                 //() DOES SUPPORT NARROWING CONVERSION (IMPLICIT CONVERSION / CASTING) => HENCE NO COMPILER ERROR

    //int array1[] {1.99, 2.99, 3.99, 4.99, 5.99};        //COMPILER ERROR => AS {} DOES NOT SUPPORT NARROWING CONVERSION (IMPLICIT CONVERSION / CASTING)
    int array2[] (1.99, 2.99, 3.99, 4.99, 5.99);        //() DOES SUPPORT NARROWING CONVERSION (IMPLICIT CONVERSION / CASTING) => HENCE NO COMPILER ERROR
    return 0;
}