#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& os, Fraction const& f1){
    return os << f1.numerator << "/" << f1.denominator ;
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

bool operator==(Fraction const& f1,Fraction const& f2){
    return (f1.numerator*f2.denominator == f1.denominator*f2.numerator);
}

bool operator!=(Fraction const& f1,Fraction const& f2){
    return !(f1==f2);
}

bool operator<(Fraction const& f1,Fraction const& f2){
    return (static_cast<float>(f1.numerator)/static_cast<float>(f1.denominator) < static_cast<float>(f2.numerator)/static_cast<float>(f2.denominator));
}