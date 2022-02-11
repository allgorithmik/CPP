#include<iostream>

int main(int argc, char **argv){                                            //for loop with multiple declarations, the control condition is decided by the value
    for(size_t i {}, x {}, y {15}; y < 50; ++i, x += 5, y -= 1){            //used for condition, and also its respective incrementor/decrementor            
        std::cout << "For Loop with multiple declarations!" << std::endl;   //please note the condition is only one, even though there are
    }                                                                       //multiple iterators and increment/decrement 
    return 0;                                                               //the types of all the other iterators are of size_t, or whatever is the type of first iterator
}                                                                           //unless explicitely declared as other types