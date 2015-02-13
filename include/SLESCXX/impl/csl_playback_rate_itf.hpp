//
//    Copyright (C) 2014-2015 Haruki Hasegawa
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

#ifndef OPENSLESCXX_CSL_PLAYBACK_RATE_ITF_HPP_
#define OPENSLESCXX_CSL_PLAYBACK_RATE_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// PlaybackRate interface
//
class CSLPlaybackRateItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLPlaybackRateItf, SLPlaybackRateItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_PLAYBACKRATE; }

    CSLPlaybackRateItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLPlaybackRateItf() {}

    SLresult SetRate(SLpermille rate)
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetRate(self(), rate);
    }

    SLresult GetRate(SLpermille *pRate)
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetRate(self(), pRate);
    }

    SLresult SetPropertyConstraints(SLuint32 constraints)
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetPropertyConstraints(self(), constraints);
    }

    SLresult GetProperties(SLuint32 *pProperties)
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetProperties(self(), pProperties);
    }

    SLresult GetCapabilitiesOfRate(SLpermille rate, SLuint32 *pCapabilities)
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetCapabilitiesOfRate(self(), rate, pCapabilities);
    }

    SLresult GetRateRange(SLuint8 index, SLpermille *pMinRate, SLpermille *pMaxRate, SLpermille *pStepSize,
                          SLuint32 *pCapabilities)
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetRateRange(self(), index, pMinRate, pMaxRate, pStepSize, pCapabilities);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_PLAYBACK_RATE_ITF_HPP_
