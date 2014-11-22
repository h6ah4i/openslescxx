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

#ifndef OPENSLESCXX_CSL_ENGINE_CAPABILITIES_ITF_HPP_
#define OPENSLESCXX_CSL_ENGINE_CAPABILITIES_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Engine Capabilities Interface
//
class CSLEngineCapabilitiesItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLEngineCapabilitiesItf, SLEngineCapabilitiesItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_ENGINECAPABILITIES; }

    CSLEngineCapabilitiesItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLEngineCapabilitiesItf() {}

    SLresult QuerySupportedProfiles(SLuint16 *pProfilesSupported) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QuerySupportedProfiles(self(), pProfilesSupported);
    }

    SLresult QueryAvailableVoices(SLuint16 voiceType, SLint16 *pNumMaxVoices, SLboolean *pIsAbsoluteMax,
                                  SLint16 *pNumFreeVoices) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryAvailableVoices(self(), voiceType, pNumMaxVoices, pIsAbsoluteMax, pNumFreeVoices);
    }

    SLresult QueryNumberOfMIDISynthesizers(SLint16 *pNumMIDIsynthesizers) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryNumberOfMIDISynthesizers(self(), pNumMIDIsynthesizers);
    }

    SLresult QueryAPIVersion(SLint16 *pMajor, SLint16 *pMinor, SLint16 *pStep) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryAPIVersion(self(), pMajor, pMinor, pStep);
    }

    SLresult QueryLEDCapabilities(SLuint32 *pIndex, SLuint32 *pLEDDeviceID, SLLEDDescriptor *pDescriptor) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryLEDCapabilities(self(), pIndex, pLEDDeviceID, pDescriptor);
    }

    SLresult QueryVibraCapabilities(SLuint32 *pIndex, SLuint32 *pVibraDeviceID, SLVibraDescriptor *pDescriptor) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryVibraCapabilities(self(), pIndex, pVibraDeviceID, pDescriptor);
    }

    SLresult IsThreadSafe(SLboolean *pIsThreadSafe) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->IsThreadSafe(self(), pIsThreadSafe);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_ENGINE_CAPABILITIES_ITF_HPP_
