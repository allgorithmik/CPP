#include<iostream>

int main(int argc, char **argv){
    //nullptr SAFETY IS ABOUT MAKING SURE THAT THE POINTER WE ARE USING IS POINTING TO A VALID ADDRESS
    int *pointer1 {};                                   //nullptr declared
    if(!(pointer1 == nullptr)){                         //implementing checks to null pointers
        std::cout << "This can be used" << std::endl;
    }
    else{
        std::cout << "This cannot be used" << std::endl;
    }

    //COMPACT nullptr check => if a pointer is passed to conditionals, if the pointer IS NOT a nullptr, it will return TRUE => implicitly converted to bool
    if(pointer1){
        std::cout << "This can be used" << std::endl;
    }
    else{
        std::cout << "This cannot be used" << std::endl;
    }

    int *pointer2 {};                                   //declaring a nullptr and deleting WON'T CAUSE any problems
    delete pointer2;                                    //calling delete on a nullptr will not have any negative effect, anyway pointer was pointing to nullptr

    //NOW IMPLEMENTING THE SAME BUT NOW WITH !nullptr => POINTER POINTING TO A VALID ADDRESS
    int *pointer3 {new int {100}};                      //nullptr declared
    if(!(pointer3 == nullptr)){                         //implementing checks to null pointers
        std::cout << "This can be used" << std::endl;
    }
    else{
        std::cout << "This cannot be used" << std::endl;
    }

    //COMPACT nullptr check => if a pointer is passed to conditionals, if the pointer IS NOT a nullptr, it will return TRUE => implicitly converted to bool
    if(pointer3){
        std::cout << "This can be used" << std::endl;
    }
    else{
        std::cout << "This cannot be used" << std::endl;
    }

    //releasing and resetting memory
    delete pointer3;
    pointer3 = nullptr;
    return 0;
}