#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    /* EXERCICE 1*/
    // Fraction operator+(Fraction const& f2);
    // Fraction operator-(Fraction const& f2);
    // Fraction operator*(Fraction const& f2);
    // Fraction operator/(Fraction const& f2);

    Fraction operator+=(Fraction const& f2);
    Fraction operator-=(Fraction const& f2);
    Fraction operator*=(Fraction const& f2);
    Fraction operator/=(Fraction const& f2);

    float to_float() const;
    operator float() const ;
    
};

std::ostream& operator<<(std::ostream& os, Fraction const& f1);
bool operator==(Fraction const& f1,Fraction const& f2);
bool operator!=(Fraction const& f1,Fraction const& f2);
bool operator<(Fraction const& f1,Fraction const& f2);
bool operator<=(Fraction const& f1,Fraction const& f2);
bool operator>(Fraction const& f1,Fraction const& f2);
bool operator>=(Fraction const& f1,Fraction const& f2);

/*EXERCICE 5*/
Fraction operator+(Fraction f1, Fraction const& f2);
Fraction operator-(Fraction f1, Fraction const& f2);
Fraction operator*(Fraction f1, Fraction const& f2);
Fraction operator/(Fraction f1, Fraction const& f2);
