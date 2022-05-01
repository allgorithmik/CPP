#include<iostream>

class Animal{
    public:
        Animal() = default;
        Animal(const std::string name_param, const std::string breed_param, const int age_param);
        std::string AnimalInfo() const;

    private:
        std::string animal_name;
        std::string animal_breed;
        unsigned int animal_age {};
        mutable unsigned int count {};                  //mutable allows a member of a class to be modified even if its modified from within a const member function from
};                                                      //within a const object => BUT DOING THIS VIOLATES const CORRECTNESS

std::string Animal::AnimalInfo() const{
    ++count;
    std::cout << "Animal name is: " + animal_name +
                 ", its breed is: " + animal_breed +
                 " and its age is: " + std::to_string(animal_age) << std::endl;
    return std::to_string(count);
}

int main(int argc, char **argv){
    const Animal animal1;
    animal1.AnimalInfo();
    animal1.AnimalInfo();
    animal1.AnimalInfo();
    animal1.AnimalInfo();                               //count member variable can be modified and is being incremented even while its being called from within a const object
    auto var1 = animal1.AnimalInfo();
    std::cout << "Number of times AnimalInfo() is called: " << var1 << std::endl;
    return 0;
}