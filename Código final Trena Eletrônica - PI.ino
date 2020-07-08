
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//Define os pinos para o trigger e echo
#define pino_trigger 7
#define pino_echo 6
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
double med = 0;
double soma = 0;
void setup()
{
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("aperte o botao 4");
  lcd.setCursor(0, 1);
  lcd.print("para informacoes");
}
void loop()
{
  float medida;
  long microsec = ultrasonic.timing();
  medida = ultrasonic.convert(microsec, Ultrasonic::CM);
  if(digitalRead(8) == LOW){
  //botão medir
   lcd.clear();
   lcd.setCursor(3, 0);
   lcd.print("valor:");
   lcd.setCursor(3, 1);
   lcd.print(medida);
   delay(1000);
  }
  if(digitalRead(9) == LOW){
   //botão salvar valor
    med = medida;
    lcd.clear();
    lcd.setCursor(2, 1);
    lcd.print("valor salvo");
  }
  if(digitalRead(10) == LOW){
   //botão somar
   if(med>0){
    soma = med+medida;
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("valor somado:");
    lcd.setCursor(3, 1);
    lcd.print(soma);
    }else{
    lcd.setCursor(0, 0);
    lcd.print("salve a medida");
    lcd.setCursor(0, 1);
    lcd.print("para poder somar");
    }
  }
  if(digitalRead(13) == LOW){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("botao 1: medir");
    lcd.setCursor(0, 1);
    lcd.print("botao 2: salvar");
    delay(10000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("botao 3: somar");
    lcd.setCursor(0, 1);
    lcd.print("botao 4: infor.");
  }
}
