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

#ifndef OPENSLESCXX_CSL_METADATA_TRAVERSAL_ITF_HPP_
#define OPENSLESCXX_CSL_METADATA_TRAVERSAL_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Meta data traversal interface
//
class CSLMetadataTraversalItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLMetadataTraversalItf, SLMetadataTraversalItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_METADATATRAVERSAL; }

    CSLMetadataTraversalItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLMetadataTraversalItf() {}

    SLresult SetMode(SLuint32 mode) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetMode(self(), mode);
    }

    SLresult GetChildCount(SLuint32 *pCount) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetChildCount(self(), pCount);
    }

    SLresult GetChildMIMETypeSize(SLuint32 index, SLuint32 *pSize) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetChildMIMETypeSize(self(), index, pSize);
    }

    SLresult GetChildInfo(SLuint32 index, SLint32 *pNodeID, SLuint32 *pType, SLuint32 size, SLchar *pMimeType) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetChildInfo(self(), index, pNodeID, pType, size, pMimeType);
    }

    SLresult SetActiveNode(SLuint32 index) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->SetActiveNode(self(), index);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_METADATA_TRAVERSAL_ITF_HPP_
