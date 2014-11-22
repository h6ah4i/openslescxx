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

#ifndef OPENSLESCXX_CSL_VOLUME_ITF_HPP_
#define OPENSLESCXX_CSL_VOLUME_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Volume interface
//
class CSLVolumeItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLVolumeItf, SLVolumeItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_VOLUME; }

    CSLVolumeItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLVolumeItf() {}

    SLresult SetVolumeLevel(SLmillibel level) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetVolumeLevel(self(), level);
    }

    SLresult GetVolumeLevel(SLmillibel *pLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetVolumeLevel(self(), pLevel);
    }

    SLresult GetMaxVolumeLevel(SLmillibel *pMaxLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetMaxVolumeLevel(self(), pMaxLevel);
    }

    SLresult SetMute(SLboolean mute) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetMute(self(), mute);
    }

    SLresult GetMute(SLboolean *pMute) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetMute(self(), pMute);
    }

    SLresult EnableStereoPosition(SLboolean enable) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->EnableStereoPosition(self(), enable);
    }

    SLresult IsEnabledStereoPosition(SLboolean *pEnable) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->IsEnabledStereoPosition(self(), pEnable);
    }

    SLresult SetStereoPosition(SLpermille stereoPosition) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetStereoPosition(self(), stereoPosition);
    }

    SLresult GetStereoPosition(SLpermille *pStereoPosition) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetStereoPosition(self(), pStereoPosition);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_VOLUME_ITF_HPP_
