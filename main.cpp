#include <arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x26, 16, 2);
const int ledpin1 = 16;
const int sensorpin = 2;
long timmer = 0;
int x = 0, y = 0, z = 0;
char mode[] =" AM";

void setup(){
  pinMode(ledpin1, OUTPUT);
  pinMode(sensorpin, INPUT);
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
}



void loop(){
  int sensorvalue = digitalRead(sensorpin);
  long currenttimmer = millis();
  
  if(currenttimmer-timmer>=1000){
    digitalWrite(ledpin1, !digitalRead(ledpin1));
    timmer = currenttimmer ;

    Serial.print("Time:");
    Serial.print(z);
    Serial.print(":");
    Serial.print(y);
    Serial.print(":");
    Serial.print(x);
    Serial.println(mode);
    Serial.println(sensorvalue);
    lcd.setCursor(0, 0);
    lcd.print("Time :");
    lcd.print(z);
    lcd.print(":");
    lcd.print(y);
    lcd.print(":");
    lcd.print(x);
    lcd.setCursor(13, 0);
    lcd.print(mode);
    lcd.setCursor(0, 1);
    lcd.print("sensor value : ");
    lcd.print(sensorvalue);


    x++;
  }
  if(x==60){
  y++;
  x = 0;
  }
  if(y==60){
z++;
y = 0;
  }
  if(z==12 )
  { z = 0;
  if (strcmp(mode, "AM") == 0) {
     strcpy(mode, "PM");
    } else {
      strcpy(mode, "AM");
    }

}}



