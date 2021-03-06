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

#ifndef OPENSLESCXX_CSL_VIRTUALIZER_ITF_HPP_
#define OPENSLESCXX_CSL_VIRTUALIZER_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Virtualizer Interface
//
class CSLVirtualizerItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLVirtualizerItf, SLVirtualizerItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_VIRTUALIZER; }

    CSLVirtualizerItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLVirtualizerItf() {}

    SLresult SetEnabled(SLboolean enabled) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetEnabled(self(), enabled);
    }

    SLresult IsEnabled(SLboolean *pEnabled) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->IsEnabled(self(), pEnabled);
    }

    SLresult SetStrength(SLpermille strength) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetStrength(self(), strength);
    }

    SLresult GetRoundedStrength(SLpermille *pStrength) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetRoundedStrength(self(), pStrength);
    }

    SLresult IsStrengthSupported(SLboolean *pSupported) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->IsStrengthSupported(self(), pSupported);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_VIRTUALIZER_ITF_HPP_
