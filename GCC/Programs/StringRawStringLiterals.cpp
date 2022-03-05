#include<iostream>
#include<string>

int main(int argc, char **argv){
    //RAW STRING LITERALS ARE USED IN PLACE OF MESSY ESCAPE SEQUENCES => WYSIWYG kind of thing, what you type is what gets printed out
    //std::string identifier {R"(<string literal content>)"};

    //uniform initialization
    std::string todo_tasks {R"(
        Learn continuously
        Practice continuously
        Knowledge is ultimate need
        Apply to good
        Expand your learnings
    )"};

    //assignment initialization also works => std::string identifier = R"(<string literal content>)";
    std::string todo_tasks1 = R"(
        Learn continuously
        Practice continuously
        Knowledge is ultimate need
        Apply to good
        Expand your learnings
    )";

    //RAW STRING LITERALS ALSO WORKS WITH C-STRINGS USING UNIFORM INITIALIZATION
    const char *todo_tasks2 {R"(
        Learn continuously
        Practice continuously
        Knowledge is ultimate need
        Apply to good
        Expand your learnings
    )"};

    //RAW STRING LITERALS ALSO WORKS WITH C-STRINGS USING ASSIGNMENT INITIALIZATION
    const char *todo_tasks3 = R"(
        Learn continuously
        Practice continuously
        Knowledge is ultimate need
        Apply to good
        Expand your learnings
    )";

    //RAW STRING LITERALS CAN ALSO BE USED TO FIX OTHER STRINGS WITH ESCAPE SEQUENCES
    std::string windows_path {R"(Drive:\Directory1\Directory2\Directory3\File1)"};  //raw string literal does not need \\ to display forward slash
    std::string  double_quotes {R"(Mars said to earthlings, "please do not pollute and plunder me as well")"};    //raw string literal does not need \" to display "

    //"()" ARE DELIMITERS OF RAW STRING LITERALS => IF STRING CONTAINS "()" AS PART OF STRING THAT NEEDS TO BE DISPLAYED, USE:
    //std::string identifier {R"---"(<string content>)"---"}; -> uniform initialization => --- is OPTIONAL, WE CAN USE ANY DELIMITER *** OR ### ANYTHING
    std::string weird1 {R"---("(This will work)")---"};

    //std::string identifier = R"---"(<string content>)"---"; -> assignment initialization => --- is OPTIONAL, WE CAN USE ANY DELIMITER *** OR ### ANYTHING
    std::string weird2 = R"---("(This also works)")---";

    std::cout << "Raw string literals using uniform initialization: " << todo_tasks << std::endl;
    std::cout << "Raw string literals using assignment initialization: " << todo_tasks1 << std::endl;
    std::cout << "Raw string literals using C-strings using uniform initialization: " << todo_tasks2 << std::endl;
    std::cout << "Raw string literals using C-strings using assignment initialization: " << todo_tasks3 << std::endl;
    std::cout << windows_path << std::endl;
    std::cout << double_quotes << std::endl;
    std::cout << weird1 << std::endl;
    std::cout << weird2 << std::endl;

    return 0;
}