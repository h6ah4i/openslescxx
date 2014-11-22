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

#ifndef OPENSLESCXX_CSL_BUFFER_QUEUE_ITF_HPP_
#define OPENSLESCXX_CSL_BUFFER_QUEUE_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Buffer Queue interface
//
class CSLBufferQueueItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLBufferQueueItf, SLBufferQueueItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_BUFFERQUEUE; }

    CSLBufferQueueItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLBufferQueueItf() noexcept {}

    SLresult Enqueue(const void *pBuffer, SLuint32 size) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->Enqueue(self(), pBuffer, size);
    }

    SLresult Clear() noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->Clear(self());
    }

    SLresult GetState(SLBufferQueueState *pState) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetState(self(), pState);
    }

    SLresult RegisterCallback(slBufferQueueCallback callback, void *pContext) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->RegisterCallback(self(), callback, pContext);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_BUFFER_QUEUE_ITF_HPP_
