//void setup() {
  // put your setup code here, to run once:

//}

//void loop() {
  // put your main code here, to run repeatedly:

//}

//3.8.  PROGRAMACIÓN


#include <Wire.h> //Librería que permite comunicarse con los dispositivos #include "RTClib.h" //Librería para el módulo reloj (RTC)
#include <Keypad.h> //Librería para el teclado

#include <LiquidCrystal.h> //Librería para la pantalla LCD 16x2

// RTC_DS1307 rtc;

RTC_DS3231 rtc;
 
char pulsacion;

#define COLS 16 // Columnas del LCD #define ROWS 2 // Filas del LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Pines de la pantalla LCD 16x2 int HORA=0; //Definición de variables de horas y minutos
int c=0;

int Hora2=0; int Mint=0; int h1=9;
int h2=9; int m1=9;
int m2=9; //Definición de variables de horas y minutos int Seg=9; //Variable para los segundos
int Mes=0; //Definición de variable para el mes int Dia=0; //Definición de variable para el día
int Semana=0; //Definición de variable para las semanas String DIA;
const byte Filas = 4; //Cuatro filas  Estableciendo filas y columnas const byte Cols = 3;   //Tres columnas de la matriz
byte Pins_Cols[] = {10,9,A1}; //Pines Arduino para las columnas byte Pins_Filas[] = {A2,A3,A0,6};   // Pines Arduino para las filas char Teclas [ Filas ][ Cols ] =   //Características de teclas en filas y
columnas en la matriz

{

{'1','2','3'},

{'4','5','6'},

{'7','8','9'},
 
{'*','0','#'},

};

Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols); //Creamos lo que va a ser nuestro Keypad, que llamaremos "Teclado1"



String daysOfTheWeek[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
String monthsNames[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };


int i;  //Se crea una variable i int pulsacion1;
int min2,hor2; //Hora que defino yo como alarma. Solo me interesan la hora y los minutos


int alarm [10][4]; //Declaracion de la matriz de 10x4

int counter=0;  //Se esta creando, contador 1 y 2 de tipo int int counter2=0;   //y su valor es cero


void setup() {  //funcion que recoge la configuracion del programa pinMode(13,OUTPUT); //declaración para las luces led pinMode(8,OUTPUT); //declaración para las luces led
pinMode(7,OUTPUT); //declaración para las luces led digitalWrite(13,HIGH); //declaración para las luces led digitalWrite(8,LOW); //declaración para las luces led digitalWrite(7,LOW); //declaración para las luces led
 
Serial.begin(9600); //Abre el puerto serie y fija la velocidad en baudios para la transmisión de datos en serie
if (!rtc.begin()) { Serial.println(F("Couldn't find RTC")); while (1);


}

lcd.begin(COLS, ROWS);

//rtc.adjust(DateTime(2018, 8, 21, 14, 18, 0)); //configuración de fecha y hora

}

void loop() { //Funcion que contiene la configuracion del programa que se ejecutara ciclicamente



Serial.print(DIA); //imprimir en pantalla el dia Serial.print(" "); //espaciado
Serial.print(h1); //imprimir digito de hora Serial.print(" "); //espaciado Serial.print(h2); //imprimir digito de hora Serial.print(" "); //espaciado


Serial.print(m1); //imprimir digito de minuto Serial.print(" "); //espaciado Serial.print(m2); //imprimir digito de minuto Serial.print(" "); //espaciado
Serial.println(Seg); //imprimir dígitos de los segundos

DateTime now = rtc.now(); // establecimiento de fecha y hora
 
// Serial.println(HORA);

char pulse = Teclado1.getKey() ; // se lee la pulsación

if (pulse == '#') {   //comparación de la pulsación en la tecla # lcd.clear();  //limpieza en la pantalla LCD
for (counter2=0;counter2<10;counter2++) //si el contador 2 es igual a cero o menor a 10
{

Serial.print(pulse); //imprime pulsación

lcd.setCursor(0,0); //definición de espacios del cursor en la pantalla LCD lcd.print ("A"); //definición de espacios del cursor en la pantalla LCD lcd.setCursor(1,0); //definición de espacios del cursor en la pantalla LCD lcd.print(counter2); //definición de espacios del cursor en la pantalla LCD lcd.setCursor(3,0); //definición de espacios del cursor en la pantalla LCD lcd.print (alarm [counter2][0]); //y se cumple la funcion el contador incrementa 1
lcd.setCursor(4,0); //definición de espacios del cursor en la pantalla LCD lcd.print (alarm [counter2][1]); //y se cumple la funcion el contador incrementa 1 lcd.print(':'); //definición de espacios
lcd.setCursor(6,0); //definición de espacios del cursor en la pantalla LCD lcd.print (alarm [counter2][2]);   //hasta que el ciclo termine lcd.setCursor(7,0); //definición de espacios del cursor en la pantalla LCD lcd.print(alarm [counter2][3]); //y se cumple la funcion el contador incrementa 1 lcd.setCursor(0,1); //definición de espacios del cursor en la pantalla LCD lcd.print("desea borrar"); //muestra en la pantalla el mensaje "desea borrar"
lcd.setCursor(12,1); //definición de espacios del cursor en la pantalla LCD lcd.print(" "); //definición de espacios del cursor en la pantalla LCD
 
pulsacion=Teclado1.waitForKey(); // Esperamos a que pulse un botón. switch(pulsacion){  // Pulsación es de tipo char, por eso hemos definido al principio de programa "pulsacion1", de tipo int,
// Que tendrá un valor numérico que será el de la hora en la que el usuario ha definido la alarma.
//Este valor, será dependiendo el botón pulsado en el teclado matricial, que hemos guardado en pulsacion.
case '1': alarm [counter2][0]=0;  //instruccion case donde se compara el valor del contador2 que sea cero
alarm [counter2][1]=0;  //se compara si en la posicion alarm [counter2][2]=0; //de hora y minutos es cero alarm [counter2][3]=0;
break; case '2': {};
break;  //sale del ciclo case

}

}

counter2=0;

}

if (pulse == '*') { //se compara si se pulsa la tecla *

// Serial.print("hora:"); //aparecera en la pantalla el mensaje "hora:"

{

if(counter<10){ //si el contador es menor a 11

if (alarm [counter][0]==0 && alarm[counter][1]==0 && alarm[counter][2]==0 && alarm[counter][3]==0) { //se comparara si hora y minuto esta en valor cero
lcd.clear(); //limpieza de la pantalla LCD

for(i=0;i<4;i++){ // si la condicion se cumple se incrementa i
 
char pulsacion; //caracteristica de pulsacion pulsacion=Teclado1.waitForKey(); // Esperamos a que pulse un boton.


if(i<2){

lcd.setCursor(i,0); //definición de espacios del cursor en la pantalla LCD lcd.print(pulsacion);} //imprime la pulsación
if(i>1){ //si es mayor que 1 incrementara un espacio en el cursor lcd.setCursor(i+1,0); //definición de espacios del cursor en la pantalla LCD lcd.print(pulsacion);} //imprime la pulsación
lcd.setCursor(2,0); //definición de espacios del cursor en la pantalla LCD lcd.print(":"); //definición de espacios del cursor en la pantalla LCD
Serial.print(pulsacion);    //Escribimos el el valor de pulsacion en el LCD. switch(pulsacion){ // Pulsacion es de tipo char, por eso hemos definido
al principio de programa "pulsacion1", de tipo int,

// Que tendra un valor numerico que sera el de la hora en la que el usuario ha definido la alarma.
//Este valor, sera dependiendo el boton pulsado en el teclado matricial, que hemos guardado en pulsacion.
case '1': alarm [counter][i]=1; break;
case '2': alarm [counter][i]=2; break;
case '3': alarm [counter][i]=3; break;
case '4':alarm [counter][i]=4; break;
case '5': alarm [counter][i]=5;
 
break;

case '6':alarm [counter][i]=6; break;
case '7':alarm [counter][i]=7; break;
case '8':alarm [counter][i]=8; break;
case '9': alarm [counter][i]=9; break;
case '0': alarm [counter][i]=0;

}  delay(200);  //tiene un retraso o pausa de 200 milisegundos

}

}

}

}

if (counter<10) {   //si el contador es menor a 11 se incrementara counter++; //contador incrementa
}

if (counter==10) {  //el contador será igual a 10 counter=0;
}

lcd.clear(); //limpieza de pantalla LCD lcd.setCursor(0,0); //situar el cursor en su posición lcd.print("Alarma");//mostrara en la pantalla "Alarma"
lcd.setCursor(7,0); //definición de espacios del cursor en la pantalla LCD lcd.print(counter-1);  //se imprimira el contador
lcd.setCursor(9,0); //definición de espacios del cursor en la pantalla LCD
 
lcd.print("Config"); //mostrara en la pantalla "Configurada" lcd.setCursor(1,1); //definición de espacios del cursor en la pantalla LCD lcd.print (alarm [counter-1][0]);
lcd.setCursor(2,1); //definición de espacios del cursor en la pantalla LCD lcd.print (alarm [counter-1][1]);
lcd.setCursor(3,1); //definición de espacios del cursor en la pantalla LCD lcd.print(':'); //definición de espacios del cursor en la pantalla LCD lcd.setCursor(4,1); //definición de espacios del cursor en la pantalla LCD lcd.print (alarm [counter-1][2]);
lcd.setCursor(5,1); //definición de espacios del cursor en la pantalla LCD lcd.print (alarm [counter-1][3]);
delay(2000); //tiempo de pausa de 2 milisegundos lcd.clear(); //limpeza de pantalla LCD
}

printDate(now); //lectura de fecha

for(c=0;c<10;c++){  // si la condicion se cumple se incrementa i Serial.println(DIA); //imprimir el día
if(alarm[c][0]==h1 && alarm[c][1]==h2 && alarm[c][2]==m1 && alarm[c][3]==m2 && Seg<10 && Semana==1) { //configuración del horario de los días sábados
digitalWrite(13,LOW); //pin digital de los led digitalWrite(8,HIGH); //pin digital de los led digitalWrite(7,HIGH);} //pin digital de los led


if(h1==0 && h2==8 && m1==0 && m2==0 && Seg<10 && DIA=="Sabado") { digitalWrite(13,LOW); //pin digital de los led
digitalWrite(8,HIGH); //pin digital de los led digitalWrite(7,HIGH);} //pin digital de los led
 


if(h1==1 && h2==0 && m1==0 && m2==0 && Seg<10 && DIA=="Sabado") { digitalWrite(13,LOW); //pin digital de los led
digitalWrite(8,HIGH); //pin digital de los led digitalWrite(7,HIGH);} //pin digital de los led


if(h1==1 && h2==0 && m1==1 && m2==5 && Seg<10 && DIA=="Sabado") { digitalWrite(13,LOW); //pin digital de los led
digitalWrite(8,HIGH); //pin digital de los led digitalWrite(7,HIGH);} //pin digital de los led


if(h1==1 && h2==2 && m1==1 && m2==5 && Seg<10 && DIA=="Sabado") { digitalWrite(13,LOW); //pin digital de los led
digitalWrite(8,HIGH); //pin digital de los led digitalWrite(7,HIGH);} //pin digital de los led


if(h1==1 && h2==3 && m1==0 && m2==0 && Seg<10 && DIA=="Sabado") { digitalWrite(13,LOW); //pin digital de los led
digitalWrite(8,HIGH); //pin digital de los led digitalWrite(7,HIGH);} //pin digital de los led


if(h1==1 && h2==5 && m1==0 && m2==0 && Seg<10 && DIA=="Sabado") { digitalWrite(13,LOW); //pin digital de los led
digitalWrite(8,HIGH); //pin digital de los led digitalWrite(7,HIGH);} //pin digital de los led


if(h1==1 && h2==5 && m1==1 && m2==5 && Seg<10 && DIA=="Sabado") {
 
digitalWrite(13,LOW); //pin digital de los led digitalWrite(8,HIGH); //pin digital de los led digitalWrite(7,HIGH);} //pin digital de los led


if(h1==1 && h2==7 && m1==1 && m2==5 && Seg<10 && DIA=="Sabado") { digitalWrite(13,LOW); //pin digital de los led
digitalWrite(8,HIGH); //pin digital de los led digitalWrite(7,HIGH);} //pin digital de los led


if(h1==0 && h2==8 && m1==0 && m2==0 && Seg>10 && DIA=="Sabado") { digitalWrite(13,HIGH); //pin digital de los led
digitalWrite(8,LOW); //pin digital de los led digitalWrite(7,LOW);} //pin digital de los led


if(h1==1 && h2==0 && m1==0 && m2==0 && Seg>10 && DIA=="Sabado") { digitalWrite(13,HIGH); //pin digital de los led
digitalWrite(8,LOW); //pin digital de los led digitalWrite(7,LOW);} //pin digital de los led


if(h1==1 && h2==0 && m1==1 && m2==5 && Seg>10 && DIA=="Sabado") { digitalWrite(13,HIGH); //pin digital de los led
digitalWrite(8,LOW); //pin digital de los led digitalWrite(7,LOW);} //pin digital de los led


if(h1==1 && h2==2 && m1==1 && m2==5 && Seg>10 && DIA=="Sabado") { digitalWrite(13,HIGH); //pin digital de los led
digitalWrite(8,LOW); //pin digital de los led
 
digitalWrite(7,LOW);} //pin digital de los led


if(h1==1 && h2==3 && m1==0 && m2==0 && Seg>10 && DIA=="Sabado") { digitalWrite(13,HIGH); //pin digital de los led
digitalWrite(8,LOW); //pin digital de los led digitalWrite(7,LOW);} //pin digital de los led


if(h1==1 && h2==5 && m1==0 && m2==0 && Seg>10 && DIA=="Sabado") { digitalWrite(13,HIGH); //pin digital de los led
digitalWrite(8,LOW); //pin digital de los led digitalWrite(7,LOW);} //pin digital de los led


if(h1==1 && h2==5 && m1==1 && m2==5 && Seg>10 && DIA=="Sabado") { digitalWrite(13,HIGH); //pin digital de los led
digitalWrite(8,LOW); //pin digital de los led digitalWrite(7,LOW);} //pin digital de los led


if(h1==1 && h2==7 && m1==1 && m2==5 && Seg>10 && DIA=="Sabado") { digitalWrite(13,HIGH); //pin digital de los led
digitalWrite(8,LOW); //pin digital de los led digitalWrite(7,LOW);} //pin digital de los led


if(alarm[c][0]==h1 && alarm[c][1]==h2 && alarm[c][2]==m1 && alarm[c][3]==m2 && Seg>10) {
digitalWrite(13,HIGH); //pin digital de los led digitalWrite(8,LOW); //pin digital de los led digitalWrite(7,LOW);} //pin digital de los led
 
} //configuración del horario de los días sábados

}

void printDate(DateTime date) //imprimir fecha y hora

{

lcd.setCursor(6,0); //definición de espacios del cursor en la pantalla LCD lcd.print(date.year(), DEC); //definición de fecha del cursor en la pantalla LCD lcd.setCursor(8,1); //definición de espacios del cursor en la pantalla LCD lcd.print("  "); //definición de espacios del cursor en la pantalla LCD lcd.setCursor(2,0); //definición de espacios del cursor en la pantalla LCD lcd.print('/'); //definición de espacios del cursor en la pantalla LCD
//lcd.setCursor(3,0);

//lcd.print(date.month(), DEC); lcd.setCursor(5,0);
lcd.print('/');

// lcd.setCursor(0,0);

//lcd.print(date.day(), DEC);

lcd.setCursor(13,0); //definición de espacios del cursor en la pantalla LCD lcd.print(daysOfTheWeek[date.dayOfTheWeek()]);
if(Dia<10){

lcd.setCursor(0,0); //definición de espacios del cursor en la pantalla LCD lcd.print("0"); //definición de espacios del cursor en la pantalla LCD lcd.setCursor(1,0); //definición de espacios del cursor en la pantalla LCD lcd.print(Dia); //imprimir el día
}

if(Dia>=10){ //definición de los días de la semana

lcd.setCursor(0,0); //definición de espacios del cursor en la pantalla LCD lcd.print(Dia); //imprimir el día
 
}

if(Mes<10){ //definición del mes

lcd.setCursor(3,0); //definición de espacios del cursor en la pantalla LCD lcd.print("0");
lcd.setCursor(4,0); //definición de espacios del cursor en la pantalla LCD lcd.print(Mes); //imprimir el mes
}

if(Mes>=10){

lcd.setCursor(3,0); //definición de espacios del cursor en la pantalla LCD lcd.print(Mes); //imprimir el mes
}

if(Hora2<10){ //definición de los dígitos de la hora

lcd.setCursor(0,1); //definición de espacios del cursor en la pantalla LCD lcd.print(" "); //definición de espacios del cursor en la pantalla LCD lcd.setCursor(1,1); //definición de espacios del cursor en la pantalla LCD lcd.print(Hora2); //imprimir hora
}

if(Hora2>=10){ //definición de los dígitos de la hora

lcd.setCursor(0,1); //definición de espacios del cursor en la pantalla LCD lcd.print(Hora2);//imprimir hora
}

if(Mint<10){ //definición de minutos

lcd.setCursor(3,1); //definición de espacios del cursor en la pantalla LCD lcd.print("0");
lcd.setCursor(4,1); //definición de espacios del cursor en la pantalla LCD lcd.print(Mint); //imprimir minuto
}
 
if(Mint>=10){

lcd.setCursor(3,1); //definición de espacios del cursor en la pantalla LCD lcd.print(Mint);//imprimir minuto
}

if(Seg<10){ //definir los segundos

lcd.setCursor(7,1); //definición de espacios del cursor en la pantalla LCD lcd.print(" "); //definición de espacios del cursor en la pantalla LCD
//lcd.setCursor(7,1); //definición de espacios del cursor en la pantalla LCD

//lcd.print(Seg);//imprimir los segundos

}

//if(Mint>=10){

//lcd.setCursor(6,1); //definición de espacios del cursor en la pantalla LCD

//lcd.print(Mint);

//}

// lcd.setCursor(0,1); //definición de espacios del cursor en la pantalla LCD

//lcd.print(date.hour(), DEC);

lcd.setCursor(2,1); //definición de espacios del cursor en la pantalla LCD lcd.print(':'); //definición de espacios del cursor en la pantalla LCD
// lcd.setCursor(3,1); //definición de espacios del cursor en la pantalla LCD

// lcd.print(date.minute(), DEC);

lcd.setCursor(5,1); //definición de espacios del cursor en la pantalla LCD lcd.print(':'); //definición de espacios del cursor en la pantalla LCD
lcd.setCursor(6,1); //definición de espacios del cursor en la pantalla LCD lcd.print(date.second(), DEC);
Hora2=date.hour(), DEC; //variables de hora h1=Hora2/10;
h2=Hora2-(h1*10);
 
Mint=date.minute(), DEC; //variables de minutos m1=Mint/10;
m2=Mint-(m1*10);


Seg=date.second(), DEC; //comparación de fecha y segundos Mes=date.month(), DEC; //comparación de mes Dia=date.day(), DEC; //comparación de día
DIA=daysOfTheWeek[date.dayOfTheWeek()];//verificación de los días de la semana


if (DIA=="Lunes" || DIA=="Martes" || DIA=="Miercoles" || DIA=="Jueves" || DIA=="Viernes") { //si el dia es lunes, martes, miércoles, jueves o viernes la alarma no sonara
Semana=1;}


if (DIA=="Sabado" || DIA=="Domingo") {

Semana=0;} //la alarma sonara según el día previamente programado

}
