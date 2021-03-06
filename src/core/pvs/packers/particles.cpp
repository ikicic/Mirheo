#include "particles.h"

#include <core/pvs/particle_vector.h>

ParticlePacker::ParticlePacker(PackPredicate predicate) :
    predicate(predicate)
{}

ParticlePacker::~ParticlePacker() = default;

void ParticlePacker::update(LocalParticleVector *lpv, cudaStream_t stream)
{
    particleData.updateChannels(lpv->dataPerParticle, predicate, stream);
}

ParticlePackerHandler ParticlePacker::handler()
{
    return {particleData.handler()};
}

size_t ParticlePacker::getSizeBytes(int numElements) const
{
    return particleData.getSizeBytes(numElements);
}
