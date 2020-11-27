#ifndef ALGORITHM6_H
#define ALGORITHM6_H

#include "algorithm.h"

class Algorithm6 : public Algorithm
{
public:
    // Algorithm interface
public:
    float compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators);
    bool isDone(const Operator* operators) const;
};

#endif // ALGORITHM6_H
