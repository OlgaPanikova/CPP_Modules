#ifndef INDEXMANAGER_HPP
#define INDEXMANAGER_HPP

#include <vector>
#include "JacobsthalGenerator.hpp"

class IndexManager {
private:
    int upperBound;
    int lowerBound;
    int activeIndex;
    JacobsthalGenerator jacobGen;

public:
    IndexManager();
    IndexManager(const IndexManager& copy);
    IndexManager& operator=(const IndexManager& other);
    ~IndexManager();
    int nextIndex();
};

#endif