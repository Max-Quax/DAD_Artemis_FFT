#include "DAD_FFT_App.h"

DAD_FFT_App::DAD_FFT_App(){
  FFT_Setup_Hann_Window(hann);
}

// Calculates FFT
arm_status DAD_FFT_App::FFT_Calculate(q15_t inData[SAMPLE_LENGTH], q15_t outData[SAMPLE_LENGTH]){
  int i = 0;
  
  // Compute RFFT 
  for(i = 0; i < SAMPLE_LENGTH; i++)
  {
      inData[i] = (q15_t)(hann[i] * inData[i]);
  }
  arm_rfft_instance_q15 instance;
  status = arm_rfft_init_q15(&instance, SAMPLE_LENGTH, IFFT_FLAG, DO_BIT_REVERSE);

  arm_rfft_q15(&instance, inData, data_input);

  // Calculate magnitude
  for(i = 0; i < 2*SAMPLE_LENGTH; i += 2)
  {
      outData[i / 2] =
          (int32_t)(sqrtf((data_input[i] *  
                            data_input[i]) +
                          (data_input[i + 1] * data_input[i + 1])));  // TODO make sure these types make sense
  } 

  return status;
}


// Populates hann window to mitigate error from non-integer # of samples
void DAD_FFT_App::FFT_Setup_Hann_Window (float hann[SAMPLE_LENGTH]){
  // Initialize Hann Window
  int n;
  for(n = 0; n < SAMPLE_LENGTH; n++)
  {
      hann[n] = 0.5f - 0.5f * cosf((2 * PI * n) / (SAMPLE_LENGTH - 1));
  }    
}
