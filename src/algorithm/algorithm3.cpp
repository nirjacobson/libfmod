#include "algorithm3.h"


float Algorithm3::compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators)
{
    float output =
            (Algorithm::series(freq, feedback, t1, t2, 0.0f, operators, 0, 1) +
             Algorithm::series(freq, feedback, t1, t2, 0.0f, operators, 1, 2)) / 2;

    output = Algorithm::series(freq, feedback, t1, t2, output, operators, 3, 3);

    return output;
}

bool Algorithm3::isDone(const Operator* operators) const
{
    return operators[3].output() >= 1;
}
