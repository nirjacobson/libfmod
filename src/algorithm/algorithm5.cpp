#include "algorithm5.h"

float Algorithm5::compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators)
{
    float output = Algorithm::series(freq, feedback, t1, t2, 0.0f, operators, 0, 0);

    output =
            (Algorithm::series(freq, feedback, t1, t2, 0.0f, operators, 1, 1) +
             Algorithm::series(freq, feedback, t1, t2, output, operators, 2, 2) +
             Algorithm::series(freq, feedback, t1, t2, 0.0f, operators, 3, 3)) / 3;

    return output;
}

bool Algorithm5::isDone(const Operator* operators) const
{
    return operators[1].output() >= 1 &&
           operators[2].output() >= 1 &&
           operators[3].output() >= 1;
}
