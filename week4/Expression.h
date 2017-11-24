#pragma once
#include "Visitor.h"

struct Expression
{
	virtual double evaluate() const = 0;
/*	virtual void visit(Visitor * visitor) const = 0;*/
	virtual ~Expression() {}
};

struct Number : Expression
{
	Number(double value)
		: value(value)
	{}

	virtual void bla() const {}

	double evaluate() const {
		// we can call virtual methods from non-virtual ones
		bla();
		return value;
	}

	double get_value() const { return value; }
/*
	void visit(Visitor * visitor) const { visitor->visitNumber(this); }
	*/
private:
	double value;
};

struct BinaryOperation : Expression
{
	BinaryOperation(Expression const * left, char op, Expression const * right)
		: left(left), op(op), right(right)
	{ }

	~BinaryOperation() {
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

	Expression const * get_left() const { return left; }
	Expression const * get_right() const { return right; }
	char get_op() const { return op; }

/*	void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }*/

private:
	Expression const * left;
	Expression const * right;
	char op;
};