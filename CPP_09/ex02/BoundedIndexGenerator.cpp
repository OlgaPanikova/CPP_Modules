#include "BoundedIndexGenerator.hpp"

BoundedIndexGenerator::BoundedIndexGenerator(int limit) : maxLimit(limit) {}

BoundedIndexGenerator::BoundedIndexGenerator(const BoundedIndexGenerator& other) : indexMgr(other.indexMgr), maxLimit(other.maxLimit) {}

BoundedIndexGenerator& BoundedIndexGenerator::operator=(const BoundedIndexGenerator& other) {
  if (this != &other)
  {
    indexMgr = other.indexMgr;
    maxLimit = other.maxLimit;
  }
    return *this;
}

BoundedIndexGenerator::~BoundedIndexGenerator() {};

int BoundedIndexGenerator::nextBoundedIndex()
{
  while (true)
  {
    int index = indexMgr.nextIndex();
    if (index < maxLimit) return index;
  }
}