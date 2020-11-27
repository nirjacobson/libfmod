#ifndef OPERATOR_H
#define OPERATOR_H

#include <math.h>
#include <algorithm>

#include "envelope.h"

class Operator
{
public:
    Operator();

    void setEnvelope(const Envelope& e);
    float pressed(const float time);
    float released(const float releaseTime, const float time);

    float output() const;

private:
    struct Point {
        float x;
        float y;
    };

    Envelope _envelope;
    float _rrSlope;
    float _output;

    Point _p1;
    Point _p2;
    Point _p3;


};

#endif // OPERATOR_H
