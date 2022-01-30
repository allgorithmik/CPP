#include <iostream>

int main(int args, char **argv){
    int pre {1};
    int post {5};

    std::cout << ++pre << std::endl;
    std::cout << post++ << std::endl;
    return 0;
}