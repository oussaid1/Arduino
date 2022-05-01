
int delayInMSec = 100;
int onOffDelay = 300 ;
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  pattern1();
  pattern2();
  pattern3();
  pattern4();
  pattern5();
  pattern6();
   pattern3();
  pattern4();
}

void pattern1() {
  blinkred1(13, delayInMSec);
  blinkred1(12, delayInMSec);
  blinkred1(11, delayInMSec);
  blinkred1(10, delayInMSec);
  blinkred1(9, delayInMSec);



}

void pattern2() {
  blinkred1(2, delayInMSec);
  blinkred1(3, delayInMSec);
  blinkred1(4, delayInMSec);
  blinkred1(5, delayInMSec);
  blinkred1(6, delayInMSec);


}
void pattern3() {
  blinkONOFF();
  blinkONOFF();
  blinkONOFF();
  blinkONOFF();
  blinkONOFF();

}
void pattern4() {
  blinkONOFFHalf();
  blinkONOFFHalf();
  blinkONOFFHalf();
  blinkONOFFHalf();

}
void pattern5() {
  oneOnOff(2);
  oneOnOff(3);
  oneOnOff(4);
  oneOnOff(5);
  oneOnOff(6);
  oneOnOff(7);
  oneOnOff(8);
  oneOnOff(9);
  oneOnOff(10);
  oneOnOff(11);
  oneOnOff(12);
  oneOnOff(13);

}
void pattern6() {
  oneOnOff(13);
  oneOnOff(12);
  oneOnOff(11);
  oneOnOff(10);
  oneOnOff(9);
  oneOnOff(8);
  oneOnOff(7);
  oneOnOff(6);
  oneOnOff(5);
  oneOnOff(4);
  oneOnOff(3);
  oneOnOff(2);

}
void blinkred1(int pin, int delayInmilisec) {
  digitalWrite(pin, HIGH);
  delay(delayInmilisec);
  digitalWrite(pin, LOW);
  delay(delayInmilisec);
}

void blinkONOFF() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  delay(onOffDelay);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(onOffDelay);
}

void blinkONOFFHalf() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  // delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  delay(onOffDelay);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  // delay(500);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  delay(onOffDelay);
}
void oneOnOff(int pinN) {
  digitalWrite(pinN, HIGH);
  delay(onOffDelay);
  digitalWrite(pinN, LOW);
  delay(50);
}

void oneOnOffINVER(int pinN) {
  digitalWrite(pinN, LOW);
  delay(onOffDelay);
  digitalWrite(pinN, HIGH);
  delay(50);
}
