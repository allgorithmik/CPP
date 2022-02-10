#include<iostream>

int main(int argc, char **argv){

    int item_count {10};

    if (item_count){                                                                    //Any number different than 0, or expession evauating to something other than 0,
        std::cout << "There are " << item_count << " items in the bag" << std::endl;    //will be true, So this will evaluate to true
    }
    else{                                                                               //Any number equal to 0, or expression evauating to 0, will be false
        std::cout << "There are no items in the bag" << std::endl;
    }

    bool condition = item_count;                                                        //Implicitly converting a integral type to boolean

    std::cout << std::boolalpha;

    if (condition){                                                                    //Any number different than 0, or expession evauating to something other than 0,
        std::cout << "There are " << condition << " items in the bag" << std::endl;    //will be true, So this will evaluate to true
    }
    else{                                                                              //Any number equal to 0, or expression evauating to 0, will be false
        std::cout << "There are no items in the bag" << std::endl;
    }
    return 0;
}