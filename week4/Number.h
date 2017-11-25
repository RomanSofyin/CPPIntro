#pragma once



struct Number : Expression
{
	Number(double value)
		: value(value)
	{}

	virtual void bla() const { int b = 4; return; }

	double evaluate() const {
		// we can call virtual methods from non-virtual ones
		bla();
		return value;
	}

	void visit(Visitor * v) const {

	}
	
private:
	double value;
};
