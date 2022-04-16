#include<iostream>

class Dog{
    std::string dog_name;
    std::string breed;
    int age;
    int *num {nullptr};

    public:
        Dog(std::string name_param, std::string breed_param, int age_param, int num_param);
        void dogBehave();
        ~Dog();
};

Dog::Dog(std::string name_param, std::string breed_param, int age_param, int num_param){
    dog_name = name_param;
    breed = breed_param;
    age = age_param;
    num = new int;                                                          //dynamic memory allocated on HEAP
    *num = num_param;
    std::cout << "This is Dog Constructor for " << dog_name << std::endl;
}

void Dog::dogBehave(){
    std::cout << dog_name << " is a Dog Object and its properties are: \n"
            << breed << "\n" << age << "\n" << *num << std::endl;;
}

Dog::~Dog(){
    delete num;
    std::cout << "Dog object is destroyed for " << dog_name << std::endl;
}

int main(int argc, char **argv){

    std::string name_var {"Dobber"};                                        //name changed below for better sepeartion of objects
    std::string breed_var {"Dog"};
    int age_var {10};
    int num_var {100};

    Dog dog1("Canine1", breed_var, age_var, num_var);                       //CONSTRUCTORS ARE CALLED IN ORDER (1,2,3,4) BUT DESTRUCTORS ARE CALLED IN REVERSE ORDER (4,3,2,1)
    Dog dog2("Canine2", breed_var, age_var, num_var);                       //THE OBJECT CONSTRUCTED LAST WILL BE DESTROYED FIRST <--> AND THE OBJECT CONSTRUCTED FIRST
    Dog dog3("Canine3", breed_var, age_var, num_var);                       //WILL BE DESTROYED LAST => COMPILER DOES THIS AUTOMATICALLY
    Dog dog4("Canine4", breed_var, age_var, num_var);

    //note that even when the function is called last, the function executes first and then calls destructors
    dog1.dogBehave();
    return 0;
}