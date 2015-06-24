/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_SIGNAL_H
#define _MOCK_SIGNAL_H

#include "Signal.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC)
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_Signal_Init(void);
void mock_Signal_Destroy(void);
void mock_Signal_Verify(void);




#define setPinHigh_Ignore() setPinHigh_CMockIgnore()
void setPinHigh_CMockIgnore(void);
#define setPinHigh_Expect(pinNo) setPinHigh_CMockExpect(__LINE__, pinNo)
void setPinHigh_CMockExpect(UNITY_LINE_TYPE cmock_line, int pinNo);
typedef void (* CMOCK_setPinHigh_CALLBACK)(int pinNo, int cmock_num_calls);
void setPinHigh_StubWithCallback(CMOCK_setPinHigh_CALLBACK Callback);
#define setPinLow_Ignore() setPinLow_CMockIgnore()
void setPinLow_CMockIgnore(void);
#define setPinLow_Expect(pinNo) setPinLow_CMockExpect(__LINE__, pinNo)
void setPinLow_CMockExpect(UNITY_LINE_TYPE cmock_line, int pinNo);
typedef void (* CMOCK_setPinLow_CALLBACK)(int pinNo, int cmock_num_calls);
void setPinLow_StubWithCallback(CMOCK_setPinLow_CALLBACK Callback);
#define readPin_IgnoreAndReturn(cmock_retval) readPin_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void readPin_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define readPin_ExpectAndReturn(pinNo, cmock_retval) readPin_CMockExpectAndReturn(__LINE__, pinNo, cmock_retval)
void readPin_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int pinNo, int cmock_to_return);
typedef int (* CMOCK_readPin_CALLBACK)(int pinNo, int cmock_num_calls);
void readPin_StubWithCallback(CMOCK_readPin_CALLBACK Callback);
#define setPinToOutput_Ignore() setPinToOutput_CMockIgnore()
void setPinToOutput_CMockIgnore(void);
#define setPinToOutput_Expect(pinNo) setPinToOutput_CMockExpect(__LINE__, pinNo)
void setPinToOutput_CMockExpect(UNITY_LINE_TYPE cmock_line, int pinNo);
typedef void (* CMOCK_setPinToOutput_CALLBACK)(int pinNo, int cmock_num_calls);
void setPinToOutput_StubWithCallback(CMOCK_setPinToOutput_CALLBACK Callback);
#define setPinToInput_Ignore() setPinToInput_CMockIgnore()
void setPinToInput_CMockIgnore(void);
#define setPinToInput_Expect(pinNo) setPinToInput_CMockExpect(__LINE__, pinNo)
void setPinToInput_CMockExpect(UNITY_LINE_TYPE cmock_line, int pinNo);
typedef void (* CMOCK_setPinToInput_CALLBACK)(int pinNo, int cmock_num_calls);
void setPinToInput_StubWithCallback(CMOCK_setPinToInput_CALLBACK Callback);

#endif