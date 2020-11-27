#ifndef ALGORITHM4_H
#define ALGORITHM4_H

#include "algorithm.h"

class Algorithm4 : public Algorithm
{
public:
    float compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators);
    bool isDone(const Operator* operators) const;
};

#endif // ALGORITHM4_H
