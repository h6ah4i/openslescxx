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

#ifndef OPENSLESCXX_CSL_OBJECT_ITF_HPP_
#define OPENSLESCXX_CSL_OBJECT_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Standard Object Interface
//
class CSLObjectItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLObjectItf, SLObjectItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_OBJECT; }

    explicit CSLObjectItf(bool autoDestroy = true) : CSLInterface(sGetIID()), autoDestroy_(autoDestroy) {}

    virtual ~CSLObjectItf()
    {
        if (autoDestroy_) {
            Destroy();
        }
    }

    bool autoDestroy() const { return autoDestroy_; }

    SLresult Realize(SLboolean async) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->Realize(self(), async);
    }

    SLresult Resume(SLboolean async) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->Resume(self(), async);
    }

    SLresult GetState(SLuint32 *pState) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetState(self(), pState);
    }

    SLresult GetInterface(const SLInterfaceID iid, void *pInterface) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetInterface(self(), iid, pInterface);
    }

    SLresult GetInterface(CSLInterface *pInterface) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        if (!pInterface)
            return SL_RESULT_PARAMETER_INVALID;
        return (*self())->GetInterface(self(), pInterface->getIID(), pInterface->rawPtrEntity());
    }

    SLresult RegisterCallback(slObjectCallback callback, void *pContext) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->RegisterCallback(self(), callback, pContext);
    }

    void AbortAsyncOperation() noexcept
    {
        if (!self())
            return;
        (*self())->AbortAsyncOperation(self());
    }

    void Destroy() noexcept
    {

        if (!self())
            return;

        (*self())->Destroy(self());
        unbind();
    }

    SLresult SetPriority(SLint32 priority, SLboolean preemptable) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetPriority(self(), priority, preemptable);
    }

    SLresult GetPriority(SLint32 *pPriority, SLboolean *pPreemptable) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetPriority(self(), pPriority, pPreemptable);
    }

    SLresult SetLossOfControlInterfaces(SLint16 numInterfaces, SLInterfaceID *pInterfaceIDs, SLboolean enabled) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetLossOfControlInterfaces(self(), numInterfaces, pInterfaceIDs, enabled);
    }

protected:
    virtual void onMove(CSLInterface &other) noexcept override
    {
        CSLInterface::onMove(other);
        this->autoDestroy_ = dynamic_cast<CSLObjectItf &>(other).autoDestroy_;
    }

    virtual void onDetachEntity(bool unbind) noexcept override
    {

        if (!unbind && autoDestroy_) {
            Destroy();
        } else {
            CSLInterface::onDetachEntity(unbind);
        }
    }

    bool autoDestroy_;
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_OBJECT_ITF_HPP_
