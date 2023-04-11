#include "DAD_FFT_App.h"

float32_t inData[SAMPLE_LENGTH];
float32_t outData[SAMPLE_LENGTH/2];

//#define TESTMODE_FLOAT
#define TESTMODE_8_BIT 

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
    Serial.print("test");
  fftApp.FFT_Calculate(inData, outData);
    Serial.print("\ntest2");
  double timeElapsed = micros() - timeStart;


  Serial.print("Time Elapsed: ");
  Serial.println(timeElapsed);  
  Serial.println("Data out: ");
  for(int i = 0; i < SAMPLE_LENGTH/2-1; i++){
    Serial.print(" ");
    Serial.print((byte) outData[i]);
  }
  Serial.println("\n\n");  


  analogReadResolution(16);    // set the resolution of analogRead results

  
  
  
  #ifdef TESTMODE_8_BIT 
  while(1){
    uint8_t outData_8bit[SAMPLE_LENGTH];
    // Collect data, calc sum
      fftApp.collectData(inData);

      // Output collected input
      Serial.println("Data in: ");
      for(int i = 0; i < SAMPLE_LENGTH; i++){
        Serial.print(" ");
        Serial.print(inData[i]);
      }
      Serial.println();

      // Calc FFT
      fftApp.FFT_Calculate(inData, outData_8bit);
      
      // Output FFT
      Serial.println("Data out: ");
      for(int i = 0; i < SAMPLE_LENGTH; i++){
        Serial.print(" ");
        Serial.print(outData_8bit[i]);
      }
      Serial.println("\n\n");  
  }
  #endif
  
  
  
  #ifdef TESTMODE_FLOAT   
  while(1){
    // Collect data, calc sum
    fftApp.collectData(inData);

    // Output collected input
    Serial.println("Data in: ");
    for(int i = 0; i < SAMPLE_LENGTH; i++){
      Serial.print(" ");
      Serial.print(inData[i]);
    }
    Serial.println();

    // Calc FFT
    fftApp.FFT_Calculate(inData, outData);
    
    // Output FFT
    Serial.println("Data out: ");
    for(int i = 0; i < SAMPLE_LENGTH/2-1; i++){
      Serial.print(" ");
      Serial.print(outData[i]);
    }
    Serial.println("\n\n");  
  }
  #endif
}

void loop() {
}
