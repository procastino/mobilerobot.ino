/* Sketch para o funcionamento do redbot como seguelinhas, empregando as librarias de @fstdp, 
Conectar os sensores de infravermellos aos pins A4 (esquerdo) e A5 (dereito)*/

#include <RobotMovil.h>
RobotMovil robot; 



//definimos o umbral dos sensores
int umbral=700;
//definimos o xiro co que queremos que reaccione o robot
int xiro=40;
//definimos as variables que gardaran as lecturas
int lecturaEsquerda;
int lecturaDereita;

void setup()
{
}

void loop()
{
//facemos lectura esquerda e dereita
lecturaEsquerda=analogRead(A4);
lecturaDereita=analogRead(A5);
if (lecturaEsquerda>umbral && lecturaDereita<umbral){
robot.rotate(xiro);}
else if (lecturaEsquerda<umbral && lecturaDereita>umbral){
robot.rotate(-xiro);}
else {robot.forward(120,120,10);}
  
}
