#include<iostream>

int main(int argc, char **argv){                //THE FURTHER YOU GO THE LARGER THE POINTER ADDRESS GETS

    int array[] {1,2,3,4,5,6,7,8,9,10};
    int *pointer1 {&array[0]};
    int *pointer2 {&array[9]};

    //RELATIONAL OPERATIONS ON POINTERS
    std::cout << "Pointer1 < Pointer2: " << (pointer1 < pointer2) << std::endl;
    std::cout << "Pointer1 > Pointer2: " << (pointer1 > pointer2) << std::endl;
    std::cout << "Pointer1 <= Pointer2: " << (pointer1 <= pointer2) << std::endl;
    std::cout << "Pointer1 >= Pointer2: " << (pointer1 >= pointer2) << std::endl;
    std::cout << "Pointer1 == Pointer2: " << (pointer1 == pointer2) << std::endl;
    std::cout << "Pointer1 != Pointer2: " << (pointer1 != pointer2) << std::endl;

    std::cout << std::boolalpha;
    std::cout << "With Boolean 1 / 0 => True / False" << std::endl;

    std::cout << "Pointer1 < Pointer2: " << (pointer1 < pointer2) << std::endl;
    std::cout << "Pointer1 > Pointer2: " << (pointer1 > pointer2) << std::endl;
    std::cout << "Pointer1 <= Pointer2: " << (pointer1 <= pointer2) << std::endl;
    std::cout << "Pointer1 >= Pointer2: " << (pointer1 >= pointer2) << std::endl;
    std::cout << "Pointer1 == Pointer2: " << (pointer1 == pointer2) << std::endl;
    std::cout << "Pointer1 != Pointer2: " << (pointer1 != pointer2) << std::endl;

    return 0;

}