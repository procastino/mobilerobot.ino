#include <NewPing.h>
NewPing sonar_L(11,11,50);  // trigger y echo al pin 10, distancia máxima limitada a 50cm
NewPing sonar_R(10,10,50);

float dist_L, dist_R, dist;

void setup()
{
pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop()
{

// lee los sensores HC-SR04

  delay(30);  // necesario para que el sensor espere el eco del pulso
  dist_L = sonar_L.ping_cm();
  if (dist_L==0) {dist_L=50;}  // corrige las distancias mayores de 50cm que dan lectura 0

  delay(30);
  dist_R = sonar_R.ping_cm();
  if (dist_R==0) {dist_R=50;}
 
  dist=min(dist_L,dist_R);
 
  if (dist<15)
  {
    if (dist_L>dist_R) rotate(30);
    else rotate(-30);
  }
  else forward(110,110,0);
}



void forward(int l, int r, int t)
{
  analogWrite(5,l);
  analogWrite(6,r);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  delay(t);
}

void reverse(int l, int r, int t)
{
  analogWrite(5,l);
  analogWrite(6,r);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  delay(t);
}

void brake(int t)
{
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  delay(t);
}

void rotate(int t)
{
  analogWrite(5,100);
  analogWrite(6,100);
  if (t>0) {
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
   }
  else
  {
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
  } 
  delay(abs(t));
}
