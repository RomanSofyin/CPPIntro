#pragma once

#include <iostream>

struct  Number1;
struct  BinaryOperation1;

struct Visitor1 {
	virtual void visitNumber(Number1 const * number) = 0;
	virtual void visitBinaryOperation(BinaryOperation1 const * operation) = 0;
	virtual ~Visitor1() {};
};


struct Expression1
{
	virtual double evaluate() const = 0;
	virtual void visit(Visitor1 * v) const {};
	virtual ~Expression1() {}
};


struct Number1 : Expression1
{
	Number1(double value)
		: value(value)
	{}

	virtual void bla() const {}

	double evaluate() const {
		// we can call virtual methods from non-virtual ones
		bla();
		return value;
	}

	virtual void visit(Visitor1 * v) const {
		v->visitNumber(this);
	}

	double get_value() const { return value; }

private:
	double value;
};

struct BinaryOperation1 : Expression1
{
	virtual void visit(Visitor1 * v) const {
		v->visitBinaryOperation(this);
	}

	BinaryOperation1(Expression1 const * left, char op, Expression1 const * right)
		: left(left), op(op), right(right)
	{}

	~BinaryOperation1() {
		delete left;
		delete right;
	}

	double evaluate() const {
		double res = 0;

		switch (op)
		{
		case '+':
			res = left->evaluate() + right->evaluate();
			break;
		case '-':
			res = left->evaluate() - right->evaluate();
			break;
		case '*':
			res = left->evaluate() * right->evaluate();
			break;
		case '/':
			res = left->evaluate() / right->evaluate();
			break;
		default:
			break;
		}
		return res;
	}

	Expression1 const * get_left() const { return left; }
	Expression1 const * get_right() const { return right; }
	char get_op() const { return op; }

private:
	Expression1 const * left;
	Expression1 const * right;
	char op;
};


struct PrintVisitor1 : Visitor1
{
	void visitNumber(Number1 const * number) {
		std::cout << number->get_value();
	}

	void visitBinaryOperation(BinaryOperation1 const * bop) {
		std::cout << '(';
		bop->get_left()->visit(this);
		std::cout << bop->get_op();
		bop->get_right()->visit(this);
		std::cout << ')';
	}
};