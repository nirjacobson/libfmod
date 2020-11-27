#ifndef PATCHFILE_H
#define PATCHFILE_H

#include <assert.h>
#include <string>
#include <fstream>

#include "envelope.h"

class PatchFile
{
public:
    PatchFile(const std::string& file);

    void setEnvelope(const int i, const Envelope& e);
    void setAlgorithm(const int alg);
    void setFeedback(const int fb);

    const Envelope& envelope(const int i) const;
    char algorithm() const;
    char feedback() const;

    bool exists() const;
    void read();
    void write();

private:
    static constexpr int NUM_ENVELOPES = 4;
    Envelope _envelopes[NUM_ENVELOPES];
    int _algorithm;
    char _feedback;

    std::string _file;
};

#endif // PATCHFILE_H
