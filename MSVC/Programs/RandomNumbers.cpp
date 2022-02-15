#include<iostream>
#include<ctime>

int main(int argc, char **argv){
    int random = std::rand();                                                           //std::rand() is function from std lib which generates random integers
    std::cout << "Random number is: " << random << std::endl;
    std::cout << "Maximum random number is: " << RAND_MAX << std::endl;                 //RAND_MAX gives the limit of random number => compiler dependent

    //generating random numbers in a loop
    for(size_t i {}; i < 10; ++i){
        std::cout << "Random number at: " << i << " is: " << std::rand() << std::endl;
    }

    //generating random numbers between std::rand() and upper bound value but within RAND_MAX => std::rand() % integer(operand2), the operand2 must be n-1 of the upper bound
    int random1 = std::rand() % 11;                                                     //value, the resultant remainder of % operator will always be between
    std::cout << "Random between std::rand() and 10: " << random1 << std::endl;         //std::rand and operand2, in this case it is 10 => 11-1

    //random number between std::rand and 25
    int random2 = std::rand() % 26;
    std::cout << "Random between std::rand() and 25: " << random2 << std::endl;

    //random number between lower and upper bound generating random number between a lower bound and upper bound
    int random3 = (std::rand() % 16) + 1;                                               //=> (std::rand() % integer(operand2)) + integer(operand3), operand3 is the
    std::cout << "Random between lower and upper bound: " << random3 << std::endl;      //lower bound to generate random values between lower and upper bound

    //std::rand() has a huge PROBLEM! => every time it generates the SAME SEQUENCE
    for(size_t i {}; i < 3; ++i){                                                       //=>generates 9961, 491, 2995 => for multiple runs
        std::cout << "Random number at: " << i << " is: " << std::rand() << std::endl;  //This happens because the system gives the compiler the SAME SEED always
    }                                                                                   //WE NEED TO PASS A DIFFERENT SEED FOR EACH TIME sts::rand() IS CALLED

    std::cout << "-------------Will generate same sequence now!------" << std::endl;

    for(size_t i {}; i < 3; ++i){                                                       //=> generates 11942, 4827, 5346 => for multiple runs
        std::cout << "Random number at: " << i << " is: " << std::rand() << std::endl;  //This happens because the system gives the compiler the SAME SEED always
    }                                                                                   //WE NEED TO PASS A DIFFERENT SEED FOR EACH TIME sts::rand() IS CALLED

    //DIFFERENT SEEDS CAN BE PASSED USING std::srand(seed) => seed is EPOCH TIME BUT THIS TIME ITS RANDOM AS WE ARE USING stdd:srand(seed)
    //USING EPOCH TIME AS SEED

    std::srand(std::time(0));                                                           //std::time(0) is from <ctime> library

    std::cout << "With different seed and really random numbers" << std::endl;

    for(size_t i {}; i < 3; ++i){                                                       //=>generates a different sequence between for multiple runs
        std::cout << "Random number at: " << i << " is: " << std::rand() << std::endl;  //This time the system gives the compiler a different seed from
    }                                                                                   //=>std::srand(std::time(0)) evrytime std::rand() is called

    std::cout << "------Will NOT generate same sequence now!------" << std::endl;

    for(size_t i {}; i < 3; ++i){                                                       //=>generates a different sequence between for multiple runs
        std::cout << "Random number at: " << i << " is: " << std::rand() << std::endl;  //This time the system gives the compiler a different seed from
    }                                                                                   //=>std::srand(std::time(0)) evrytime std::rand() is called

    return 0;
}