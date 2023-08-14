/*
 * The MIT License
 *
 * Copyright (c) 2023 Giovanni di Dio Bruno https://gbr1.github.io
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "ucPack.h"


//Declare a packetizer with buffer size. Optionally you can add a custom index byte and end stop byte 
ucPack pack(100);

void setup(){
    Serial.begin(115200);
    while(!Serial);

    Serial.println("Begin test");
}

void loop(){
    // Some dumb variables to be shipped
    uint8_t sent_code = 'C';
    float sent_value = 1.23;

    // Here the ucPack convert data and load in the "msg" internal buffer. The size of this buffer is returned, too.
    uint8_t pack_size = pack.packetC1F(sent_code,sent_value);

    Serial.print("sent packet:\t");
    Serial.print(sent_code);
    Serial.print("\t");
    Serial.println(sent_value);

    // Here you load the output buffer (msg) into the input buffer (pack.buffer). Generally you do this using a serial transmission
    for (int i = 0; i<pack_size; i++){
        pack.buffer.push(pack.msg[i]);
    }

    // checkPayload do a formal check if some data is available and in the format of a ucPack packet
    if (pack.checkPayload()){
        Serial.println("new packet available!");
        Serial.print("code:\t");
        // Here you can get the code inside the message
        Serial.println(pack.payloadTop());
        

        // Prepare two variables for the unpacket
        uint8_t received_code;
        float received_value;
        pack.unpacketC1F(received_code,received_value);

        // Received data
        Serial.print("received packet:\t");
        Serial.print(received_code);
        Serial.print("\t");
        Serial.println(received_value);
    }

    delay(10000);
}