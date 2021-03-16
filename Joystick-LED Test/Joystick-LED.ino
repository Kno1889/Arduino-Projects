// This code outputs the current coordinates of a joystick to a potentiometer-controlled LED.
// This code will be used in the design of my custom, joystick controlled laser pointer project (for my cat to play with :) )

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initializing LCD Digital Pins
int xpotPin = A0; // initializing Joystick analog pins
int ypotPin = A1;            
int bpotPin = 6; 

int xval=0;       //Initializing variables to hold x, y values of joystick output
int yval=0;
int bval=0;

void setup()                                                                                     
{
  lcd.begin(16,2);   //Display Address
  pinMode(xpotPin,INPUT); // defining input from joystick to Arduino board
  pinMode(ypotPin,INPUT);
  pinMode(bpotPin,INPUT);
   
  lcd.print("  Welcome to ");
  lcd.setCursor(0,1);
  lcd.print("     Smraza");
  delay(2000);
  lcd.clear();
}

void loop()
{ 
  xval = analogRead(xpotPin);   //Read Values from the xpotPin
  yval = analogRead(ypotPin);   
  bval = digitalRead(bpotPin);   

  lcd.clear();                 //clear display
  lcd.setCursor(0, 0) ;       //Display position
  lcd.print("X=");            //Display "X="
  lcd.print(xval);
  lcd.setCursor(7, 0) ;  
  lcd.print("Y=");       
  lcd.print(yval);  
  
  if (bval==LOW)
  {
    lcd.setCursor(0, 1) ;   
    lcd.print("Button ON"); 
  }
  else
  {
  lcd.setCursor(0, 1) ;
  lcd.print("Button OFF"); 
  }
  delay(150); //After 150ms the screen will be refreshed
}
