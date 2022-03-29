#include<iostream>

//                          *****OPEN VS CODE FROM WITHIN DEVELOPER POWERSHELL FROM MS VISUAL STUDIO PATH TO MAKE MSVC DEBUGGER TO WORK*****

double sum(double array[], size_t count);

int main(int argc, char **argv){

    double vals[] {10.99, 11.99, 12.99, 13.99, 14.99, 15.99, 16.99, 17.99, 18.99, 19.99};
    std::cout << "Calling sum(): " << sum(vals, std::size(vals)) << std::endl;

    return 0;
}

double sum(double array[], size_t count){
    double res {};
    for(size_t i {}; i < count; ++i){
        res += array[i];
    }
    return res;
}