#pragma once


struct Expression
{
	virtual double evaluate() const = 0;
	virtual void visit(Visitor * v) const = 0;
	virtual ~Expression() {}
};
