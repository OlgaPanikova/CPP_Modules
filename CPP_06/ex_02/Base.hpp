#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

class Base {
private:

public:
  virtual ~Base() {};
};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif