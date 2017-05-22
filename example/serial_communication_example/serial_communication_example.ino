/*
  Test
 */

#define SerialSuperVisor Serial

#include "edgar_arm_communications.h"

TDataCommunicationsChannels *DataComm;
int led = 13;
unsigned long led_toggle_period=1000;
unsigned long start_time;
unsigned long start_time1;

void setup() {
  pinMode(led, OUTPUT);
  SerialSuperVisor.begin(115200);
  start_time = millis();
  start_time1 = millis();
  DataComm=InitEdgarArmCommunications();
  
  DataComm->dataTest2=-1234;
  DataComm->dataTest3=-12.34;
}

// the loop routine runs over and over again forever:
void loop() {
  while (SerialSuperVisor.available() > 0) {
    char receivedChannel=ProcessChannelsSerialData(SerialSuperVisor.read());
    switch (receivedChannel) {
    case 'g':
      led_toggle_period=DataComm->dataTest1;
      break;
    default:
      ;
    }
  }
  
  unsigned long delta_time=millis()-start_time;
  if(delta_time>=led_toggle_period){
    start_time = millis();
    int val=digitalRead(led);
    digitalWrite(led, !val);
  }
  
  unsigned long delta_time1=millis()-start_time1;
  if(delta_time1>=100){
    start_time1 = millis();
    SerialSuperVisor.write(SendChannell('r'));
  }  
}
