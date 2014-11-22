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

#ifndef OPENSLESCXX_CSL_LED_ARRAY_ITF_HPP_
#define OPENSLESCXX_CSL_LED_ARRAY_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// LED Array interface
//
class CSLLEDArrayItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLLEDArrayItf, SLLEDArrayItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_LED; }

    CSLLEDArrayItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLLEDArrayItf() {}

    SLresult ActivateLEDArray(SLuint32 lightMask) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->ActivateLEDArray(self(), lightMask);
    }

    SLresult IsLEDArrayActivated(SLuint32 *lightMask) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->IsLEDArrayActivated(self(), lightMask);
    }

    SLresult SetColor(SLuint8 index, const SLHSL *color) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetColor(self(), index, color);
    }

    SLresult GetColor(SLuint8 index, SLHSL *color) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetColor(self(), index, color);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_LED_ARRAY_ITF_HPP_
