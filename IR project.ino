#include <IRremote.h>
 
int IR_Recv = 2;
int redPin = 7;
int greenPin = 4;
int yellowPin = 8;
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600);  
  irrecv.enableIRIn();
  pinMode(redPin, OUTPUT);  
  pinMode(greenPin, OUTPUT);   
  pinMode(yellowPin, OUTPUT);  
}
 
void loop(){
  if (IrReceiver.decode()) {
    long int decCode = IrReceiver.decodedIRData.decodedRawData;
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    Serial.println(decCode);

    switch (decCode)
    {
      case -167117056:
      digitalWrite(redPin, HIGH);
        break;   
      case -501350656: 
        digitalWrite(redPin, LOW);   
        break;
      case -233963776: 
        digitalWrite(greenPin, HIGH);
        break;           
       case -434503936: 
        digitalWrite(greenPin, LOW);
        break;       
       case -300810496: 
        digitalWrite(yellowPin, HIGH);
        break;       
       case -367657216: 
        digitalWrite(yellowPin, LOW);
        break;
    }

    IrReceiver.resume();
  }
  delay(100);
}