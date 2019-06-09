#define BOUND 200
#define pinTR 2
#define pinHR 3
#define pinTL 4
#define pinHL 5

int fsrAnalogPinTR = A0;
int fsrAnalogPinHR = A1;
int fsrAnalogPinTL = A4;
int fsrAnalogPinHL = A3;
int fsrReadingTR;
int fsrReadingHR;
int fsrReadingTL;
int fsrReadingHL;

void setup(void){
  pinMode(pinTR,OUTPUT);
  pinMode(pinHR,OUTPUT);  
  pinMode(pinTL,OUTPUT);
  pinMode(pinHL,OUTPUT);
  Serial.begin(9600); 
}

void loop(void){
  fsrReadingTR = analogRead(fsrAnalogPinTR);
  fsrReadingTL = analogRead(fsrAnalogPinTL);
  fsrReadingHR = analogRead(fsrAnalogPinHR);
  fsrReadingHL = analogRead(fsrAnalogPinHL);
  
  Serial.print("Analog reading HR = ");
  Serial.println(fsrReadingHR);
  Serial.print("Analog reading TR = ");
  Serial.println(fsrReadingTR);
  
  Serial.print("Analog reading HL = ");
  Serial.println(fsrReadingHL);
  Serial.print("Analog reading TL = ");
  Serial.println(fsrReadingTL);
  if (fsrReadingTR < BOUND)
  {
    digitalWrite(pinTR,LOW);
    Serial.println(" TR = 0");
  }
  else
  {
    digitalWrite(pinTR,HIGH);
    Serial.println(" TR = 1"); 
  }
  
  if (fsrReadingTL < BOUND)
  {
    digitalWrite(pinTL,LOW);
    Serial.println(" TL = 0"); 
  }
  else
  {
    digitalWrite(pinTL,HIGH);
    Serial.println(" TL = 1");
  }
  if (fsrReadingHR < BOUND)
  {
    digitalWrite(pinHR,LOW);
    Serial.println(" HR = 0");
  }
  else
  {
    digitalWrite(pinHR,HIGH);
    Serial.println(" HR = 1");
  }

  if (fsrReadingHL < BOUND)
  {
    digitalWrite(pinHL,LOW);
    Serial.println(" HL = 0");
  }
  else
   {
    digitalWrite(pinHL,HIGH);
    Serial.println(" HL = 1");
   }
  
  delay(10);
}
