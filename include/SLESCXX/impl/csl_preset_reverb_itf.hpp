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

#ifndef OPENSLESCXX_CSL_PRESET_REVERB_ITF_HPP_
#define OPENSLESCXX_CSL_PRESET_REVERB_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// PresetReverb
//
class CSLPresetReverbItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLPresetReverbItf, SLPresetReverbItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_PRESETREVERB; }

    CSLPresetReverbItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLPresetReverbItf() {}

    SLresult SetPreset(SLuint16 preset) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetPreset(self(), preset);
    }

    SLresult GetPreset(SLuint16 *pPreset) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetPreset(self(), pPreset);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_PRESET_REVERB_ITF_HPP_
