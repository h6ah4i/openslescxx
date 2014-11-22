//
//    Copyright (C) 2014 Haruki Hasegawa
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//

#ifndef OPENSLESCXX_CSL_MIDI_TEMPO_HPP_
#define OPENSLESCXX_CSL_MIDI_TEMPO_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Midi Tempo interface
//
class CSLMIDITempoItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLMIDITempoItf, SLMIDITempoItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_MIDITEMPO; }

    CSLMIDITempoItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLMIDITempoItf() {}

    SLresult SetTicksPerQuarterNote(SLuint32 tpqn) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetTicksPerQuarterNote(self(), tpqn);
    }

    SLresult GetTicksPerQuarterNote(SLuint32 *pTpqn) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetTicksPerQuarterNote(self(), pTpqn);
    }

    SLresult SetMicrosecondsPerQuarterNote(SLmicrosecond uspqn) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetMicrosecondsPerQuarterNote(self(), uspqn);
    }

    SLresult GetMicrosecondsPerQuarterNote(SLmicrosecond *uspqn) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetMicrosecondsPerQuarterNote(self(), uspqn);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_MIDI_TEMPO_HPP_
