#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

std::ostream& operator<<(std::ostream& os, Fraction const& f1){
    return os << f1.numerator << "/" << f1.denominator ;
}

/*EXERCICE 1*/
// Fraction Fraction::operator+(Fraction const& f2){
//     return simplify(
//         { numerator * f2.denominator + f2.numerator * denominator, denominator * f2.denominator }
//     );
// }

// Fraction Fraction::operator-(Fraction const& f2){
//     return simplify(
//         { numerator * f2.denominator - f2.numerator * denominator, denominator * f2.denominator}
//     );
// }

// Fraction Fraction::operator*(Fraction const& f2){
//     return simplify(
//         { numerator * f2.numerator , denominator * f2.denominator}
//     );
// }

// Fraction Fraction::operator/(Fraction const& f2){
//     return simplify(
//         { numerator * f2.denominator , denominator * f2.numerator}
//     );
// }
/*FIN EXERCICE 1*/

bool operator==(Fraction const& f1,Fraction const& f2){
    return (f1.numerator*f2.denominator == f1.denominator*f2.numerator);
}

bool operator!=(Fraction const& f1,Fraction const& f2){
    return !(f1==f2);
}

bool operator<(Fraction const& f1,Fraction const& f2){
    return (static_cast<float>(f1.numerator)/static_cast<float>(f1.denominator) < static_cast<float>(f2.numerator)/static_cast<float>(f2.denominator));
}

bool operator<=(Fraction const& f1,Fraction const& f2){
    return (f1<f2 || f1==f2);
}

bool operator>=(Fraction const& f1,Fraction const& f2){
    return (!(f1<f2));
}

bool operator>(Fraction const& f1,Fraction const& f2){
    return (f1>=f2 && f1!=f2);
}

Fraction Fraction::operator+=(Fraction const& f2){
    numerator = numerator * f2.denominator + f2.numerator * denominator;
    denominator = denominator * f2.denominator;
    return simplify(*this);    
}

Fraction Fraction::operator-=(Fraction const& f2){
    numerator = numerator * f2.denominator - f2.numerator * denominator;
    denominator = denominator * f2.denominator;
    return simplify(*this);    
}

Fraction Fraction::operator*=(Fraction const& f2){
    numerator = numerator * f2.numerator;
    denominator = denominator * f2.denominator;
    return simplify(*this);    
}

Fraction Fraction::operator/=(Fraction const& f2){
    numerator = numerator * f2.denominator;
    denominator = denominator * f2.numerator;
    return simplify(*this);    
}

/*EXERCICE 5*/
Fraction operator+(Fraction f1, Fraction const& f2) {
    f1 += f2;
    return simplify(f1);
}

Fraction operator-(Fraction f1, Fraction const& f2) {
    f1 -= f2;
    return simplify(f1);
}

Fraction operator*(Fraction f1, Fraction const& f2) {
    f1 *= f2;
    return simplify(f1);
}

Fraction operator/(Fraction f1, Fraction const& f2) {
    f1 /= f2;
    return simplify(f1);
}
/*FIN EXERCICE 5*/

float Fraction::to_float() const{
    return (static_cast<float>(numerator)/static_cast<float>(denominator));
}

// Fraction::operator float() const{
//     Fraction const* myself_ptr { this};
//     Fraction const&  ref {*myself_ptr};
//     return ref.to_float();
// }

Fraction::operator float() const{
    Fraction const&  ref {*this};
    return ref.to_float();
}

// Fraction::operator float() const {
//     return to_float();
// }