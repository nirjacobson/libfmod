#include "envelope.h"

Envelope::Envelope()
    : _ar(0)
    , _t1l(0)
    , _d1r(0)
    , _t2l(0)
    , _d2r(0)
    , _rr(0)
{

}

Envelope::Envelope(const float ar, const float t1l, const float d1r, const float t2l, const float d2r, const float rr)
    : _ar(ar)
    , _t1l(t1l)
    , _d1r(d1r)
    , _t2l(t2l)
    , _d2r(d2r)
    , _rr(rr)
{

}

float Envelope::ar() const
{
    return _ar;
}

float Envelope::t1l() const
{
    return _t1l;
}

float Envelope::d1r() const
{
    return _d1r;
}

float Envelope::t2l() const
{
    return _t2l;
}

float Envelope::d2r() const
{
    return _d2r;
}

float Envelope::rr() const
{
    return _rr;
}

void Envelope::setAr(float ar)
{
    _ar = ar;
}

void Envelope::setT1l(float t1l)
{
    _t1l = t1l;
}

void Envelope::setD1r(float d1r)
{
    _d1r = d1r;
}

void Envelope::setT2l(float t2l)
{
    _t2l = t2l;
}

void Envelope::setD2r(float d2r)
{
    _d2r = d2r;
}

void Envelope::setRr(float rr)
{
    _rr = rr;
}
