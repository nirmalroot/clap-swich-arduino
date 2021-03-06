int Sensor = A0;
int clap = 0;

long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;
void setup() 
{
Serial.begin(9600);
pinMode(Sensor, INPUT);
pinMode(8,OUTPUT);
}
void loop() {
  Serial.println(analogRead(A1));
  delay (50);
int status_sensor = digitalRead(Sensor);
if (status_sensor == 0)
{
if (clap == 0)
{
detection_range_start = detection_range = millis();
clap++;
}
else if (clap > 0 && millis()-detection_range >= 50)
{
detection_range = millis();
clap++;
}
}
if (millis()-detection_range_start >= 400)
{
if (clap == 2)
{
if (!status_lights)
{
status_lights = true;
digitalWrite(8, HIGH);
}
else if (status_lights)
{
status_lights = false;
digitalWrite(8, LOW);
}
}
clap = 0;
}
}
