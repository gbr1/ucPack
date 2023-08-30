#include <ucPack.h>

ucPack packeter(210, 65, 35);
uint8_t msg_size;

void setup() {
  Serial1.begin(115200);
}

void loop() {
    msg_size = packeter.packetC1F('E', 0.11);
    Serial1.write(packeter.msg, msg_size);
    delay(100);
    
    msg_size = packeter.packetC4F('J', 0.12, 1.13, 2.22, -5.0);
    Serial1.write(packeter.msg, msg_size);
    delay(100);
    
    msg_size = packeter.packetC2F('G', 1550.01, -2360.4789);
    Serial1.write(packeter.msg, msg_size);
    delay(100);
    
    msg_size = packeter.packetC1F('S', 0.0);
    Serial1.write(packeter.msg, msg_size);
    delay(100);
    
    Serial.println("Sent messages");
    delay(1000);

}