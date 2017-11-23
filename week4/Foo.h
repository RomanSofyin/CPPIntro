#pragma once



struct Foo {
	void say() const { 
		int a = 6;
		a += 6;
		std::cout << "Foo says: " << msg << "\n"; 
	
	}
protected:
	Foo(const char *msg) : msg(msg) { }
private:
	const char *msg;
};

struct FooChild : Foo {
	FooChild(const char *msg) : Foo(msg) {}
};