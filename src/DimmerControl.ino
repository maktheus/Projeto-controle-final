#include <Arduino.h>

#define TAMANHO_JANELA 5  // Define o tamanho da janela para a média móvel
int leiturasPotencia[TAMANHO_JANELA];  // Armazena as últimas N leituras
int indiceLeitura = 0;  // Índice atual para a próxima leitura
float somaPotencia = 0;  // Soma das últimas N leituras
float potenciaMedia = 0;  // Média móvel calculada



class DimmerControl {
  private:
    int controlPin; // Pino usado para controlar o dimmer
    
  public:
    DimmerControl(int pin) : controlPin(pin) {}

    void begin() {
      pinMode(controlPin, OUTPUT);
    }

    // Ajusta a luminosidade (0 a 100%)
    void setBrightness(int brightness) {
      int dimValue = map(brightness, 0, 100, 0, 255);
      analogWrite(controlPin, dimValue);
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
};
