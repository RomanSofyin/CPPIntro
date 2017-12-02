// week5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Rational.h"
#include "../week3/String.h"
#include "../week4/Expression.h"
#include "../week4/BinaryOperation.h"
#include "ScopedPtr.h"
#include "SharedPtr.h"

int main()
{
	Rational r1 = 5;
	r1 += 5;
	r1 /= 2;
	r1 = -r1;

	Rational r3 = (Rational)5 / r1;

	double d = r1;

	String const str1 = "Hello";
	String const str2 = str1[0][4];
	String const str3 = str1[1][4];
	String const str4 = str1[0][5];
	String const str5 = str1[2][2];
	String const str6 = str1[1][2];

	SharedPtr shrPtr1(new BinaryOperation(NULL,'+',NULL));
	SharedPtr shrPtr2 = shrPtr1;
	shrPtr2 = shrPtr2;
	shrPtr2 = shrPtr1;


    return 0;
}

