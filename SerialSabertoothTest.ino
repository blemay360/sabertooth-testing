//#define FWD = 0x00


//int output = 13; //output to Sabertooth
int pot = 5; //analog pin to plug potentiometer into
int potValue; //value to read from potentiometer

void setup() {
  delay(2000);
  Serial.begin(9600);
  Serial.write(0xAA); //Makes Sabertooth automatically detect baud rate in packetized serial mode
  }

void loop() {
 potValue = map(analogRead(pot), 0, 1023, 0, 127); //Maps the analog input from the potentiometer from 0 to 1023 to 0 to 127, the range of the speed value for the sabertooth
 Serial.write(128); //address
 Serial.write(0); //Command, 0 is to turn motor 1 forward
 Serial.write(potValue);  //speed
 Serial.write((128 + 0 + potValue) & 0b01111111); //This sends a packet to a Sabertooth at address 128, to go forward on channel 1 at a speed set by the potentiometer
 delay(10);
}
/*
void leftDriveForward(int speed) {
  int address = 128;
  Serial.write(address);
  Serial.write(0);
  Serial.write(speed);
  Serial.write((address + 0 + speed) & 0b01111111);
  Serial.write(address);
  Serial.write(4);
  Serial.write(speed);
  Serial.write((address + 4 + speed) & 0b01111111);
}

void rightDriveForward(int speed) {
  int address = 129;
  Serial.write(address);
  Serial.write(0);
  Serial.write(speed);
  Serial.write((address + 0 + speed) & 0b01111111);
  Serial.write(address);
  Serial.write(4);
  Serial.write(speed);
  Serial.write((address + 4 + speed) & 0b01111111);
}

void leftDriveBackward(int speed) {
  int address = 128;
  Serial.write(address);
  Serial.write(1);
  Serial.write(speed);
  Serial.write((address + 1 + speed) & 0b01111111);
  Serial.write(address);
  Serial.write(5);
  Serial.write(speed);
  Serial.write((address + 5 + speed) & 0b01111111);
}

void rightDriveBackward(int speed) {
  int address = 129;
  Serial.write(address);
  Serial.write(1);
  Serial.write(speed);
  Serial.write((address + 1 + speed) & 0b01111111);
  Serial.write(address);
  Serial.write(5);
  Serial.write(speed);
  Serial.write((address + 5 + speed) & 0b01111111);
}

void DriveForward(int speed) {
  leftDriveForward(speed);
  rightDriveForward(speed);
}

void DriveBackward(int speed) {
  leftDriveBackward(speed);
  rightDriveBackward(speed);
}

void RightTurn(int speed) {
  leftDriveForward(speed);
  rightDriveBackward(speed);
}

void LeftTurn(int speed) {
  leftDriveBackward(speed);
  rightDriveBackward(speed);
}
*/
