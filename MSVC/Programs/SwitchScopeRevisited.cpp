#include<iostream>

int main(int argc, char **argv){

    int initial_condition {0};

    switch(initial_condition){          //Entire switch block is one scope, hence variables declared in switcg block can be used anywhere in switch block
        int x;                          //Good practice is to use switch initializerif we need to use variables accross cases and switch block
        //int x1 {5};                   //statement will never be executed->compiler error => switch block may never be executed, declaration != initialization

            case 0:
                //int y1 {5};           //statement will never be executed->compiler error => switch block may never be executed, declaration != initialization
                int y;                  //there is a chance that case 0 will be executed, hence no initialization
                x = 4;
                x++;
                break;

            case 1:{
                int a;                  //if curly braces is used, this itself becomes a block on its own, and any variables decalred within this curly braced
                a++;                    //scope will be avaialble only within that block/scope
                a += 10;                //varialbes declared within this scope will NOT be avialble to other cases even within same switch
            }
            break;

            case 2:
                int z;
                y = 5;                  //The reason y is available in case 1 even though its declared in case 0 is because the compiler moves all the declarations to top
                y += 5;                 //The only criteria is that no variable must be called before it was declared
                break;
            
            default:
                int u1 {5};             //This is OK because in any case, default case will be executed even if no above cases are executed
                int u;
                z = 5;
                z++;
                break;                  //Optional but its a good practice to put break after default
    }
    return 0;
}