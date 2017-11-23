#pragma once

#include "Visitor.h"

struct Expression
{
	virtual double evaluate() const = 0;
	virtual void visit(Visitor * visitor) const = 0;
	virtual ~Expression() {}
};
