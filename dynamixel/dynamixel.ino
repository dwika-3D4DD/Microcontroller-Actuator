#include <Dynamixel_Serial.h>

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
  int sudutBaru;

void setup(){
Dynamixel.begin(1000000,2);  // Inicialize the servo at 1Mbps and Pin Control 2
}

void loop(){
  
  L1 = sqrt (x*x + y*y);
  gamma = atan (x/y) * derajat + 15;

  L = sqrt ((L1 - cx) * (L1 - cx) + Z * Z);
  betta = acos((tb*tb + fm*fm - L*L)/(2*tb*fm)) * derajat + 15;

  alpha1 = acos (Z/L) * derajat;
  alpha2 = acos ((fm*fm + L*L - tb*tb)/(2*fm*L)) * derajat;
  alpha = alpha1 + alpha2;
  sudutBaru = 300 - alpha - 15;
  
  gamma = map(gamma, 0, 300, 0, 1023);
  betta = map (betta, 0, 300, 0, 1023);
  sudutBaru = map (sudutBaru, 0, 300, 0, 1023);

  for (int i = 1; i <= 12; i+= 3){
    Dynamixel.move(i,(gamma));
  }
   for (int i = 2; i <= 12; i+= 3){
    Dynamixel.move(i,(betta));
  }
   for (int i = 3; i <= 12; i+= 3){
    Dynamixel.move(i,(sudutBaru));
  }
} 
