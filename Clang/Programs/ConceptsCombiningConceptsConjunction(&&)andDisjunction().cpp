#include<iostream>
#include<concepts>

//CONCEPTS CAN BE COMBINED WITH THE LOGICAL OPERATORS && and ||

template<typename T> concept tiny = requires(T t){                                          //template with concept which checks for syntax
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
};

template<typename T> T func1(T t) requires std::integral<T> && tiny<T>;                      //combining two concepts using && => USING TWO STANDARD BUILT-IN CONCEPTS
template<typename T> requires std::integral<T> || std::floating_point<T> T func2(T a, T b){  //combining two concepts using || => USING TWO STANDARD BUILT-IN CONCEPTS
    return a + b;
}

template<typename T> T func3(T a, T b) requires std::integral<T> && requires(T t){          //template with two concepts with one concept inserted INPLACE=>thats why extra {}
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
}
{
    std::cout << "Value: " << a <<std::endl;
    return (2 * a);
}

int main(int argc, char **argv){
    int a {100};
    int b {200};

    double c {10.99};
    double d {20.99};

    std::string e {"Hello "};
    std::string f {"Mars"};

    auto res1 = func2(a, b);                                                               //passing ints => accepts either integer or floating point values
    std::cout << "func2() with ints: " << res1 << std::endl;

    auto res2 = func2(c, d);                                                               //passing doubles => accepts either integer or floating point values
    std::cout << "func2() with double: " << res2 << std::endl;

    //auto res3 = func2(e, f);                                                               //COMPILER ERROR as func2() is not designed to accept std::string

    auto res3 = func3(a, b);                                                               //passing ints => accepts ONLY integers as template is desinged such 
    std::cout << "func3() with ints: " << res3 << std::endl;

    //auto res4 = func3(c, d);                                                               //COMPILER ERROR as func3() is not designed to accept doubles
    //std::cout << "func4() with ints: " << res4 << std::endl;

    return 0;
}