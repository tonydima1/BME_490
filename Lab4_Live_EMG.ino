int rectValue = 0;
const int numReadings = 300;
int filter_sum = 0;
int i;
int readings[numReadings];
int readindex = 0;
int total = 0;
int average = 0;
int inputPin = rectValue;
const int buzzer = 9;
#define ENABLE 5
#define DIRA 3
#define DIRB 4

void setup() {
  // put your setup code here, to run once:
  pinMode(ENABLE, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  Serial.begin(2000000);
  for (int thisReading = 0; thisReading < numReadings; thisReading++){
   readings[thisReading] = 0;
  }
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  if(sensorValue >= 322){
    rectValue = sensorValue;
  }
  else if(sensorValue<322){
    rectValue = 322 - sensorValue + 322;
  }

  total = total - readings[readindex];
  readings[readindex] = rectValue - 322;
  total = total + readings[readindex];
  readindex = readindex + 1;
  if(readindex >= numReadings)
  {
    readindex = 0;
  }
  average = ((total/numReadings)+322);

  if (average >= 326) {
    digitalWrite(ENABLE, HIGH);
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
    delay(0.5);
  }
  else if (average < 326) {
    digitalWrite(ENABLE, LOW);
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,LOW);
    delay(0.5);
  }
  Serial.print(rectValue);
  Serial.print("\t");
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.println(average);
  tone(buzzer, sensorValue*200);
  delay(1);
  noTone(buzzer);
  delay(1);


}
