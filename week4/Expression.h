#pragma once


struct Expression
{
	virtual double evaluate() const = 0;
	virtual ~Expression() {}
};
