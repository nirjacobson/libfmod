#ifndef ALGORITHM5_H
#define ALGORITHM5_H

#include "algorithm.h"

class Algorithm5 : public Algorithm
{
public:
    float compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators);
    bool isDone(const Operator* operators) const;
};

#endif // ALGORITHM5_H
