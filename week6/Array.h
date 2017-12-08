#pragma once

template <typename T>
class Array
{
public:
	//   конструктор класса, который создает
	//   Array размера size, заполненный значениями
	//   value типа T. Считайте что у типа T есть
	//   конструктор, который можно вызвать без
	//   без параметров, либо он ему не нужен.
	explicit Array(size_t size = 0, const T& value = T()) : size_(size) {
/* 
   Здесь мы подразумевали, что для типа T определена операция присваивания.
  		arr_ = new T[size_];
  		for (size_t i = 0; i < size_; i++)
  			*(arr_ + i) = value;					// <=> arr_[i] = value;
  
   Реализуем аналогичные действия, но без такого предположения.
 */
		arr_ = (T*) new char[size_ * sizeof(T)];
		for (size_t i = 0; i < size_; i++)
			new (arr_ + i) T(value);						// placement new usage
	}

	//   конструктор копирования, который создает
	//   копию параметра. Считайте, что для типа
	//   T определен оператор присваивания.
	Array(const Array & oArr) : size_(oArr.size_) {
/*
   Здесь мы подразумевали, что для типа T определена операция присваивания.
		arr_ = new T[size_];
		for (size_t i = 0; i < size_; i++)
		*(arr_ + i) = *(oArr.arr_ + i);
  
   Реализуем аналогичные действия, но без такого предположения.
 */
		arr_ = (T*) new char[size_ * sizeof(T)];
		for (size_t i = 0; i < size_; i++)
			new (arr_ + i) T(oArr.arr_[i]);			// placement new usage
	}

	//   деструктор, если он вам необходим.
	~Array() {
/*
   The loop is required in case of placement new usage only
 */		
		for (size_t i = 0; i < size_; i++)
			arr_[i].~T();
/*
		delete[] arr_;
 */
		delete[](char *)arr_;
		size_ = 0;
	}

	//   оператор присваивания.
	Array& operator=(const Array & oArr) {
		if (this != &oArr)
			Array<T>(oArr).swap(*this);
		return *this;
	}

	//   возвращает размер массива (количество элементов).
	size_t size() const {
		return size_;
	}

	//две версии оператора доступа по индексу.
	T& operator[](size_t index) {
		return *(arr_ + index);
	}

	const T& operator[](size_t index) const {
		return *(arr_ + index);
	}

private:
	T * arr_;
	size_t size_;

	void swap(Array & oArr) {
		std::swap(size_, oArr.size_);
		std::swap(arr_, oArr.arr_);
	}

};