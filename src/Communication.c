#include "Communication.h"
#include "Signal.h"

void sendBitHigh(int pinNo){
  setPinLow(CLK_PIN);
  setPinHigh(CLK_PIN);
  setPinHigh(IO_PIN);
  setPinToInput(pinNo);
}

void sendBitLow(int pinNo){
  setPinLow(CLK_PIN);
  setPinHigh(CLK_PIN);
  setPinLow(IO_PIN);
  setPinToInput(pinNo);
}

uint32_t readBit(int pinNo){
  setPinHigh(CLK_PIN);
  setPinLow(CLK_PIN);
  return readPin(pinNo);
}

/*
 *@brief Perform write-to-read turnaround
 *@param pinNo is the pin to do turnaround
 *@steps 1) set IO pin as input
 *       2) set CLK pin low
 *       3) set CLK pin high
 */
void readTurnaroundIO(int pinNo){
  setPinToInput(IO_PIN);
  setPinLow(CLK_PIN);
  setPinHigh(CLK_PIN);
}

/*
 *@brief Perform write-to-read turnaround
 *@param pinNo is the pin to do turnaround
 *@steps 1) set IO pin as output
 *       2) set CLK pin high
 *       3) set CLK pin low
 */
void writeTurnaroundIO(int pinNo){
  setPinToOutput(pinNo);
  setPinHigh(CLK_PIN);
  setPinLow(CLK_PIN);
}

void writeData(uint8_t cmd, uint16_t address, uint8_t data){
  setPinHigh(CLK_PIN);
  setPinLow(CLK_PIN);
  setPinToInput(IO_PIN);

  int i=31;
  uint8_t bData;
  int Tcmd = cmd << 24 ;
  int Taddr = address << 8;
  uint32_t fullData = Tcmd + Taddr + data;

  printf("%x\n", fullData);
  while(i!=0){
    bData = fullData >> i & 0x00000001;
    if (bData == 0x00000000)
      sendBitLow(IO_PIN);
    else
      sendBitHigh(IO_PIN);
    printf("%x", bData);
    i--;
  }
}

uint8_t readData(uint8_t cmd, uint16_t address){
  setPinLow(CLK_PIN);
  setPinHigh(CLK_PIN);
  setPinToInput(IO_PIN);
  writeTurnaroundIO(IO_PIN);
  
  int i = 23;
  int j = 7;
  uint32_t  Tcmd, fullData, bData1, bData2, receivedData = 0xBE;
  Tcmd = cmd << 16;
  fullData = Tcmd + address;
  
  printf("%x\n", fullData);
  while(i!=0){
    bData1 = fullData >> i & 0x00000001;
    if (bData1 == 0x00000000)
      sendBitLow(IO_PIN);
    else 
      sendBitHigh(IO_PIN);
    printf("%x", bData1);
  }
  readTurnaroundIO(IO_PIN);
  
  printf("\n%x\n", receivedData);
  while(j!=0){
    bData2 = receivedData >> i & 0x00000001;
    if (bData2 == 0x00000000)
      sendBitLow(IO_PIN);
    else
      sendBitHigh(IO_PIN);
    printf("%x", bData2);
    j--;
  }
  
  return receivedData;  
}





