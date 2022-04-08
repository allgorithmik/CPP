#include<iostream>

//JUST LIKE static_assert, constexprif PROVIDES A WAY TO PERFORM CONDITIONAL COMPILE TIME PROGRAMMING. CPMPARED TO static_assert, constexprif IS MORE EASIER AND
//FLEXIBLE

template<typename T> void func(T a);                            //prototype of a normal function template

void func_integral(int a);                                      //prototype of a normal function
void func_double(double a);                                     //prototype of a normal function

int main(int argc, char **argv){

    int a{10};
    double b {10.99};
    std::string str1 {"Hello Mars"};

    func(a);                                                    //PASSING AN INT VALUE WHICH THE func() ACCEPTS AS PER constexprif STATEMENT IN FUNCTION TEMPLATE
    func(b);                                                    //PASSING A DOUBLE VALUE WHICH THE func() ACCEPTS AS PER constexprif STATEMENT IN FUNCTION TEMPLATE
    //func(str1);                                               //AS EXPECTED THE COMPILATION FAILS IF PASSED WITH INCOMPATIBLE PARAMS / ARGS => IN THIS CASE std::string
    return 0;
}

void func_integral(int a){                                      //definition of a normal function
    std::cout << "This is an integer operation" << std::endl;
}

void func_double(double a){                                     //definition of a normal function
    std::cout << "This is a double operation" << std::endl;
}

template<typename T> void func(T a){                            //definition of a normal function template
    if constexpr(std::is_integral_v<T>){                        //PLEASE REMEMBER THAT std::is_integral_v<T> BY ITSELF IS A CONDITIONS WHICH EVALUATES TO BOOLEAN TRUE / FALSE
        func_integral(a);
    }
    else if constexpr(std::is_floating_point_v<T>){             //PLEASE REMEMBER THAT std::is_integral_v<T> BY ITSELF IS A CONDITIONS WHICH EVALUATES TO BOOLEAN TRUE / FALSE
        func_double(a);
    }
    else{
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>, "No type matches the templates");
    }
}