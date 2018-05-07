#include <Servo.h>//LIBRERIA PARA SERVOMOTOR
#include <AFMotor.h> //LIBRERIA PARA MOTORES

//Declaracion de los 2 motores
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
//Variable para guardad el caracter
int val;
//Declaramos servo
Servo servo1;
void setup()
{
//Declaramos velocidad maxima
motor1.setSpeed(250);
motor2.setSpeed(250);{
motor3.setSpeed(245);
}
Serial.begin(9600);
//Led para pruebas
pinMode(22, OUTPUT);
delay(7000);
//declaramos servo en el pin 24
servo1.attach(24);
 servo1.write(180);
}

void loop()
{
if(Serial.available() >= 1)
{
val = Serial.read();
Serial.print(val+"");
  if(val =='1')
{
  digitalWrite(22, HIGH);
}
else if(val =='0')
{
   digitalWrite(22, LOW);
}
else if(val =='s')
{

 motor1.run(RELEASE);
  motor2.run(RELEASE);
}
else if(val =='d')
{
servo1.write(45);

}else if(val =='i'){
  
servo1.write(135);

}else if(val =='f'){
  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  
}else if(val=='r'){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}else if(val=='x'){
  servo1.write(0);
  
}else if(val=='a'){
  motor3.run(FORWARD);
  
}else if(val=='b'){
  motor3.run(BACKWARD);
}else if(val=='p'){
   motor3.run(RELEASE);
}

}

}

