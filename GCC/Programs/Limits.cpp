#include <iostream>
#include <limits>

int main(int argc, char **argv){
    //using numerical limits functions from std for much of premitive datatypes,
    //min()
    //max()
    //lowest()
    std::cout << "The lower limit of short is: " << std::numeric_limits<short>::min() << " and maximum limit of short is: " << std::numeric_limits<short>::max() << std::endl;
    std::cout << "The lower limit of unsigned short is: " << std::numeric_limits<unsigned short>::min() << " and maximum limit of unsigned short is: " << std::numeric_limits<unsigned short>::max() << std::endl;
    std::cout << "The lower limit of int is: " << std::numeric_limits<int>::min() << " and maximum limit of int is: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "The lower limit of unsigned int is: " << std::numeric_limits<unsigned int>::min() << " and maximum limit of unsigned int is: " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "The lower limit of float is: " << std::numeric_limits<float>::min() << " and maximum limit of float is: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "The lower limit of long is: " << std::numeric_limits<long>::min() << " and maximum limit of long is: " << std::numeric_limits<long>::max() << std::endl;
    std::cout << "The lower limit of float(lowest) is: " << std::numeric_limits<float>::lowest() << " and maximum limit of float is: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "The lower limit of double(lowest) is: " << std::numeric_limits<double>::lowest() << " and maximum limit of double is: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "The lower limit of long double(lowest) is: " << std::numeric_limits<long double>::lowest() << " and maximum limit of long double is: " << std::numeric_limits<long double>::max() << std::endl;
    
    return 0;
}