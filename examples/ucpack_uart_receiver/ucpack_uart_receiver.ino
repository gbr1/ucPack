
#include <ucPack.h>

ucPack packeter(210, 65, 35);

void setup() {
  Serial1.begin(115200, SERIAL_8E1);	// Expects 8bits, Even parity, 1 Stopbit
}

void loop() {
  while (Serial1.available() > 0) {
    packeter.buffer.push(Serial1.read());
  }

  if (packeter.checkPayload()) {
      // parsing the packet

    Serial.println("got mail");
    uint8_t c = packeter.payloadTop();

    if (c == 'E') {
      float timeout;
      packeter.unpacketC1F(c, timeout);
      Serial.print("Enable command received ");
      Serial.print("timeout=");
      Serial.println(timeout);
    } 
    else if (c == 'J') {
      float f1, f2, f3, f4;
      packeter.unpacketC4F(c,f1,f2,f3,f4);
      Serial.print("Joint movement command received");
      Serial.print(" f1=");
      Serial.print(f1);
      Serial.print(" f2=");
      Serial.print(f2);
      Serial.print(" f3=");
      Serial.print(f3);
      Serial.print(" f4=");
      Serial.println(f4);
    }
    else if (c == 'S') {
      Serial.println("Stop command received");
    }
    else if (c == 'G') {
      float f1, f2;
      packeter.unpacketC2F(c,f1,f2);
      Serial.print("IMU command received");
      Serial.print(" f1=");
      Serial.print(f1);
      Serial.print(" f2=");
      Serial.println(f2);
    }
    else {
      Serial.println("Unknown command received");
    }

  }

}