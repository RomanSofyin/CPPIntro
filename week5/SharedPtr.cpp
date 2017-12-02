#include "stdafx.h"

#include "SharedPtr.h"

SharedPtr::SharedPtr(Expression *ptr) : ptr(ptr) {
	nRef = (ptr == NULL) ? NULL : new unsigned(1);
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
/*		if (copyThis.ptr && *copyThis.nRef == 1)
			copyThis.~SharedPtr();*/
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
	if (!--(*nRef))
		delete this->ptr;
	this->ptr = ptr;
}