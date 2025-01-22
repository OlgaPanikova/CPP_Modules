#ifndef BOUNDEDINDEXGENERATOR_HPP
#define BOUNDEDINDEXGENERATOR_HPP

#include <vector>
#include "IndexManager.hpp"

class BoundedIndexGenerator {
private:
    IndexManager indexMgr;
    int maxLimit; 

public:
    explicit BoundedIndexGenerator(int limit);
    BoundedIndexGenerator(const BoundedIndexGenerator& other);
    BoundedIndexGenerator& operator=(const BoundedIndexGenerator& other);
    ~BoundedIndexGenerator();
    int nextBoundedIndex();
};

#endif