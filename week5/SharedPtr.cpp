#include "stdafx.h"

#include "SharedPtr.h"

SharedPtr::SharedPtr(Expression *ptr) : ptr(ptr) {
	nRef = (ptr == NULL) ? NULL : new unsigned(1);
}

SharedPtr::~SharedPtr() {
	if (!--(*nRef)) {
		delete ptr;
		delete nRef;
	}
}

SharedPtr::SharedPtr(const SharedPtr &shp) : ptr(shp.ptr), nRef(shp.nRef) {
	*nRef += 1;
}

SharedPtr& SharedPtr::operator=(const SharedPtr& shp) {
	if (this != &shp)
/*		SharedPtr(shp).swap(*this);*/
	return *this;
}

void SharedPtr::swap(SharedPtr & shp) {
	std::swap(ptr, shp.ptr);
	std::swap(nRef, shp.nRef);
}