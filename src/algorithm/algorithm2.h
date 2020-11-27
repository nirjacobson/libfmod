#ifndef ALGORITHM2_H
#define ALGORITHM2_H

#include "algorithm.h"

class Algorithm2 : public Algorithm
{
public:
    float compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators);
    bool isDone(const Operator* operators) const;
};

#endif // ALGORITHM2_H
