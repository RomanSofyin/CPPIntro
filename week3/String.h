#include <cstddef> // size_t
#include <cstring> // strlen, strcpy


#pragma once


struct String {

	size_t size;
	char *str;
	
	String(const char *str = "") : size(strlen(str)), str(new char[size + 1]) {
		strcpy_s(this->str, this->size+1, str);
		this->str[size] = '\0';
	}

	// Make sure that the size and str struct fields defined in this order.
	// It makes sense for the initialization list here
	String(size_t n, char c) : size(n), str(new char[size + 1]) {
		for (size_t i = 0; i < n; i++)
			str[i] = c;
		str[n] = '\0';
	}

	~String() {
		delete[] str;
		size = 0;
	}

	void append(String &other) {
		char * newStr = new char[this->size + other.size + 1];
		strcpy_s(newStr, this->size + other.size + 1, this->str);
		strcpy_s(newStr+this->size, other.size + 1, other.str);
		newStr[this->size + other.size] = '\0';

		delete[] this->str;

		this->str = newStr;
		this->size += other.size;
	}

};