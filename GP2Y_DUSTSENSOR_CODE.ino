#define S0 5
#define S1 18
#define S2 19
#define S3 23
#define analogpin 35
#define led_pin 2
int sensor_8;
float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;
int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;
void setup() {
pinMode(analogpin, INPUT);
pinMode(S0,OUTPUT);
pinMode(S1,OUTPUT);
pinMode(S2,OUTPUT);
pinMode(S3,OUTPUT);
pinMode(sensor_8, INPUT);
pinMode(led_pin, OUTPUT);
Serial.begin(9600);
 
}

void loop() {
  digitalWrite(led_pin,LOW);
  delayMicroseconds(samplingTime);
  digitalWrite(S0,LOW); digitalWrite(S1,LOW); digitalWrite(S2,LOW); digitalWrite(S3,HIGH);
  sensor_8 = analogRead(analogpin);
  delayMicroseconds(deltaTime);
  digitalWrite(led_pin,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);
  calcVoltage = voMeasured * (5.0 / 1024.0);
  dustDensity = 0.17 * calcVoltage - 0.1;
  Serial.println(dustDensity);
}
