#include "operator.h"

Operator::Operator()
    : _output(1)
    , _p1({-1, -1})
    , _p2({-1, -1})
    , _p3({-1, -1})
{

}

void Operator::setEnvelope(const Envelope& e)
{
    _envelope = e;
    _rrSlope = tan(M_PI_2 * _envelope.rr());

    _p1 = {-1, -1};
    _p2 = {-1, -1};
    _p3 = {-1, -1};

    if (_envelope.ar() > 0) {
        _p1.y = _envelope.t1l();
        if (_envelope.ar() == 1) {
            _p1.x = 0;
        } else {
            const float theta = M_PI_2 * _envelope.ar();
            _p1.x = (1 - _p1.y) / tan(theta);
        }

        if (_envelope.d1r() > 0) {
            _p2.y = _p1.y + _envelope.t2l() * (1 - _p1.y);
            if (_envelope.d1r() == 1) {
                _p2.x = _p1.x;
            } else {
                const float theta = M_PI_2 * _envelope.d1r();
                _p2.x = _p1.x + (_p2.y - _p1.y) / tan(theta);
            }

            if (_envelope.d2r() > 0) {
                _p3.y = 1;
                if (_envelope.d2r() == 1) {
                    _p3.x = _p2.x;
                } else {
                    const float theta = M_PI_2 * _envelope.d2r();
                    _p3.x = _p2.x + (1 - _p2.y) / tan(theta);
                }
            }
        }
    }
}

float Operator::pressed(const float time)
{
    float x = time / 2.0f;
    float t1l = _envelope.t1l();
    float t2l = _envelope.t1l() + (1 - _envelope.t1l()) * _envelope.t2l();

    float output = 1;

    if (_p1.x >= 0) {
        if (x <= _p1.x) {
            // Attack
            output = t1l + ((1 - _p1.y) / _p1.x) * (_p1.x - x);
        } else {
            if (_p2.x > 0) {
                if (x <= _p2.x) {
                    // D1
                    output = t1l + ((t2l - t1l) / (_p2.x - _p1.x)) * (x - _p1.x);
                } else {
                    if (_p3.x > 0) {
                        if (x <= _p3.x) {
                            // D2
                            output = t2l + ((1 - t2l) / (_p3.x - _p2.x)) * (x - _p2.x);
                        } else {
                            output = 1;
                        }
                    } else {
                        output = t2l;
                    }
                }
            } else {
                output = t1l;
            }
        }
    }

    return (_output = output);

}

float Operator::released(const float releaseTime, const float time)
{
    float releaseX = releaseTime / 2.0f;
    float x = time / 2.0f;

    float atRelease = pressed(releaseX);

    float output = 1;

    if (_envelope.rr() > 0) {
        if (_envelope.rr() < 1) {
            output = std::min(1.0f, atRelease + _rrSlope * (x - releaseX));
        }
    } else {
        output = atRelease;
    }

    return (_output = output);
}

float Operator::output() const
{
    return _output;
}
