#include "DAD_FFT_App.h"

float inData[SAMPLE_LENGTH];
uint8_t outData[SAMPLE_LENGTH];

void setup() {
  Serial.begin(115200);
  DAD_FFT_App fftApp;

  // Populate inData
    // Simulates a square wave
  for(int i = 0; i < SAMPLE_LENGTH; i++){
    if(i % 32 < 16)
      inData[i] = 16383; // 0x3FFF
    else
      inData[i] = 0;
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
}

void loop() {
}
