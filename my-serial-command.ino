#include <arduino-timer.h>

auto timer = timer_create_default();

char c;
boolean ready = false;
char pin = 8;
boolean blink = false;

bool toggleLed(void*) {
  if (blink) {
    digitalWrite(pin, !digitalRead(pin)); 
  }
  return true;  
}

void setup() {
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
  timer.every(500, toggleLed);
}

void loop() {
  timer.tick();
  receive();
  show();
}

void receive() {
  if (Serial.available() > 0) {
    c = Serial.read();
    ready = true;  
  }
}

void show() {
  if (ready == true) {
    ready = false;
    handle();
  }
}

void handle() {
  switch (c) {
    case '0':
      blink = false;
      digitalWrite(pin, LOW);
      break;
    case '1':
      blink = true;
      break; 
  }
}
