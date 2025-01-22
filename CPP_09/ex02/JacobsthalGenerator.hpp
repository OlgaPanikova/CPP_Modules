#ifndef JACOBSTHALGENERATOR_HPP
#define JACOBSTHALGENERATOR_HPP

#include <vector>

class JacobsthalGenerator {
private:
    int n2;
    int n1;

public:
    JacobsthalGenerator();
    JacobsthalGenerator(const JacobsthalGenerator& copy);
    JacobsthalGenerator& operator=(const JacobsthalGenerator& other);
    ~JacobsthalGenerator();
    int nextNumber();
};

#endif