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

#ifndef OPENSLESCXX_CSL_DYNAMIC_INTERFACE_MANAGEMENT_ITF_HPP_
#define OPENSLESCXX_CSL_DYNAMIC_INTERFACE_MANAGEMENT_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Dynamic Interface Management interface
//
class CSLDynamicInterfaceManagementItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLDynamicInterfaceManagementItf, SLDynamicInterfaceManagementItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_DYNAMICINTERFACEMANAGEMENT; }

    CSLDynamicInterfaceManagementItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLDynamicInterfaceManagementItf() {}

    SLresult AddInterface(const SLInterfaceID iid, SLboolean async) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->AddInterface(self(), iid, async);
    }

    SLresult RemoveInterface(const SLInterfaceID iid) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->RemoveInterface(self(), iid);
    }

    SLresult ResumeInterface(const SLInterfaceID iid, SLboolean async) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->ResumeInterface(self(), iid, async);
    }

    SLresult RegisterCallback(slDynamicInterfaceManagementCallback callback, void *pContext) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->RegisterCallback(self(), callback, pContext);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_DYNAMIC_INTERFACE_MANAGEMENT_ITF_HPP_
