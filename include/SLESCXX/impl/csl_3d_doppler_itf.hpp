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

#ifndef OPENSLESCXX_CSL_3D_DOPPLER_ITF_HPP_
#define OPENSLESCXX_CSL_3D_DOPPLER_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// 3D Doppler Interface
//
class CSL3DDopplerItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSL3DDopplerItf, SL3DDopplerItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_3DDOPPLER; }

    CSL3DDopplerItf() : CSLInterface(sGetIID()) {}
    virtual ~CSL3DDopplerItf() {}

    SLresult SetVelocityCartesian(const SLVec3D *pVelocity) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetVelocityCartesian(self(), pVelocity);
    }

    SLresult SetVelocitySpherical(SLmillidegree azimuth, SLmillidegree elevation, SLmillimeter speed) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetVelocitySpherical(self(), azimuth, elevation, speed);
    }

    SLresult GetVelocityCartesian(SLVec3D *pVelocity) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetVelocityCartesian(self(), pVelocity);
    }

    SLresult SetDopplerFactor(SLpermille dopplerFactor) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetDopplerFactor(self(), dopplerFactor);
    }

    SLresult GetDopplerFactor(SLpermille *pDopplerFactor) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetDopplerFactor(self(), pDopplerFactor);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_3D_DOPPLER_ITF_HPP_
