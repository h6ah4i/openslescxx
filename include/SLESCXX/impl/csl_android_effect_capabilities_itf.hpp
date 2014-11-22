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

#ifndef OPENSLESCXX_CSL_ANDROID_EFFECT_CAPABILITIES_ITF_HPP_
#define OPENSLESCXX_CSL_ANDROID_EFFECT_CAPABILITIES_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>

#if OPENSLESCXX_USE_ANDROID_FEATURES

#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Android Effect Capabilities interface
//
class CSLAndroidEffectCapabilitiesItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLAndroidEffectCapabilitiesItf, SLAndroidEffectCapabilitiesItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_ANDROIDEFFECTCAPABILITIES; }

    CSLAndroidEffectCapabilitiesItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLAndroidEffectCapabilitiesItf() {}

    SLresult QueryNumEffects(SLuint32 *pNumSupportedEffects) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryNumEffects(self(), pNumSupportedEffects);
    }

    SLresult QueryEffect(SLuint32 index, SLInterfaceID *pEffectType, SLInterfaceID *pEffectImplementation,
                         SLchar *pName, SLuint16 *pNameSize) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryEffect(self(), index, pEffectType, pEffectImplementation, pName, pNameSize);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_USE_ANDROID_FEATURES

#endif // OPENSLESCXX_CSL_ANDROID_EFFECT_CAPABILITIES_ITF_HPP_
