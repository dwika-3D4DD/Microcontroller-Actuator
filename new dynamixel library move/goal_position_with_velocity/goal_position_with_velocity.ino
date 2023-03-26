#include <Dynamixel2Arduino.h>

// Please modify it to suit your hardware.
#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560) 
  //#include <SoftwareSerial.h> 
  //SoftwareSerial soft_serial(7, 8); // pke klo arduino uno/nano
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL Serial
  const uint8_t DXL_DIR_PIN = 2; 
#else // Other boards when using DynamixelShield
  #define DXL_SERIAL   Serial1
  #define DEBUG_SERIAL Serial
  const uint8_t DXL_DIR_PIN = 2; 
#endif

//Please see eManual Control Table section of your DYNAMIXEL.
//This example is written for DYNAMIXEL AX & MX series with Protocol 1.0.
//For MX 2.0 with Protocol 2.0, refer to write_x.ino example.
#define CW_ANGLE_LIMIT_ADDR         6
#define CCW_ANGLE_LIMIT_ADDR        8
#define ANGLE_LIMIT_ADDR_LEN        2
#define OPERATING_MODE_ADDR_LEN     2
#define TORQUE_ENABLE_ADDR          24
#define TORQUE_ENABLE_ADDR_LEN      1
#define LED_ADDR                    25
#define LED_ADDR_LEN                1
#define GOAL_POSITION_ADDR          30
#define GOAL_POSITION_ADDR_LEN      2
#define PRESENT_POSITION_ADDR       36
#define PRESENT_POSITION_ADDR_LEN   2
#define TIMEOUT 10    //default communication timeout 10ms

uint8_t turn_on = 1;
uint8_t turn_off = 0;

const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 1.0;

uint16_t goalPosition1 = 0;
uint16_t goalPosition2 = 1023;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

void setup() {
  
  DEBUG_SERIAL.begin(115200);   //Set debugging port baudrate to 115200bps
  while(!DEBUG_SERIAL);         //Wait until the serial port for terminal is opened
  
  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(1000000);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

//  // Turn off torque when configuring items in EEPROM area
//  if(dxl.write(DXL_ID, TORQUE_ENABLE_ADDR, (uint8_t*)&turn_off , TORQUE_ENABLE_ADDR_LEN, TIMEOUT))
//    DEBUG_SERIAL.println("DYNAMIXEL Torque off");
//  else
//    DEBUG_SERIAL.println("Error: Torque off failed");
//
//  // Set to Joint Mode
//  if(dxl.write(DXL_ID, CW_ANGLE_LIMIT_ADDR, (uint8_t*)&goalPosition1, ANGLE_LIMIT_ADDR_LEN, TIMEOUT)
//        && dxl.write(DXL_ID, CCW_ANGLE_LIMIT_ADDR, (uint8_t*)&goalPosition2, ANGLE_LIMIT_ADDR_LEN, TIMEOUT))
//    DEBUG_SERIAL.println("Set operating mode");
//  else
//    DEBUG_SERIAL.println("Error: Set operating mode failed");
//
//  // Turn on torque
//  if(dxl.write(DXL_ID, TORQUE_ENABLE_ADDR, (uint8_t*)&turn_on, TORQUE_ENABLE_ADDR_LEN, TIMEOUT))
//    DEBUG_SERIAL.println("Torque on");
//  else
//    DEBUG_SERIAL.println("Error: Torque on failed");
}

void loop() {
  
//  // Set Goal Position
//  DEBUG_SERIAL.print("Goal Position : ");
//  DEBUG_SERIAL.println(goalPosition1);
//  dxl.write(DXL_ID, GOAL_POSITION_ADDR, (uint8_t*)&goalPosition1, GOAL_POSITION_ADDR_LEN, TIMEOUT);
//  delay(1000);
//  
//   // Please refer to e-Manual(http://emanual.robotis.com) for available range of value. 
//  // Set Goal Velocity using RAW unit
//  dxl.setGoalVelocity(DXL_ID, 1023);
//  delay(1000);
//  // Print present velocity
//  DEBUG_SERIAL.print("Present Velocity(raw) : ");
//  DEBUG_SERIAL.println(dxl.getPresentVelocity(DXL_ID));
//  delay(1000);
//
//    // Set Goal Position
//  DEBUG_SERIAL.print("Goal Position : ");
//  DEBUG_SERIAL.println(goalPosition2);
//  dxl.write(DXL_ID, GOAL_POSITION_ADDR, (uint8_t*)&goalPosition2, GOAL_POSITION_ADDR_LEN, TIMEOUT);
//  delay(1000);

    // Set Goal Position
  DEBUG_SERIAL.print("Goal Position : ");
  DEBUG_SERIAL.println(goalPosition1);
  dxl.write(DXL_ID, GOAL_POSITION_ADDR, (uint8_t*)&goalPosition1, GOAL_POSITION_ADDR_LEN, TIMEOUT);
  delay(1000);

  // Set Goal Velocity using RPM
  dxl.setGoalVelocity(DXL_ID, 25.8, UNIT_RPM);
  delay(1000);
  DEBUG_SERIAL.print("Present Velocity(rpm) : ");
  DEBUG_SERIAL.println(dxl.getPresentVelocity(DXL_ID, UNIT_RPM));
  delay(1000);

     // Set Goal Position
  DEBUG_SERIAL.print("Goal Position : ");
  DEBUG_SERIAL.println(goalPosition2);
  dxl.write(DXL_ID, GOAL_POSITION_ADDR, (uint8_t*)&goalPosition2, GOAL_POSITION_ADDR_LEN, TIMEOUT);
  delay(1000);
//
//    // Set Goal Position
//  DEBUG_SERIAL.print("Goal Position : ");
//  DEBUG_SERIAL.println(goalPosition1);
//  dxl.write(DXL_ID, GOAL_POSITION_ADDR, (uint8_t*)&goalPosition1, GOAL_POSITION_ADDR_LEN, TIMEOUT);
//  delay(1000);
//
//  // Set Goal Velocity using percentage (-100.0 [%] ~ 100.0 [%])
//  dxl.setGoalVelocity(DXL_ID, -10.2, UNIT_PERCENT);
//  delay(1000);
//  DEBUG_SERIAL.print("Present Velocity(ratio) : ");
//  DEBUG_SERIAL.println(dxl.getPresentVelocity(DXL_ID, UNIT_PERCENT));
//  delay(1000);
//
//     // Set Goal Position
//  DEBUG_SERIAL.print("Goal Position : ");
//  DEBUG_SERIAL.println(goalPosition2);
//  dxl.write(DXL_ID, GOAL_POSITION_ADDR, (uint8_t*)&goalPosition2, GOAL_POSITION_ADDR_LEN, TIMEOUT);
//  delay(1000);
  
}
