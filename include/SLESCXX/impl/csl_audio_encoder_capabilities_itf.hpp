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

#ifndef OPENSLESCXX_CSL_AUDIO_ENCODER_CAPABILITIES_ITF_HPP_
#define OPENSLESCXX_CSL_AUDIO_ENCODER_CAPABILITIES_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Audio Encoder Capabilities Interface
//
class CSLAudioEncoderCapabilitiesItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLAudioEncoderCapabilitiesItf, SLAudioEncoderCapabilitiesItf)

    static const SLInterfaceID sGetIID() { return SL_IID_AUDIOENCODERCAPABILITIES; }

    CSLAudioEncoderCapabilitiesItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLAudioEncoderCapabilitiesItf() {}

    SLresult GetAudioEncoders(SLuint32 *pNumEncoders, SLuint32 *pEncoderIds)
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetAudioEncoders(self(), pNumEncoders, pEncoderIds);
    }

    SLresult GetAudioEncoderCapabilities(SLuint32 encoderId, SLuint32 *pIndex, SLAudioCodecDescriptor *pDescriptor)
    {
        if (!self())
            return SL_RESULT_RESOURCE_ERROR;
        return (*self())->GetAudioEncoderCapabilities(self(), encoderId, pIndex, pDescriptor);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_AUDIO_ENCODER_CAPABILITIES_ITF_HPP_
