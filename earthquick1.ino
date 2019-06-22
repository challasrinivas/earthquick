#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); 
SoftwareSerial mySerial(5, 6);  //GSM RX and TX pins
int buzzer=7;

int x=A1;  
int y=A2;
int z=A3;

float x1,y1,z1;
float a,b,c;
int sms_count=0;//Fire_Set;

void setup() {
  // put your setup code here, to run once:
  pinMode(x,INPUT);
  pinMode(y,INPUT);
  pinMode(z,INPUT);
  pinMode(buzzer,OUTPUT);
  mySerial.begin(9600);   
  Serial.begin(9600);    
  lcd.begin(16,2);  
  delay(500);
  lcd.setCursor(0, 0);
lcd.clear();
  lcd.print("START SYSTEM");

}

void loop() {
  // put your main code here, to run repeatedly:

lcd.setCursor(0, 0);
lcd.clear();
  lcd.print("START SYSTEM");
  //delay(1000);
a=analogRead(x);    // reads the sensor output (Vout of accelerometer)3=analogRead(x,y,z);
b=analogRead(y);
c=analogRead(z);

//a,b,c= Checkvalues();

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("x: ");
lcd.print(a);
Serial.print("x: ");
Serial.print(a);

delay(3000);
lcd.print("y: ");
lcd.print(b);

Serial.print("y: ");
Serial.print(b);

delay(3000);
lcd.setCursor(1, 1);
lcd.print("z: ");
lcd.println(c);

Serial.print("z: ");
Serial.print(c);

delay(3000);

//if( (a >=350 && a<=360) || (b >=350 && b<=360) || (c >=410 && c <= 430))

if (a >=350 && a<=360)
{
  lcd.clear();
  lcd.println("normal condition");
  Serial.println("normal condition");
  digitalWrite(buzzer,LOW);
  delay(3000);
}
else if(b >=350 && b<=360)
{
  lcd.clear();
   lcd.println("normal condition");
   Serial.println("normal condition");
  digitalWrite(buzzer,LOW);
  delay(3000);
}
else if(c >=410 && c <= 430)
{  
  lcd.clear();
  lcd.println("normal condition");
Serial.println("normal condition");
  digitalWrite(buzzer,LOW);
  delay(3000);
}

else
{
  lcd.clear();
  lcd.println("earthquick occur");
  Serial.println("earthquick occur");
digitalWrite(buzzer,HIGH);
lcd.clear();
lcd.setCursor(0, 0);
lcd.println("BUZZER HIGH");
Serial.println("BUZZER HIGH");
delay(100);
digitalWrite(buzzer,LOW);

SendTextMessage();

}
}

void SendTextMessage()
{
  mySerial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(2000);
  mySerial.println("AT+CMGS=\"+918142394515\"\r"); // change to the phone number you using 
  delay(2000);
  mySerial.println("EARTHQUICK OCCURED");//the content of the message
  delay(200);
  mySerial.println((char)26);//the stopping character
  delay(5000);
  sms_count++;
 lcd.setCursor(1, 1);
  lcd.clear();
  lcd.println("SENDING MSG...");
  Serial.println("SENDING MSG...");
  delay(1000);
  lcd.clear();
}
