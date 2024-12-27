#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <fstream>

template <typename T>
class Array {
private:
	T*				data;
	unsigned int	_size;

public:
	Array();
	Array(unsigned int i);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();
	T& operator[](unsigned int index);
	unsigned int size() const;
};

template <typename T>
Array<T>::Array() : data(nullptr), _size(0) {};


template <typename T>
Array<T>::Array(unsigned int i) : _size(i) {
	if(i == 0)
		data = nullptr;
	else
		data = new T[i];
}


template <typename T>
Array<T>::Array(const Array& other) : _size(other._size) {
	data = new T[other._size];
	for (unsigned int i = 0; i < _size; ++i) {
		data[i] = other.data[i];
	}
}


template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
	if (this == &other) {
		return *this;
	}
	delete[] data;
	_size = other._size;
	data = new T[other._size];
	for (unsigned int i = 0; i < _size; ++i) {
		data[i] = other.data[i];
	}
	return *this;
}


template <typename T>
Array<T>::~Array() {
	delete[] data;
}


template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::out_of_range("Index out of range");
	}
	return data[index];
}


template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

#endif