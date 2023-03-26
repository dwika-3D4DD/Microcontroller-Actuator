#include <Servo.h>

Servo servo1;//variable untuk menyimpan posisi data servo depan
Servo servo2;//variable untuk menyimpan posisi data servo belakang
int pos = 0;
int input = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(A0);  //sinyal data kabel motor servo dikonekan di pin A0 Arduino
  servo2.attach(A2);  //sinyal data kabel motor servo dikenakan di pin A2 Arduino
  servo1.write(180);  // posisi awal servo depan
  servo2.write(50);   //posisi awal servo belakang  
  delay(1000);
}

void loop() {
  if (Serial.available()) {
    input = Serial.parseInt();

    switch (input) {
      case 1:
        servo2.write(65);           //capit turun
        delay (200);
        Serial.println(input);
        
        servo1.write(125);          //capit menjepit
        delay(250);                       
        Serial.println(input);

        servo2.write(50);           //capit naik
        delay(200);                       
        Serial.println(input);
        break;

      case 2:
        servo2.write(65);           //capit turun 
        delay(200);                       
        Serial.println(input);

        servo1.write(180);          //capit buka ke posisi semula
        delay(200);                       
        Serial.println(input);

        servo2.write(50);           //capit naik ke posisi semula
        delay(200);
        Serial.println(input);
        break;
    }
  }
}
