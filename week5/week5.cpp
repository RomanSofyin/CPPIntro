// week5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Rational.h"

Rational operator+(Rational r1, Rational const & r2) {
	return r1 += r2;
}

Rational operator-(Rational r1, Rational const & r2) {
	return r1 -= r2;
}

Rational operator*(Rational r1, Rational const & r2) {
	return r1 *= r2;
}

Rational operator/(Rational r1, Rational const & r2) {
	return r1 /= r2;
}


int main()
{
	Rational r1 = 5;
	r1 += 5;
	r1 /= 2;
	r1 = -r1;

	Rational r2(4, 5);

	Rational r3 = 5 / r1;

    return 0;
}

