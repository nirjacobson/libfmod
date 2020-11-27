#ifndef ALGORITHM0_H
#define ALGORITHM0_H

#include "algorithm.h"

class Algorithm0 : public Algorithm
{
public:
    // Algorithm interface
public:
    float compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators);
    bool isDone(const Operator* operators) const;

};

#endif // ALGORITHM0_H
