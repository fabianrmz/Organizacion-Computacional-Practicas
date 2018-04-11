import controlP5.*;

import processing.serial.*;

import cc.arduino.*;
import org.firmata.*;

import processing.serial.*;
Serial myPort;
Arduino arduino;

boolean sensor1;//Variables para los sensores
boolean sensor2;
boolean sensor3;

void setup() {
size(500, 650); //Este es el tamaño de la interfaz.
arduino= new Arduino(this, "COM3", 57600);
sensor1=false;
sensor2=false;
sensor3=false;
arduino.pinMode(3, Arduino.OUTPUT);
arduino.pinMode(4, Arduino.INPUT);//sensor1 de movimiento
arduino.pinMode(5, Arduino.INPUT);
arduino.pinMode(6, Arduino.INPUT);
arduino.pinMode(0, Arduino.INPUT);
 }
void draw() {
background(0, 0, 150);
fill(0,0,0);
int foto=arduino.analogRead(0);
text("PRACTICA 6 ", 220, 30);
fill(150,150,150);
rect(0,50, 500, 300);
rect(0,400, 500, 250);


if(arduino.digitalRead(4) == Arduino.HIGH){
  sensor1=true;
}else{
  sensor1=false;
}
if(arduino.digitalRead(5) == Arduino.HIGH){
  sensor2=true;
}else{
  sensor2=false;
}
if(arduino.analogRead(0) >250){
  sensor3=true;
}else{
  sensor3=false;
}

if( (sensor1 && sensor2) || (sensor1 && sensor3) || (sensor2 && sensor3) ){//si detecta mas de un sensor
  fill(0,0,0);
  rect(0,50, 500, 300);
  
  text("error", 224, 450);
  
}else if(sensor1){//si detecta sensor 1
  fill(150,0,0);
  ellipse(260,200, 250,250);
  text("Hola", 224, 450);
  
  
  
}else if(sensor2){//si detecta sensor 2
  fill(0,150,0);
  rect(250, 150, 55, 55);
  text("Practica 8", 224, 450);
  
}else if(sensor3){ //si detecta sensor 3
  fill(247 ,255,0);
  triangle(30+200, 75+100, 58+200, 20+100, 86+200, 75+100);
  text("Salu2", 224, 450);
  
}else{
  
}
  
  
       
  

}


void mousePressed(){
 arduino.digitalWrite(3, Arduino.HIGH);
}
void mouseReleased(){
 arduino.digitalWrite(3, Arduino.LOW);
 }