#include <Servo.h>

#define WS 25
Servo servo_0, servo_1, servo_2;
int ang0[WS], ang1[WS], ang2[WS];

void setup() {
  // put your setup code here, to run once:
  servo_0.attach(4);
  servo_1.attach(3);
  servo_2.attach(2);
  Serial.begin(115200);
}

void shiftr(int reg[WS], int in) {
  for (int i = 0; i<WS-1; i++)
    reg[i] = reg[i+1];
  reg[WS-1] = in;
}

int aver(int reg[WS]) {
  int sum = 0;
  for (int i = 0; i<WS; i++)
    sum = sum + reg[i];
  return int(sum/WS);
}

void loop() {
  // put your main code here, to run repeatedly:
  shiftr(ang0,analogRead(A0)*0.15);
  shiftr(ang1,analogRead(A1)*0.15);
  shiftr(ang2,analogRead(A2)*0.15);
  servo_0.write(aver(ang0)+10);
  servo_1.write(aver(ang1)+10);
  servo_2.write(aver(ang2)+10);
  Serial.println(ang0[WN-1]);
  Serial.println(ang1[WN-1]);
  Serial.println(ang2[WN-1]);
  Serial.println('____________');
  delay(5);
}
