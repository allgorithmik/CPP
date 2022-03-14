#include<iostream>
//IMPLCIT CASTING OF std::string_view TO std::string AND VICE VERSA IS NOT POSSIBLE => ONLY FIX IS TO EXPLICITLY CAST
void name(const std::string &name);
void process_name(std::string_view name_sv);

int main(int argc, char **argv){

    std::string name1 {"C++"};
    process_name(name1);
    return 0;
}

void name(const std::string &name){
    std::cout << "My name is: " << name << std::endl;
}

void process_name(std::string_view name_sv){
    //COMPILER ERROR! IMPLICIT CASTING OF std::string_view TO std::string IS NOT ALLOWED => ONLY FIX IS TO EXPLICITLY CAST std::string_view TO std::string
    //THE REASON WHY std::string_view TO std::string IS NOT ALLOWED IS BECAUSE std::string_view WAS CREATED TO AVOID COPIES OF std::string WHILE PASSING AS PARAMS / ARGS
    //TO FUNCTIONS => BUT BY CONVERTING std::string_view TO std::string, THIS CONTRADICTS THE COMPILER DESIGN, HENCE COMPILER ERROR
    //name(name_sv);                                    //PASSING THE PARAM / ARG OF ANOTHER FUNCTION TO THIS FUNCTION
    //FIX IS TO EXPLICITLY CAST std::string_view TO std::string
    
    name(std::string(name_sv));                         //NO COMPILER ERROR WORKS FINE
}