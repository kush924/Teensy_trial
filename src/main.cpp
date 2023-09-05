#include <Arduino.h>
#include <FlexCAN_T4.h>

// void setup() {
// pinMode(13,OUTPUT);
// Serial.begin(9600);
// }

// void loop() {
//   digitalWrite(13,HIGH);
//   delay(1000);
//   digitalWrite(13,LOW);
//   delay(1000);
//   Serial.println("Hello_world");
// }


FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;
CAN_message_t msg;

void setup(void) {
  Serial.begin(9600);
  can1.begin();
  can1.setBaudRate(1000000);
}

void loop() {
  if ( can1.read(msg) ) {
    Serial.print("msg  ");
    for(int i = 0; i <8 ; i++){
    Serial.print(msg.buf[i]);  
    }
    Serial.println("  end");
  }
  
}
