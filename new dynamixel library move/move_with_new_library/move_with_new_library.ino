#include <Dynamixel2Arduino.h>

// Please modify it to suit your hardware.
#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560)
//#include <SoftwareSerial.h>
//SoftwareSerial soft_serial(7, 8); // pke klo arduino uno/nano
#define DXL_SERIAL   Serial1
#define DEBUG_SERIAL Serial
#else // Other boards when using DynamixelShield
#define DXL_SERIAL   Serial1
#define DEBUG_SERIAL Serial
#endif

#define DXL_DIR_PIN                 31
#define GOAL_POSITION_ADDR          30
#define GOAL_POSITION_ADDR_LEN      2

#define TIMEOUT 10    //default communication timeout 10ms

const float DXL_PROTOCOL_VERSION = 1.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

//ukuran kaki
//coxa untuk servo 1-2, femur unuk servo 2-3, tibia untuk servo 3-tanah
float coxa = 37.5, tibia = 89, femur = 60;
//tinggi dari bawah robot ke tanah (femur 15 derajat)
float height = 73.47;

//posisi awal robot (x dan y)
float startPos = 67.50;         //posisi agar tibia bisa tegak dan femur 0 derajat (lurus horizontal)
float alpha, beta, gama;       //sudut-sudut tiap servo setelah dihitung di inverse kinematics

//ID servo
unsigned char servoID[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
//ID servo tiap arah
unsigned char servoID_fl[] = {1, 2, 3};
unsigned char servoID_fr[] = {4, 5, 6};
unsigned char servoID_br[] = {7, 8, 9};
unsigned char servoID_bl[] = {10, 11, 12};

int move_counter = 0;

void setup() {
  DEBUG_SERIAL.begin(115200);   //Set debugging port baudrate to 115200bps
  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  //  for (int i = 1; i <= 12; i++){
  //  dxl.setGoalVelocity(servoID[i], 1023);
  //  }

  // Turn off torque when configuring items in EEPROM area
//  for (int i = 1; i <= 3; i++){
//  dxl.torqueOff(i);
//  dxl.setOperatingMode(i, OP_POSITION);
//  dxl.torqueOn(i);
//
//  dxl.writeControlTableItem(PROFILE_ACCELERATION, i, 0);
//  dxl.writeControlTableItem(PROFILE_VELOCITY, i, 0);
//  }
  standby_1();
  delay (1000);
}

void loop() {
  move_1(0, 30, 10);
  //  // put your main code here, to run repeatedly:
  //  move_1(0, 20, 10);
  //  DEBUG_SERIAL.print("alpha :");
  //  DEBUG_SERIAL.println(dxl.getPresentPosition(1, UNIT_RAW));
  //  DEBUG_SERIAL.print("beta :");
  //  DEBUG_SERIAL.println(dxl.getPresentPosition(2, UNIT_RAW));
  //  DEBUG_SERIAL.print("gamma :");
  //  DEBUG_SERIAL.println(dxl.getPresentPosition(3, UNIT_RAW));
  //  DEBUG_SERIAL.print("alpha:");
  //  DEBUG_SERIAL.println(alpha);
  //  DEBUG_SERIAL.print("beta");
  //  DEBUG_SERIAL.println(beta);
  //  DEBUG_SERIAL.print("gamma");
  //  DEBUG_SERIAL.println(gama);
  //  delay(2000);
  //  dxl.setGoalPosition(1, 0);
  //  delay(1000);
  //  DEBUG_SERIAL.print("present position :");
  //  DEBUG_SERIAL.println(dxl.getPresentPosition(1));
  //  dxl.setGoalPosition(1, 1023);
  //  delay(1000);
  //  DEBUG_SERIAL.print("present position :");
  //  DEBUG_SERIAL.println(dxl.getPresentPosition(1));
  //  delay(10);
}
