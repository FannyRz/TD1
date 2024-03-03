#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1 { 3, 4 };
    Fraction f2 { 1, 4 };

    std::cout << "f1 = ";
    std::cout << f1 ;
    std::cout << " f2 = ";
    std::cout << f2 ;
    std::cout << std::endl;

    std::cout << "add(f1, f2) = ";
    std::cout << f1+f2;

    std::cout << std::endl << "sub(f1, f2) = ";
    std::cout << f1-f2;

    std::cout << std::endl << "mul(f1, f2) = ";
    std::cout << f1*f2;

    std::cout << std::endl << "div(f1, f2) = ";
    std::cout << f1/f2 ;

    std::cout << std::endl << "f1==f2 = ";
    std::cout << (f1==f2);

    std::cout << std::endl << "f1!=f2 = ";
    std::cout << (f1!=f2);

    std::cout << std::endl << "f1<f2 = ";
    std::cout << (f1<f2);

    std::cout << std::endl << "f1<=f2 = ";
    std::cout << (f1<=f2);

    std::cout << std::endl << "f1>f2 = ";
    std::cout << (f1>f2);

    std::cout << std::endl << "f1>=f2 = ";
    std::cout << (f1>=f2);

    // std::cout << std::endl << "f1+=f2 = ";
    // std::cout << (f1+=f2);

    // std::cout << std::endl << "f1-=f2 = ";
    // std::cout << (f1-=f2);

    return 0;
}