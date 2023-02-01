/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "micro_features_generator.h"
#include <Arduino.h>
#include <cmath>
#include <cstring>

#include "tensorflow/lite/experimental/microfrontend/lib/frontend.h"
#include "tensorflow/lite/experimental/microfrontend/lib/frontend_util.h"
#include "micro_model_settings.h"

// Configure FFT to output 16 bit fixed point.
#define FIXED_POINT 16

namespace {

FrontendState g_micro_features_state;
bool g_is_first_time = true;

}  // namespace

TfLiteStatus InitializeMicroFeatures(tflite::ErrorReporter* error_reporter) {
  
  g_is_first_time = true;
  return kTfLiteOk;
}

// This is not exposed in any header, and is only used for testing, to ensure
// that the state is correctly set up before generating results.
void SetMicroFeaturesNoiseEstimates(const uint32_t* estimate_presets) {
  for (int i = 0; i < g_micro_features_state.filterbank.num_channels; ++i) {
    g_micro_features_state.noise_reduction.estimate[i] = estimate_presets[i];
  }
}
 constexpr float value_scale = 1.0f / 32768.0f;
TfLiteStatus GenerateMicroFeatures(tflite::ErrorReporter* error_reporter,
                                   const int16_t* input, int input_size,
                                   int output_size, uint8_t* output,
                                   size_t* num_samples_read) {
  const int16_t* frontend_input;
  if (g_is_first_time) {
    frontend_input = input;
    g_is_first_time = false;
  } else {
    frontend_input = input;
  }
  // FrontendOutput frontend_output = FrontendProcessSamples(
  //     &g_micro_features_state, frontend_input, input_size, num_samples_read);
   const double INPUT_SCALE = 0.0012479894794523716;
    const double INPUT_ZERO_POINT = 163.0;
    const double kNomailzed = 0.15899658;
    
    // Serial.println("\nFloat Normalized (-1.0 to 1.0) ");
  for (int i = 0; i < kMaxAudioSampleSize; i++) {
    

  float raw_float = value_scale * frontend_input[i];
  if (raw_float > 1.0f){
    raw_float = 1.0;
  }else if(raw_float < -1.0f){
    raw_float = -1.0;
  }
   float normalized_float = raw_float/kNomailzed;
  //  Serial.printf("frontend: %d\n",frontend_input[i]);
  // Serial.printf("%.15f,",raw_float);
   
  output[i] = (uint8_t)((normalized_float/INPUT_SCALE) + INPUT_ZERO_POINT);
  }

  //  Serial.println("\nFloat Normalized ");
  // for (int i = 0; i < kMaxAudioSampleSize; i++) {
    

  // float raw_float = value_scale * frontend_input[i];
  // if (raw_float > 1.0f){
  //   raw_float = 1.0;
  // }else if(raw_float < -1.0f){
  //   raw_float = -1.0;
  // }
   
  // //  Serial.printf("frontend: %d\n",frontend_input[i]);
  // Serial.printf("%.5f,",raw_float);
   
  // output[i] = (uint8_t)((raw_float/INPUT_SCALE) + INPUT_ZERO_POINT);
  // }
  
  

  return kTfLiteOk;
}
