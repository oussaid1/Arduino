#include <Servo.h>
#include "NewPing.h"
#include <IRremote.h>  //including infrared remote header file    
Servo myservo;  // create servo object to control a servo
///
const int iRRadarPin  = A0;

int iRRadarDistance  = 0;

///
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
#define echoPin 6 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 7 //attach pin D3 Arduino to pin Trig of HC-SR04
#define maxDistance 400 //attach pin D3 Arduino to pin Trig of HC-SR04
# define orangeLight 5
# define greenLight 4
# define irTestPin 2
////////////////////
// remote init
int RECV_PIN = 3; // the pin where you connect the output pin of IR sensor
IRrecv irrecv(RECV_PIN);
decode_results results;
////////////////////
int pos = 0;
#define rightDrvPin 13 //pin for DC Motor // Right drive
#define leftDrvPin 12 //pin for DC Motor // Left drive
#define rightDrvPin2 11 //pin for DC Motor // Right drive
#define leftDrvPin2 10 //pin for DC Motor // Left drive

float duration; // variable for the duration of sound wave travel
float distance; // variable for the distance measurement

bool obstaclFront = false;

NewPing sonar(trigPin, echoPin, maxDistance);





void setup() {
  irrecv.enableIRIn();
  //set the mode for drive pins
  pinMode(rightDrvPin, OUTPUT);
  pinMode(leftDrvPin, OUTPUT);
  pinMode(rightDrvPin2, OUTPUT);
  pinMode(leftDrvPin2, OUTPUT);
  pinMode(orangeLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
  myservo.attach(8);
  pinMode(iRRadarPin, INPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

void loop() {
 // ultrSonicRead();
  detectDistance();
  //zservoSweepLook();
 // getRemote();


  selfDrive();
}

void selfDrive() {drive();

  if (!obstaclFront) {
    stopDrive();
     delay(500);
//  //  servoLookRight();
//    turnRight();
//    delay(1000);
//    pos=0;
//    if (obstaclFront) {
//       drive();
//      }else{
//         servoLookLeft();
//    turnLeft();
//        
//        }
  }
}

// decode the remote code
void getRemote() {
  if (IrReceiver.decode()) {
    // Print a short summary of received data
    IrReceiver.printIRResultShort(&Serial);
    if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
      // We have an unknown protocol here, print more info
      IrReceiver.printIRResultRawFormatted(&Serial, true);
    }
    Serial.println();
    /*
       !!!Important!!! Enable receiving of the next value,
       since receiving has stopped after the end of the current received data packet.
    */
    IrReceiver.resume(); // Enable receiving of the next value

    /*
       Finally, check the received data and perform actions according to the received command
    */
    switch (IrReceiver.decodedIRData.command  ) {
      // up button pressed
      case 0x46: digitalWrite(irTestPin, HIGH);
        delay(10);
        digitalWrite(irTestPin, LOW);
        drive();
        break;
      // down button pressed
      case 0x15: digitalWrite(irTestPin, HIGH);
        delay(10);
        digitalWrite(irTestPin, LOW);
        backDrive();
        break;
      case 0x43: digitalWrite(irTestPin, HIGH);
        delay(10);
        digitalWrite(irTestPin, LOW);
        servoLookRight();
        turnRight();
        break;
      case 0x44: digitalWrite(irTestPin, HIGH);
        delay(10);
        digitalWrite(irTestPin, LOW);
        servoLookLeft();
        turnLeft();
        break;
      case 0x40: digitalWrite(irTestPin, HIGH);
        delay(10);
        digitalWrite(irTestPin, LOW);
        stopDrive();
        break;

    }
  }

}
//////


// using the distance sensor  BACK
void detectDistance( ) { /* function testGP2Y0A21 */
  ////Read distance sensor
  iRRadarDistance = analogRead(iRRadarPin);
  Serial.print(iRRadarDistance);

  if (iRRadarDistance < 200) {
    Serial.println(F("Obstacle detected front"));
    obstaclFront = true;
    digitalWrite(orangeLight, HIGH);
      digitalWrite(greenLight, LOW);

  } else {
    //  digitalWrite(orangeLight, LOW);
    Serial.println(F("No obstacle front"));
    digitalWrite(orangeLight, LOW);
    digitalWrite(greenLight, HIGH);
    obstaclFront = false;
  }
}







//
//
//int distRawToPhys(int raw) { /* function distRawToPhys */
//  ////IR Distance sensor conversion rule
//  float Vout = float(raw) * 0.0048828125; // Conversion analog to voltage
//  int phys = 13 * pow(Vout, -1); // Conversion volt to distance
//
//  return phys;
//}


// spin one wheel to drive Right
void turnRight() {
  digitalWrite(rightDrvPin, LOW);
  digitalWrite(leftDrvPin, HIGH);


}
// spin one wheel to drive Right
void turnLeft() {
  digitalWrite(rightDrvPin2, HIGH);
  digitalWrite(leftDrvPin2, LOW);


}
// brake
void stopDrive() {

  digitalWrite(rightDrvPin, LOW);
  digitalWrite(leftDrvPin, LOW);
  digitalWrite(rightDrvPin2, LOW);
  digitalWrite(leftDrvPin2, LOW);
}
// drive forward
void drive() {
  // digitalWrite(orangeLight, LOW);
  //digitalWrite(greenLight, HIGH);
  digitalWrite(rightDrvPin, LOW);
  digitalWrite(leftDrvPin, HIGH);
  digitalWrite(rightDrvPin2, LOW);
  digitalWrite(leftDrvPin2, HIGH);
}
// drive backwards
void backDrive() {
  // digitalWrite(orangeLight, HIGH);
  // digitalWrite(greenLight, LOW);
  digitalWrite(rightDrvPin, HIGH);
  digitalWrite(leftDrvPin, LOW);
  digitalWrite(rightDrvPin2, HIGH);
  digitalWrite(leftDrvPin2, LOW);
}


// look left right
void servoSweepLook() {

  for ( pos = 0; pos <= 100; pos += 1) {
    // in steps of 1 degree
    myservo.write(pos);
    delay(15);
  }

  for ( pos = 100; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}

// look  right
void servoLookRight() {
  pos = -180;
  myservo.write(pos);
  delay(15);
}

// look left
void servoLookLeft() {
  pos = 180;
  myservo.write(pos);
  delay(15);
}






//
void ultrSonicRead() {
  duration = sonar.ping();

  distance = (duration * 0.5) * 0.0343;
  //send results to the serial monitor

  if ( distance < 80) {
    Serial.println("Out Of Range ");
    //    stopDrive();
    //    turnLeft();
    //    delay(1000);
    //    backDrive();
    //    delay(1000);
    stopDrive();

  }
  else {
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.print(" cm ");
    //delay(500);

  }
  //delay(500);
}
