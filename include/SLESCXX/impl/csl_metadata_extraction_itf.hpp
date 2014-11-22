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

#ifndef OPENSLESCXX_CSL_METADATA_EXTRACTION_ITF_HPP_
#define OPENSLESCXX_CSL_METADATA_EXTRACTION_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Meta data extraction interface
//
class CSLMetadataExtractionItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLMetadataExtractionItf, SLMetadataExtractionItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_METADATAEXTRACTION; }

    CSLMetadataExtractionItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLMetadataExtractionItf() {}

    SLresult GetItemCount(SLuint32 *pItemCount) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetItemCount(self(), pItemCount);
    }

    SLresult GetKeySize(SLuint32 index, SLuint32 *pKeySize) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetKeySize(self(), index, pKeySize);
    }

    SLresult GetKey(SLuint32 index, SLuint32 keySize, SLMetadataInfo *pKey) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetKey(self(), index, keySize, pKey);
    }

    SLresult GetValueSize(SLuint32 index, SLuint32 *pValueSize) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetValueSize(self(), index, pValueSize);
    }

    SLresult GetValue(SLuint32 index, SLuint32 valueSize, SLMetadataInfo *pValue) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetValue(self(), index, valueSize, pValue);
    }

    SLresult AddKeyFilter(SLuint32 keySize, const void *pKey, SLuint32 keyEncoding, const SLchar *pValueLangCountry,
                          SLuint32 valueEncoding, SLuint8 filterMask) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())
            ->AddKeyFilter(self(), keySize, pKey, keyEncoding, pValueLangCountry, valueEncoding, filterMask);
    }

    SLresult ClearKeyFilter() noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->ClearKeyFilter(self());
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_METADATA_EXTRACTION_ITF_HPP_
