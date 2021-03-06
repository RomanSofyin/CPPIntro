// week1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include <cmath>

// week 1, lesson 7, step 14
void printTypes() {
	int i = 42;
	double d = 3.14;
	const char *s = "C-style string";
	const bool b = true;

	std::cout << "This is an integer " << i << "\n";
	std::cout << "This is a double " << d << "\n";
	std::cout << "This is a \"" << s << "\"\n";
	std::cout << "This is a boolean \"" << b << "\"\n";

}


// week 1, lesson 7, step 14
void inputOutput() {
	int i = 42;
	double d = 3.14;

	std::cout << "Enter an integer and a double:\n";
	std::cin >> i >> d;
	std::cout << "Your input is " << i << ", " << d << "\n";
}


// week 1, lesson 7, step 15
void getTest() {
	char c = '\0';
	while (std::cin.get(c)) { // на каждой итерации считываем один символ в переменную c
							  /* здесь можно пользоваться значением прочитанным в переменную c */
		if (c != 'a')
			std::cout << c; // выводим символ, если он не равен 'a'
	}
}


// week 1, lesson 8, step 4
int power(int x, unsigned p) {
	int answer = 1;
	while (p > 0) {
		answer *= x;
		p--;
	}
	return answer;
}


#define MAX(x, y, r) {int myXVar = x; int myYVar = y; r = myXVar > myYVar ? myXVar : myYVar;}

void foo_w1l8s9() {
	int a = 0;
	int b = 0;
	std::cout << "Enter a and b: ";
	std::cin >> a >> b;

	std::cout << "a + b = " << (a + b) << std::endl;

}

void foo_w1l8s10() {
	int a = 0;
	int b = 0;

	int count = 0;

	std::cin >> count;

	while (count--) {
		std::cin >> a >> b;
		std::cout << (a + b) << std::endl;
	}
}

void foo_w1l8s11() {
	int a = 0, b = 0, c = 0;
	std::cin >> a >> b >> c;

	double d = (b*b - 4 * a*c);

	if (d < 0) std::cout << "No real roots";
	else if (d == 0) {
		double x12 = 0 - (b / (2 * a));
		std::cout << x12 << " " << x12;
	}
	else {
		double x1 = ((0 - b) + sqrt(d)) / (2 * a);
		double x2 = ((0 - b) - sqrt(d)) / (2 * a);
		std::cout << x1 << " " << x2;
	}
}

void foo_w1l8s12() {
	char c = '\0', p = '\0';

	while (std::cin.get(c)) {

		if (c == ' ' && p == ' ')
			continue;
		std::cout << c;
		p = c;
	}
}

int getLog2(int a) {
	int p;
	for (p = 1; power(2, p) <= a; p++);
	return --p;
}

void foo_w1l8s13() {
	int count = 0;
	std::cin >> count;

	while (count--) {
		int a;
		std::cin >> a;
		int p = getLog2(a);
		std::cout << p << std::endl;
	}
}


int main()
{
	//	printTypes();
	//	inputOutput();
	//	getTest();
	//	int a = power(2, 5);

	int a = 10;
	int b = 20;
	int c = 0;
	MAX(a, b, c); // теперь c равно 20
	MAX(a += b, b, c); // теперь a = с = 30

	//	foo_w1l8s9();
	//	foo_w1l8s10();
	//	foo_w1l8s11();
	//	foo_w1l8s12();

	foo_w1l8s13();

	return 0;
}
