#include "algorithm.h"

Algorithm::~Algorithm()
{

}

float Algorithm::operator0(const float freq, const char feedback, const float t1, const float t2, Operator* operators)
{
    bool release = t1 >= 0;
    float cycles = freq * t2;
    float cycleFraction;
    float baseOutput;
    float gain;
    float amplitude = 0.0;

    for (int i = 0; i < feedback + 1; i++) {
        cycleFraction = fmod(cycles + amplitude, 1.0);
        baseOutput = sin(cycleFraction * 2 * M_PI);

        if (release) {
            gain = GAIN * operators[0].released(t1, t2);
        } else {
            gain = GAIN * operators[0].pressed(t2);
        }
        amplitude = baseOutput * pow(10, gain / 20.0f);
    }

    return amplitude;
}

float Algorithm::series(const float freq, const char feedback, const float t1, const float t2, float amplitude, Operator* operators, int left, int right)
{
    bool release = t1 >= 0;
    float cycles = freq * t2;
    float cycleFraction;
    float baseOutput;
    float gain;

    if (left == 0) {
        amplitude = operator0(freq, feedback, t1, t2, operators);
    }

    for (int i = (left == 0 ? 1 : left); i <= right; i++) {
        cycleFraction = fmod(cycles + amplitude, 1.0);
        baseOutput = sin(cycleFraction * 2 * M_PI);

        if (release) {
            gain = GAIN * operators[i].released(t1, t2);
        } else {
            gain = GAIN * operators[i].pressed(t2);
        }

        amplitude = baseOutput * pow(10, gain / 20.0f);
    }

    return amplitude;
}
