#pragma once

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    void display();
    
    Fraction operator+(Fraction const& f2);
    Fraction operator-(Fraction const& f2);
    Fraction operator*(Fraction const& f2);
    Fraction operator/(Fraction const& f2);
};
