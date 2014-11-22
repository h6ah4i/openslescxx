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

#ifndef OPENSLESCXX_CSL_3D_MACROSCOPIC_ITF_HPP_
#define OPENSLESCXX_CSL_3D_MACROSCOPIC_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// 3D Macroscopic Interface
//
class CSL3DMacroscopicItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSL3DMacroscopicItf, SL3DMacroscopicItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_3DMACROSCOPIC; }

    CSL3DMacroscopicItf() : CSLInterface(sGetIID()) {}
    virtual ~CSL3DMacroscopicItf() {}

    SLresult SetSize(SLmillimeter width, SLmillimeter height, SLmillimeter depth) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetSize(self(), width, height, depth);
    }

    SLresult GetSize(SLmillimeter *pWidth, SLmillimeter *pHeight, SLmillimeter *pDepth) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetSize(self(), pWidth, pHeight, pDepth);
    }

    SLresult SetOrientationAngles(SLmillidegree heading, SLmillidegree pitch, SLmillidegree roll) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetOrientationAngles(self(), heading, pitch, roll);
    }

    SLresult SetOrientationVectors(const SLVec3D *pFront, const SLVec3D *pAbove) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetOrientationVectors(self(), pFront, pAbove);
    }

    SLresult Rotate(SLmillidegree theta, const SLVec3D *pAxis) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->Rotate(self(), theta, pAxis);
    }

    SLresult GetOrientationVectors(SLVec3D *pFront, SLVec3D *pUp) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetOrientationVectors(self(), pFront, pUp);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_3D_MACROSCOPIC_ITF_HPP_
