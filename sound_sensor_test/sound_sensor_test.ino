int soundSensor = 3;



void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  pinMode (soundSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int statusSensor = digitalRead (soundSensor);
  //Serial.println(statusSensor);
  if (statusSensor == 1)
  {
    Serial.println("Loud Noise Detected");
  }
  else
  {
    Serial.println("Monitoring");
  }
delay(100);
}
