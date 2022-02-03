#include <iostream>

int main(){
    constexpr int eye_count {10};

    const int var1 {5};                                                         //if we change this to const, error will be gone
    constexpr int var2 {var1};                                                  //constexpr variables must always have another constexpr value or const value, any other value type
                                                                                //their value will be unknown at compile time -> all constexpr values must be known at compile time

    std::cout << "ConstExpr Eye Count: " << eye_count << std::endl;

    constexpr int door_count {10};
    constexpr int room_count {door_count};                                      //one constexpr variable can initialize another constexpr variable

    constexpr int SOME_VERSION_CHECK {155};
    static_assert(SOME_VERSION_CHECK == 155);                                   //This checks/asserts at compile time for a given value, else compilation will fail
                                                                                //ANY VARIABLE'S VALUE OTHER THAN CONSTEXPR/CONST, THEIR VALUE WILL NOT BE KNOWN AT COMPILE TIME
                                                                                //->ONLY AT RUNTIME
    std::cout << SOME_VERSION_CHECK << std::endl;

    return 0;
}