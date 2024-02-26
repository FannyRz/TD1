#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

Fraction Fraction::operator+(Fraction const& f2){
    return simplify(
        { numerator * f2.denominator + f2.numerator * denominator, denominator * f2.denominator }
    );
}

Fraction Fraction::operator-(Fraction const& f2){
    return simplify(
        { numerator * f2.denominator - f2.numerator * denominator, denominator * f2.denominator}
    );
}

Fraction Fraction::operator*(Fraction const& f2){
    return simplify(
        { numerator * f2.numerator , denominator * f2.denominator}
    );
}

Fraction Fraction::operator/(Fraction const& f2){
    return simplify(
        { numerator * f2.denominator , denominator * f2.numerator}
    );
}