#include <LiquidCrystal.h>
#include <Stepper.h>
#include <Servo.h>
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
Servo myservo;

int ServoPos = 0;

int button1State = 0;
int button2State = 0;
int button3State = 0;
int button4State = 0;
int button5State = 0;
int PosLCD = 0;
int OnOffLcd = 0;



String PrintLCD[2];
int Janela_Max_ID = 1;

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
  
  myservo.attach(9);


  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
}
void loop() {
  
  lcd.setCursor(0, PosLCD);
  lcd.print(PrintLCD[PosLCD]);
  
  lcd.setCursor(0, PosLCD + 1);
  lcd.print(PrintLCD[PosLCD + 1]);
  
  lcd.setCursor(0, PosLCD);
  
  button1State = analogRead(A2);
  button2State = analogRead(A3);
  button3State = digitalRead(A4);
  button3State = digitalRead(A5);
  button3State = digitalRead(A6);

  //botao 1 para selecionar a proxima porta no lcd
  if (button1State == HIGH)
  {
    if (PosLCD < Janela_Max_ID)
      {
        lcd.clear();
        lcd.print(PrintLCD[PosLCD]);
        PosLCD++;
        lcd.setCursor(0,PosLCD);
        lcd.print(PrintLCD[PosLCD]);
      }
  }

  //botao 2 para selecionar a porta anterior no lcd
  if (button2State == HIGH)
  {
    if (PosLCD > 0)
      {
        lcd.clear();
        lcd.print(PrintLCD[PosLCD]);
        PosLCD--;
        lcd.setCursor(0,PosLCD);
        lcd.print(PrintLCD[PosLCD]);
      }
  }

  //botao 3 para abrir a janela
  if (button3State == HIGH)
  {
    motor.step(1000);
    delay(1000);
    motor.step(500);
    delay(500);
    ServoPos = myservo.read();
    //se sensor nao detectou porta ent motor corre
    for(int c = 0;c<=5;c++)
    {
      if (ServoPos = 0)
      {
        for (ServoPos = myservo.read(); ServoPos <= 90; ServoPos++)
        {
          myservo.write(ServoPos);
          delay(15);
        }
      }
    }
  }
  
  //Botao 4 para destrancar
  if (button4State == HIGH)
  {
    ServoPos = 0;
    myservo.write(ServoPos);
  }
  
  //botao 5 para on/off do LCD
  if (button5State == HIGH)
  {
    if (OnOffLcd = 0){
      lcd.noDisplay();
      OnOffLcd=1;
    }
    else
    {
      lcd.display();
      OnOffLcd=0;
    }   
  }
}
