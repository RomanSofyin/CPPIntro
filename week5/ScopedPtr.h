#pragma once

struct Expression;

struct ScopedPtr
{
	explicit ScopedPtr(Expression *ptr = 0);
	~ScopedPtr();
	Expression* get() const;
	Expression* release();
	void reset(Expression *ptr = 0);
	Expression& operator*() const;
	Expression* operator->() const;


private:
	// prohibit using of the constructor and operator below
	ScopedPtr(const ScopedPtr&);
	ScopedPtr& operator=(const ScopedPtr&);

	Expression *ptr_;
};