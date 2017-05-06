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
    _sentidoGiro = 0;
  }

  void avanzar(int velocidad){
    digitalWrite(_pinAtras, LOW);
    digitalWrite(_pinAdelante, HIGH);

    if(_sentidoGiro!=1)
      romperInercia();

    analogWrite(_pinPotencia, velocidad);
    _sentidoGiro = 1;
  }

   void retroceder(int velocidad){
    digitalWrite(_pinAdelante, LOW);
    digitalWrite(_pinAtras, HIGH);

    if(_sentidoGiro!=2)
      romperInercia();
    analogWrite(_pinPotencia, velocidad);
    _sentidoGiro = 2;
  }

  void romperInercia(){
    analogWrite(_pinPotencia, 255);
    delay(5);
  }
  
  private:
    int _pinAdelante = 0;
    int _pinAtras = 0;
    int _pinPotencia = 0;
    int _sentidoGiro = 0;
};

#endif
