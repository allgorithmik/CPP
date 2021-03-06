//ALL CONST VARIABLES AND THEIR VALUES WILL BE PRESENT HERE
#ifndef PI_H                                //THESE ARE INCLUDE GUARDS => THESE WILL GUARD AGAINST INCLUDING A HEADER FILE MULTIPLE TIMES
#define PI_H                                //IT BASICALLY TELLS THE COMPILER THAT IF  **THIS** PARTICULAR FILE IS INCLUDED SOMEWHERE, DO NOT INCLUDE THIS THIS, ELSE INCLUDE
//IF THE FILE IS INCLUDED, #ifndef WILL FAIL AND WILL NOT PROCEED TO #define STATEMENT, IF THE FILE IS NOT INCLUDED #ifndef WILL BE TRUE AND WILL EXECUTE #define STATEMENT
//AND INCLUDE WHATEVER FILE IS INCLUDE NEXT TO #define STATEMENT
 
const double PI {3.141592653589793238};

#endif                                      //THIS WILL INDICATE THE END OF #define / #ifndef PRE-PROCESSOR DIRECTIVES FOR THIS FILE