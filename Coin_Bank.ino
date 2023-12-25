//Imports
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Number of coins
int numQuarters = 0;
int numDimes = 0;
int numNickels = 0;

//Ports
int quarters = 13;
int nickels = 12;
int dimes = 11;
double balance = 0;
int button1 = 10; //Quarters
int button2 = 9; //Dimes
int button3 = 8; //Nickels

LiquidCrystal_I2C lcd(0x27, 16, 2);

//LCD and Port Initialization
void setup()
{
  lcd.begin();
  lcd.backlight();
  pinMode(quarters, INPUT);
  pinMode(nickels, INPUT);
  pinMode(dimes, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("Balance: $");
  lcd.print(balance);
  lcd.setCursor(0, 1);
  lcd.print("Q:");
  lcd.print(numQuarters);
  lcd.print("  D:");
  lcd.print(numDimes);
  lcd.print("  N:");
  lcd.print(numNickels);
}

//Updates LCD display
void loop()
{
  if(digitalRead(button1) == HIGH){
    //Clears quarters count
    balance -= numQuarters * 0.25;
    numQuarters = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Balance: $");
    lcd.print(balance);
    lcd.setCursor(0, 1);
    lcd.print("Q:");
    lcd.print(numQuarters);
    lcd.print("  D:");
    lcd.print(numDimes);
    lcd.print("  N:");
    lcd.print(numNickels);
  }
  if(digitalRead(button2) == HIGH){
    //Clears dimes count
    balance -= numDimes * 0.10;
    numDimes = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Balance: $");
    lcd.print(balance);
    lcd.setCursor(0, 1);
    lcd.print("Q:");
    lcd.print(numQuarters);
    lcd.print("  D:");
    lcd.print(numDimes);
    lcd.print("  N:");
    lcd.print(numNickels);
  }
  if(digitalRead(button3) == HIGH){
    //Clears nickels count
    balance -= numNickels * 0.05;
    numNickels = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Balance: $");
    lcd.print(balance);
    lcd.setCursor(0, 1);
    lcd.print("Q:");
    lcd.print(numQuarters);
    lcd.print("  D:");
    lcd.print(numDimes);
    lcd.print("  N:");
    lcd.print(numNickels);
  }
  if (digitalRead(quarters) == 0) {
    //Quarter detected
    numQuarters++;
    balance += 0.25;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Balance: $");
    lcd.print(balance);
    lcd.setCursor(0, 1);
    lcd.print("Q:");
    lcd.print(numQuarters);
    lcd.print("  D:");
    lcd.print(numDimes);
    lcd.print("  N:");
    lcd.print(numNickels);
    delay(300); // Wait for 300 millisecond(s)
  }else if (digitalRead(dimes) == 0) {
    //Dime detected
    numDimes++;
    balance += 0.10;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Balance: $");
    lcd.print(balance);
    lcd.setCursor(0, 1);
    lcd.print("Q:");
    lcd.print(numQuarters);
    lcd.print("  D:");
    lcd.print(numDimes);
    lcd.print("  N:");
    lcd.print(numNickels);
    delay(300); // Wait for 300 millisecond(s)
  }else if (digitalRead(nickels) == 0) {
    //Nickel detected
    numNickels++;
    balance += 0.05;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Balance: $");
    lcd.print(balance);
    lcd.setCursor(0, 1);
    lcd.print("Q:");
    lcd.print(numQuarters);
    lcd.print("  D:");
    lcd.print(numDimes);
    lcd.print("  N:");
    lcd.print(numNickels);
    delay(300); // Wait for 300 millisecond(s)
  }
}
