
const int analogInPin = A0;  

int sensorValue = 0; 
void setup() {
  // put your setup code here, to run once:
pinMode(3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(analogInPin);
int g=3; //BLUE
int Z=sensorValue/2; //ZAPOVNENNYA
analogWrite(g, 255-Z);// Для фоторезистора
//analogWrite(g, Z);// Для терморезистора
delay(10);
}
