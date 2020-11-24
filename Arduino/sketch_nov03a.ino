#include <SCoop.h>



const int RED = A1;
const int GREEN = A2;
const int BLUE = A0;
int led_flag = 0;


//Daily 0
//Happy 3
//SMile 4
//Maloncony 5
//Excited 7

defineTask(TaskTest);
void TaskTest::setup()
{
  Serial.begin(9600);
  Serial.println("Helloworld, programmed by nyovelt.");
}

void TaskTest::loop()
{
  Serial.println(led_flag);
  if (Serial.available()) {
    char a = Serial.read(); // 0  3 4 5 7
    if (a == 'a'){
      led_flag = 3;
      Serial.println("Mode Happy");
    }
    else if(a == 'b'){
      led_flag = 4;
      Serial.println("Mode Smile");
    }
    else if(a == 'c'){
      led_flag = 5;
      Serial.println("Mode Malocony");
    }
    else if(a == 'd'){
      led_flag = 7;
      Serial.println("Mode Excited");
    }
    else if(a == 'e'){
      led_flag = 0;
      Serial.println("Mode Default");
    }
  }

}




void setup() {
  mySCoop.start();

}

void loop() {
  // put your main code here, to run repeatedly:
  yield();
  if (led_flag == 1) {
    led_flag = 0;
  }
  else if (led_flag == 0)
  {
    int r = random(0, 255);
    int g = random(0, 255);
    int b = random(0, 255);
    if ((r <= 150) && g <= 150 && b <= 150) {
      b = 255;
    }
    for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= int(0.01 * (i - 50) * (i - 50)); j++) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        delayMicroseconds(2000);
        analogWrite(RED, r);
        analogWrite(GREEN, g);
        analogWrite(BLUE, b);
        delayMicroseconds(i);
      }
    }
    for (int i = 100; i >= 0; i--) {
      for (int j = 0; j <= int(0.01 * (i - 50) * (i - 50)); j++) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        delayMicroseconds(2000);
        analogWrite(RED, r);
        analogWrite(GREEN, g);
        analogWrite(BLUE, b);
        delayMicroseconds(i);
      }
    }
  }
  else if (led_flag == 3) {
    for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= int(0.01 * (i - 50) * (i - 50)); j++) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        delayMicroseconds(2000);
        analogWrite(GREEN, 200);
        delayMicroseconds(i);
      }
    }
    for (int i = 100; i >= 0; i--) {
      for (int j = 0; j <= int(0.01 * (i - 50) * (i - 50)); j++) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        delayMicroseconds(2000);
        analogWrite(GREEN, 200);
        delayMicroseconds(i);
      }
    }

  }
  else if (led_flag == 4) {
    for (int i = 0; i <= 80; i++) {
      for (int j = 0; j <= int(0.001 * (i - 50) * (i - 50)); j++) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        delayMicroseconds(2000);
        analogWrite(GREEN, 200);
        delayMicroseconds(i);
      }
    }
    for (int i = 80; i >= 0; i--) {
      for (int j = 0; j <= int(0.001 * (i - 50) * (i - 50)); j++) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        delayMicroseconds(2000);
        analogWrite(GREEN, 200);
        delayMicroseconds(i);
      }
    }

  }
  else if (led_flag == 5) {
    for (int i = 0; i <= 100; i+=2) {
      for (int j = 0; j <= int(0.01 * (i - 50) * (i - 50)); j++) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        delayMicroseconds(2000);
        analogWrite(BLUE, 200);
        delayMicroseconds(i);
      }
    }
    for (int i = 100; i >= 0; i--) {
      for (int j = 0; j <= int(0.01 * (i - 50) * (i - 50)); j++) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        delayMicroseconds(2000);
        analogWrite(BLUE, 200);
        delayMicroseconds(i);
      }
    }
    

  }
  else if (led_flag == 7) {
    for (int i = 0; i <= 80; i++) {
      for (int j = 0; j <= int(0.001 * (i - 50) * (i - 50)); j++) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        delayMicroseconds(2000);
        analogWrite(GREEN, 200);
        analogWrite(RED, 200);
        delayMicroseconds(i);
      }
    }
    for (int i = 80; i >= 0; i--) {
      for (int j = 0; j <= int(0.001 * (i - 50) * (i - 50)); j++) {
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);
        delayMicroseconds(2000);
        analogWrite(GREEN, 200);
        analogWrite(RED, 200);
        delayMicroseconds(i);
      }
    }

  }
  else {
    led_flag = 0;
  }
  
}

void show(int r, int g, int b) {
  analogWrite(RED, r);
  analogWrite(GREEN, g);
  analogWrite(BLUE, b);
}

void off() {
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}
