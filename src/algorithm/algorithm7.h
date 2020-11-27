#ifndef ALGORITHM7_H
#define ALGORITHM7_H

#include "algorithm.h"

class Algorithm7 : public Algorithm
{
public:
    // Algorithm interface
public:
    float compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators);
    bool isDone(const Operator* operators) const;
};

#endif // ALGORITHM7_H
