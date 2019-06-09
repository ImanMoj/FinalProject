#define BOUND 200
int photocellPinL = 0;     // the cell and 10K pulldown are connected to a0
int photocellPinR = 1;     // the cell and 10K pulldown are connected to a1
int photocellReadingL;     // the analog reading from the analog resistor divider
int photocellReadingR;     // the analog reading from the analog resistor divider 
int OutputPin = 3;
void setup(void) {
  // We'll send debugging information via the Serial monitor
  Serial.begin(9600);
  pinMode(OutputPin , OUTPUT);  
}
 
void loop(void) {
  photocellReadingL = analogRead(photocellPinL);  
  photocellReadingR = analogRead(photocellPinR); 
  
  Serial.print("Analog reading of Left hand is = ");
  Serial.println(photocellReadingL);     // the raw analog reading
 
  Serial.print("Analog reading of Right hand is = ");
  Serial.println(photocellReadingR);     // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  
  if ( ( photocellReadingR < BOUND ) || (photocellReadingL < BOUND ))
    {
       Serial.println("L signal is 0");
       digitalWrite(OutputPin,LOW);
    }
  else
  {
       Serial.println("L signal is 1");
       digitalWrite(OutputPin,HIGH); 
  }
    
  delay(1000);
}
