#include<iostream>
#include<iomanip>

int main(int argc, char **argv){
    int WIDTH {2};
    const size_t ROWS {12};
    const size_t COLS {3};

    auto w = std::setw(WIDTH);

    //or loop
    for(size_t rows {}; rows < ROWS; ++rows){
        for(size_t cols {}; cols < COLS; ++cols){
            std::cout << "ROWS: " << w << rows << " COLS: " << w << cols << std::endl;
        }
    }

    //while loop
    std::cout << "Acheiving same functionaliy using while loop" << std::endl;
    size_t row {};
    size_t col {};

    while(row < ROWS){
        while(col < COLS){
            std::cout << "ROWS: " << w << row << " COLS: " << w << col << std::endl;
            ++col;
        }
        col = 0;
        ++row;
    }

    //do while loop
    std::cout << "Acheiving same functionaliy using do while loop" << std::endl;

    size_t row1 {};
    size_t col1 {};
    do{
        do{
            std::cout << "ROWS: " << w << row1 << " COLS: " << w << col1 << std::endl;
            ++col1;
        }while(col1 < COLS);
        col1 = 0;
        ++row1;
    }while(row1 < ROWS);

    return 0;
}