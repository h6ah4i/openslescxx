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

#ifndef OPENSLESCXX_CSL_3D_SOURCE_ITF_HPP_
#define OPENSLESCXX_CSL_3D_SOURCE_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// 3D Source Interface
//
class CSL3DSourceItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSL3DSourceItf, SL3DSourceItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_3DSOURCE; }

    CSL3DSourceItf() : CSLInterface(sGetIID()) {}
    virtual ~CSL3DSourceItf() {}

    SLresult SetHeadRelative(SLboolean headRelative) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetHeadRelative(self(), headRelative);
    }

    SLresult GetHeadRelative(SLboolean *pHeadRelative) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetHeadRelative(self(), pHeadRelative);
    }

    SLresult SetRolloffDistances(SLmillimeter minDistance, SLmillimeter maxDistance) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetRolloffDistances(self(), minDistance, maxDistance);
    }

    SLresult GetRolloffDistances(SLmillimeter *pMinDistance, SLmillimeter *pMaxDistance) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetRolloffDistances(self(), pMinDistance, pMaxDistance);
    }

    SLresult SetRolloffMaxDistanceMute(SLboolean mute) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetRolloffMaxDistanceMute(self(), mute);
    }

    SLresult GetRolloffMaxDistanceMute(SLboolean *pMute) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetRolloffMaxDistanceMute(self(), pMute);
    }

    SLresult SetRolloffFactor(SLpermille rolloffFactor) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetRolloffFactor(self(), rolloffFactor);
    }

    SLresult GetRolloffFactor(SLpermille *pRolloffFactor) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetRolloffFactor(self(), pRolloffFactor);
    }

    SLresult SetRoomRolloffFactor(SLpermille roomRolloffFactor) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetRoomRolloffFactor(self(), roomRolloffFactor);
    }

    SLresult GetRoomRolloffFactor(SLpermille *pRoomRolloffFactor) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetRoomRolloffFactor(self(), pRoomRolloffFactor);
    }

    SLresult SetRolloffModel(SLuint8 model) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetRolloffModel(self(), model);
    }

    SLresult GetRolloffModel(SLuint8 *pModel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetRolloffModel(self(), pModel);
    }

    SLresult SetCone(SLmillidegree innerAngle, SLmillidegree outerAngle, SLmillibel outerLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetCone(self(), innerAngle, outerAngle, outerLevel);
    }

    SLresult GetCone(SLmillidegree *pInnerAngle, SLmillidegree *pOuterAngle, SLmillibel *pOuterLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetCone(self(), pInnerAngle, pOuterAngle, pOuterLevel);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_3D_SOURCE_ITF_HPP_
