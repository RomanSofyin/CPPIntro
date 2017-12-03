#include "stdafx.h"

#include "SharedPtr.h"

SharedPtr::SharedPtr(Expression *ptr) : ptr(ptr) {
	nRef = (ptr) ? new unsigned(1) : NULL;
}

SharedPtr::SharedPtr(const SharedPtr &shp) : ptr(shp.ptr), nRef(shp.nRef) {
	if (ptr)
		*nRef += 1;
}

SharedPtr::~SharedPtr() {
	if (ptr && !--(*nRef)) {
		delete ptr;
		delete nRef;
	}
}

SharedPtr& SharedPtr::operator=(const SharedPtr& shp) {
	if (this != &shp) {
		SharedPtr copyThis(shp);
		copyThis.swap(*this);
	}
	return *this;
}

void SharedPtr::swap(SharedPtr & shp) {
	std::swap(ptr, shp.ptr);
	std::swap(nRef, shp.nRef);
}

Expression& SharedPtr::operator*() const {
	return *ptr;
}

Expression* SharedPtr::operator->() const {
	return ptr;
}

Expression* SharedPtr::get() const {
	return ptr;
}

void SharedPtr::reset(Expression *ptr) {
	SharedPtr shrPtr(ptr);
	this->swap(shrPtr);
}