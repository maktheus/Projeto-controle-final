#include <Arduino.h>

class SensorDeTensao {
private:
    int sensorPin;
    float Vcc;
    float offset;
    int numSamples;
  
  public:
    SensorDeTensao(int pin, float Vcc = 5.0, float offset = 2.5, int numSamples = 500)
      : sensorPin(pin), Vcc(Vcc), offset(offset), numSamples(numSamples) {}

    float readVoltage() {
      long sum = 0;
      for (int i = 0; i < numSamples; i++) {
        sum += analogRead(sensorPin);
      }
      float average = (float)sum / numSamples;
      float voltage = (average * (Vcc / 1023.0)) - offset; // Converte o valor médio para a tensão
      return voltage;
    }

    float calculateRMS() {
      float sumSq = 0;
      for (int i = 0; i < numSamples; i++) {
        float sample = readVoltage();
        sumSq += sample * sample;
      }
      float rms = sqrt(sumSq / numSamples);
      return rms * sqrt(2); // Ajuste para obter o valor RMS para senoidal pura
    }
  
};