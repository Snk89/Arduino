#include <LiquidCrystal.h>
#include <Stepper.h>
#define HALFSTEP 8  //Half-step mode (8 step control signal sequence)
 

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define IN1  6
#define IN2  5
#define IN3  4
#define IN4  3

Stepper motor(512, IN1, IN2, IN3, IN4);

int button1State = 0;
int button2State = 0;
int button3State = 0;
int PosLCD = 0;

String PrintLCD[2];

void setup() {
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Print a message to the LCD.
  lcd.print("Bem-Vindo:Keyuno");
  delay(3000);
  lcd.clear();
  PrintLCD[0] = "Fechar Todas";
  PrintLCD[1] = "Janela Quarto";


  //Motor
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);
  motor.setSpeed(20);


  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
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

  button1State = analogRead(2);
  button2State = analogRead(3);
  button3State = analogRead(4);
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
  if (button3State == HIGH)
  {
    motor.step(500);
  }
}
