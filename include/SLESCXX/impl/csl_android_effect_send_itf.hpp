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

#ifndef OPENSLESCXX_CSL_ANDROID_EFFECT_SEND_ITF_HPP_
#define OPENSLESCXX_CSL_ANDROID_EFFECT_SEND_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>

#if OPENSLESCXX_USE_ANDROID_FEATURES

#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Android Effect Send interface
//
class CSLAndroidEffectSendItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLAndroidEffectSendItf, SLAndroidEffectSendItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_ANDROIDEFFECTSEND; }

    CSLAndroidEffectSendItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLAndroidEffectSendItf() {}

    SLresult EnableEffectSend(SLInterfaceID effectImplementationId, SLboolean enable, SLmillibel initialLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->EnableEffectSend(self(), effectImplementationId, enable, initialLevel);
    }

    SLresult IsEnabled(SLInterfaceID effectImplementationId, SLboolean *pEnable) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->IsEnabled(self(), effectImplementationId, pEnable);
    }

    SLresult SetDirectLevel(SLmillibel directLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetDirectLevel(self(), directLevel);
    }

    SLresult GetDirectLevel(SLmillibel *pDirectLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetDirectLevel(self(), pDirectLevel);
    }

    SLresult SetSendLevel(SLInterfaceID effectImplementationId, SLmillibel sendLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetSendLevel(self(), effectImplementationId, sendLevel);
    }

    SLresult GetSendLevel(SLInterfaceID effectImplementationId, SLmillibel *pSendLevel) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetSendLevel(self(), effectImplementationId, pSendLevel);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_USE_ANDROID_FEATURES

#endif // OPENSLESCXX_CSL_ANDROID_EFFECT_SEND_ITF_HPP_
