#pragma once

struct Expression
{
	double evaluate() const = 0;
};

struct Number : Expression
{
	Number(double value)
		: value(value)
	{}

private:
	double value;
};

struct BinaryOperation : Expression
{
	/*
	����� op ��� ���� �� 4 ��������: '+', '-', '*' ��� '/', ��������������� ���������,
	������� ��� ����� �����������.
	*/
	BinaryOperation(Expression const * left, char op, Expression const * right)
		: left(left), op(op), right(right)
	{ }

private:
	Expression const * left;
	Expression const * right;
	char op;
};