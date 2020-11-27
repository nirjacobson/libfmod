#ifndef GENERATOR_H
#define GENERATOR_H

#include <assert.h>
#include <math.h>
#include <map>
#include <mutex>
#include <fstream>

#include "producer.h"
#include "operator.h"
#include "algorithm/algorithm.h"
#include "algorithm/algorithm0.h"
#include "algorithm/algorithm1.h"
#include "algorithm/algorithm2.h"
#include "algorithm/algorithm3.h"
#include "algorithm/algorithm4.h"
#include "algorithm/algorithm5.h"
#include "algorithm/algorithm6.h"
#include "algorithm/algorithm7.h"

class Generator : public Producer<float>
{
public:

    struct Key {
        long sampleCount;
        long sampleCountAtRelease;
    };

    Generator(const int sampleRate);
    ~Generator();

    float next();

    void keyOn(char key);
    void keyOff(const char key);

    void setEnvelope(const int op, const Envelope& e);
    void setAlgorithm(const int alg);
    void setFeedback(const int fb);

    // Producer interface
private:
    static constexpr int NUM_ALGORITHMS = 8;
    static constexpr int NUM_OPERATORS = 4;
    static constexpr int BASE_OCTAVE = 4;
    static constexpr float GAIN = -96.0f;
    static constexpr int KEYS_PER_OCTAVE = 12;
    static float BASE_FREQUENCIES[KEYS_PER_OCTAVE];

    float _sampleSeconds;

    std::map<char, Key> _keys;
    std::mutex _keysMutex;

    Operator _operators[NUM_OPERATORS];
    Algorithm* _algorithms[NUM_ALGORITHMS];
    int _algorithm;
    int _feedback;

    float freqForKey(const char key) const;
};

#endif // GENERATOR_H
