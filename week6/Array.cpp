//#include "stdafx.h"
//#include "Array.h"

// Two statements below are about overcoming a definition disadvantage
// of the methods in template classes -
// declaration and definition should be located in the header file
template Array<int>;
template Array<float>;
// but I don't want to add analoguous statment for each type I'm using with the class,
// so now I decided not to exploit this .cpp (marked as text) but leave it in the project



template <typename T>
Array<T>::Array(size_t size, const T& value) : size_(size) {
	arr_ = new T[size_];
	for (size_t i = 0; i < size_; i++)
		*(arr_ + i) = value;
}

template <typename T>
Array<T>::Array(const Array & oArr) : size_(oArr.size_) {
	arr_ = new T[size_];
	for (size_t i = 0; i < size_; i++)
		*(arr_ + i) = *(oArr.arr_ + i);
}

template <typename T>
Array<T>::~Array() {
	delete[] arr_;
	size_ = 0;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T> & oArr) {
	if (this != &oArr)
		Array<T>(oArr).swap(*this);
	return *this;
}

template <typename T>
void Array<T>::swap(Array & oArr) {
	std::swap(size_, oArr.size_);
	std::swap(arr_, oArr.arr_);
}

template <typename T> size_t Array<T>::size() const {
	return size_;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
	return *(arr_ + index);
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
	return *(arr_ + index);
}

