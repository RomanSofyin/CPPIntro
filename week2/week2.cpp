// week2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*
	GCD(a, b) = GCD(b, amodb)GCD(a, b) = GCD(b, amodb)
	GCD(0, a) = aGCD(0, a) = a
	GCD(a, b) = GCD(b, a)
*/
unsigned gcd(int a, int b) {

	int rem = a > b ? a % b : b % a;
	if (rem == 0)
		return a > b ? b : a;

	a > b ? a = rem : b = rem;
	return gcd(a, b);
}

int main()
{
	unsigned x = gcd(35484984, 19);
    return 0;
}

