#pragma once

#include <iostream>

class Proper_Fraction {

private:

	int numerator;
	int denominator;

	void simplify();

public:

	Proper_Fraction(int numerator, int denominator);
	Proper_Fraction(const Proper_Fraction& frac1);

	Proper_Fraction() = delete;

	int getNumerator() const;
	int getDenominator() const;

	Proper_Fraction add(const Proper_Fraction& frac1) const;
	Proper_Fraction multiply(const Proper_Fraction& frac1) const;
	Proper_Fraction divide(const Proper_Fraction& frac1) const;

	void print() const;

};
