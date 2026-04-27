// Atribuir um nome ao pino do LED
// int LED_1 = 12;
// const int LED_1 = 12;
#define LED_1 4
#define LED_2 12
#define LED_3 9

void setup() {
  // Condigurar o pino do LED como uma saída (OUTPUT)
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
}

void loop() {
 sequencia_1();
}

void sequencia_1 (){
  
  digitalWrite(LED_1, HIGH);
  delay(1000); // em milisegundos
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);
  delay(1000); // em milisegundos
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, HIGH);
  delay(1000); // em milisegundos
  digitalWrite(LED_3, LOW);

}

void sequencia_2 (){
  digitalWrite(LED_1, HIGH);
  delay(500); // em milisegundos
  digitalWrite(LED_2, HIGH);
  delay(500); // em milisegundos
  digitalWrite(LED_3, HIGH);
  delay(500); // em milisegundos
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  delay(500);
}


