#ifndef MOTOR_CLASS
#define MOTOR_CLASS

#include "Arduino.h"

#define DEBUG

class Motor {
  public:
  Motor(int pinPotencia, int pinAdeltante, int pinAtras){
    _pinAdelante = pinAdeltante;
    _pinAtras = pinAtras;
    _pinPotencia = pinPotencia;
    
    pinMode(_pinAdelante, OUTPUT);
    pinMode(_pinAtras, OUTPUT);
    //pinMode(_pinPotencia, OUTPUT);
  
    detener();
  }

  void detener(){
    digitalWrite(_pinAtras, LOW);
    digitalWrite(_pinAdelante, LOW);
    analogWrite(_pinPotencia, 0);
  }

  void avanzar(byte velocidad){
    digitalWrite(_pinAtras, LOW);
    digitalWrite(_pinAdelante, HIGH);
    delay(10);
    analogWrite(_pinPotencia, velocidad);
  }

   void retroceder(byte velocidad){
    digitalWrite(_pinAtras, HIGH);
    digitalWrite(_pinAdelante, LOW);
    delay(10);
    analogWrite(_pinPotencia, velocidad);
  }

  void romperInercia(){
    avanzar(255);
    retroceder(255);
  }
  
  private:
    int _pinAdelante = 0;
    int _pinAtras = 0;
    int _pinPotencia = 0;
};

#endif
