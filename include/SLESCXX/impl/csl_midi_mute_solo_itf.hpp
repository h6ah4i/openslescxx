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

#ifndef OPENSLESCXX_CSL_MIDI_MUTE_SOLO_ITF_HPP_
#define OPENSLESCXX_CSL_MIDI_MUTE_SOLO_ITF_HPP_

#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_interface.hpp>

namespace opensles {

//
// Midi Mute Solo interface
//
class CSLMIDIMuteSoloItf : public CSLInterface {
public:
    DECL_CSL_INTERFACE_OPERATORS(CSLMIDIMuteSoloItf, SLMIDIMuteSoloItf)

    static const SLInterfaceID sGetIID() noexcept { return SL_IID_MIDIMUTESOLO; }

    CSLMIDIMuteSoloItf() : CSLInterface(sGetIID()) {}
    virtual ~CSLMIDIMuteSoloItf() {}

    SLresult SetChannelMute(SLuint8 channel, SLboolean mute) noexcept
    {
        return (*self())->SetChannelMute(self(), channel, mute);
    }

    SLresult GetChannelMute(SLuint8 channel, SLboolean *pMute) noexcept
    {
        return (*self())->GetChannelMute(self(), channel, pMute);
    }

    SLresult SetChannelSolo(SLuint8 channel, SLboolean solo) noexcept
    {
        return (*self())->SetChannelSolo(self(), channel, solo);
    }

    SLresult GetChannelSolo(SLuint8 channel, SLboolean *pSolo) noexcept
    {
        return (*self())->GetChannelSolo(self(), channel, pSolo);
    }

    SLresult GetTrackCount(SLuint16 *pCount) noexcept { return (*self())->GetTrackCount(self(), pCount); }

    SLresult SetTrackMute(SLuint16 track, SLboolean mute) noexcept
    {
        return (*self())->SetTrackMute(self(), track, mute);
    }

    SLresult GetTrackMute(SLuint16 track, SLboolean *pMute) noexcept
    {
        return (*self())->GetTrackMute(self(), track, pMute);
    }

    SLresult SetTrackSolo(SLuint16 track, SLboolean solo) noexcept
    {
        return (*self())->SetTrackSolo(self(), track, solo);
    }

    SLresult GetTrackSolo(SLuint16 track, SLboolean *pSolo) noexcept
    {
        return (*self())->GetTrackSolo(self(), track, pSolo);
    }
};

} // namespace opensles

#endif // OPENSLESCXX_CSL_MIDI_MUTE_SOLO_ITF_HPP_
