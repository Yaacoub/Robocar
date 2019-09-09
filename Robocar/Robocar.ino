// Libraries

#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>



// Constants

const int irRecieverPin = 2;
const int ledBuiltinPin = 13;
const int ledPin = 3;
const int relay1Pin = 6;
const int relay2Pin = 7;



// Variables

bool powerStatus = LOW;



// IR Setup

IRrecv irrecv(irRecieverPin);
decode_results results;



// Default Functions

void setup() {
  
  irrecv.enableIRIn();
  pinMode(ledPin, OUTPUT);
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(ledBuiltinPin, OUTPUT);
  
}

void loop() {
  
  if (irrecv.decode(&results)) {
    switch (results.value) {

      // PLAY/PAUSE
      case 0xFFC23D:
        digitalWrite(ledPin, HIGH);
        delay(10);
        digitalWrite(ledPin, LOW);
        powerStatus = !powerStatus;
        digitalWrite(ledBuiltinPin, powerStatus);
        digitalWrite(relay1Pin, LOW);
        digitalWrite(relay2Pin, LOW);
        break;
        
        // 2
        case 0xFF18E7:
          if (powerStatus == HIGH) {
            digitalWrite(ledPin, HIGH);
            delay(10);
            digitalWrite(ledPin, LOW);
            digitalWrite(relay1Pin, HIGH);
            digitalWrite(relay2Pin, HIGH);
          }
          break;

      // 4
      case 0xFF10EF:
        if (powerStatus == HIGH) {
          digitalWrite(ledPin, HIGH);
          delay(10);
          digitalWrite(ledPin, LOW);
          digitalWrite(relay1Pin, HIGH);
          digitalWrite(relay2Pin, LOW);
        }
        break;

      // 5
      case 0xFF38C7:
        if (powerStatus == HIGH) {
          digitalWrite(ledPin, HIGH);
          delay(10);
          digitalWrite(ledPin, LOW);
          digitalWrite(relay1Pin, LOW);
          digitalWrite(relay2Pin, LOW);
        }
        break;

      // 6
      case 0xFF5AA5:
        if (powerStatus == HIGH) {
          digitalWrite(ledPin, HIGH);
          delay(10);
          digitalWrite(ledPin, LOW);
          digitalWrite(relay1Pin, LOW);
          digitalWrite(relay2Pin, HIGH);
        }
        break;
      
    }
    irrecv.resume();
  }
  
}
