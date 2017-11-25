#pragma once

//#include "Number.h"
//#include "BinaryOperation.h"

struct  Number1;
struct  BinaryOperation1;

struct Visitor {
	virtual void visitNumber(Number const * number) = 0;
	virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
	virtual ~Visitor() {};
};

