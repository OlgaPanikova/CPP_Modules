#include "JacobsthalGenerator.hpp"

JacobsthalGenerator::JacobsthalGenerator() : n2(1), n1(1) {}

JacobsthalGenerator::JacobsthalGenerator(const JacobsthalGenerator& copy) : n2(copy.n2), n1(copy.n1) {}

JacobsthalGenerator& JacobsthalGenerator::operator=(const JacobsthalGenerator& other) {
  if (this != &other) 
  {
    n2 = other.n2;
    n1 = other.n1;
  }
  return *this;
}

JacobsthalGenerator::~JacobsthalGenerator() {}

int JacobsthalGenerator::nextNumber() {
  int current = n1 + 2 * n2;
  n2 = n1;
  n1 = current;
  return current;
}