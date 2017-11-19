// week4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Foo.h"
#include "Expression.h"

void foo_says(const Foo& foo) { foo.say(); }

const Foo get_foo(const char * msg) {
	FooChild fooChild(msg);
	return fooChild;
}

int main()
{
	
	foo_says(get_foo("abcdefghigklmnopqrstuvwxyz"));
	Number b(3);
	Number &bb = b;
	// to call virtual methods we dont's have to refferer to the object via a ponter
	b.bla();
	bb.bla();

	// 3 + 4.5 * 5
	Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	Expression * expr = new BinaryOperation(new Number(3), '+', sube);
	std::cout << expr->evaluate() << std::endl;
	delete expr;

    return 0;
}

