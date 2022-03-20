#include<iostream>

int main(int argc, char **argv){

    double some_val {55.99};
    auto x = some_val;                                                                      //when auto is detected, the compiler auto deduces the type => autos are just copy

    std::cout << "Size of double is: " << sizeof(some_val) << std::endl;
    std::cout << "Address of double is: " << &some_val << std::endl;                        //different address than auto => again proving auto is just a copy

    std::cout << "Size of auto is: " << sizeof(x) << std::endl;
    std::cout << "Address of auto is: " << &x << std::endl;                                 //different address than double => again proving auto is just a copy

    //NAKED auto REFERENCE DETECTION
    std::cout << "Type deducton with references" << std::endl;
    double &some_val_ref {some_val};

    //y IS NOT DEDUCED TO A REFERENCE, IT IS ONLY GOING TO BE DEDUCED TO A double TYPE, SO ANY CHANGES TO y WILL NOT AFFECT ITS ORIGINAL VARIABLE UNLIKE x
    auto y {some_val_ref};

    std::cout << "Size of Reference: " << sizeof(some_val_ref) << std::endl;
    std::cout << "Size of Reference auto: " << sizeof(y) << std::endl;
    std::cout << "Address of Reference: " << &some_val_ref << std::endl;
    std::cout << "Address of Reference auto: " << &y << std::endl;

    std::cout << "Proving auto will NOT deduce a reference:" << std::endl;
    std::cout << "Value of auto y before modification: " << y << std::endl;

    ++y;                                                                                    //modifying by incrementing

    std::cout << "Value of auto y after modification: " << y << std::endl;
    std::cout << "Value of auto ORIGINAL after modification: " << some_val << std::endl;    //value does not change hence proving auto will not deduce references, only types

    //IF WE NEED auto TO DUDUCE EVEN THE REFERENCES, THIS IS A POSSIBILITY IN C++
    //syntax: auto &<variable_name>
    auto &z {some_val};

    std::cout << "Size of Reference: " << sizeof(some_val_ref) << std::endl;
    std::cout << "Size of Reference auto WITH REFERENCE DEDUCTION: " << sizeof(z) << std::endl;
    std::cout << "Address of Reference: " << &some_val_ref << std::endl;
    std::cout << "Address of Reference auto WITH REFERENCE DEDUCTION: " << &z << std::endl;

    //NOW ANY MODIFICATIONS TO auto deduced REFERENCES, IT WILL AFFECT THE ORIGINAL VALUE
    std::cout << "Proving auto WILL deduce a reference with syntax change:" << std::endl;
    std::cout << "Value of auto z before modification: " << z << std::endl;

    ++z;                                                                                    //modifying by incrementing

    std::cout << "Value of auto z after modification: " << z << std::endl;
    std::cout << "Value of auto ORIGINAL after modification: " << some_val << std::endl;    //value DOES change hence proving auto CAN ALSO deduce references(syntax change)

    //const-ness PRESERVATION THROUGH auto => const-ness IS PRESERVED ONLY WHEN WE USE auto reference DEDUCTION SYNTAX
    const double some_val2 {99.55};
    const double &some_val2_ref {some_val2};

    auto some_val_auto {some_val2_ref};
    ++some_val_auto;                                                                        //POSSIBLE TO CHANGE => BECAUSE ITS A COPY

    auto &some_val_auto_syn = some_val2_ref;

    std::cout << "Value of const some_val2: " << some_val2 << std::endl;
    //++some_val_auto_syn;                                                                    //COMPILER ERROR! => BECAUSE ITS A REFERENCE => const-ness PRESERVED
    return 0;
    
}