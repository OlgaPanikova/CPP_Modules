#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <fstream>
#include <cstddef>

template <typename T>
void iter(T* array, std::size_t len, void (*function)(const T&)) {
	for(std::size_t i = 0; i < len; i++) {
		function(array[i]);
	}
}

template <typename T>
void printElement(const T& elem) {
	std::cout << elem << " " << std::endl;
}

#endif