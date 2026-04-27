// Declaração dos nomes para os pinos de I/O
#define led_vm 12
#define led_am 9
#define led_vd 5
#define led_az 2


// Variáveis globais
int valorAnalog;
float tensao_0_5V;
float tensao_0_60V;

/*
ADC de 10 bits ----> ANALOG TO DIGITAL CONVETER
entrada (A0 a A5) ----> 0.0V a 5.0V
saida (0 a 1023)
0.0 ---> 0
5.0 ---> 1023
*/


// Rotina de configuração (roda apenas na inicialização)
void setup() {
  
  // Configuração do sentido dos pinos de I/O
  pinMode(led_am, OUTPUT);
  pinMode(led_az, OUTPUT);
  pinMode(led_vd, OUTPUT);
  pinMode(led_vm, OUTPUT);
  
  // Inicialização do monitoramento serial (baud rate: 9600 bits/s)
  Serial.begin(9600);

  // Mensagem de inicialização  
  Serial.println("Medidor de tensao - 1CCPW - SERS");
  Serial.println("");
  delay(2000); // tempo até o incio do loop
}

// Rotina principal (roda ciclicamente)
void loop() {
  medidor();
  comparador();

}

// Código para medição da tensão
void medidor(){
  valorAnalog = analogRead(A0); // 0 a 1023

  tensao_0_5V = map(valorAnalog, 0, 1023, 0, 500) / 100.0;

  tensao_0_60V = map(valorAnalog, 0, 1023, 0, 6000) / 100.0;

  Serial.print("Valor do ADC: ");
  Serial.print(valorAnalog);

  Serial.print(" V - Tensao (0 - 5V): ");
  Serial.print(tensao_0_5V);

  Serial.print("- Tensao (0 - 60V): ");
  Serial.print(tensao_0_60V);
  Serial.println(" V");

  delay(500);

}

// Código para verificar valores de tensão e ativar os LEDs
void comparador(){
  // LED azul ---> se a tensão gerada for maior que 55V
  if (tensao_0_60V > 55){
    digitalWrite(led_az, HIGH);
    digitalWrite(led_vd, LOW);
  }
  // LED verde ---> se a tensão gerada for entre que 40 a 55V
  if (tensao_0_60V > 40  && tensao_0_60V <= 55){
    digitalWrite(led_az, LOW);
    digitalWrite(led_vd, HIGH);
    digitalWrite(led_am, LOW);
  }
  // LED amarelo ---> se a tensão gerada for entre que 30 a 40V
  if (tensao_0_60V > 30  && tensao_0_60V <= 40){
    digitalWrite(led_vd, LOW);
    digitalWrite(led_am, HIGH);
    digitalWrite(led_vm, LOW);
  } 
  // LED vermelho ---> se a tensão gerada for menor que 30V
  if (tensao_0_60V <= 30){
    digitalWrite(led_am, LOW);
    digitalWrite(led_vm, HIGH);
  } 
}



