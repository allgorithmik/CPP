#include<iostream>

double sum2D(double array[][5], size_t count);                   //function prototype
double sum3D(double array[][5][5], size_t count);                //function prototype

int main(int argc, char **argv){

    double values1[][5] {
        {(15.55, 55.55, 100.55, 75.20, 45.99)},
        {(15.55, 55.55, 100.55, 75.20, 45.99)},
        {(15.55, 55.55, 100.55, 75.20, 45.99)},
        {(15.55, 55.55, 100.55, 75.20, 45.99)},
        {(15.55, 55.55, 100.55, 75.20, 45.99)}
    };

    double values2[][5][5] {
    {{(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}},
    {{(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}},
    {{(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}},
    {{(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}},
    {{(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}, {(15.55, 55.55, 100.55, 75.20, 45.99)}}
    };

    std::cout << "Calling sum1()" << std::endl;

    //double res1 = sum2D(values1, 5);                          //SIZE IS NOT REQUIRED IF ARRAY IS PASSED AS REFERENCE
    double res1 = sum2D(values1, std::size(values1));           //std::size() can also be used when using array within main() as size info is not lost

    std::cout << "The result sum1(): " << res1 << std::endl;

    std::cout << "Calling sum2()" << std::endl;

    //double res2 = sum3D(values2, 5);                          //SIZE IS NOT REQUIRED IF ARRAY IS PASSED AS REFERENCE
    double res2 = sum3D(values2, std::size(values2));           //std::size() can also be used when using array within main() as size info is not lost

    std::cout << "The result of sum2(): " << res2 << std::endl;

    return 0;
}

//TWO DIMENSIONAL ARRAY AS PARAM / ARG
double sum2D(double array[][5], size_t count){                  //function defintion
    double result {};
    for(size_t i {}; i < count; ++i){
        for(size_t j {}; j < 5; ++j){                           //ALWAYS PASS THE SECOND DIMENSION SIZE TO THE INNER LOOP
            result += *(*(array + i) + j);                      //POINTER ARITHMATIC NOTATION
            //result += array[i][j];                            //ARRAY INDEXING NOTATION
        }
    }
    return result;
}

//THREE DIMENSIONAL ARRAY AS PARAM / ARG
double sum3D(double array[][5][5], size_t count){               //function defintion
    double result {};
    for(size_t i {}; i < count; ++i){
        for(size_t j {}; j < 5; ++j){                           //ALWAYS PASS THE SECOND DIMENSION SIZE TO THE INNER LOOP
            for(size_t k {}; k < 5; ++k){
                result += array[i][j][k];                       //ARRAY INDEXING NOTATION
                //result += *(*(*(array + i) + j) + k);         //POINTER ARITHMATIC NOTATION
        }
            }                      
    }
    return result;
}