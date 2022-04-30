#include<iostream>

//A POINTER OR REFERENCE IS SAID TO BE DANGLING IF ITS PONTING TO OR REFERENCING TO AN INVALID DATA. AN EXAMPLE IS IF A POINTER IS POINTING TO A DELETED PIECE OF MEMORY

class Animal{
    public:
        Animal() = default;
        const std::string &AnimalInfo() const;
        int *returnPointer() const;

    private:
        std::string animal_name;
        std::string animal_breed;
        int animal_age;
};

//DANGLING REFERENCE EXAMPLE => WARNING DURING COMPILING => BUT COMPILES SUCCESSFULLY
const std::string &Animal::AnimalInfo() const{
    std::string info = "Animmal Name: " + animal_name
                        + " Animal Breed: " + animal_breed
                        + " Animal Age: " + std::to_string(animal_age);
    return info;                                                        //this will become a dangling reference because the moment the control exits the function body, the
}                                                                       //'info' variable will be destroyed but its reference will still be available => dengling

//DANGLING POINTER EXAMPLE => WARNING DURING COMPILING => BUT COMPILES SUCCESSFULLY
int *Animal::returnPointer() const{
    int value {100};
    return &value;                                                      //this will become a dangling pointer because the moment the control exits the function body, the
}                                                                       //'value' variabe will be destroyed but the pointer pointing to it will still be available=> dangling 

int main(int argc, char **argv){
    Animal animal1;
    std::string var1 = animal1.AnimalInfo();
    //PROGRAM CRASHES AS WE ARE TRYNG TO USE A REFERENCE VARIABLE AFTER ITS VARIABLE IS DESTROYED => BASICALLY TRYING TO USE A DANGLING REFERENCE
    std::cout << var1 << std::endl;

    int *var2 = animal1.returnPointer();
    //PROGRAM CRASHES AS WE ARE TRYNG TO USE ACCESS A MEMORY SPACE VIA A POINTER ADDRESS AFTER ITS VARIABLE IS DESTROYED => BASICALLY TRYING TO USE A DANGLING POINTER
    std::cout << *var2 << std::endl;
    return 0;
}