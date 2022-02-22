#include<iostream>

int main(int argc, char **argv){
    //SOMETIMES NEW OPERATOR FAILS AND MEMORY WILL NOT BE ALLOCATED, IF NECCESSARY MECHANISMS ARE NOT IN PLACE, THE PROGRAM CRASHES

    int *large_number {new int[1000000000000000000]};   //std::bad_alloc EXCEPTION IS THROWN AND PROGRAM CRASHES, CONTROL DOES NOT MOVE BEYOND THIS STATEMENT

    std::cout << "This executed" << std::endl;

    for(size_t i {}; i < 10000000000; ++i){
        int *large_nmber {new int[10000000000]};
    }

    //ONE METHOD TO HANDLE std::bad_alloc EXCEPTION IS TO PUT new OPERATOR IN A try catch BLOCK
    for(size_t i {}; i < 100000000000; ++i){
        try{
            int *very_big_number {new int[1000000000000000000]};
        }
        catch(std::exception& ex){                                          //std::exception& ex => very big loop, manually terminate
            std::cout << "Exception occured: " << ex.what() << std::endl;   //ex.what() is a finctions which returns the exception type
        }
    }

    //ANOTHER METHOD TO HANDLE std::bad_alloc IS TO USE std::nothrow WHILE CALLING new
    for(size_t i {}; i < 100000000000; ++i){                                //very big loop, manually terminate
        int *very_very_big {new(std::nothrow) int[1000000000000000000]};    //std::nothrow
        if(very_very_big == nullptr){                                       //IF new FAILS AND std::nothrow IS USED, nullptr IS RETURNED
            std::cout << "Memory Allocation Failed" << std::endl;
        }
        else{
            std::cout << "Memory Allocation Succeeded" << std::endl;
        }
    }
    return 0;
}