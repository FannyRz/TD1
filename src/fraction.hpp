#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    Fraction operator+(Fraction const& f2);
    Fraction operator-(Fraction const& f2);
    Fraction operator*(Fraction const& f2);
    Fraction operator/(Fraction const& f2);
};

std::ostream& operator<<(std::ostream& os, Fraction const& f1);