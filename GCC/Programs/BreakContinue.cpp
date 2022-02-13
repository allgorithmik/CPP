#include<iostream>

int main(int argc, char **argv){
    //break breaks out of the loop immediately after encountering break and control starts executing the code immediately after the loop block
    //continue allows to SKIP ONE loop iteration and move to the next iteration
    for(size_t i {}; i < 20; ++i){
        if(i == 5){
            break;                                                                  //loop breaks at 5 and exits the loop block and control excutes code ater loop block
        }
        std::cout << "Current loop iteration: " << i << std::endl;
    }

    std::cout << "Loop ended" << std::endl;

    for(size_t i {}; i < 10; ++i){
        if(i == 5){
            continue;                                                               //loop SKIPS 5th iteration and control continues to excute rest of the
        }                                                                           //iterations of loop block
        std::cout << "Current loop iteration: " << i << std::endl;
    }
    
    std::cout << "Continue Loop ended!" << std::endl;

    size_t COUNT {};
    while(COUNT < 10){
        std::cout << "Current iteration of while loop: " << COUNT << std::endl;
        //continue;                                                                 //BE VERY CAREFUL OF WHERE BREAK/CONTINUE IS INSERTED, IN THIS CASE ITERATOR
        ++COUNT;                                                                    //INCREMENT/DECREMENT WILL NEVER EXECUTE AND LOOP WILL BE INFINITE
    }

    size_t COUNT1 {};
    do{                                                                             //SAME GOES FOR do while LOOP
        std::cout << "Current iteration of do while loop: " << COUNT1 << std::endl;
        //continue;                                                                 //BE VERY CAREFUL OF WHERE BREAK/CONTINUE IS INSERTED, IN THIS CASE ITERATOR
        ++COUNT1;                                                                   //INCREMENT/DECREMENT WILL NEVER EXECUTE AND LOOP WILL BE INFINITE
    }while(COUNT1 < 10);

    return 0;
}