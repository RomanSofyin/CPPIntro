// week4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Foo.h"

void foo_says(const Foo& foo) { foo.say(); }

const Foo get_foo(const char * msg) {
	FooChild fooChild(msg);
	return fooChild;
}

int main()
{
	
	foo_says(get_foo("abcdefghigklmnopqrstuvwxyz"));


    return 0;
}

