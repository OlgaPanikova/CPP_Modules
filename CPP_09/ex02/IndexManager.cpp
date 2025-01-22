#include "IndexManager.hpp"

IndexManager::IndexManager() : upperBound(1), lowerBound(0), activeIndex(1) {}

IndexManager::IndexManager(const IndexManager& copy) : upperBound(copy.upperBound), lowerBound(copy.lowerBound), activeIndex(copy.activeIndex), jacobGen(copy.jacobGen) {}

IndexManager& IndexManager::operator=(const IndexManager& other) {
  if (this != &other) 
  {
    upperBound = other.upperBound;
    lowerBound = other.lowerBound;
    activeIndex = other.activeIndex;
    jacobGen = other.jacobGen;
  }
  return *this;
}

IndexManager::~IndexManager() {};

int IndexManager::nextIndex()
{
  int result = activeIndex;
  activeIndex--;
  if (activeIndex == lowerBound) {
    lowerBound = upperBound;
    upperBound = jacobGen.nextNumber();
    activeIndex = upperBound;
}
  return result - 1;
}