#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int trigPin = 2; //Sensor Trip pin connected to Arduino pin 4
int echoPin = 3; //Sensor Echo pin connected to Arduino pin 5
int trigPin1 = 4; //Sensor Trip pin connected to Arduino pin 6
int echoPin1 = 5; //Sensor Echo pin connected to Arduino pin 7
int trigPin2 = 6; //Sensor Trip pin connected to Arduino pin 8
int echoPin2 = 7; //Sensor Echo pin connected to Arduino pin 9
int trigPin3 = 8; //Sensor Trip pin connected to Arduino pin 10
int echoPin3 = 9; //Sensor Echo pin connected to Arduino pin 11
int pump = 10; //pump connected to pin 2

float pingTime;
float pingTime1;
float pingTime2;
float pingTime3;//time for ping to travel from sensor to target and return
float h = 0;
float h1 = 0;
float h2 = 0;
float h3 = 0;
int v = 0;
int v1 = 0;
int v2 = 0;
int v3 = 0; // volume of the water


float speedOfSound = 776.5; //Speed of sound in miles per hour when temp is 77 degrees.

void setup() {

  Serial.begin(9600);


  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pump, OUTPUT);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  lcd.begin(20, 4); //Tell Arduino to start your 16 column 2 row lcd
  lcd.setCursor(3, 0); //Start at character 4 on line 0
  lcd.print("Ultra Water");
  lcd.setCursor(0, 1); //Start at character 4 on line 0
  lcd.print("Save Water,Save Life");
  lcd.setCursor(0, 2); //Start at character 4 on line 0

  delay(8000);
  lcd.clear();

  lcd.setCursor(0, 0); //Set lcd cursor to upper left corner, column 0, row 0
  lcd.print("Tank1 Lvl=");
  lcd.setCursor(0, 1);
  lcd.print("Tank2 Lvl="); //Print Message on First Row
  lcd.setCursor(0, 2);
  lcd.print("Tank3 Lvl=");
  lcd.setCursor(0, 3);
  lcd.print("Tank4 Lvl=");

}
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pingTime = pulseIn(echoPin, HIGH);  //pingTime is presented in microceconds
  h = (pingTime/2)/29.1;  
  Serial.println(h);
  v = ((22 / 7) * 54.9 * 54.9 * (110.6 - h)) / 1000;


  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  pingTime1 = pulseIn(echoPin1, HIGH); //pingTime is presented in microceconds
  h1 = (pingTime1/2)/29.1;
  Serial.println(h1);
  v1 = ((22 / 7) * 54.9 * 54.9 * (110.6 - h1)) / 1000;



  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  pingTime2 = pulseIn(echoPin2, HIGH);  //pingTime is presented in microceconds
  h2 = (pingTime2/2)/29.1;
  Serial.println(h2);
  v2 = ((22 / 7) * 54.9 * 54.9 * (110.6 - h2)) / 1000;



  digitalWrite(trigPin3, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  pingTime3 = pulseIn(echoPin3, HIGH);  //pingTime is presented in microceconds
  h3 = (pingTime3/2)/29.1;
  Serial.println(h3);
  v3 = ((22 / 7) * 54.9 * 54.9 * (110.6 - h3))/ 1000;

  lcd.setCursor(10, 0); //Set cursor to first column of second row
  lcd.print(v); //Print measured volume
  lcd.setCursor(13, 0);
  lcd.print("Ltr");  //Print your units.
  delay(250);
  lcd.setCursor(10, 1); //Set cursor to first column of second row
  lcd.print(v1); //Print measured total volume
  lcd.setCursor(13, 1);
  lcd.print("Ltr");  //Print your units.
  delay(250);

  lcd.setCursor(10, 2); //Set cursor to first column of second row
  lcd.print(v2); //Print measured total volume
  lcd.setCursor(13, 2);
  lcd.print("Ltr");  //Print your units.
  delay(250);
  lcd.setCursor(10, 3); //Set cursor to first column of second row
  lcd.print(v3); //Print measured total volume
  lcd.setCursor(13, 3);
  lcd.print("Ltr");  //Print your units.
  delay(250);


  if ((100 < h) || (100 < h1) || ( 100 < h2 ) || ( 100 < h3))//h = air gap 
  {

    digitalWrite(pump, HIGH);
    lcd.setCursor(17, 1);
    lcd.print("ON ");  //Set cursor to first column of second row
    delay(250);
  }
  else if ((h < 10) && (h1 < 10 ) && (h2 < 10) && ( h3 < 10))
  {

    digitalWrite(pump, LOW);
    lcd.setCursor(17, 1);
    lcd.print("OFF");  //Set cursor to first column of second row
    delay(250);
  }
  else
  {
    digitalWrite(pump, LOW);
    lcd.setCursor(17, 1);
    lcd.print("OFF");  //Set cursor to first column of second row
    delay(250);
  }



}



