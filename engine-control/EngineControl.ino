//initialization of vars for rising edge detection
int buttonStateLeft = 0;  
int lastButtonStateLeft = 0;

int buttonStateRight = 0;
int lastButtonStateRight = 0;

int buttonStateStop = 0;
int lastButtonStateStop = 0;

void setup()
{
  //input init
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  Serial.begin(9600);
  //output init and assignment
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  
}

//loop with engine control, priority for Stop button
void loop()
{
  // read the pushbutton input pin
   buttonStateLeft = digitalRead(3);  
   buttonStateRight = digitalRead(4);
   buttonStateStop = digitalRead(5);

  // compare the buttonState to its previous state
  if (buttonStateLeft != lastButtonStateLeft) {
    if (buttonStateLeft == HIGH) {
      Serial.println("Left");
      digitalWrite(8, HIGH);
 	  digitalWrite(9, LOW);
    }
    
  }
    
   delay(5);
   lastButtonStateLeft = buttonStateLeft;
    
    if (buttonStateRight != lastButtonStateRight) {
    if (buttonStateRight == HIGH) {
      Serial.println("Right");
      digitalWrite(8, LOW);
 	  digitalWrite(9, HIGH);
      }
    }
    
   delay(5);
   lastButtonStateRight = buttonStateRight;
      
    if (buttonStateStop != lastButtonStateStop) {
    if (buttonStateStop == HIGH) {
      Serial.println("STOP");
      digitalWrite(8, LOW);
 	  digitalWrite(9, LOW);
      }
    }
    
   delay(5);
   lastButtonStateStop = buttonStateStop;  
}