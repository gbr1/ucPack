
#include <ucPack.h>

ucPack packeter(210, 65, 35);

void setup() {
  Serial1.begin(115200);
}

void loop() {
  while (Serial1.available() > 0) {
    packeter.buffer.push(Serial1.read());
  }

  if (packeter.checkPayload()) {
      // parsing the packet

    Serial.println("got mail");
    uint8_t c = packeter.payloadTop();

    switch (c)
    {
    case 'E':
      float timeout;
      packeter.unpacketC1F(c, timeout);
      Serial.print("Enable command received ");
      Serial.print("timeout=");
      Serial.println(timeout);
      break;
    case 'J':
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
      break;
    case 'S':
      Serial.println("Stop command received");
      break;
    case 'G':
      float f1, f2;
      packeter.unpacketC2F(c,f1,f2);
      Serial.print("IMU command received");
      Serial.print(" f1=");
      Serial.print(f1);
      Serial.print(" f2=");
      Serial.println(f2);
      break;
    default:
      Serial.println("Unknown command received");
      break;
    }

  }

}