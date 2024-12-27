#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <fstream>
#include "Data.hpp"

class Serializer {
private:
	Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& other);
	~Serializer();

public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

};

#endif