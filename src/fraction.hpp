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
bool operator==(Fraction const& f1,Fraction const& f2);
bool operator!=(Fraction const& f1,Fraction const& f2);
bool operator<(Fraction const& f1,Fraction const& f2);
bool operator<=(Fraction const& f1,Fraction const& f2);
bool operator>(Fraction const& f1,Fraction const& f2);
bool operator>=(Fraction const& f1,Fraction const& f2);