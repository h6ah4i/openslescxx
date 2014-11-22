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

#ifndef OPENSLESCXX_CSL_MUTE_SOLO_ITF_HPP_
#define OPENSLESCXX_CSL_MUTE_SOLO_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Mute Solo interface
//
class CSLMuteSoloItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLMuteSoloItf, SLMuteSoloItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_MUTESOLO; }

    CSLMuteSoloItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLMuteSoloItf() {}

    SLresult SetChannelMute(SLuint8 chan, SLboolean mute) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetChannelMute(self(), chan, mute);
    }

    SLresult GetChannelMute(SLuint8 chan, SLboolean *pMute) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetChannelMute(self(), chan, pMute);
    }

    SLresult SetChannelSolo(SLuint8 chan, SLboolean solo) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetChannelSolo(self(), chan, solo);
    }

    SLresult GetChannelSolo(SLuint8 chan, SLboolean *pSolo) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetChannelSolo(self(), chan, pSolo);
    }

    SLresult GetNumChannels(SLuint8 *pNumChannels) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetNumChannels(self(), pNumChannels);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_MUTE_SOLO_ITF_HPP_
