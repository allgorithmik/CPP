#include<iostream>

int main(int argc, char **argv){
    int count1 {10};
    int count2 {20};
    int count3 {count1 + count2}; //expressions can used as initializers
    int garbage {};
    int count4 (50);                                                                        //can be initialised using () also functional initialisation
    int count5 {55.5};                                                                      //can be initialized using {} also, but values if type mismatched, warning will be shown
    int count6 (55.5);                                                                      //if we use () instead of {}, type will be implicitly casted
    int count7 = 100;
    std::cout << count1 << std::endl;
    std::cout << count2 << std::endl;
    std::cout << count3 << std::endl;
    std::cout << garbage << std::endl;
    std::cout << count4 << std::endl;
    std::cout << "using {} but with warning " << count5 << std::endl;                       //can be initialized using {} also, but values if type mismatched, warning will be shown
    std::cout << "using () but without warning implictly casted " << count6 << std::endl;   //if we use () instead of {}, type will be implicitly casted
    std::cout << sizeof(int) << std::endl;
    std::cout << "Normal assignment initialization: " << count7 << std::endl;               //Normal assignment initializer
    return 0;
}