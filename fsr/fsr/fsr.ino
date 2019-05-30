int fsrAnalogPin = A0;
int fsrReading;

void setup(void){
  Serial.begin(9600);
}

void loop(void){
  fsrReading = analogRead(fsrAnalogPin);
  int num = fsrReading/5;
  Serial.print("Analog reading = ");
  Serial.println(num);
  
  delay(100);
}
