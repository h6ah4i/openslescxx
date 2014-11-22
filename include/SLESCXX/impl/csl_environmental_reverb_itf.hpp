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

#ifndef OPENSLESCXX_CSL_ENVIRONMENTAL_REVERB_ITF_HPP_
#define OPENSLESCXX_CSL_ENVIRONMENTAL_REVERB_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Environmental Reverb Interface
//
class CSLEnvironmentalReverbItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLEnvironmentalReverbItf, SLEnvironmentalReverbItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_ENVIRONMENTALREVERB; }

    CSLEnvironmentalReverbItf() : CSLInterface(sGetIID()) {}
    ~CSLEnvironmentalReverbItf() {}

    SLresult SetRoomLevel(SLmillibel room) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetRoomLevel(self(), room);
    }

    SLresult GetRoomLevel(SLmillibel *pRoom) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetRoomLevel(self(), pRoom);
    }

    SLresult SetRoomHFLevel(SLmillibel roomHF) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetRoomHFLevel(self(), roomHF);
    }

    SLresult GetRoomHFLevel(SLmillibel *pRoomHF) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetRoomHFLevel(self(), pRoomHF);
    }

    SLresult SetDecayTime(SLmillisecond decayTime) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetDecayTime(self(), decayTime);
    }

    SLresult GetDecayTime(SLmillisecond *pDecayTime) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetDecayTime(self(), pDecayTime);
    }

    SLresult SetDecayHFRatio(SLpermille decayHFRatio) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetDecayHFRatio(self(), decayHFRatio);
    }

    SLresult GetDecayHFRatio(SLpermille *pDecayHFRatio) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetDecayHFRatio(self(), pDecayHFRatio);
    }

    SLresult SetReflectionsLevel(SLmillibel reflectionsLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetReflectionsLevel(self(), reflectionsLevel);
    }

    SLresult GetReflectionsLevel(SLmillibel *pReflectionsLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetReflectionsLevel(self(), pReflectionsLevel);
    }

    SLresult SetReflectionsDelay(SLmillisecond reflectionsDelay) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetReflectionsDelay(self(), reflectionsDelay);
    }

    SLresult GetReflectionsDelay(SLmillisecond *pReflectionsDelay) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetReflectionsDelay(self(), pReflectionsDelay);
    }

    SLresult SetReverbLevel(SLmillibel reverbLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetReverbLevel(self(), reverbLevel);
    }

    SLresult GetReverbLevel(SLmillibel *pReverbLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetReverbLevel(self(), pReverbLevel);
    }

    SLresult SetReverbDelay(SLmillisecond reverbDelay) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetReverbDelay(self(), reverbDelay);
    }

    SLresult GetReverbDelay(SLmillisecond *pReverbDelay) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetReverbDelay(self(), pReverbDelay);
    }

    SLresult SetDiffusion(SLpermille diffusion) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetDiffusion(self(), diffusion);
    }

    SLresult GetDiffusion(SLpermille *pDiffusion) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetDiffusion(self(), pDiffusion);
    }

    SLresult SetDensity(SLpermille density) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetDensity(self(), density);
    }

    SLresult GetDensity(SLpermille *pDensity) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetDensity(self(), pDensity);
    }

    SLresult SetEnvironmentalReverbProperties(const SLEnvironmentalReverbSettings *pProperties) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetEnvironmentalReverbProperties(self(), pProperties);
    }

    SLresult GetEnvironmentalReverbProperties(SLEnvironmentalReverbSettings *pProperties) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetEnvironmentalReverbProperties(self(), pProperties);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_ENVIRONMENTAL_REVERB_ITF_HPP_
