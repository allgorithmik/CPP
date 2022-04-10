#include<ostream>
#include<iostream>

//THIS SYNTAX CONSTRAINS THE auto PARAMS TO COMPLY WITHIN THE std::integral CONCEPT
std::integral auto func1(std::integral auto a, std::integral auto b){
    return a + b;
}

int main(int argc, char **argv){

//EVEN THE VARIABLES WE DECLARE CAN BE CONSTRAINED WITHIN CONCEPTS LIKE BELOW:
std::integral auto x = func1(10, 20);                   //x IS CONSTRAINED WITHIN std::integral CONCEPT

//COMPILER EEROR AS THE TYPE OF func1() IS CONSTRAINED WITHIN std::integral BUT VARIABLE IS CONSTRAINED WITHIN CONCEPT std::floating_point
//std::floating_point auto y = func1(10, 20);

//COMPILER ERROR AS A VAIABLE OF TYPE std::ntegral IS ASSIGNED TO A DOUBLE / FLOATING POINT TYPE => USELESS BUT SUPPORTED IN C++
//std::integral auto z = 10.99;

std::floating_point auto a = 11.99;                     //VALID AS THE VARIABLE OF TYPE std::floating_pont IS ASSIGNED A VALUE OF TYPE FLOAT / DOUBLE

    std::cout << "Result of func1(): " << x << std::endl;
    std::cout << "a with std::floating_point concept constrained: " << a << std::endl;
    return 0;
}