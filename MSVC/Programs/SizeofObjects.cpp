#include<iostream>

//SIZE OF OBJECTS IN C++ WILL BE THE SUMM OF ALL THE DATATYPE SIZES OF ITS MEMBER VARIABLES => BUT THIS IS NOT ALWAYS TRUE BECAUSE OF A CONCEPT CALLED
//BOUNDARY ALIGNMENT
//BOUNDARY ALIGNMENT HAPPENS WHEN THERE ARE MEMBER VARIABLES OF DIFFERENT TYPES (int, double, char etc) => DUE TO THIS ALL THE SIMILAR TYPES WILL BE GROUPED TOGETHER =>
//ints WILL BE STORED IN MEMORY ADDRESSES ON MULTIPLE OF 4 AS ints ARE OF 4 BYTES SIZE AND SO ON FOR ALL TYPES => THIS WILL CAUSE GAPS IN THE MEMORY AND OUR MEMORY SUM
//WILL BE OFF A LITTLE BIT

class Wrapper{
    public:
        void do_something();
        void print_something();

    private:                                                                    //note that private comes after public,this is no problem as access spcifiers are mentioned  
        int var1 {};                                                            //8 bytes
        int var2 {};                                                            //8 bytes
        int *p_var {nullptr};                                                   //8 bytes as this is only the size of the pointer and not whats its pointing to
        std::string str1 {"Mars will be colonzed by Humans"};                   //unspecified number of bytes as std::string is represented as a class internally and its
};                                                                              //referred by a pointer

void Wrapper::do_something(){                                                   //functions are NOT counted for size as they are affiliated to the class and not object

}

void Wrapper::print_something(){                                                //functions are NOT counted for size as they are affiliated to the class and not object
    std::cout << "Want to print something? Here you go!" << std::endl;
}

int main(int argc, char **argv){

    Wrapper wrap;
    std::cout << "Size of objects in C++ is: " << sizeof(wrap) << std::endl;    //size of objects in C++ will be the sum of all the datatype sizes of its member variables

    return 0;
}