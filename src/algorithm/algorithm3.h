#ifndef ALGORITHM3_H
#define ALGORITHM3_H

#include "algorithm.h"

class Algorithm3 : public Algorithm
{
public:
    float compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators);
    bool isDone(const Operator* operators) const;
};

#endif // ALGORITHM3_H
