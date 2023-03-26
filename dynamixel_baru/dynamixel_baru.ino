#include <DynamixelSerial.h>
#include <math.h>

  float x = 68.9;
  float y = 68.9;
  float z = 0;
  float cx = 37.5; //dalam mm
  float fm = 60; //dalam mm
  float tb = 105; //dalam mm
  float Z = 105;
  float L1, L;
  float alpha,betta,gamma;
  float derajat = 180 / 3.1415;
  float alpha1, alpha2;


void setup(){
Dynamixel.begin(1000000,2);  // Inicialize the servo at 1Mbps and Pin Control 2
}

void loop(){
stand();
//delay (1000);
//walk(10, 10);
}
  void reverse (float x,float y,float z){
  Z = Z - z;
  
  L1 = sqrt (x*x + y*y);
  gamma = atan (x/y) * derajat + 15;

  L = sqrt ((L1 - cx) * (L1 - cx) + Z * Z);
  betta = acos((tb*tb + fm*fm - L*L)/(2*tb*fm)) * derajat + 15;

  alpha1 = acos (Z/L) * derajat;
  alpha2 = acos ((fm*fm + L*L - tb*tb)/(2*fm*L)) * derajat;
  alpha = 300 - (alpha1 + alpha2) - 15;
  
  gamma = map(gamma, 0, 300, 0, 1023);
  betta = map (betta, 0, 300, 0, 1023);
  alpha = map (alpha, 0, 300, 0, 1023);
}

  void stand (){
    reverse(x,y,z);
  for (int i = 1; i <= 12; i+= 3){ 
    Dynamixel.move(i,(gamma));
  }
   for (int i = 2; i <= 12; i+= 3){
    Dynamixel.move(i,(betta));
  }
   for (int i = 3; i <= 12; i+= 3){
    Dynamixel.move(i,(alpha));
  }
}

void walk (float x, float y ){
 float z = -10;
  reverse(68.9,68.9,z);
  
  Dynamixel.move(1, gamma);
  Dynamixel.move(7, gamma);
  Dynamixel.move(2, betta);
  Dynamixel.move(8, betta);
  Dynamixel.move(3, alpha);
  Dynamixel.move(9, alpha);
  delay(500);
  
  z = -10;
  reverse(58.9,58.9,z);

  Dynamixel.move(1, gamma);
  Dynamixel.move(7, gamma);
  Dynamixel.move(2, betta);
  Dynamixel.move(8, betta);
  Dynamixel.move(3, alpha);
  Dynamixel.move(9, alpha);
  delay(500);
  
  z = 0;
  reverse(68.9,68.9,z);
  Dynamixel.move(1, gamma);
  Dynamixel.move(7, gamma);
  Dynamixel.move(2, betta);
  Dynamixel.move(8, betta);
  Dynamixel.move(3, alpha);
  Dynamixel.move(9, alpha);
  delay(500);
}
