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

#ifndef OPENSLESCXX_CSL_MIDI_MESSAGE_ITF_HPP_
#define OPENSLESCXX_CSL_MIDI_MESSAGE_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Midi Message interface
//
class CSLMIDIMessageItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLMIDIMessageItf, SLMIDIMessageItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_MIDIMESSAGE; }

    CSLMIDIMessageItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLMIDIMessageItf() {}

    SLresult SendMessage(const SLuint8 *data, SLuint32 length) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SendMessage(self(), data, length);
    }

    SLresult RegisterMetaEventCallback(slMetaEventCallback callback, void *pContext) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->RegisterMetaEventCallback(self(), callback, pContext);
    }

    SLresult RegisterMIDIMessageCallback(slMIDIMessageCallback callback, void *pContext) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->RegisterMIDIMessageCallback(self(), callback, pContext);
    }

    SLresult AddMIDIMessageCallbackFilter(SLuint32 messageType) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->AddMIDIMessageCallbackFilter(self(), messageType);
    }

    SLresult ClearMIDIMessageCallbackFilter() noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->ClearMIDIMessageCallbackFilter(self());
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_MIDI_MESSAGE_ITF_HPP_
