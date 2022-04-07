#include<iostream>

auto func(auto a, auto b){                                                  //this function's return type and param's type will be auto deduced => this will be internally
    return (a > b)? a : b;                                                  //represented as function template whose return type and param's type will be deduced using
}                                                                           //auto / decltype as we saw earlier (line 7)

/*template<typename T, typename P> auto func(T a, P b) -> decltype((a > b)? a : b){   //COMPILER ERROR => AS THIS IS AN AMBIGOUS DECLARATION BECAUSE ITS LOGIC / FUNCTIONALITY
    return (a > b)? a : b;                                                          //IS SAME AS func() IN LINE 3-5 => HENCE COMMENTING THIS OUT
}

template<typename T, typename P> decltype(auto) func(T a, P b){             //this is implemented just to avoid code repetition by using decltype(auto) as we saw earlier
    return (a > b)? a : b;
}*/
//line 7 - 13 function templates will be generated internally by the compiler when a function like line 3 - 5 is encountered
//use https://cppinsights.io/ for checking this happen in real time

int main(int argc, char **Argv){

    int a {500};
    double b {200.99};

    auto res1 = func(a, b);

    std::cout << "The result of func(): " << res1 << std::endl;             //irrespective of result of func(), the return type is deduced by memory size criteria as we knew
    std::cout << "Type deduced by func(): " << sizeof(res1) << std::endl;   //type deduced is double as per memory size rule (declype / auto function templates concept)

    return 0;

}