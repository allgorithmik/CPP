#include<iostream>
//                                 *****PLEASE START VS CODE USING DEVELOPER POWERSHELL FROM WITHIN THE MS VISUAL STUDIO PATH***** => ELSE MS DEBUGGER WILL NOT WORK
//launch.json FILE FOR THIS g++ and gdb COMPILER => SAME CAN BE FOUND IN LINK:https://code.visualstudio.com/docs/cpp/config-mingw.
//launch.json FILE MS C++ COMPILER/DEBUGGER => SAME CAN BE FOUND IN LINK:https://code.visualstudio.com/docs/cpp/config-msvc
//*****PLEASE REFER THE LINKS FOR LATEST UPDATES*****

/*
FOR GDB => REFER LINK:https://code.visualstudio.com/docs/cpp/config-mingw.
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++.exe - Build and Debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "console": "externalTerminal",
            "MIMode": "gdb",
            "miDebuggerPath": "D:\\C++Compilers\\mingw64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Build with g++ 11.2.0"
        }
    ]
}
FOR MSVC => REFER LINK:https://code.visualstudio.com/docs/cpp/config-msvc
{
            "name": "cl.exe buld and debug active file",
            "type": "cppvsdbg",
            "request":"launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args":[],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "preLaunchTask": "Build with MSVC 19.30.30709"
}
*/

//DEBUGGING IS THE PROCESS OF RUNNING OUR PROGRAM THROUGH ANOTHER PROGRAM CALLED A DEBUGGER TO FREEZE THE EXECUTION OF OUR PROGRAM AT ANY GIVEN POINT OF TIME. THIS
//ALLOWS US TO MONITOR THE EXECUTION OF OUR PROGRAM LINE-BY-LINE, ANALYZING FUNCTION CALLS, EXAMINING LOCAL/GLOBAL/STATIC VARIABLES AND THEIR RUNTIME VALUES IN THE
//CURRENT FUNCTION ACTIVATION RECORD (FAR).

//DEBUGGING TERMS:
//STEP
//WATCH: WATCH IS USED WE NEED TO TEST AN EXPRESSION ON A CERTAIN CASES=>EX: IN LINE 71 (look for int result = sum(a, b) if line number does not match),
//WE CAN CREATE A WATCH WITH AN EXPRESSION TO CHECK IF THE RESULT IS GREATER THAN 10

int sum(int a, int b);
int modify(int &a);

int main(int argc, char **argv){

    int a {10};
    int b {20};

    int result = sum(a, b);

    std::cout << "sum(): " << result << std::endl; 

    return 0;
    
}

int sum(int a, int b){
    int add = a + b;
    modify(add);
    return add;
}

int modify(int &a){
    int mod {10};
    a += mod;
    return a;
}