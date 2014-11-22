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

#ifndef OPENSLESCXX_CSL_MIDI_TIME_HPP_
#define OPENSLESCXX_CSL_MIDI_TIME_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Midi Time interface
//
class CSLMIDITimeItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLMIDITimeItf, SLMIDITimeItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_MIDITIME; }

    CSLMIDITimeItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLMIDITimeItf() {}

    SLresult GetDuration(SLuint32 *pDuration) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetDuration(self(), pDuration);
    }

    SLresult SetPosition(SLuint32 position) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetPosition(self(), position);
    }

    SLresult GetPosition(SLuint32 *pPosition) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetPosition(self(), pPosition);
    }

    SLresult SetLoopPoints(SLuint32 startTick, SLuint32 numTicks) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetLoopPoints(self(), startTick, numTicks);
    }

    SLresult GetLoopPoints(SLuint32 *pStartTick, SLuint32 *pNumTicks) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetLoopPoints(self(), pStartTick, pNumTicks);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_MIDI_TIME_HPP_
