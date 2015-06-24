#include "unity.h"
#include "Communication.h"
#include <stdint.h>
#include "mock_Signal.h"

void setUp(void){}

void tearDown(void){}

void while_loop_for_checking_the_writeData(uint32_t fullData, int i){
	uint8_t bData;
	
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
}
void test_while_loop_for_checking_the_writeData(){
	//get 0
	setPinLow_Expect(CLK_PIN);
    setPinHigh_Expect(CLK_PIN);
    setPinLow_Expect(IO_PIN);
    setPinToInput_Expect(IO_PIN);
	  
	//get 1
    setPinLow_Expect(CLK_PIN);
    setPinHigh_Expect(CLK_PIN);
    setPinHigh_Expect(IO_PIN);
    setPinToInput_Expect(IO_PIN);	
	
	sendBitLow(IO_PIN);
	sendBitHigh(IO_PIN);
}
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

void test_write_turnaround(){
  setPinToOutput_Expect(IO_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  
  writeTurnaroundIO(IO_PIN);
}

void test_read_turnaround(){
  setPinToInput_Expect(IO_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);

  readTurnaroundIO(IO_PIN);
}

void test_writeData_given_0xCD_and_addr_0xDEAD_and_data_0xC0_should_send_out_0xCdDEADC0(void)
{
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinToInput_Expect(IO_PIN);
  
  while_loop_for_checking_the_writeData(0xCDDEADC0, 31);

  writeData(0xCD, 0xDEAD, 0xC0);
}

void test_readData_given_0xAB_and_addr_0xFACE_should_send_0xFACEAB_and_turnaround_and_receive_0xBE(void)
{
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinToInput_Expect(IO_PIN);
  
  //writeTurnaround
  setPinToOutput_Expect(IO_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  
//  uint32_t fullData = 0xABFACE;  
  while_loop_for_checking_the_writeData(0xABFACE, 23);
/*  while(i!=0){
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
  } */
  //readTurnaround
  setPinToInput_Expect(IO_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  
  //readBit
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  readPin_ExpectAndReturn(IO_PIN,0xBE);

  uint32_t receivedData = readData(0xAB, 0xFACE);
  TEST_ASSERT_EQUAL(0xBE,receivedData);
}



