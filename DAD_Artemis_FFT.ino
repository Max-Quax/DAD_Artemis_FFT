#include "DAD_FFT_App.h"

q15_t inData[SAMPLE_LENGTH];
q15_t outData[SAMPLE_LENGTH];

void setup() {
  Serial.begin(115200);
  DAD_FFT_App fftApp;

  // Populate inData
    // Simulates a 2.5kHz square wave
  for(int i = 0; i < SAMPLE_LENGTH; i++){
    if(i % 4 == 0)
      inData[i] = 1023;
    else if(i % 3 == 0)
      inData[i] = 2047;    
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
    Serial.print(outData[i]);
  }
  Serial.println("\n\n");  
  
}

void loop() {
}
