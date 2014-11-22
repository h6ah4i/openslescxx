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

#ifndef OPENSLESCXX_CSL_PREFETCH_STATUS_ITF_HPP_
#define OPENSLESCXX_CSL_PREFETCH_STATUS_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Prefetch Status interface
//
class CSLPrefetchStatusItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLPrefetchStatusItf, SLPrefetchStatusItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_PREFETCHSTATUS; }

    CSLPrefetchStatusItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLPrefetchStatusItf() {}

    SLresult GetPrefetchStatus(SLuint32 *pStatus) noexcept { return (*self())->GetPrefetchStatus(self(), pStatus); }

    SLresult GetFillLevel(SLpermille *pLevel) noexcept { return (*self())->GetFillLevel(self(), pLevel); }

    SLresult RegisterCallback(slPrefetchCallback callback, void *pContext) noexcept
    {
        return (*self())->RegisterCallback(self(), callback, pContext);
    }

    SLresult SetCallbackEventsMask(SLuint32 eventFlags) noexcept
    {
        return (*self())->SetCallbackEventsMask(self(), eventFlags);
    }

    SLresult GetCallbackEventsMask(SLuint32 *pEventFlags) noexcept
    {
        return (*self())->GetCallbackEventsMask(self(), pEventFlags);
    }

    SLresult SetFillUpdatePeriod(SLpermille period) noexcept { return (*self())->SetFillUpdatePeriod(self(), period); }

    SLresult GetFillUpdatePeriod(SLpermille *pPeriod) noexcept
    {
        return (*self())->GetFillUpdatePeriod(self(), pPeriod);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_PREFETCH_STATUS_ITF_HPP_
