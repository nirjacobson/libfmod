#ifndef ALGORITHM1_H
#define ALGORITHM1_H

#include "algorithm.h"

class Algorithm1 : public Algorithm
{
public:
    float compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators);
    bool isDone(const Operator* operators) const;
};

#endif // ALGORITHM1_H
