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

#ifndef OPENSLESCXX_CSL_AUDIO_IO_DEVICE_CAPABILITIES_ITF_HPP_
#define OPENSLESCXX_CSL_AUDIO_IO_DEVICE_CAPABILITIES_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Audio IO Device capabilities interface
//
class CSLAudioIODeviceCapabilitiesItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLAudioIODeviceCapabilitiesItf, SLAudioIODeviceCapabilitiesItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_AUDIOIODEVICECAPABILITIES; }

    CSLAudioIODeviceCapabilitiesItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLAudioIODeviceCapabilitiesItf() {}

    SLresult GetAvailableAudioInputs(SLint32 *pNumInputs, SLuint32 *pInputDeviceIDs) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetAvailableAudioInputs(self(), pNumInputs, pInputDeviceIDs);
    }

    SLresult QueryAudioInputCapabilities(SLuint32 deviceId, SLAudioInputDescriptor *pDescriptor) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryAudioInputCapabilities(self(), deviceId, pDescriptor);
    }

    SLresult RegisterAvailableAudioInputsChangedCallback(slAvailableAudioInputsChangedCallback callback,
                                                         void *pContext) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->RegisterAvailableAudioInputsChangedCallback(self(), callback, pContext);
    }

    SLresult GetAvailableAudioOutputs(SLint32 *pNumOutputs, SLuint32 *pOutputDeviceIDs) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetAvailableAudioOutputs(self(), pNumOutputs, pOutputDeviceIDs);
    }

    SLresult QueryAudioOutputCapabilities(SLuint32 deviceId, SLAudioOutputDescriptor *pDescriptor) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->QueryAudioOutputCapabilities(self(), deviceId, pDescriptor);
    }

    SLresult RegisterAvailableAudioOutputsChangedCallback(slAvailableAudioOutputsChangedCallback callback,
                                                          void *pContext) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->RegisterAvailableAudioOutputsChangedCallback(self(), callback, pContext);
    }

    SLresult RegisterDefaultDeviceIDMapChangedCallback(slDefaultDeviceIDMapChangedCallback callback,
                                                       void *pContext) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->RegisterDefaultDeviceIDMapChangedCallback(self(), callback, pContext);
    }

    SLresult GetAssociatedAudioInputs(SLuint32 deviceId, SLint32 *pNumAudioInputs,
                                      SLuint32 *pAudioInputDeviceIDs) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetAssociatedAudioInputs(self(), deviceId, pNumAudioInputs, pAudioInputDeviceIDs);
    }

    SLresult GetAssociatedAudioOutputs(SLuint32 deviceId, SLint32 *pNumAudioOutputs,
                                       SLuint32 *pAudioOutputDeviceIDs) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetAssociatedAudioOutputs(self(), deviceId, pNumAudioOutputs, pAudioOutputDeviceIDs);
    }

    SLresult GetDefaultAudioDevices(SLuint32 defaultDeviceID, SLint32 *pNumAudioDevices,
                                    SLuint32 *pAudioDeviceIDs) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetDefaultAudioDevices(self(), defaultDeviceID, pNumAudioDevices, pAudioDeviceIDs);
    }

    SLresult QuerySampleFormatsSupported(SLuint32 deviceId, SLmilliHertz samplingRate, SLint32 *pSampleFormats,
                                         SLint32 *pNumOfSampleFormats) noexcept
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())
            ->QuerySampleFormatsSupported(self(), deviceId, samplingRate, pSampleFormats, pNumOfSampleFormats);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_AUDIO_IO_DEVICE_CAPABILITIES_ITF_HPP_
