#include <arduino-timer.h>

auto timer = timer_create_default();

char c;
boolean ready = false;
char pin = 13;
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
  Serial.println("Started");
  help();
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
      Serial.println("BLINKING OFF");
      blink = false;
      digitalWrite(pin, LOW);
      break;
    case '1':
      Serial.println("BLINKING ON");
      blink = true;
      break;
    default:
      Serial.print("Unknown command character: ");
      Serial.println(c);
      help();
  }
}

void help() {
  Serial.println("1 - turn on  blinking");
  Serial.println("0 - turn off blinking");
}
