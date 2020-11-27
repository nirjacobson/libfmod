#include "generator.h"

float Generator::BASE_FREQUENCIES[] = {
    261.63,
    277.18,
    293.66,
    311.13,
    329.63,
    349.23,
    369.99,
    392.00,
    415.30,
    440.00,
    466.16,
    493.88
};

Generator::Generator(const int sampleRate)
    : _sampleSeconds(1.0f / sampleRate)
    , _algorithm(0)
    , _feedback(0)
{
    _algorithms[0] = new Algorithm0;
    _algorithms[1] = new Algorithm1;
    _algorithms[2] = new Algorithm2;
    _algorithms[3] = new Algorithm3;
    _algorithms[4] = new Algorithm4;
    _algorithms[5] = new Algorithm5;
    _algorithms[6] = new Algorithm6;
    _algorithms[7] = new Algorithm7;
}

Generator::~Generator()
{
    for (int i = 0; i < NUM_ALGORITHMS; i++) {
        delete _algorithms[i];
    }
}

float Generator::next()
{
    static bool left = true;
    static float output = 0.0f;

    if (left) {
        _keysMutex.lock();

        output = 0.0f;

        for (auto it = _keys.begin(); it != _keys.end();) {

            float freq = freqForKey(it->first);
            float seconds = _sampleSeconds * it->second.sampleCount;
            float secondsRelease = _sampleSeconds * it->second.sampleCountAtRelease;
            bool release = it->second.sampleCountAtRelease >= 0;

            output += _algorithms[_algorithm]->compute(
                        freq,
                        _feedback,
                        (release ? secondsRelease : -1),
                        seconds,
                        _operators);

            if (release && _algorithms[_algorithm]->isDone(_operators)) {
                it = _keys.erase(it);
            } else {
                it->second.sampleCount++;
                it++;
            }
        }
        output /= 10;

        _keysMutex.unlock();
    }

    left = !left;

    return output;
}

void Generator::keyOn(char key)
{
    _keysMutex.lock();

    std::map<char, Key>::iterator it;
    if ((it = _keys.find(key)) == _keys.end()) {
        if (_keys.size() == 5) {
            std::map<char, Key>::iterator it1 = std::max_element(_keys.begin(), _keys.end(), [](const std::pair<char, Key>& pair1, const std::pair<char, Key>& pair2) {
                return pair1.second.sampleCount > pair2.second.sampleCount;
            });
            _keys.erase(it1);
        }
        _keys.insert(std::pair<char, Key>(key, {0, -1}));
    } else {
        it->second = {0, -1};
    }

    _keysMutex.unlock();
}

void Generator::keyOff(const char key)
{
    _keysMutex.lock();

    std::map<char, Key>::iterator it;
    if ((it = _keys.find(key)) != _keys.end()) {
        it->second.sampleCountAtRelease = it->second.sampleCount;
    }

    _keysMutex.unlock();
}

void Generator::setEnvelope(const int op, const Envelope& e)
{
    assert(op < NUM_OPERATORS);

    _operators[op].setEnvelope(e);
}

void Generator::setAlgorithm(const int alg)
{
    _algorithm = alg;
}

void Generator::setFeedback(const int fb)
{
    _feedback = fb;
}

float Generator::freqForKey(const char key) const
{
    int octave = key / KEYS_PER_OCTAVE;
    int octaveDistance = octave - BASE_OCTAVE;

    float freq = BASE_FREQUENCIES[key % KEYS_PER_OCTAVE];
    if (octaveDistance < 0) {
        for (int i = 0; i > octaveDistance; i--) {
            freq /= 2.0f;
        }
    } else {
        for (int i = 0; i < octaveDistance; i++) {
            freq *= 2.0f;
        }
    }

    return freq;
}

