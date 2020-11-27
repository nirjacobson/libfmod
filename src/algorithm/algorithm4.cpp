#include "algorithm4.h"


float Algorithm4::compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators)
{
    float output =
            (Algorithm::series(freq, feedback, t1, t2, 0.0f, operators, 0, 1) +
             Algorithm::series(freq, feedback, t1, t2, 0.0f, operators, 2, 3)) / 2;

    return output;
}

bool Algorithm4::isDone(const Operator* operators) const
{
    return operators[1].output() >= 1 &&
           operators[3].output() >= 1;
}
