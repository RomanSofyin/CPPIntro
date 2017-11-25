#pragma once


struct BinaryOperation : Expression
{
	void visit(Visitor * v) const {

	}


	BinaryOperation(Expression const * left, char op, Expression const * right)
		: left(left), op(op), right(right)
	{}

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