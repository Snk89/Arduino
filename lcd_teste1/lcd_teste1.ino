#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int button1State = 0;
int PosLCD = 0;

String PrintLCD[2];

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Ola");
  delay(3000);
  lcd.clear();
  PrintLCD[0] = "Fechar Todas";
  PrintLCD[1] = "Janela Quarto";


  pinMode(3, INPUT);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  
  lcd.setCursor(0, 0);
  lcd.print(PrintLCD[0]);
  lcd.setCursor(0, 1);
  lcd.print(PrintLCD[1]);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);

  button1State = digitalRead(3);
  lcd.setCursor(0, 0);
  
  if (button1State == HIGH)
  {
    if (PosLCD == 0)
      {
        PosLCD++;
        lcd.setCursor(0,PosLCD);
      }
      else{
        PosLCD--;
        lcd.setCursor(0,PosLCD);
      }
  }
}
