#include "stdafx.h"

#include "Rational.h"

/*
GCD(a, b) = GCD(b, amodb)GCD(a, b) = GCD(b, amodb)
GCD(0, a) = aGCD(0, a) = a
GCD(a, b) = GCD(b, a)
*/
int Rational::gcd(int a, int b) {
	bool aGTb = a > b;
	
	int rem = aGTb ? a % b : b % a;
	if (rem == 0)
		return aGTb ? b : a;
	
	aGTb ? a = rem : b = rem;
	return gcd(a, b);
}

int Rational::lcm(int a, int b) {
	return abs(a*b) / gcd(a, b);
}

Rational::Rational(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {}

void Rational::add(Rational rational) {
	int denLcm = lcm(denominator_, rational.denominator_);
	numerator_ = numerator_*(denLcm / denominator_) + rational.numerator_*(denLcm / denominator_);
	denominator_ = denLcm;
}

void Rational::sub(Rational rational) {
	rational.neg();
	add(rational);
}

void Rational::mul(Rational rational) {
	numerator_ *= rational.numerator_;
	denominator_ *= rational.denominator_;

}

void Rational::div(Rational rational) {
	numerator_ *= rational.denominator_;
	denominator_ *= rational.numerator_;
}

void Rational::neg() {
	numerator_ = -numerator_;
}

void Rational::inv() {
	int tmp = numerator_;
	numerator_ = denominator_;
	denominator_ = tmp;
}

double Rational::to_double() const {
	return numerator_ / denominator_;
}

Rational & Rational::operator+=(Rational const & r) {
	add(r);
	return *this;
}

Rational & Rational::operator-=(Rational const & r) {
	sub(r);
	return *this;
}

Rational & Rational::operator*=(Rational const & r) {
	mul(r);
	return *this;
}

Rational & Rational::operator/=(Rational const & r) {
	div(r);
	return *this;
}

Rational Rational::operator+() const {
	return *this;
}

Rational Rational::operator-() const {
	Rational r(*this);
	r.neg();
	return r;
}