#include <iostream>

int main(int argc, char **argv){
    //Explicit data casting, external human intervention is required
    double x {45.45};
    double y {55.55};

    int sum = static_cast<int>(x) + static_cast<int>(y);                //Explicit cast using static_cast<target_type>(variable)
                                                                        // -> static_cast (C++ style) is checked by compiler for type compatibility
    sum = static_cast<int>(x + y);                                      //Another way of explicit cast
    sum = (int)(x) + (int)(y);                                          //Another way of explicit cast, but very unsafe -> legacy style

    std::cout << "The explicit cast result: " << sum << std::endl;

    return 0;
}