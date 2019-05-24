#define RUNNING_FAULT 17
#define T1 2000
#define T2 2000
#define HR_PIN 3
#define TR_PIN 4
#define HL_PIN 6
#define TL_PIN 7
#define FAULT_PIN 5

bool flag = false;
int state_g;
int hr = 0; 
int tr = 0;
int hl = 0;
int tl = 0;
int temp = 0 ;
unsigned long start1_g , finish1_g, duration1_g,start2_g,finish2_g,duration2_g;
unsigned long start3_g , finish3_g, duration3_g,start4_g,finish4_g,duration4_g;
const byte interruptPin = 2 ;

// l ri bayad hamishe check konim ke age 1 shod , bepare biroon az in fsm_g 

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  state_g = 0;
  TIMSK2 = (TIMSK2 & B11111110) | 0x01;
  TCCR2B = (TCCR2B & B11111000) | 0x07;
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(HR_PIN , INPUT_PULLUP);
  pinMode(TR_PIN , INPUT_PULLUP);
  pinMode(HL_PIN , INPUT_PULLUP);
  pinMode(TL_PIN , INPUT_PULLUP);
  pinMode(FAULT_PIN , OUTPUT);
  digitalWrite(FAULT_PIN , 0);
 // attachInterrupt(0, isr_g, CHANGE);
  fsm_g();
  //Serial.println("Goodnight moon!");
}

ISR(TIMER2_OVF_vect){

  hr = digitalRead(HR_PIN);
  //Serial.println("hr");
  //Serial.println(hr);
  hl = digitalRead(HL_PIN);
  //Serial.println("hl");
  //Serial.println(hl);
  tr = digitalRead(TR_PIN);
  //Serial.println("tr");
  //Serial.println(tr);
  tl = digitalRead(TL_PIN);
//  Serial.println(hr);
//  Serial.println(tr);
//  Serial.println(hl);
//  Serial.println(tl);
  //Serial.println("tl");
  //Serial.println(tl);
  
}
void fsm_g()
{
  switch (state_g)
  {
    case 0 :
      Serial.println("fsm_g s0 ");
      s0_g();
      break;
    case 1 :
      Serial.println("fsm_g s1 ");
      s1_g();
      break;
    case 2 :
      Serial.println("fsm_g s2 ");
      s2_g();
      break;
     case 3 : 
       Serial.println("fsm_g s3 ");
       s3_g();
       break;
     case 4 : 
       Serial.println("fsm_g s4 ");
       s4_g();
       break;
     case 5 : 
       Serial.println("fsm_g s5 ");
       s5_g();
       break;
     case 6 : 
       Serial.println("fsm_g s6");
       s6_g();
       break;
     case 7 : 
       Serial.println("fsm_g s7");
       s7_g();
       break;
     case 8 : 
      Serial.println("fsm_g s8");
      s8_g();
      break;
     case 9 : 
      Serial.println("fsm_g s9");
      s9_g();
      break;
     case 10 : 
      Serial.println("fsm_g s10");
      s10_g();
      break;
     case 11 : 
      Serial.println("fsm_g s11");
      s11_g();
      break;
     case 12 : 
      Serial.println("fsm_g s12");
      s12_g();
      break;
     case 13 : 
      Serial.println("fsm_g s13");
      s13_g();
      break;
     case 14 : 
      Serial.println("fsm_g s14");
      s14_g();
      break;
     case 15 : 
      Serial.println("fsm_g s15");
      s15_g();
      break;
     case 16 : 
      Serial.println("fsm_g s16");
      s16_g();
      break;
     case 17 : 
      Serial.println("fsm_g RUNNING FAULT");
      s17_g();
      break;
  }
}
//void isr_g()
//{
//  hr = digitalRead(HR_PIN);
//  hl = digitalRead(HL_PIN);
//  tr = digitalRead(TR_PIN);
//  tl = digitalRead(TL_PIN);
//}
void s0_g()
{
 
  if( (( hr == 1)||(tr == 1)) && (( hl == 1)||(tl == 1)) )
  {
    state_g =  1 ;
    Serial.println("Inside first if in s0");
    //fsm_g();
  }
  else if( (( hl == 0)&&(tl == 0)) && (( hr == 1)||(tr == 1)) )
  {
    state_g =  7 ;
    Serial.println("Inside second if in s0");
    //fsm_g();
  }
  
  else if( (( hr == 0)&&(tr == 0)) && (( hl == 1)||(tl == 1)) )
  {
    state_g =  8 ;
    Serial.println("Inside third if in s0");
    //fsm_g();
  } 
  else
  {
    //fsm_g();
  }
}

void s1_g()
{
   if( (( hl == 0)&&(tl == 0)) && (( hr == 1)||(tr == 1)) )
   {
      state_g =  2 ;
      Serial.println("Inside first if in s1");
      //fsm_g();
   }
   else if( (( hr == 0)&&(tr == 0)) && (( hl == 1)||(tl == 1)) )
   {
      state_g =  4 ;
      Serial.println("Inside second if in s1");
      //fsm_g();
   }
   else if( (( hr == 0)&&(tr == 0)) && (( hl == 0)&&(tl == 0)) )
   {
      state_g =  6 ;
      Serial.println("Inside third if in s1");
      //fsm_g();
   }
   else
   {
      //fsm_g();
   }
}
void s2_g()
{
  Serial.println("HERE");
  if( (( hl == 1)||(tl == 1))&&(( hr == 1)||(tr == 1)) )
  {
      state_g =  3 ;
      Serial.println("Inside first if in s2");
      //fsm_g();
  }
  else if( (( hr == 0)&&(tr == 0))&&(( hl == 1)||(tl == 1)) ) // tina
  {
      state_g =  RUNNING_FAULT ;
      Serial.println("Inside second if in s2");
      //fsm_g();
  }
  else
  {
      //fsm_g();
  }
}
  
void s3_g()
{
  if( ( hr == 0)&&(tr == 0) )
  {
      state_g =  RUNNING_FAULT ;
      Serial.println("Inside first if in s3");
      //fsm_g();
  }
  else
  {
      state_g =  3 ;
      Serial.println("Inside second if in s3");
      //fsm_g();
  }  
}

void s4_g()
{
  if( (( hl == 1)||(tl == 1))&&(( hr == 1)||(tr == 1)) )
  {
      state_g =  5 ;
      Serial.println("Inside first if in s4");
      //fsm_g();
  }
  else if( (( hl == 0)&&(tl == 0))&&(( hr == 1)||(tr == 1)) ) // tina
  {
      state_g =  RUNNING_FAULT ;
      Serial.println("Inside second if in s4");
      //fsm_g();
  }
  else
  {
      //fsm_g();
  }
}
void s5_g()
{
  if( ( hl == 0)&&(tl == 0) )
  {
      state_g =  RUNNING_FAULT ;
      Serial.println("Inside first if in s5");
      //fsm_g();
  }
  else
  {
      state_g =  5 ;
      Serial.println("Inside second if in s5");
      //fsm_g();
  }
}

void s6_g()
{
  if( (( hl == 1)||(tl == 1))||(( hr == 1)||(tr == 1)) ) // tina
  {
      state_g =  RUNNING_FAULT ;
      Serial.println("Inside second if in s6");
      //fsm_g();
  }
  else
  {
    Serial.println("Inside else s6");
    //fsm_g();
  }
}
void s7_g()
{
  if( (( hl == 1)||(tl == 1))&&(( hr == 0)&&(tr == 0)) )
  {
      state_g =  9 ;
      Serial.println("Inside first if in s7");
      //fsm_g();
  }
  else if ( (( hl == 1)||(tl == 1))&&(( hr == 1)||(tr == 1)) )
  {
      state_g =  3 ;
      Serial.println("Inside second if in s7");
      //fsm_g();
  }
  else
  {
      //fsm_g();
  }
}
void s8_g()
{
   if( (( hr == 1)||(tr == 1))&&(( hl == 0)&&(tl == 0)) )
  {
      state_g =  13 ;
      Serial.println("Inside first if in s8");
      //fsm_g();
  }
  else if ( (( hl == 1)||(tl == 1))&&(( hr == 1)||(tr == 1)) )
  {
      state_g =  5 ;
      Serial.println("Inside second if in s8");
      //fsm_g();
  }
  else
  {
      //fsm_g();
  }
}

void s9_g()
{
  start1_g = millis();
  state_g = 10 ;
  //fsm_g();
}

void s10_g()
{
//  finish1_g = millis();
//  duration1_g = finish1_g - start1_g ;
  while ( 1 )
  {
    finish1_g = millis();
    duration1_g = finish1_g - start1_g ;
    //delay(3);
    Serial.println("duration");
    //Serial.println(duration1_g);
    if( duration1_g > T1)
    {
      state_g = RUNNING_FAULT ;
      break;
    //  fsm_g();
    }
    else if( (( hr == 1)||(tr == 1))&&(( hl == 0)&&(tl == 0)) )
    {
      state_g = 11 ;
            break;
    //  fsm_g();
    }
    else if ( (( hl == 1)||(tl == 1))&&(( hr == 1)||(tr == 1)) )
    {
      state_g = RUNNING_FAULT ;
            break;
    //  fsm_g();
    }
    else
    {
      state_g = 10 ;
            break;
    //  fsm_g();
    }
  }
}

void s11_g()
{
  start2_g = millis();
  state_g = 12 ;
  //fsm_g();
}

void s12_g()
{
//  finish2_g = millis();
//  duration2_g = finish2_g - start2_g ;
  while ( 1 )
  {
    finish2_g = millis();
    duration2_g = finish2_g - start2_g ;
    
    if( duration2_g > T2)
    {
      state_g = RUNNING_FAULT ;
            break;
    //  fsm_g();
    }
    else if(( hl == 1)||(tl == 1))
    {
      state_g = RUNNING_FAULT ;
            break;
    //  fsm_g();
    }
    else 
    {
      state_g = 12 ;
            break;
    //  fsm_g();
    }
  }
}

void s13_g()
{
  start3_g = millis();
  state_g = 14 ;
 // fsm_g();
}

void s14_g()
{
//  finish3_g = millis();
//  duration3_g = finish3_g - start3_g ;
  while ( 1 )
  {
    finish3_g = millis();
    duration3_g = finish3_g - start3_g ;
    
    if( duration3_g > T1)
    {
      state_g = RUNNING_FAULT ;
            break;
   //   fsm_g();
    }
    else if( (( hl == 1)||(tl == 1))&&(( hr == 0)&&(tr == 0)) )
    {
      state_g = 15 ;
            break;
     // fsm_g();
    }
    else if ( (( hl == 1)||(tl == 1))&&(( hr == 1)||(tr == 1)) )
    {
      state_g = RUNNING_FAULT ;
            break;
    //  fsm_g();
    }
    else
    {
      state_g = 14 ;
            break;
    //  fsm_g();
    }
  }
}
void s15_g()
{
  start4_g = millis();
  state_g = 16 ;
 // fsm_g();
}

void s16_g()
{
//  finish4_g = millis();
//  duration4_g = finish4_g - start4_g ;
  while ( 1 )
  {
    finish4_g = millis();
    duration4_g = finish4_g - start4_g ;
    
    if( duration4_g > T2)
    {
      state_g = RUNNING_FAULT ;
            break;
   //   fsm_g();
    }
    else if(( hr == 1)||(tr == 1))
    {
      state_g = RUNNING_FAULT ;
            break;
    //  fsm_g();
    }
    else 
    {
      state_g = 16 ;
            break;
    //  fsm_g();
    }
  }
}

void s17_g()
{
   Serial.println("RUNNING FUALT");
   digitalWrite(FAULT_PIN , 1);
   detachInterrupt(0);
   
}




void loop() { // run over and over
 if(state_g != RUNNING_FAULT)
 {
  fsm_g();
 }
 else if (flag == false)
 {
   Serial.println("RUNNING FAULT !!!");
   flag = true ;
 }
 else
 {
 }
}
 
