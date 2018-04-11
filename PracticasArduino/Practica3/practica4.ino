void setup()
{
  
  
  pinMode(1,INPUT);//A1
  pinMode(2,INPUT);//A2
  pinMode(3,INPUT);//A3  
  
  pinMode(4, INPUT);//B1
  pinMode(5, INPUT);//B2
  pinMode(6, INPUT);//B3
  
  pinMode(7, OUTPUT);//S0
  pinMode(8, OUTPUT);//S1
  pinMode(9, OUTPUT);//S2
  pinMode(10, OUTPUT);//S3
  
}

void loop()
{
 int S0=0; 
 int S1=0;
 int S2=0;
  
 int c1=0; 
 int c2=0;
 int c3=0;
 int suma1=digitalRead(1)+digitalRead(4);
 int suma2=digitalRead(2)+digitalRead(5);
 int suma3=digitalRead(3)+digitalRead(6);

 if (suma1==2)//primera fila
  {
    S0=0;
    c1=1;
  }
  else if (suma1==1)
  {
    S0=1;
    c1=0;
  }
  else
  {
    S0=0;
    c1=0;
  }

  if ((suma2+c1)==1)     //para segunda fila
  {
    S1=1;
    c2=0;
  }
  else if ((suma2+c1)==2)
  {
    S1=0;
    c2=1;
  }
  else if ((suma2+c1)==3)
  {
    S1=1;
    c2=1;
  }
  else
  {
    S1=0;
    c2=0;
  }
  if ((suma3+c2)==1)     //para tercera fila
  {
    S2=1;
    c3=0;
  }
  else if ((suma3+c2)==2)
  {
    S2=0;
    c3=1;
  }
  else if ((suma3+c2)==3)
  {
    S2=1;
    c3=1;
  }
  else
  {
    S2=0;
    c3=0;
  }



   if ((S0)==0){             // S0
    digitalWrite(7, LOW);
   }
   else{
    digitalWrite(7, HIGH);
   }
   if (S1==0){            //S1
    digitalWrite(8, LOW);
   }
   else{
    digitalWrite(8, HIGH);
   }
   if (S2==0){            //S2
    digitalWrite(9, LOW);
   }
   else
   {
    digitalWrite(9, HIGH);
   }
   if (c3==0){             //S3
    digitalWrite(10, LOW);
   }
   else
   {
    digitalWrite(10, HIGH);
   }
}