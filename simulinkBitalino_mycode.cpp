#include <mex.h>
#include "simstruc.h"

#include <string>
#include <iostream>
#include <sstream>
#include <conio.h>
#include "bitalino.h"


static const int iNrAnalogChannels = 4;
static const int iNrDigitalChannels = 4;

std::string int_array_to_string(const uint16_T * int_array, int size_of_array) {
  std::ostringstream oss("");

  for (int temp = 0; temp < size_of_array; temp++) {
    oss << (char)int_array[temp];
  }
  std::string str = oss.str();
  std::size_t found = str.find('\0');
  str = str.substr(0, found);
  return str;
}


void myStart(real_T *xD,
             void **pW,
             const uint16_T *device, const int_T p_width0,
             const uint16_T *samplingfrequency, const int_T p_width1,
             SimStruct *S) {
  try
    {

      std::string strDevice = int_array_to_string(device, p_width0);
        
      //std::string strDevice = "98:d3:31:b1:83:ea";  // "COM5" //PARAM
      // strDevice = "98:d3:31:b1:83:b0"; // "COM9"

      std::cerr << "Connecting to device \"" << strDevice << "\"" << std::endl;


      // use one of the lines below
      //      BITalino dev(strDevice.c_str());  // device MAC address (Windows and Linux)

      BITalino *dev = new BITalino(strDevice.c_str());
      pW[0] = (void *)dev;

      //BITalino dev("COM5");  // Bluetooth virtual COM port or USB-UART COM port (Windows)
      
      //BITalino dev("/dev/ttyUSB0");  // USB-UART device (Linux)
      //BITalino dev("/dev/rfcomm0");  // Bluetooth virtual serial port (Linux) 
      
      //BITalino dev("/dev/tty.usbserial-A1000QIz");  // USB-UART device (Mac OS)
      //BITalino dev("/dev/tty.bitalino-DevB");  // Bluetooth virtual serial port (Mac OS) 
      
      std::cerr << "Connection successful" << std::endl;

      std::string ver = dev->version();    // get device version string
      std::cerr << "BITalino version: " << ver.c_str() << std::endl;

      dev->battery(10);  // set battery threshold (optional)

      int iSamplingFrequency = 100; //PARAM 10, 100, 1000,

      dev->start(iSamplingFrequency, {0, 1, 2, 3, 4, 5});   // start acquisition of all channels at 1000 Hz
    } 
  catch(BITalino::Exception &e)
    {
      std::cerr << "BITalino exception: " << e.getDescription() << std::endl;
      std::string strError = "BITalino error: " + std::string(e.getDescription());
      ssSetErrorStatus(S,strError.c_str());
    }
  
}

void myUpdate(real_T *outputAnalog,
              real_T *outputDigital,
              real_T *xD,
              void **pW,
              const uint16_T *device, const int_T p_width0,
              const uint16_T *samplingfrequency, const int_T p_width1){

  
  BITalino *dev = (BITalino *)pW[0];
  BITalino::VFrame frames(1); // initialize the frames vector with 100 frames 
  
  dev->read(frames); // get 100 frames from device
  const BITalino::Frame &f = frames[0];  // get a reference to the first frame of each 100 frames block

  /*
    printf("%d : %d %d %d %d ; %d %d %d %d %d %d\n",   // dump the first frame
    f.seq,
    f.digital[0], f.digital[1], f.digital[2], f.digital[3],
    f.analog[0], f.analog[1], f.analog[2], f.analog[3], f.analog[4], f.analog[5]);
  */

  
  for(int i1=0; i1<iNrAnalogChannels; i1++){
    outputAnalog[i1] = f.analog[i1];
  }
  


        
  for(int i1=0; i1<iNrDigitalChannels; i1++){
    outputDigital[i1] = f.digital[i1];
  }
  
}


void myTerminate(real_T *xD,
                 void **pW,
                 const uint16_T *device, const int_T p_width0,
                 const uint16_T *samplingfrequency, const int_T p_width1){

  

  BITalino *dev = (BITalino *)pW[0];
  dev->stop();
  delete dev;

}




