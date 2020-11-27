#include "patchfile.h"

PatchFile::PatchFile(const std::string& file)
    : _file(file)
{

}

void PatchFile::setEnvelope(const int i, const Envelope& e)
{
    assert(i < NUM_ENVELOPES);
    _envelopes[i] = e;
}

void PatchFile::setAlgorithm(const int alg)
{
    _algorithm = alg;
}

void PatchFile::setFeedback(const int fb)
{
    _feedback = fb;
}

const Envelope& PatchFile::envelope(const int i) const
{
    assert(i < NUM_ENVELOPES);
    return _envelopes[i];
}

char PatchFile::algorithm() const
{
    return _algorithm;
}

char PatchFile::feedback() const
{
    return _feedback;
}

bool PatchFile::exists() const
{
    std::ifstream in(_file);
    return in.good();
}

void PatchFile::read()
{
    std::ifstream in(_file);
    in.read((char*)this, sizeof(PatchFile));
    in.close();
}

void PatchFile::write()
{
    std::ofstream out(_file, std::ios::trunc);
    out.write((char*)this, sizeof(PatchFile));
    out.flush();
    out.close();
}
