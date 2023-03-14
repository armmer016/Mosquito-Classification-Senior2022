# Mosquito Classification

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

- A LCD monitor to show the prediction result.

- A trained TensorFlow Lite model for mosquito classification.

- The [Arduino Core for ESP32](https://github.com/espressif/arduino-esp32) library for programming the ESP32 board.

- The [TensorFlow Lite for Microcontrollers](https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/micro) library for running the model on the ESP32.


## Usage

To use this project, follow these steps:

1. Connect INMP441 microphone to the ESP32 board.

2. Upload the trained TensorFlow Lite model to the ESP32.

3. Upload the code to the ESP32 board.

4. See the prediction result on LCD screen or Open the serial monitor to view more detail.


## Conclusion

This project demonstrates the feasibility of using an ESP32 microcontroller and a TensorFlow Lite model for real-time mosquito classification based on their wingbeat sounds. With further development, it has the potential to be used as a tool for mosquito control and disease prevention.

## Disclaimer (TH)
ซอฟต์แวร์นี้เป็นผลงานที่พัฒนาขึ้นโดย นางสาวกานต์พิชชา อัศววินิจกุลชัย นายธนวิชญ์ ธรรมพากรณ์ และ นายวศิน ฮีสวัสดิ์ คณะเทคโนโลยีสารสนเทศและการสื่อสาร มหาวิทยาลัยมหิดล ภายใต้การดูแลของ Prof. Dr. Peter Haddawy ภายใต้โครงการ การเก็บรวบรวมข้อมูลเสียงทางชีวภาพของยุงและเฝ้าระวังทางกีฏวิทยาด้วยเซ็นเซอร์เทคโนโลยีอินเทอร์เน็ตของสรรพสิ่ง ซึ่งสนับสนุนโดย สำนักงานพัฒนาวิทยาศาสตร์และเทคโนโลยีแห่งชาติ โดยมีวัตถุประสงค์เพื่อส่งเสริมให้นักเรียนและนักศึกษาได้เรียนรู้และฝึกทักษะในการ พัฒนาซอฟต์แวร์ ลิขสิทธิ์ของซอฟต์แวร์นี้จึงเป็นของผู้พัฒนา ซึ่งผู้พัฒนาได้ อนุญาตให้สานักงานพัฒนาวิทยาศาสตร์และเทคโนโลยีแห่งชาติ เผยแพร่ซอฟต์แวร์ นี้ตาม “ต้นฉบับ” โดยไม่มีการแก้ไขดัดแปลงใด ๆ ทั้งสิ้น ให้แก่บุคคลทั่วไปได้ใช้เพื่อ ประโยชน์ส่วนบุคคลหรือประโยชน์ทางการศึกษาที่ไม่มีวัตถุประสงค์ในเชิงพาณิชย์ โดยไม่คิดค่าตอบแทนการใช้ซอฟต์แวร์ ดังนั้น สานักงานพัฒนาวิทยาศาสตร์และ เทคโนโลยีแห่งชาติ จึงไม่มีหน้าที่ในการดูแล บำรุงรักษา จัดการอบรมการใช้งาน หรือพัฒนาประสิทธิภาพซอฟต์แวร์ รวมทั้งไม่รับรองความถูกต้องหรือประสิทธิภาพ การทางานของซอฟต์แวร์ ตลอดจนไม่รับประกันความเสียหายต่าง ๆ อันเกิดจาก การใช้ซอฟต์แวร์นี้ทั้งสิ้น 

## Disclaimer (EN)
This software is a work developed by Miss Kanpitcha Assawavinijkulchai, Mr. Thanawit Thampakorn and Mr. Wasin Heesawat from the faculty of Information Communication and Technology, Mahidol university under the provision of Prof. Dr. Peter Haddawy under Mosquito Sensor: Bio-acoustic IoT Sensors for Mosquito Data Collection and Surveillance , which has been supported by the National Science and Technology Development Agency (NSTDA), in order to encourage pupils and students to learn and practice their skills in developing software. Therefore, the intellectual property of this software shall belong to the developer and the developer gives NSTDA a permission to distribute this software as an “as is” and non- modified software for a temporary and non-exclusive use without remuneration to anyone for his or her own purpose or academic purpose, which are not commercial purposes. In this connection, NSTDA shall not be responsible to the user for taking care, maintaining, training or developing the efficiency of this software. Moreover, NSTDA shall not be liable for any error, software efficiency and damages in connection with or arising out of the use of the software.” 

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
