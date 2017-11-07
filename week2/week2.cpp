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

void swap(int * a, int * b) {
	int t = *a;
	*a = *b;
	*b = t;
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
	const unsigned size = 65536;
	int m[size] = {};
//                &m[0]     &m[9]  p+=1 or p++
	for (int * p = m;   p <= m+size;  ++p) {
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

void reverseArray(int * m, unsigned size) {
	for (int i = 0, j = size-1; (m + i) <= (m + j); i++, j--) {
		swap(m+i, m+j);
	}
}

void rotate(int a[], unsigned size, int shift) {
	shift %= size;
	reverseArray(a, shift);
	reverseArray(a + shift, size - shift);
	reverseArray(a, size);
}

unsigned strLen(const char * str) {
	unsigned i;
//                    ++i
	for (i = 0; *str; i++, str++);
	return i;
}

void strCat(char *to, const char *from) {
	to += strLen(to);
	for (; *from; to++, from++)
		*to = *from;
	*to = '\0';
}

int strStr(const char *text, const char *pattern)
{
	int i = 0, j = 0;
	
	while (*(text+i))
	{
		for (j = 0; *(pattern + j) && *(text + i + j) && *(pattern + j) == *(text + i + j); j++);
		
		if (!(*(pattern + j) && *(text + i + j)))
			break;
		
		j == 0 ? i++ : i += j;
	}

	int res;
	if (!*(pattern + j))
		res = i;
	else if (!*(text + i + j))
		res = -1;

	return res;
}

char * resize(const char *str, unsigned size, unsigned new_size)
{
	char * newStr = new char[new_size];
	
	unsigned minSize = size < new_size ? size : new_size;

	for (size_t i = 0; i < minSize; i++)
		newStr[i] = str[i];

	delete []  str;
	return newStr;
}

char *getline()
{
	const unsigned baseLen = 128;
	char * str = new char[baseLen];
	unsigned resizeCount = 0;
	size_t i = 0;

	for (char smb; cin.get(smb); i++) {
		if (smb == '\n')
			break;
		if (i + 1 == baseLen * (resizeCount + 1)) {
			str = resize(str, baseLen*(resizeCount + 1), baseLen*(resizeCount + 2));
			resizeCount += 1;
		}
		str[i] = smb;
	}

	str[i] = '\0';
	return str;
}


int ** create_array2d(size_t a, size_t b) {
	int ** m = new int *[a];
	for (size_t i = 0; i < a; ++i)
		m[i] = new int[b];
	return m;
}

void free_array2d(int ** m, size_t a, size_t b) {
	for (size_t i = 0; i < a; ++i)
		delete[] m[i];
	delete[] m;
}

int ** q_create_array2d(size_t a, size_t b) {
	int ** m = new int *[a];
	m[0] = new int[a*b];
	for (size_t i = 1; i < a; ++i)
		m[i] = m[i - 1] + b;
	return m;
}

void q_free_array2d(int ** m, size_t a) {
	delete[] m[0];
	delete[] m;
}

// Should be tested
void copyArray(const int * const * originArr, int * const * copyArr, unsigned rows, unsigned cols) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			copyArr[i][j] = originArr[i][j];
		}
	}
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
	int ** p_arr = q_create_array2d(rows, cols);
	
	//cloneArray()
	
	for (size_t i = 0; i < rows-1; i++)
	{
		for (size_t j = i+1; j < cols; j++)
		{
		//	swap()
		}

	}
	int * p_int = new int(5);
	return &p_int;
}

int main()
{
	unsigned x = gcd(35484984, 19);
	foo_w2s2l6();
	//reverseInputInts();
	fillUpArray();
	
	int m [] = { 1,2,3,4,5,6,7 };
	rotate(m, 7, 3);

	int l = strlen("");

	char str1 [4+3+1] = {'A', 'B' ,'C' ,'D'};
	char * str2 = "EFG";
	strCat(str1, str2);

	int i = strStr("", "");

	char * p = resize(new char [512], 512, 1024);
	delete[] p;

	//p = getline();
	//delete[] p;

	free_array2d(create_array2d(1000, 1500), 1000, 1500);
	q_free_array2d(q_create_array2d(1000, 1500), 1000);

	int a[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//transpose

	return 0;
}

