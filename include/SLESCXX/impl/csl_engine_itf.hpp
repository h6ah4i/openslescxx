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

#ifndef OPENSLESCXX_CSL_ENGINE_ITF_HPP_
#define OPENSLESCXX_CSL_ENGINE_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_object_itf.hpp>

namespace opensles {

//
// Engine Interface
//
class CSLEngineItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLEngineItf, SLEngineItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_ENGINE; }

    CSLEngineItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLEngineItf() {}

    SLresult CreateLEDDevice(SLObjectItf *pDevice, SLuint32 deviceID, SLuint32 numInterfaces,
                             const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->CreateLEDDevice(self(), pDevice, deviceID, numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult CreateLEDDevice(CSLObjectItf *pDevice, SLuint32 deviceID, SLuint32 numInterfaces,
                             const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired) noexcept
    {
        if (!pDevice)
            return SL_RESULT_PARAMETER_INVALID;
        return CreateLEDDevice(&(pDevice->self()), deviceID, numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult CreateVibraDevice(SLObjectItf *pDevice, SLuint32 deviceID, SLuint32 numInterfaces,
                               const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())
            ->CreateVibraDevice(self(), pDevice, deviceID, numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult CreateVibraDevice(CSLObjectItf *pDevice, SLuint32 deviceID, SLuint32 numInterfaces,
                               const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired) noexcept
    {
        if (!pDevice)
            return SL_RESULT_PARAMETER_INVALID;
        return CreateVibraDevice(&(pDevice->self()), deviceID, numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult CreateAudioPlayer(SLObjectItf *pPlayer, SLDataSource *pAudioSrc, SLDataSink *pAudioSnk,
                               SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                               const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->CreateAudioPlayer(self(), pPlayer, pAudioSrc, pAudioSnk, numInterfaces, pInterfaceIds,
                                            pInterfaceRequired);
    }

    SLresult CreateAudioPlayer(CSLObjectItf *pPlayer, SLDataSource *pAudioSrc, SLDataSink *pAudioSnk,
                               SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                               const SLboolean *pInterfaceRequired) noexcept
    {
        if (!pPlayer)
            return SL_RESULT_PARAMETER_INVALID;
        return CreateAudioPlayer(&(pPlayer->self()), pAudioSrc, pAudioSnk, numInterfaces, pInterfaceIds,
                                 pInterfaceRequired);
    }

    SLresult CreateAudioRecorder(SLObjectItf *pRecorder, SLDataSource *pAudioSrc, SLDataSink *pAudioSnk,
                                 SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                                 const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->CreateAudioRecorder(self(), pRecorder, pAudioSrc, pAudioSnk, numInterfaces, pInterfaceIds,
                                              pInterfaceRequired);
    }

    SLresult CreateAudioRecorder(CSLObjectItf *pRecorder, SLDataSource *pAudioSrc, SLDataSink *pAudioSnk,
                                 SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                                 const SLboolean *pInterfaceRequired) noexcept
    {
        if (!pRecorder)
            return SL_RESULT_PARAMETER_INVALID;
        return CreateAudioRecorder(&(pRecorder->self()), pAudioSrc, pAudioSnk, numInterfaces, pInterfaceIds,
                                   pInterfaceRequired);
    }

    SLresult CreateMidiPlayer(SLObjectItf *pPlayer, SLDataSource *pMIDISrc, SLDataSource *pBankSrc,
                              SLDataSink *pAudioOutput, SLDataSink *pVibra, SLDataSink *pLEDArray,
                              SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                              const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->CreateMidiPlayer(self(), pPlayer, pMIDISrc, pBankSrc, pAudioOutput, pVibra, pLEDArray,
                                           numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult CreateMidiPlayer(CSLObjectItf *pPlayer, SLDataSource *pMIDISrc, SLDataSource *pBankSrc,
                              SLDataSink *pAudioOutput, SLDataSink *pVibra, SLDataSink *pLEDArray,
                              SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                              const SLboolean *pInterfaceRequired) noexcept
    {
        if (!pPlayer)
            return SL_RESULT_PARAMETER_INVALID;
        return CreateMidiPlayer(&(pPlayer->self()), pMIDISrc, pBankSrc, pAudioOutput, pVibra, pLEDArray, numInterfaces,
                                pInterfaceIds, pInterfaceRequired);
    }

    SLresult CreateListener(SLObjectItf *pListener, SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                            const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->CreateListener(self(), pListener, numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult CreateListener(CSLObjectItf *pListener, SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                            const SLboolean *pInterfaceRequired) noexcept
    {
        if (!pListener)
            return SL_RESULT_PARAMETER_INVALID;
        return CreateListener(&(pListener->self()), numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult Create3DGroup(SLObjectItf *pGroup, SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                           const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->Create3DGroup(self(), pGroup, numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult Create3DGroup(CSLObjectItf *pGroup, SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                           const SLboolean *pInterfaceRequired) noexcept
    {
        if (!pGroup)
            return SL_RESULT_PARAMETER_INVALID;
        return Create3DGroup(&(pGroup->self()), numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult CreateOutputMix(SLObjectItf *pMix, SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                             const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->CreateOutputMix(self(), pMix, numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult CreateOutputMix(CSLObjectItf *pMix, SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                             const SLboolean *pInterfaceRequired) noexcept
    {
        if (!pMix)
            return SL_RESULT_PARAMETER_INVALID;
        return CreateOutputMix(&(pMix->self()), numInterfaces, pInterfaceIds, pInterfaceRequired);
    }

    SLresult CreateMetadataExtractor(SLObjectItf *pMetadataExtractor, SLDataSource *pDataSource, SLuint32 numInterfaces,
                                     const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->CreateMetadataExtractor(self(), pMetadataExtractor, pDataSource, numInterfaces, pInterfaceIds,
                                                  pInterfaceRequired);
    }

    SLresult CreateMetadataExtractor(CSLObjectItf *pMetadataExtractor, SLDataSource *pDataSource,
                                     SLuint32 numInterfaces, const SLInterfaceID *pInterfaceIds,
                                     const SLboolean *pInterfaceRequired) noexcept
    {
        if (!pMetadataExtractor)
            return SL_RESULT_PARAMETER_INVALID;
        return CreateMetadataExtractor(&(pMetadataExtractor->self()), pDataSource, numInterfaces, pInterfaceIds,
                                       pInterfaceRequired);
    }

    SLresult CreateExtensionObject(SLObjectItf *pObject, void *pParameters, SLuint32 objectID, SLuint32 numInterfaces,
                                   const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->CreateExtensionObject(self(), pObject, pParameters, objectID, numInterfaces, pInterfaceIds,
                                                pInterfaceRequired);
    }

    SLresult CreateExtensionObject(CSLObjectItf *pObject, void *pParameters, SLuint32 objectID, SLuint32 numInterfaces,
                                   const SLInterfaceID *pInterfaceIds, const SLboolean *pInterfaceRequired) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return CreateExtensionObject(&(pObject->self()), pParameters, objectID, numInterfaces, pInterfaceIds,
                                     pInterfaceRequired);
    }

    SLresult QueryNumSupportedInterfaces(SLuint32 objectID, SLuint32 *pNumSupportedInterfaces) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryNumSupportedInterfaces(self(), objectID, pNumSupportedInterfaces);
    }

    SLresult QuerySupportedInterfaces(SLuint32 objectID, SLuint32 index, SLInterfaceID *pInterfaceId) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QuerySupportedInterfaces(self(), objectID, index, pInterfaceId);
    }

    SLresult QueryNumSupportedExtensions(SLuint32 *pNumExtensions) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryNumSupportedExtensions(self(), pNumExtensions);
    }

    SLresult QuerySupportedExtension(SLuint32 index, SLchar *pExtensionName, SLint16 *pNameLength) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QuerySupportedExtension(self(), index, pExtensionName, pNameLength);
    }

    SLresult IsExtensionSupported(const SLchar *pExtensionName, SLboolean *pSupported) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->IsExtensionSupported(self(), pExtensionName, pSupported);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_ENGINE_ITF_HPP_
