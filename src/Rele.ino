#include <Arduino.h>

class Rele {
  public:
    Rele(int pin);
    void on(){
        digitalWrite(_pin, HIGH);
    }
    void off(){
        digitalWrite(_pin, LOW);
    }
  private:
    int _pin;

};
