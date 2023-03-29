#include "DAD_FFT_App.h"

q15_t inData[SAMPLE_LENGTH];
q15_t outData[SAMPLE_LENGTH];
byte  inDataBytes[SAMPLE_LENGTH*2];
byte  outDataBytes[SAMPLE_LENGTH*2];

void setup() {
  Serial.begin(115200);
  DAD_FFT_App fftApp;

  // Populate inData
    // Simulates a square wave
  for(int i = 0; i < SAMPLE_LENGTH; i++){
    if(i % 32 < 16)
      inData[i] = 0x3FFF;
    else
      inData[i] = 0;
    inDataBytes[i*2] = (byte)((inData[i] & 0x0FF00) >> 8);
    inDataBytes[i*2+1] = (byte)(inData[i] & 0x00FF);
    Serial.println((q15_t)(inDataBytes[i*2] << 8) | (inDataBytes[i*2 + 1]));  // Expects MSB first
  }

  double timeStart = micros();
  fftApp.FFT_Calculate(inData, outData);
  double timeElapsed = micros() - timeStart;

  Serial.print("Time Elapsed: ");
  Serial.println(timeElapsed);  
  Serial.println("Data out: ");
  for(int i = 0; i < SAMPLE_LENGTH; i++){
    Serial.print(" ");
    Serial.print((byte) outData[i]);
  }
  Serial.println("\n\n");  

  timeStart = micros();
  fftApp.FFT_Calculate(inDataBytes, outDataBytes);
  timeElapsed = micros() - timeStart;  

  Serial.print("Time Elapsed: ");
  Serial.println(timeElapsed);  
  Serial.println("Data out: ");
  for(int i = 0; i < SAMPLE_LENGTH; i++){
    Serial.print(" ");
    Serial.print(outDataBytes[i]);
  }
  Serial.println("\n\n");  
}

void loop() {
}
