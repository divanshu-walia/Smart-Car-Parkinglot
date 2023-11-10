#include <SoftwareSerial.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3); //connected to RS,EN,D4,D5,D6,D7 of LCD display respectively

SoftwareSerial soft( 6, 7);  //RX and TX

int in    = 9;  // IN sensor pin no.
int out   = 8;  // EXIT sensor pin no.
int count = 0;
int valin = 0;
int valout = 0;

int space=3;

void setup() {
 
  Serial.begin(9600);
  soft.begin(9600);

  pinMode(in, INPUT);   // Pin 9 set as INPUT
  pinMode(out, INPUT);  // Pin 8 set as EXIT

 

  lcd.begin(16, 2);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Welcome");
  delay(100);
 
  lcd.clear();
  lcd.setCursor(0, 0);
  count = 0;
}


void loop() {
  //*******************************************************
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("P-L:");
  lcd.setCursor(0, 1);

 
  lcd.print("       ");
  valin = digitalRead(in);
  
  valout = digitalRead(out);
  

  //********************************************************
  if (valout == LOW) {

    while (valout == LOW) {
      valout = digitalRead(out);
      delay(1000);
    }
    count++;
    delay(100);

    if (count < 4) { }

   
  }
  //********************************************************
  if (valin == LOW) {

   
    while (valin == LOW) {
      valin = digitalRead(in);
      delay(1000);
    }
    count--;
    delay(100);

    if (count <= 0) {
      count = 0;
    }

    
  }
  //********************************************************
  lcd.setCursor(10, 1);
 delay(100);
  if (count >= 3) {
    count = 3;
 
    lcd.setCursor(5, 1);
    lcd.print("       Full   ");
    
    space=0;
      soft.write(space);
      Serial.println(space);
  }
  else
  {
      lcd.setCursor(3,1);
     lcd.print("     Space: ");
    
     space= 3-count;
     soft.write(space);
     Serial.println(space);
      lcd.print(space);
  }

}
