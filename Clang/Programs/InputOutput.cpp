#include<iostream>
#include<string>

//cout -> console output
//cin -> input from console
//cerr -> errors to console
//clog -> logs to console

int main(){
    int age;
    std::string name;
    std::string full_name;
    std::cout << "This is a normal console output" << std::endl;
    std::cout << "Please enter your name and age:" << std::endl;
    std::cin >> name >> age;                                                            //In a single line of input
    //std::cout << "Please enter your age:" << std::endl;
    //std::cin >> age;
    std::cout << "Your name is " << name << " and your age is " << age << std::endl;
    std::cout << "Please enter your full name: " << std::endl;
    std::cin.ignore(256, '\n');                                                         //std::cin.getline() will not work if we do not clear buffer,
    std::getline(std::cin, full_name);                                                  //its still storing the last input, i.e ENTER \n from last cin
    std::cout << "Your full name is: " << full_name << std::endl;                       //PLEASE REMEMBER TO CLEAR BUFFER IF USING getline AFTER USING cin IN PREVIOUS STATEMENTS
    std::cerr << "This is an error!" <<std::endl;                                       //cerr -> errors to console
    std::clog << "!!!!!This is a log!!!!!" << std::endl;                                //clog -> logs to console

    return 0;
}