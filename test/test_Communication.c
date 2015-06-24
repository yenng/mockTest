#include "unity.h"
#include "Communication.h"
#include <stdint.h>
#include "mock_Signal.h"

void setUp(void){}

void tearDown(void){}

void test_sendBitHigh_give_xxx_should_xxx(){
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN);
  setPinToInput_Expect(IO_PIN);
  sendBitHigh(IO_PIN);
}

void test_sendBitLow_give_xxx_should_xxx(){
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);
  setPinToInput_Expect(IO_PIN);
  sendBitLow(IO_PIN);
}

void test_readBit_give_xxx_should_xxx(){
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  readPin_ExpectAndReturn(IO_PIN,IO_PIN);
  uint32_t bit = readBit(IO_PIN);
}


void test_writeData_given_0xCD_and_addr_0xDEAD_and_data_0xC0_should_send_out_0xCdDEADC0(void)
{
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinToInput_Expect(IO_PIN);
  
  
  int i=31;
  uint8_t bData;
  uint32_t fullData = 0xCDDEADC0;

  while(i!=0){
    bData = fullData >> i & 0x00000001;
    if (bData == 0x00000000){
      setPinLow_Expect(CLK_PIN);
      setPinHigh_Expect(CLK_PIN);
      setPinLow_Expect(IO_PIN);
      setPinToInput_Expect(IO_PIN);
    }
    else{
      setPinLow_Expect(CLK_PIN);
      setPinHigh_Expect(CLK_PIN);
      setPinHigh_Expect(IO_PIN);
      setPinToInput_Expect(IO_PIN);
    }
    i--;
  }
	writeData(0xCD, 0xDEAD, 0xC0);
}

void test_readData_given_0xAB_and_addr_0xFACE_should_send_0xFACEAB_and_turnaround_and_receive_0xBE(void)
{
  setPinLow_Expect(CLK_PIN);
	setPinHigh_Expect(CLK_PIN);
  setPinToInput_Expect(IO_PIN);
  
  setPinToOutput_Expect(IO_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  
  int i=23;
  int j=7;
  uint8_t bData1,bData2;
  uint32_t fullData = 0xABFACE;
  uint32_t receivedData = 0xBE;

  while(i!=0){
    bData1 = fullData >> i & 0x00000001;
    if (bData1 == 0x00000000){
      setPinLow_Expect(CLK_PIN);
      setPinHigh_Expect(CLK_PIN);
      setPinLow_Expect(IO_PIN);
      setPinToInput_Expect(IO_PIN);
    }
    else{
      setPinLow_Expect(CLK_PIN);
      setPinHigh_Expect(CLK_PIN);
      setPinHigh_Expect(IO_PIN);
      setPinToInput_Expect(IO_PIN);
    }
    i--;
  }  
  setPinToInput_Expect(IO_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  
  while(j!=0){
    bData2 = receivedData >> i & 0x00000001;
    if (bData2 == 0x00000000){
      setPinLow_Expect(CLK_PIN);
      setPinHigh_Expect(CLK_PIN);
      setPinLow_Expect(IO_PIN);
      setPinToInput_Expect(IO_PIN);
    }
    else{
      setPinLow_Expect(CLK_PIN);
      setPinHigh_Expect(CLK_PIN);
      setPinHigh_Expect(IO_PIN);
      setPinToInput_Expect(IO_PIN);
    }
    j--;
  }  
  
  readData(0xAB, 0xFACE);
}



