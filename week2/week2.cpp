// week2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

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

int foo_w2s2l6_helper() {
	cout << "The foo_w2s2l6 has received control!";
	return 123;
}

// Stack overflow weak point
int foo_w2s2l6() {
	int * m[1];
// It seems that the compiler is smart enough to point us on the error here (code C4789)
//	m [3] = (int *) &foo_w2s2l6_helper;
	return 1;
}

int reverseInputInts() {
	int i;
	cin >> i;
	if (i == 0)
		return 0;
	reverseInputInts();
	cout << i << " ";
	return i;
}

void fillUpArray() {
	int m[10] = {};
//                &m[0]     &m[9]  p+=1 or p++
	for (int * p = m;   p <= m+9;  ++p) {
		*p = (p - m) + 1;
	}
}

int maxArrElem(int * m, int size) {
	int max = *m;
	for (int i = 1;i < size; ++i)
		if (m[i] > max)
			max = m[i];
	return max;
}

int main()
{
	//unsigned x = gcd(35484984, 19);
	//foo_w2s2l6();
	//reverseInputInts();
	fillUpArray();
	return 0;
}

