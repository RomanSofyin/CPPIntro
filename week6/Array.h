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
	explicit Array(size_t size = 0, const T& value = T());

	//   конструктор копирования, который создает
	//   копию параметра. Считайте, что для типа
	//   T определен оператор присваивания.
	Array(const Array &);

	//   деструктор, если он вам необходим.
	~Array();

	//   оператор присваивания.
	Array& operator=(const Array &);

	//   возвращает размер массива (количество элементов).
	size_t size() const;

	//две версии оператора доступа по индексу.
	T& operator[](size_t);
	const T& operator[](size_t) const;

private:
	T * arr_;
	size_t size_;

	void swap(Array & oArr);

};