# ucPack

ucPack - Unified C++ Packetizer

---

It is possible to use this library with Arduino or any other generic C++ framework.



## How to use

```c++
// declare ucPack class
ucPack pack(100,0x41,0x23);

// use the internal buffer
pack.buffer.push(<uint8_t value>);

// to check if a correct message is arrived
pack.checkPayload();


// compose a byte + 4 float packet
uint8_t size=pack.packetC4F('C',1.23,-3.14,90.0,45.0);


// to unpack
char c;
float f1,f2,f3,f4;
pack.unpacketC4F(c, f1, f2, f3, f4);

```



## How it works

A packet is managed as:

| index_byte           | message length | message                     | stop_byte            | crc8   |
|:--------------------:|:--------------:|:---------------------------:|:--------------------:|:------:|
| 1 byte (_default A_) | 1 byte         | N bytes from message length | 1 byte (_default #_) | 1 byte |



## Todo

- check all functions

- add variadic compose and unpack



> ***Copyright © 2022 Giovanni di Dio Bruno under MIT License.***
