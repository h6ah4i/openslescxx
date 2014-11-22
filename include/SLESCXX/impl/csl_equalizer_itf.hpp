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

#ifndef OPENSLESCXX_CSL_EQUALIZER_ITF_HPP_
#define OPENSLESCXX_CSL_EQUALIZER_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Equalizer interface
//
class CSLEqualizerItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLEqualizerItf, SLEqualizerItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_EQUALIZER; }

    CSLEqualizerItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLEqualizerItf() {}

    SLresult SetEnabled(SLboolean enabled) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetEnabled(self(), enabled);
    }

    SLresult IsEnabled(SLboolean *pEnabled) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->IsEnabled(self(), pEnabled);
    }

    SLresult GetNumberOfBands(SLuint16 *pAmount) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetNumberOfBands(self(), pAmount);
    }

    SLresult GetBandLevelRange(SLmillibel *pMin, SLmillibel *pMax) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetBandLevelRange(self(), pMin, pMax);
    }

    SLresult SetBandLevel(SLuint16 band, SLmillibel level) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetBandLevel(self(), band, level);
    }

    SLresult GetBandLevel(SLuint16 band, SLmillibel *pLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetBandLevel(self(), band, pLevel);
    }

    SLresult GetCenterFreq(SLuint16 band, SLmilliHertz *pCenter) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetCenterFreq(self(), band, pCenter);
    }

    SLresult GetBandFreqRange(SLuint16 band, SLmilliHertz *pMin, SLmilliHertz *pMax) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetBandFreqRange(self(), band, pMin, pMax);
    }

    SLresult GetBand(SLmilliHertz frequency, SLuint16 *pBand) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetBand(self(), frequency, pBand);
    }

    SLresult GetCurrentPreset(SLuint16 *pPreset) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetCurrentPreset(self(), pPreset);
    }

    SLresult UsePreset(SLuint16 index) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->UsePreset(self(), index);
    }

    SLresult GetNumberOfPresets(SLuint16 *pNumPresets) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetNumberOfPresets(self(), pNumPresets);
    }

    SLresult GetPresetName(SLuint16 index, const SLchar **ppName) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetPresetName(self(), index, ppName);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_EQUALIZER_ITF_HPP_
