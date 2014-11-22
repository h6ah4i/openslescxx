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

#ifndef OPENSLESCXX_OPENSLES_CXX_HPP_
#define OPENSLESCXX_OPENSLES_CXX_HPP_

//
// Standard OpenSL APIs
//
#include <SLESCXX/impl/csl_impl_common.hpp>
#include <SLESCXX/impl/csl_boolean.hpp>
#include <SLESCXX/impl/csl_object_itf.hpp>
#include <SLESCXX/impl/csl_audio_io_device_capabilities_itf.hpp>
#include <SLESCXX/impl/csl_led_array_itf.hpp>
#include <SLESCXX/impl/csl_vibra_itf.hpp>
#include <SLESCXX/impl/csl_metadata_extraction_itf.hpp>
#include <SLESCXX/impl/csl_metadata_traversal_itf.hpp>
#include <SLESCXX/impl/csl_dynamic_source_itf.hpp>
#include <SLESCXX/impl/csl_output_mix_itf.hpp>
#include <SLESCXX/impl/csl_play_itf.hpp>
#include <SLESCXX/impl/csl_prefetch_status_itf.hpp>
#include <SLESCXX/impl/csl_seek_itf.hpp>
#include <SLESCXX/impl/csl_record_itf.hpp>
#include <SLESCXX/impl/csl_equalizer_itf.hpp>
#include <SLESCXX/impl/csl_volume_itf.hpp>
#include <SLESCXX/impl/csl_device_volume_itf.hpp>
#include <SLESCXX/impl/csl_buffer_queue_itf.hpp>
#include <SLESCXX/impl/csl_preset_reverb_itf.hpp>
#include <SLESCXX/impl/csl_environmental_reverb_itf.hpp>
#include <SLESCXX/impl/csl_effect_send_itf.hpp>
#include <SLESCXX/impl/csl_3d_grouping_itf.hpp>
#include <SLESCXX/impl/csl_3d_commit_itf.hpp>
#include <SLESCXX/impl/csl_3d_location_itf.hpp>
#include <SLESCXX/impl/csl_3d_doppler_itf.hpp>
#include <SLESCXX/impl/csl_3d_source_itf.hpp>
#include <SLESCXX/impl/csl_3d_macroscopic_itf.hpp>
#include <SLESCXX/impl/csl_mute_solo_itf.hpp>
#include <SLESCXX/impl/csl_dynamic_interface_management_itf.hpp>
#include <SLESCXX/impl/csl_midi_message_itf.hpp>
#include <SLESCXX/impl/csl_midi_mute_solo_itf.hpp>
#include <SLESCXX/impl/csl_midi_tempo_itf.hpp>
#include <SLESCXX/impl/csl_midi_time_itf.hpp>
#include <SLESCXX/impl/csl_audio_decoder_capabilities_itf.hpp>
#include <SLESCXX/impl/csl_audio_encoder_capabilities_itf.hpp>
#include <SLESCXX/impl/csl_audio_encoder_itf.hpp>
#include <SLESCXX/impl/csl_bass_boost_itf.hpp>
#include <SLESCXX/impl/csl_pitch_itf.hpp>
#include <SLESCXX/impl/csl_rate_pitch_itf.hpp>
#include <SLESCXX/impl/csl_virtualizer_itf.hpp>
#include <SLESCXX/impl/csl_visualization_itf.hpp>
#include <SLESCXX/impl/csl_engine_itf.hpp>
#include <SLESCXX/impl/csl_engine_capabilities_itf.hpp>
#include <SLESCXX/impl/csl_thread_sync_itf.hpp>

//
// Android specific APIs
//
#include <SLESCXX/impl/csl_android_effect_itf.hpp>
#include <SLESCXX/impl/csl_android_effect_send_itf.hpp>
#include <SLESCXX/impl/csl_android_effect_capabilities_itf.hpp>
#include <SLESCXX/impl/csl_android_configuration_itf.hpp>
#include <SLESCXX/impl/csl_android_simple_buffer_queue_itf.hpp>
#include <SLESCXX/impl/csl_android_buffer_queue_itf.hpp>

#endif // OPENSLESCXX_OPENSLES_CXX_HPP_
