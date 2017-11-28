#pragma once

struct Rational
{
	Rational(int numerator = 0, int denominator = 1);

	void add(Rational rational);
	void sub(Rational rational);
	void mul(Rational rational);
	void div(Rational rational);

	void neg();
	void inv();
	double to_double() const;


	Rational & operator+=(Rational const & r);
	Rational & operator-=(Rational const & r);
	Rational & operator*=(Rational const & r);
	Rational & operator/=(Rational const & r);

	Rational operator+() const;
	Rational operator-() const;
	
private:
	int numerator_;
	int denominator_;

	// greatest common delimiter
	int gcd(int a, int b);
	//least common multiple
	int lcm(int a, int b);
};