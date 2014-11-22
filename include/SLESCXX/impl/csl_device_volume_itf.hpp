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

#ifndef OPENSLESCXX_CSL_DEVICE_VOLUME_ITF_HPP_
#define OPENSLESCXX_CSL_DEVICE_VOLUME_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Device Volume Interface
//
class CSLDeviceVolumeItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLDeviceVolumeItf, SLDeviceVolumeItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_DEVICEVOLUME; }

    CSLDeviceVolumeItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLDeviceVolumeItf() {}

    SLresult GetVolumeScale(SLuint32 deviceID, SLint32 *pMinValue, SLint32 *pMaxValue,
                            SLboolean *pIsMillibelScale) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetVolumeScale(self(), deviceID, pMinValue, pMaxValue, pIsMillibelScale);
    }

    SLresult SetVolume(SLuint32 deviceID, SLint32 volume) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetVolume(self(), deviceID, volume);
    }

    SLresult GetVolume(SLuint32 deviceID, SLint32 *pVolume) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetVolume(self(), deviceID, pVolume);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_DEVICE_VOLUME_ITF_HPP_
