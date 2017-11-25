#pragma once


struct Visitor {
	virtual void visitNumber(Number const * number) = 0;
	virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
	virtual ~Visitor() {};
};

