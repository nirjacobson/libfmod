#include "algorithm0.h"

float Algorithm0::compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators)
{
    return Algorithm::series(freq, feedback, t1, t2, 0.0f, operators, 0, 3);
}

bool Algorithm0::isDone(const Operator* operators) const
{
    return operators[3].output() >= 1;
}
