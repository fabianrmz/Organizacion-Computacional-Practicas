#define trigger 11
#define echo 12
#define led 2
#define led2 3
#define led3 4
#define interruptor 5

void setup() {
Serial.begin(9600);
pinMode(trigger, OUTPUT);
pinMode(echo, INPUT);
pinMode(led, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(interruptor, INPUT);

}
 
void loop() {
  if((digitalRead(interruptor))==1) {
    long duracion, distancia;
  delay(1000); 
  digitalWrite(trigger, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);
  duracion = pulseIn(echo, HIGH);
  distancia= (duracion/2) / 29.1;
  Serial.print("Distance: ");
  Serial.print(distancia);
  Serial.print("cm");
  Serial.println();
  
   if(distancia < 50) {
      digitalWrite(led, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    else if((distancia < 100) && (distancia >= 50)){
      digitalWrite(led, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    }
    else{
      digitalWrite(led, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
    }
    
    delay(100);
    }
  
  else{
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

}



