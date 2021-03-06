// week3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"
#include "Cls.h"
#include "ClsClone.h"

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
	ClsClone& clsClone = (ClsClone&)cls;
	return clsClone.c;
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
	ClsClone& clsClone = (ClsClone&)cls;
	return clsClone.d;
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
	ClsClone& clsClone = (ClsClone&)cls;
	return clsClone.i;
}


int main()
{
	String s1 = String("abc");
	String s2 = String("def");
	s1.append(s2);
	s1.append(s1);

	//Small hack, do not do this in real working code
	Cls cls = Cls('c', 3.14, 5);
	char &c = get_c(cls);
	c = 'f';
	c = c;
	
	const int * const * m1;

	int i = 5;
	int * p_i = &i;
	int ** pp_i = &p_i;
	*(*(pp_i + 0) + 0) = 55;
	pp_i[0][0] = 555;

	String s3 = s2;			// copying

	s3 = s1;				// assignment

    return 0;
}

