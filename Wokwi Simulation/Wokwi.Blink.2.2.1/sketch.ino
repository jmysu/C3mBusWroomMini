/*
 * C3mBus LED Blink 2+2+1
 */
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //delay(100);
  Serial.print("\n---C3mBusMini Blink---");
  delay(500);
  Serial.end();

  pinMode(0, OUTPUT); //AD0
  pinMode(1, OUTPUT); //IO1
 
  pinMode(21, OUTPUT); //TX21
  pinMode(20, OUTPUT); //Change RX20 to Output
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite( 0, LOW);
  digitalWrite( 1, HIGH);
 
  digitalWrite(20, LOW);
  digitalWrite(21, HIGH);
  delay(1000); // this speeds up the simulation

  digitalWrite( 0, HIGH);
  digitalWrite( 1, LOW);
 
  digitalWrite(20, HIGH);
  digitalWrite(21, LOW);
  delay(1000); // this speeds up the simulation
}