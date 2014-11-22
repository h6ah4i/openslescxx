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

#ifndef OPENSLESCXX_CSL_PLAY_ITF_HPP_
#define OPENSLESCXX_CSL_PLAY_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Playback interface
//
class CSLPlayItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLPlayItf, SLPlayItf);

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_PLAY; }

    CSLPlayItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLPlayItf() {}

    SLresult SetPlayState(SLuint32 state) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetPlayState(self(), state);
    }

    SLresult GetPlayState(SLuint32 *pState) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetPlayState(self(), pState);
    }

    SLresult GetDuration(SLmillisecond *pMsec) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetDuration(self(), pMsec);
    }

    SLresult GetPosition(SLmillisecond *pMsec) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetPosition(self(), pMsec);
    }

    SLresult RegisterCallback(slPlayCallback callback, void *pContext) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->RegisterCallback(self(), callback, pContext);
    }

    SLresult SetCallbackEventsMask(SLuint32 eventFlags) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetCallbackEventsMask(self(), eventFlags);
    }

    SLresult GetCallbackEventsMask(SLuint32 *pEventFlags) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetCallbackEventsMask(self(), pEventFlags);
    }

    SLresult SetMarkerPosition(SLmillisecond mSec) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetMarkerPosition(self(), mSec);
    }

    SLresult ClearMarkerPosition() noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->ClearMarkerPosition(self());
    }

    SLresult GetMarkerPosition(SLmillisecond *pMsec) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetMarkerPosition(self(), pMsec);
    }

    SLresult SetPositionUpdatePeriod(SLmillisecond mSec) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetPositionUpdatePeriod(self(), mSec);
    }

    SLresult GetPositionUpdatePeriod(SLmillisecond *pMsec) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetPositionUpdatePeriod(self(), pMsec);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_PLAY_ITF_HPP_
