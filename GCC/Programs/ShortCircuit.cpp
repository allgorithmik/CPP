#include<iostream>

const bool a {true};
const bool b {false};
const bool c {true};
const bool d {false};

const bool p {false};
const bool q {true};
const bool r {false};
const bool s {true};

bool car(){
    std::cout << "Car Function" << std::endl;
    return true;
}

bool house(){
    std::cout << "House Function" << std::endl;
    return false;
}

bool wife(){
    std::cout << "Wife Function" << std::endl;
    return true;
}

bool job(){
    std::cout << "Job Function" << std::endl;
    return true;
}

int main(int argc, char **argv){

    if (car() && house() && wife() && job()){
        std::cout << "Happy!" << std::endl;
    }
    else{
        std::cout << "Sad!" << std::endl;
    }

    if (car() || house() || wife() || job()){                       //Short circuit will not execute any further if any one condition is met in AND / OR
        std::cout << "Happy!" << std::endl;
    }
    else{
        std::cout << "Sad!" << std::endl;
    }

    std::cout << "AND Short Circuit" << std::endl;
    bool resultAND = a && b && c && d;
    std::cout << "AND Short Circuit result is: " << resultAND << std::endl;

    std::cout << "OR Short Circuit" << std::endl;
    bool resultOR = a || b || c || d;
    std::cout << "OR Short Circuit result is: " << resultOR << std::endl;

    std::cout << std::boolalpha;

    std::cout << "In True/False" << std::endl;

    std::cout << "AND Short Circuit" << std::endl;
    bool resultANDBool = a && b && c && d;
    std::cout << "AND Short Circuit result is: " << resultANDBool << std::endl;

    std::cout << "OR Short Circuit" << std::endl;
    bool resultORBool = a || b || c || d;
    std::cout << "OR Short Circuit result is: " << resultORBool << std::endl;

    return 0;
}