class SensorDeCorrente{
      private:
    int sensorPin;
    float sensitivity; // Sensibilidade do sensor em mV/A
    float offsetVoltage; // Tensão de offset (Vcc/2)
    float Vcc; // Tensão de alimentação

  public:
    // Construtor
    SensorDeCorrente(int pin, float Vcc = 5.0, float sensitivity = 185.0)
    : sensorPin(pin), Vcc(Vcc), sensitivity(sensitivity) {
      offsetVoltage = Vcc / 2.0;
    }

    // Método para ler a corrente
    float readCurrent() {
      int rawValue = analogRead(sensorPin);
      float voltage = (rawValue * (Vcc / 1023.0));
      float current = (voltage - offsetVoltage) / (sensitivity / 1000.0);
      return current;
    }
}