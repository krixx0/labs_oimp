#include "Fraction.h"
#include <iostream>

int nod(int num, int denom) {
    
    num = std::abs(num);
    denom = std::abs(denom);
    while (denom != 0) {

        int t = denom;
        denom = num % denom;
        num = t;
    }
    return num;
}

void Proper_Fraction::simplify() {
   
    if (denominator == 0) {

        std::cerr << "Fatal mistake! na 0 delit', serious?" << '\n';
        exit(1);
    }

    if (denominator < 0) {
        
        numerator = -numerator;
        denominator = -denominator;
    }

    int delitel = nod(numerator, denominator);
    numerator /= delitel;
    denominator /= delitel;
}

Proper_Fraction::Proper_Fraction(int num, int denom) {
    
    numerator = num;     
    denominator = denom;
    simplify();
}

Proper_Fraction::Proper_Fraction(const Proper_Fraction& frac1) {

    numerator = frac1.numerator;     
    denominator = frac1.denominator;
}

int Proper_Fraction::getNumerator() const {
    
    return numerator;
}

int Proper_Fraction::getDenominator() const {
    
    return denominator;
}

Proper_Fraction Proper_Fraction::add(const Proper_Fraction& frac2) const {

    int Num2 = numerator * frac2.denominator + frac2.numerator * denominator;
    int Denom2 = denominator * frac2.denominator;

    return Proper_Fraction(Num2, Denom2);
}

Proper_Fraction Proper_Fraction::multiply(const Proper_Fraction& frac2) const {
    
    int Num3 = numerator * frac2.numerator;
    int Denom3 = denominator * frac2.denominator;

    return Proper_Fraction(Num3, Denom3);
}

Proper_Fraction Proper_Fraction::divide(const Proper_Fraction& frac2) const {
    
    int Num4 = numerator * frac2.denominator;
    int Denom4 = denominator * frac2.numerator;

    return Proper_Fraction(Num4, Denom4);
}


void Proper_Fraction::print() const {
    
    if (denominator == 1) {
        
        std::cout << numerator;
    }

    else {
        
        std::cout << numerator << "/" << denominator;
    }
}
