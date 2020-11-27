#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "../operator.h"

class Algorithm
{
public:
    virtual ~Algorithm();

    virtual float compute(const float freq, const char feedback, const float t1, const float t2, Operator* operators) = 0;
    virtual bool isDone(const Operator* operators) const = 0;

protected:
   float series(const float freq, const char feedback, const float t1, const float t2, float amplitude, Operator* operators, int left, int right);

private:
   static constexpr float GAIN = -96.0f;

   float operator0(const float freq, const char feedback, const float t1, const float t2, Operator* operators);

};

#endif // ALGORITHM_H
