# Mosquito Classification 11 Class

This project is designed to classify 11 different species of mosquitoes based on their wingbeat sounds. The input to the model is 300ms of mosquito wingbeat sound.

## Code Overview

The `loop()` function is the main loop of the project that performs the following tasks:

1. Fetch the audio for the current time using `LatestAudioTimestamp()`.

2. Call the `PopulateFeatureData` method of the `feature_provider` object to populate the feature buffer with audio data for the current time.

3. Copy the feature buffer to the model input buffer `model_input_buffer`.

4. Run the model using the `interpreter->Invoke()` method.

5. Obtain a pointer to the output tensor of the model using `interpreter->output(0)`.

6. Use the `recognizer->ProcessLatestResults` method to process the output of the model and determine whether a command was recognized.

7. Call the `RespondToCommand` function to respond to the recognized command.

## Requirements

To run this project, you will need the following:

- A development board with an ESP32 microcontroller.

- A INMP441 microphone to capture the mosquito wingbeat sounds.

- A trained TensorFlow Lite model for mosquito classification.

- The [Arduino Core for ESP32](https://github.com/espressif/arduino-esp32) library for programming the ESP32 board.

- The [TensorFlow Lite for Microcontrollers](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/micro) library for running the model on the ESP32.

## Usage

To use this project, follow these steps:

1. Connect the amplifier and microphone to the ESP32 board.

2. Upload the trained TensorFlow Lite model to the ESP32.

3. Upload the code to the ESP32 board.

4. Open the serial monitor to view the results of the classification.

## Conclusion

This project demonstrates the feasibility of using an ESP32 microcontroller and a TensorFlow Lite model for real-time mosquito classification based on their wingbeat sounds. With further development, it has the potential to be used as a tool for mosquito control and disease prevention.

## Faculty of ICT Mahidol University, Senior Project 2022

This project was completed as a senior project by the following students:

- MR. THANAWIT THAMPAKORN (6288051) 
- MISS KANPITCHA ASSAWAVINIJKULCHAI (6288064)
- MR. WASIN HEESAWAT (6288077)

The project was advised by:
- PROF. DR. PETER HADDAWY (Advisor)
- DR. DOLVARA GUNA-TILAKA (Co-Advisor)

This project was submitted in partial fulfillment of the requirements for the degree of Bachelor of Science in Information and Communication Technology at the Faculty of Information and Communication Technology, Mahidol University in 2022.

## Authors
<a href="https://github.com/armmer016/Mosquito-Sensor-Senior2022/graphs/contributors">
   
  <img src="https://contrib.rocks/image?repo=armmer016/Mosquito-Sensor-Senior2022" /> 
  <img src="https://contrib.rocks/image?repo=oatact/Object-oriented-Programming" />
  <img src="https://contrib.rocks/image?repo=Kanpitcha-Ping/ITCS209-Object-Oriented-Programming" />
    
</a>
