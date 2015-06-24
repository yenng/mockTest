#include "mock_Signal.h"
#include "Communication.h"
#include "unity.h"




void setUp(void){}



void tearDown(void){}



void while_loop_for_checking_the_writeData(uint32_t fullData, int i){

 uint8_t bData;



 while(i!=0){

    bData = fullData >> i & 0x00000001;

    if (bData == 0x00000000){

      setPinLow_CMockExpect(16, 5);

      setPinHigh_CMockExpect(17, 5);

      setPinLow_CMockExpect(18, 4);

      setPinToInput_CMockExpect(19, 4);

    }

    else{

      setPinLow_CMockExpect(22, 5);

      setPinHigh_CMockExpect(23, 5);

      setPinHigh_CMockExpect(24, 4);

      setPinToInput_CMockExpect(25, 4);

    }

    i--;

  }

}

void test_while_loop_for_checking_the_writeData(){



 setPinLow_CMockExpect(32, 5);

    setPinHigh_CMockExpect(33, 5);

    setPinLow_CMockExpect(34, 4);

    setPinToInput_CMockExpect(35, 4);





    setPinLow_CMockExpect(38, 5);

    setPinHigh_CMockExpect(39, 5);

    setPinHigh_CMockExpect(40, 4);

    setPinToInput_CMockExpect(41, 4);



 sendBitLow(4);

 sendBitHigh(4);

}

void test_sendBitHigh_give_xxx_should_xxx(){

  setPinLow_CMockExpect(47, 5);

  setPinHigh_CMockExpect(48, 5);

  setPinHigh_CMockExpect(49, 4);

  setPinToInput_CMockExpect(50, 4);

  sendBitHigh(4);

}



void test_sendBitLow_give_xxx_should_xxx(){

  setPinLow_CMockExpect(55, 5);

  setPinHigh_CMockExpect(56, 5);

  setPinLow_CMockExpect(57, 4);

  setPinToInput_CMockExpect(58, 4);

  sendBitLow(4);

}



void test_readBit_give_xxx_should_xxx(){

  setPinHigh_CMockExpect(63, 5);

  setPinLow_CMockExpect(64, 5);

  readPin_CMockExpectAndReturn(65, 4, 4);

  uint32_t bit = readBit(4);

}



void test_write_turnaround(){

  setPinToOutput_CMockExpect(70, 4);

  setPinHigh_CMockExpect(71, 5);

  setPinLow_CMockExpect(72, 5);



  writeTurnaroundIO(4);

}



void test_read_turnaround(){

  setPinToInput_CMockExpect(78, 4);

  setPinLow_CMockExpect(79, 5);

  setPinHigh_CMockExpect(80, 5);



  readTurnaroundIO(4);

}



void test_writeData_given_0xCD_and_addr_0xDEAD_and_data_0xC0_should_send_out_0xCdDEADC0(void)

{

  setPinHigh_CMockExpect(87, 5);

  setPinLow_CMockExpect(88, 5);

  setPinToInput_CMockExpect(89, 4);



  while_loop_for_checking_the_writeData(0xCDDEADC0, 31);



  writeData(0xCD, 0xDEAD, 0xC0);

}



void test_readData_given_0xAB_and_addr_0xFACE_should_send_0xFACEAB_and_turnaround_and_receive_0xBE(void)

{

  setPinLow_CMockExpect(98, 5);

  setPinHigh_CMockExpect(99, 5);

  setPinToInput_CMockExpect(100, 4);





  setPinToOutput_CMockExpect(103, 4);

  setPinHigh_CMockExpect(104, 5);

  setPinLow_CMockExpect(105, 5);





  while_loop_for_checking_the_writeData(0xABFACE, 23);

  setPinToInput_CMockExpect(126, 4);

  setPinLow_CMockExpect(127, 5);

  setPinHigh_CMockExpect(128, 5);





  setPinHigh_CMockExpect(131, 5);

  setPinLow_CMockExpect(132, 5);

  readPin_CMockExpectAndReturn(133, 4, 0xBE);



  uint32_t receivedData = readData(0xAB, 0xFACE);

  UnityAssertEqualNumber((_U_SINT)((0xBE)), (_U_SINT)((receivedData)), (((void *)0)), (_U_UINT)136, UNITY_DISPLAY_STYLE_INT);

}
