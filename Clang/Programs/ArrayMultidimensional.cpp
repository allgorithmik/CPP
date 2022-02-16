#include<iostream>

int main(int argc, char **argv){
    
    int multi_array[5][5];                                                                      //Initializing a 2-D array [m][n]

    std::cout << "The size of multi_array is: " << sizeof(multi_array) << std::endl;
    std::cout << "Element count in multi_array is: " << std::size(multi_array) << std::endl;    //std::size() from C++17 standard to find elements in multi_array

    for(size_t i {}; i < 5; ++i){                                                               //multi_array containes garbage values as we have not initialized
        for(size_t j {}; j < 5; ++j){                                                           //printing values
            std::cout << "Element " << i << " " << j << multi_array[i][j] << std::endl;         //BUT WE HAVE HARDCODED the array size, which is not recommended
        }
    }

    for(size_t i {}; i < std::size(multi_array); ++i){                                          //using std::size() to auto dedude the size of array
        for(size_t j {}; j < std::size(multi_array[i]); ++j){                                   //inner loop must target the inner size
            std::cout << "Element " << i << " " << j << multi_array[i][j] << std::endl;         
        }
    }

    int multi_array_ini [5][5] {                                                                //Manually initializing the 2-D array
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    for(size_t i {0}; i < std::size(multi_array_ini); ++i){                                     //using std::size() to auto dedude the size of array
        for(size_t j {0}; j < std::size(multi_array_ini[i]); ++j){                              //inner loop must target the inner size
            std::cout << "Element " << i << " " << j << multi_array_ini[i][j] << std::endl;         
        }
    }

    int dimen{5};
    int multi_array_auto_deduce [][dimen]{                                                      //the compiler will auto deduce the outer dimension(rows) of array based the
        {1,2,3,4,5},                                                                            //number of outer elements in an array, in this case 5 rows
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5},                                                                            //we can any number of rows as we want as its auto deduced by compiler
    };

    int three_d_array[][5][5]{                                                                  //even for 3-D array the compiler can auto deduce the outer dimension

    };                                                                                          //just not typing the initialization values

    three_d_array [0][0][5] = 10;                                                               //we can also modify values of an array by targetting its index

    int auto_fill [5][5]{                                                                       //the compiler auto fills values with 0 if the declared number of
        {1,2,3},                                                                                //elements are not present in the array, in this case, even though there
        {1,2,3},                                                                                //is 5 columns declared, only 3 elements are initialized in column,
        {1,2,3},                                                                                //=>the compiler will auto fill the remaining 2 column elements with 0
        {1,2,3},                                                                                //this is legal in C++, and this works for N-dimensional arrays 
        {1,2,3},
    };
    return 0;
} 