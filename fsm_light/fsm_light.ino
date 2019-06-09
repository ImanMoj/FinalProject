#define FIVE_SEC_FAULT 4 
#define T_DRIBBLE 5000
#define T_t 5000
#define FAULT_PIN 5
int state_d;
int l;
unsigned long start1_d , finish1_d, duration1_d,start2_d,finish2_d,duration2_d,start3_d,finish3_d,duration3_d;
const byte interruptPin = 2 ;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  state_d = 0;
  l = digitalRead(2);
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(FAULT_PIN , OUTPUT);
  digitalWrite(FAULT_PIN , 0);
  attachInterrupt(0, isr, CHANGE);
  
  //fsm_d();
  //Serial.println("Goodnight moon!");
}

//void leg_fsm_runner()
//{
//  while(flag)
//  {
//    fsm_g() ; 
//  }
//}
void fsm_d()
{
  switch (state_d)
  {
    case 0 :
      Serial.println("fsm_d s0 ");
      s0_d();
      break;
    case 1 :
      Serial.println("fsm_d s1 ");
      s1_d();
      break;
    case 2 :
      Serial.println("fsm_d s2 ");
      s2_d();
      break;
     case 3 : 
       Serial.println("fsm_d s3 ");
       s3_d();
       break;
     case 4 : 
       Serial.println("fsm_d s4 - five seconds fault ");
       s4_d();
       break;
     case 5 : 
       Serial.println("fsm_d s5 ");
       s5_d();
       break;
     case 6 : 
       Serial.println("fsm_d s6");
       s6_d();
       break;
     case 7 : 
       Serial.println("fsm_d s7");
       s7_d();
       break;
     case 8 : 
      Serial.println("fsm_d s8");
      s8_d();
      break;
  }
}
void isr()
{
  l = digitalRead(2);
}
void s0_d()
{
  while(l==1)
    delayMicroseconds(1);
  state_d = 1;
  Serial.println("Inside s0");
  //fsm_d();
}
void s1_d()
{
    start1_d = millis();
    //delay(1000);
    state_d = 2;
    //fsm_d();
}
void s2_d()
{
  finish1_d = millis();
  duration1_d = finish1_d - start1_d ;
  while ( ( l == 0 ) && (duration1_d < 5000) )
  {
    finish1_d = millis();
    duration1_d = finish1_d - start1_d ;
  }
  if ( l == 1 )
  {
    state_d = 3;
    //fsm_d();
  }
  else if (duration1_d >= 5000)
  {
    state_d = FIVE_SEC_FAULT;
    //fsm_d();
  }
}
  
void s3_d()
{
  start2_d = millis();
  state_d = 5 ;
  //fsm_d();
}  
void s4_d()
{
  Serial.println("LAMP");
  digitalWrite(FAULT_PIN , 1);
  detachInterrupt(0);
}
void s5_d()
{
  Serial.println("Inside s5");
  while ( l == 1 )
  {
    finish2_d = millis();
    duration2_d = finish2_d - start2_d;
    if(duration2_d > T_DRIBBLE)
      break;
    delayMicroseconds(1);  
  }
  if (( l == 0 )&&(duration2_d < T_DRIBBLE ) )
  {
    
    state_d = 6 ; 
    //fsm_d();
  }
  else if (( l == 1 )&&(duration2_d > T_DRIBBLE ))
  {
    state_d = 0;
    //fsm_d();
  }
}
void s6_d()
{
  start3_d = millis();
  while(l == 0)
  {
    finish3_d = millis();
    duration3_d = finish3_d - start3_d;
    if(duration3_d > T_t)
      break;
  }
  if ((l==1) && (duration3_d < T_t))
  {
     state_d = 7;
     //fsm_d();
  }
  else if (duration3_d >= T_t)
  {
    state_d = 0;
    //fsm_d();
  }
  
}
void s7_d()
{
  state_d = 8 ;
  //fsm_d();
}
void s8_d()
{
  start2_d = millis();
  state_d = 5 ;
  //fsm_d();
}

void loop() { // run over and over
  fsm_d();
  //Serial.println("HAAAAAAAAA");
}
