#include "mock_Signal.h"
#include "Communication.h"
#include "unity.h"




void setUp(void){}



void tearDown(void){}



void test_sendBitHigh_give_xxx_should_xxx(){

  setPinLow_CMockExpect(11, 5);

  setPinHigh_CMockExpect(12, 5);

  setPinHigh_CMockExpect(13, 4);

  setPinToInput_CMockExpect(14, 4);

  sendBitHigh(4);

}



void test_sendBitLow_give_xxx_should_xxx(){

  setPinLow_CMockExpect(19, 5);

  setPinHigh_CMockExpect(20, 5);

  setPinLow_CMockExpect(21, 4);

  setPinToInput_CMockExpect(22, 4);

  sendBitLow(4);

}



void test_readBit_give_xxx_should_xxx(){

  setPinHigh_CMockExpect(27, 5);

  setPinLow_CMockExpect(28, 5);

  readPin_CMockExpectAndReturn(29, 4, 4);

  uint32_t bit = readBit(4);

}





void test_writeData_given_0xCD_and_addr_0xDEAD_and_data_0xC0_should_send_out_0xCdDEADC0(void)

{

  setPinHigh_CMockExpect(36, 5);

  setPinLow_CMockExpect(37, 5);

  setPinToInput_CMockExpect(38, 4);





  int i=31;

  uint8_t bData;

  uint32_t fullData = 0xCDDEADC0;



  while(i!=0){

    bData = fullData >> i & 0x00000001;

    if (bData == 0x00000000){

      setPinLow_CMockExpect(48, 5);

      setPinHigh_CMockExpect(49, 5);

      setPinLow_CMockExpect(50, 4);

      setPinToInput_CMockExpect(51, 4);

    }

    else{

      setPinLow_CMockExpect(54, 5);

      setPinHigh_CMockExpect(55, 5);

      setPinHigh_CMockExpect(56, 4);

      setPinToInput_CMockExpect(57, 4);

    }

    i--;

  }

 writeData(0xCD, 0xDEAD, 0xC0);

}



void test_readData_given_0xAB_and_addr_0xFACE_should_send_0xFACEAB_and_turnaround_and_receive_0xBE(void)

{

  setPinLow_CMockExpect(66, 5);

 setPinHigh_CMockExpect(67, 5);

  setPinToInput_CMockExpect(68, 4);



  setPinToOutput_CMockExpect(70, 4);

  setPinHigh_CMockExpect(71, 5);

  setPinLow_CMockExpect(72, 5);



  int i=23;

  int j=7;

  uint8_t bData1,bData2;

  uint32_t fullData = 0xABFACE;

  uint32_t receivedData = 0xBE;



  while(i!=0){

    bData1 = fullData >> i & 0x00000001;

    if (bData1 == 0x00000000){

      setPinLow_CMockExpect(83, 5);

      setPinHigh_CMockExpect(84, 5);

      setPinLow_CMockExpect(85, 4);

      setPinToInput_CMockExpect(86, 4);

    }

    else{

      setPinLow_CMockExpect(89, 5);

      setPinHigh_CMockExpect(90, 5);

      setPinHigh_CMockExpect(91, 4);

      setPinToInput_CMockExpect(92, 4);

    }

    i--;

  }

  setPinToInput_CMockExpect(96, 4);

  setPinLow_CMockExpect(97, 5);

  setPinHigh_CMockExpect(98, 5);



  while(j!=0){

    bData2 = receivedData >> i & 0x00000001;

    if (bData2 == 0x00000000){

      setPinLow_CMockExpect(103, 5);

      setPinHigh_CMockExpect(104, 5);

      setPinLow_CMockExpect(105, 4);

      setPinToInput_CMockExpect(106, 4);

    }

    else{

      setPinLow_CMockExpect(109, 5);

      setPinHigh_CMockExpect(110, 5);

      setPinHigh_CMockExpect(111, 4);

      setPinToInput_CMockExpect(112, 4);

    }

    j--;

  }



  readData(0xAB, 0xFACE);

}
