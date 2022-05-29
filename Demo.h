#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
	int gcd(int a, int b)
	{
		while (b > 0) {
			int c = a % b;
			a = b;
			b = c;
		}
		return a;
	}
	int lcm(int a, int b)
	{
		return gcd(a, b) * a * b;
	}

	Fraction& reduction()
	{
		int c = gcd(numerator, denominator);
		numerator = numerator / c;
		denominator = denominator / c;
		return *this;
	}

public:
	Fraction(int num, int denom) : numerator{ num }, denominator{ denom }{}
	Fraction() : Fraction(1, 1) {}
	Fraction(const Fraction& fract)
		: numerator{ fract.numerator },
		denominator{ fract.denominator }{}
	Fraction(int num) : numerator{ num }, denominator{ 1 } {}

	void printFraction()
	{
		cout << numerator << "/" << denominator << endl;
	}

	Fraction& add(Fraction f1)
	{
		if (denominator == f1.denominator)
		{
			numerator = numerator + f1.numerator;
			return *this;
		}
		else
		{
			int c = denominator * f1.denominator;
			numerator = numerator * f1.denominator;
			f1.numerator = f1.numerator * denominator;
			denominator = c;
			numerator = numerator + f1.numerator;
			reduction();
			return *this;

		}
	}
	Fraction& multiplication(Fraction f1)
	{
		numerator = numerator * f1.numerator;
		denominator = denominator * f1.denominator;
		return *this;
	}
	Fraction& sub(Fraction f1)
	{
		if (denominator == f1.denominator)
		{
			numerator = numerator - f1.numerator;
			return *this;
		}
		else
		{
			int c = denominator * f1.denominator;
			numerator = numerator * f1.denominator;
			f1.numerator = f1.numerator * denominator;
			denominator = c;
			numerator = numerator - f1.numerator;
			reduction();
			return *this;

		}
	}
	Fraction& add(int a)
	{
		Fraction f1(a);
		if (denominator == f1.denominator)
		{
			numerator = numerator + f1.numerator;
			return *this;
		}
		else
		{
			int c = denominator * f1.denominator;
			numerator = numerator * f1.denominator;
			f1.numerator = f1.numerator * denominator;
			denominator = c;
			numerator = numerator + f1.numerator;
			reduction();
			return *this;

		}
	}
	Fraction& multiplication(int a)
	{
		Fraction f1(a);
		numerator = numerator * f1.numerator;
		denominator = denominator * f1.denominator;
		return *this;
	}
	Fraction& sub(int a)
	{
		Fraction f1(a);
		if (denominator == f1.denominator)
		{
			numerator = numerator - f1.numerator;
			return *this;
		}
		else
		{
			int c = denominator * f1.denominator;
			numerator = numerator * f1.denominator;
			f1.numerator = f1.numerator * denominator;
			denominator = c;
			numerator = numerator - f1.numerator;
			reduction();
			return *this;

		}
	}

};