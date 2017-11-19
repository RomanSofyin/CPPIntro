#pragma once

struct Expression
{
	virtual double evaluate() const = 0;
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
	
private:
	double value;
};

struct BinaryOperation : Expression
{
	/*
	Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
	которые вам нужно реализовать.
	*/
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

private:
	Expression const * left;
	Expression const * right;
	char op;
};