#include<iostream>

double operand1 {};
double operand2 {};
char CONTINUE;
bool flag {true};

int main(int argc, char **argv){
    std::cout << "Welcome to calculator program" << std::endl;

    while(flag){
        std::cout << "Some Operation" << std::endl;

        std::cout << "Do you want to continue the operation: Y | N" << std::endl;
        std::cin >> CONTINUE;

        if((CONTINUE == 'Y') || (CONTINUE == 'y')){
            flag = true;
        }
        else{
            flag = false;
        }

    }
    
    return 0;
}