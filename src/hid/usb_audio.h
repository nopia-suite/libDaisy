#pragma once

#include <cstdlib>
#include <cstdint>

namespace daisy
{

// Lightweight abstraction for handling tusb audio
// Currently only handles Tx for exactly 4 channels, no Rx
// and a single sample rate
class USBAudioHandle
{
  public:
    USBAudioHandle()  = default;
    ~USBAudioHandle() = default;

    // Should match audio callback blocksize - cannot change
    void Init(uint32_t blocksize);

    // Call these in order
    void Prepare();
    void ProcessChannel(uint32_t     idx,
                        const float* samples,
                        uint32_t     size,
                        uint32_t     offset = 0);
    void WriteToEndpoint();
};
} // namespace daisy
