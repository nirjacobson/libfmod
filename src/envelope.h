#ifndef ENVELOPE_H
#define ENVELOPE_H


class Envelope
{
public:
    Envelope();
    Envelope(const float ar, const float t1l, const float d1r, const float t2l, const float d2r, const float rr);

    float ar() const;
    float t1l() const;
    float d1r() const;
    float t2l() const;
    float d2r() const;
    float rr() const;

    void setAr(float ar);
    void setT1l(float t1l);
    void setD1r(float d1r);
    void setT2l(float t2l);
    void setD2r(float d2r);
    void setRr(float rr);

private:
    float _ar;
    float _t1l;
    float _d1r;
    float _t2l;
    float _d2r;
    float _rr;
};

#endif // ENVELOPE_H
