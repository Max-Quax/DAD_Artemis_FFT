#ifndef DAD_FFT_
#define DAD_FFT_

#include <Arduino.h>
extern "C"{
  #include <arm_math.h>
  //#include <arm_const_structs.h>
}

#define SAMPLE_LENGTH 512
#define IFFT_FLAG 0
#define DO_BIT_REVERSE 1

class DAD_FFT_App{
  public:
    DAD_FFT_App();
    
    arm_status FFT_Calculate(q15_t inData[SAMPLE_LENGTH], q15_t outData[SAMPLE_LENGTH]);
    
    // TODO destructor
    // TODO validate that types are correct
    // TODO validate that it works
    
  private:
    void FFT_Setup_Hann_Window (float hann[SAMPLE_LENGTH]);
    
    q15_t data_input[SAMPLE_LENGTH*2];
    float hann[SAMPLE_LENGTH];
    arm_status status;
};

#endif