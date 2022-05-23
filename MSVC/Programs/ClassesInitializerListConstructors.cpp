#include<iostream>
#include<cassert>   //A LIBRARY WHICH GIVES US ACCESS TO DATA DURING RUNTIME => MOST OF TE DATA WE USED UP UNTILL THIS TIME WERE AVAILABLE DURING COMPILE TIME

//Aggregates group together entities in a container like data structure. These containers are initialized using INITIALIZER LIST CONSTRUCTORS. Some of the aggregates we
//already use are arrays, structs. In this lesson we use structs to initialize the aggregates as arrays are built in and we do not want to mess with it using our own
//constructors. USING INITIALIZER LIST CONSTRUCTORS, WE CAN MODIFY THE DEFAULT BEHAVIOUR OF INITIALIZERS WHICH INITIALIZE THE AGGREGATES

struct Point{                                                                                   //struct members are PUBLIC by default
public:
    Point(std::initializer_list<double> list){
        assert(list.size() == 2);
        std::cout << "Initializer List Constrctor called" << std::endl;
        std::cout << "List size is: " << list.size()  << std::endl;
        std::cout << "First Element is: " << *(list.begin())  << std::endl;                     //Dereference the element else it will return the address
        std::cout << "Second Element is: " << *(list.begin() + 1)  << std::endl;                //Dereference the element else it will return the address

        //using for loop to access elements within std::initializer_list
        for(size_t i {}; i < list.size(); ++i){
            std::cout << "Element " << i << " is: " << *(list.begin() + i)  << std::endl;
        }

        //ACTUAL CUSTOM ASSIGNMENT => ACTUAL CUSTOM IMPLEMENTATION OF INITIALIZER LIST CONSTRUCTORS
        x = *(list.begin());                                                                    //PLEASE REMENBER TO FIRST DEREFERENCE THE ELEMENT ELSE COMPILER ERROR
        //THIS LOGIC ONLY ASSIGNS THE SECOND ELEMENT => CAHNGE LOGIC AS PER WHICH ELEMENT TO BE ASSIGNED
        y = *(list.begin() + 1);                                                                //PLEASE REMENBER TO FIRST DEREFERENCE THE ELEMENT ELSE COMPILER ERROR
    }

    void print_info() const{
        std::cout << "X: " << x << " Y: " << y  << std::endl;
    }

private:
    double x;
    double y;
};

int main(int argc, char **argv){

    //default initializer list for initializing the struct => can be of any number => but assertion is mplemented as a safety check
    //Point p1 {10.99, 11.99, 1.99, 15.99, 20.99};                                                //RUNTIME ERROR AS ASSERTION FAILS
    Point p2 {10.99, 11.99}; 
    //std::cout << "X: " << p1.x << " Y: " << p1.y  << std::endl;                               //COMPILER ERROR=>x and y are no longer public=>they have been made private

    return 0;
}