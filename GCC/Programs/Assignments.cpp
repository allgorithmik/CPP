#include <iostream>

int main(int argc, char **argv){
    int var = -1;
    std::cout << var << std::endl;
    auto var1 {55};                     //auto deduces as unsigned decimal
    var1 = -55;                         //compiler reassigns var1 to -55 -->> DANGER! DO NOT DO THIS AS IT MIGHT SILENTLY FAIL -> but in this case its not failing!!!!!
    std::cout << var1 << std::endl;
    return 0;
}