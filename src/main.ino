#include <Arduino.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define sensorTensao A0



void setup() {
  Serial.begin(9600);
  DHT dht(DHTPIN, DHTTYPE);
  dht.begin();
  Wire.begin();


}

void loop() {
  // put your main code here, to run repeatedly:

}


void controleRele(int pinoRele, bool estadoRele) {
  digitalWrite(pinoRele, estadoRele);
}


int potenciaMedia(int novaLeitura){
  // Atualiza a soma das leituras ao adicionar a nova leitura e subtrair a mais antiga
  somaPotencia = somaPotencia - leiturasPotencia[indiceLeitura] + novaLeitura;
  // Armazena a nova leitura no array
  leiturasPotencia[indiceLeitura] = novaLeitura;
  // Calcula a média móvel
  potenciaMedia = somaPotencia / TAMANHO_JANELA;

  // Atualiza o índice para a próxima leitura, voltando para 0 se atingir o tamanho da janela
  indiceLeitura = (indiceLeitura + 1) % TAMANHO_JANELA;

  return potenciaMedia;
}