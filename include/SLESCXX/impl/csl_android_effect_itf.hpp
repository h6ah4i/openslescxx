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

#ifndef OPENSLESCXX_CSL_ANDROID_EFFECT_ITF_HPP_
#define OPENSLESCXX_CSL_ANDROID_EFFECT_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>

#if OPENSLESCXX_USE_ANDROID_FEATURES

#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Android Effect interface
//
class CSLAndroidEffectItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLAndroidEffectItf, SLAndroidEffectItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_ANDROIDEFFECT; }

    CSLAndroidEffectItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLAndroidEffectItf() {}

    SLresult CreateEffect(SLInterfaceID effectImplementationId) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->CreateEffect(self(), effectImplementationId);
    }

    SLresult ReleaseEffect(SLInterfaceID effectImplementationId) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->ReleaseEffect(self(), effectImplementationId);
    }

    SLresult SetEnabled(SLInterfaceID effectImplementationId, SLboolean enabled) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetEnabled(self(), effectImplementationId, enabled);
    }

    SLresult IsEnabled(SLInterfaceID effectImplementationId, SLboolean *pEnabled) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->IsEnabled(self(), effectImplementationId, pEnabled);
    }

    SLresult SendCommand(SLInterfaceID effectImplementationId, SLuint32 command, SLuint32 commandSize,
                         void *pCommandData, SLuint32 *replySize, void *pReplyData) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())
            ->SendCommand(self(), effectImplementationId, command, commandSize, pCommandData, replySize, pReplyData);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_USE_ANDROID_FEATURES

#endif // OPENSLESCXX_CSL_ANDROID_EFFECT_ITF_HPP_
