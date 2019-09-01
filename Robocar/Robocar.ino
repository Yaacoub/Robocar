// Libraries

#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>



// Digital Pins

int irRecieverPin = 2;
int redLedPin = 3;
int relayPin1 = 6;
int relayPin2 = 7;
int builtinLedPin = 13;



// Variables

bool powerStatus = LOW;



// IR Setup

IRrecv irrecv(irRecieverPin);
decode_results results;



// Functions

void setup() {
  irrecv.enableIRIn();
  pinMode(redLedPin, OUTPUT);
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(builtinLedPin, OUTPUT);
}

void loop() {
  
  if (irrecv.decode(&results)) {
    switch (results.value) {

      // PLAY/PAUSE
      case 0xFFC23D:
        digitalWrite(redLedPin, HIGH);
        delay(10);
        digitalWrite(redLedPin, LOW);
        powerStatus = !powerStatus;
        digitalWrite(builtinLedPin, powerStatus);
        digitalWrite(relayPin1, LOW);
        digitalWrite(relayPin2, LOW);
        break;
        
        // 2
        case 0xFF18E7:
          if (powerStatus == HIGH) {
            digitalWrite(redLedPin, HIGH);
            delay(10);
            digitalWrite(redLedPin, LOW);
            digitalWrite(relayPin1, HIGH);
            digitalWrite(relayPin2, HIGH);
          }
          break;

      // 4
      case 0xFF10EF:
        if (powerStatus == HIGH) {
          digitalWrite(redLedPin, HIGH);
          delay(10);
          digitalWrite(redLedPin, LOW);
          digitalWrite(relayPin1, HIGH);
          digitalWrite(relayPin2, LOW);
        }
        break;

      // 5
      case 0xFF38C7:
        if (powerStatus == HIGH) {
          digitalWrite(redLedPin, HIGH);
          delay(10);
          digitalWrite(redLedPin, LOW);
          digitalWrite(relayPin1, LOW);
          digitalWrite(relayPin2, LOW);
        }
        break;

      // 6
      case 0xFF5AA5:
        if (powerStatus == HIGH) {
          digitalWrite(redLedPin, HIGH);
          delay(10);
          digitalWrite(redLedPin, LOW);
          digitalWrite(relayPin1, LOW);
          digitalWrite(relayPin2, HIGH);
        }
        break;
      
    }
    irrecv.resume();
  }
  
}
