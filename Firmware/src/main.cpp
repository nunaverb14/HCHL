/* Default Firmware for Livid Console

 * This ino file with light each led in sequence using the analog pins 
 * and play a startup buzzer tone.
 * 
 * When each button is pressed, the buzzer will tone and the leds will display the binary of the button.
 * 
 * The display will not be setup in this file.
 */

#include <Arduino.h>

#define LED1 26
#define LED2 27
#define LED3 28
#define BUZZER 18
#define START 13
#define SELECT 17
#define UP 15
#define DOWN 14
#define LEFT 16
#define RIGHT 5

int leds[] = {LED1, LED2, LED3};

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(START, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);

  tone(BUZZER, 440, 350);
  delay(350);
  tone(BUZZER, 550, 150);

  for(int i = 0; i < 3; i++){
    for(int l = 0; l < 255; l++){
      analogWrite(leds[i], l);
      delay(5);
    }

    delay(50);

    for(int l = 255; l >= 0; l--){
      analogWrite(leds[i], l);
      delay(5);
    }

    delay(50);
  }


}

void loop() {
  if (digitalRead(START) == LOW) {
    tone(BUZZER, 660, 200);
    digitalWrite(LED3, HIGH);
    delay(200);
  }

  if (digitalRead(SELECT) == LOW) {
    tone(BUZZER, 660, 200);
    digitalWrite(LED2, HIGH);
    delay(200);
  }

  if (digitalRead(UP) == LOW) {
    tone(BUZZER, 660, 200);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED2, HIGH);
    delay(200);
  }

  if (digitalRead(DOWN) == LOW) {
    tone(BUZZER, 660, 200);
    digitalWrite(LED1, HIGH);
    delay(200);
  }

  if (digitalRead(LEFT) == LOW) {
    tone(BUZZER, 660, 200);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, HIGH);
    delay(200);
  }

  if (digitalRead(RIGHT) == LOW) {
    tone(BUZZER, 660, 200);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    delay(200);
  }

  for(int i = 0; i < 3; i++){
    digitalWrite(leds[i], LOW);
  }
}
