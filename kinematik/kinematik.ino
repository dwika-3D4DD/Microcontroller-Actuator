#include <DynamixelSerial.h>
#include <math.h>

float tb = 105, fm = 50 , cx = 37.5; 
float l, l1;
float a, b, gamma;
float tinggi = 105;

void reverse(float x, float y, float z);
void stand();
void walk(float x, float y );

void setup(){
    Dynamixel.begin(1000000,2); 
}

void loop(){
  //stand();

  delay(3000);
  walk(10, 10);
}

void reverse(float x, float y, float z){
    z = tinggi - z;   

    l1 = sqrt((x * x) + (y * y));
    l = sqrt(((l1 - cx) * (l1 - cx)) + (z * z));
    gamma = atan(x / y);
    gamma = gamma * 57.296;
    b = acos(((tb * tb) + (fm * fm) - (l * l)) / (2 * tb * fm)); 
    b = b * 57.296;
  
    a = (acos(z / l) * 57.296) + (acos(((fm * fm) + (l * l) - (tb * tb)) / (2 * fm * l)) * 57.296);
    
    a = 300 - a -15;
    b += 15;
    gamma += 15;
    
    a = map(a, 0, 300, 0, 1023);
    b = map(b, 0, 300, 0, 1023);
    gamma = map(gamma, 0, 300, 0, 1023);
}

void stand(){
    float x = 61.8; 
    float y = 61.8; 
    float z = 0;

    reverse(x,y,z);
    for(int i = 1; i <= 12; i += 3){
       Dynamixel.move(i, gamma);
    }
    for(int i = 2; i <= 12; i += 3){
       Dynamixel.move(i, b);
    }
    for(int i = 3; i <= 12; i += 3){
       Dynamixel.move(i, a);
    }
}

void walk(float x, float y ){
  float z = -10;
  reverse(61.8,61.8,z);
  
  Dynamixel.move(1, gamma);
  Dynamixel.move(7, gamma);
  Dynamixel.move(2, b);
  Dynamixel.move(8, b);
  Dynamixel.move(3, a);
  Dynamixel.move(9, a);
  delay(500);
  
  z = -10;
  reverse(x,y,z);

  Dynamixel.move(1, gamma);
  Dynamixel.move(7, gamma);
  Dynamixel.move(2, b);
  Dynamixel.move(8, b);
  Dynamixel.move(3, a);
  Dynamixel.move(9, a);
  delay(500);
  
  z = 0;
  reverse(61.8,61.8,z);
  Dynamixel.move(1, gamma);
  Dynamixel.move(7, gamma);
  Dynamixel.move(2, b);
  Dynamixel.move(8, b);
  Dynamixel.move(3, a);
  Dynamixel.move(9, a);
  delay(500);
}
