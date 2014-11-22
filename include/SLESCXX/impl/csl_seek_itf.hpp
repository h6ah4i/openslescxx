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

#ifndef OPENSLESCXX_CSL_SEEK_ITF_HPP_
#define OPENSLESCXX_CSL_SEEK_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Seek interface
//
class CSLSeekItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLSeekItf, SLSeekItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_SEEK; }

    CSLSeekItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLSeekItf() {}

    SLresult SetPosition(SLmillisecond pos, SLuint32 seekMode) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetPosition(self(), pos, seekMode);
    }

    SLresult SetLoop(SLboolean loopEnable, SLmillisecond startPos, SLmillisecond endPos) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetLoop(self(), loopEnable, startPos, endPos);
    }

    SLresult GetLoop(SLboolean *pLoopEnabled, SLmillisecond *pStartPos, SLmillisecond *pEndPos) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetLoop(self(), pLoopEnabled, pStartPos, pEndPos);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_SEEK_ITF_HPP_
