#include "stdafx.h"

#include "ScopedPtr.h"

ScopedPtr::ScopedPtr(Expression *ptr) : ptr_(ptr) {}

ScopedPtr::~ScopedPtr() {
	delete ptr_;
}

Expression* ScopedPtr::get() const {
	return ptr_;
}

Expression* ScopedPtr::release() {
	Expression * res = ptr_;
	ptr_ = NULL;
	return res;
}

void ScopedPtr::reset(Expression *ptr) {
	delete ptr_;
	ptr_ = ptr;
}

Expression& ScopedPtr::operator*() const {
	return *ptr_;
}

Expression* ScopedPtr::operator->() const {
	return ptr_;
}
