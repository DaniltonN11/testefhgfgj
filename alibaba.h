// 1 led
// 1 buzzer
// 1 sensor 
// 1 botao
// 1 resistor

#include <Ultrasonic.h>

int pino_Trig = 3;
int pino_Echo = 2;
/* Especifi ca o nome e os pinos para o sensor */
Ultrasonic Sensor(pino_Trig, pino_Echo);
/* Variável que armazenará as medidas. */
int distancia;

#define led 4
#define buzzer 9
void setup()
{
/* Define o pino do buzzer como Saída */
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
Serial.begin(9600);
}
void loop()
{

 distancia = Sensor.read();
 Serial.print("Distância: ");
 Serial.print(distancia);
 Serial.println("cm");

if(distancia <= 10){

  tone(buzzer,1500);
  digitalWrite(led, HIGH);
delay(100);
noTone(buzzer);
digitalWrite(led, LOW);
tone(buzzer,1713);
delay(100);
noTone(buzzer);
  
  }else{
    digitalWrite(led, LOW);
    }



}
