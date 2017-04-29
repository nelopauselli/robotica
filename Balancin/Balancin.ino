#include "Motor.cpp"

Motor motorDerecho(3, 2, 4);
Motor motorIzquierdo(6, 7, 8);

void setup() {
  motorDerecho.romperInercia();
  motorIzquierdo.romperInercia();
  
  motorDerecho.retroceder(100);
  delay(100);
  motorIzquierdo.retroceder(100);
  delay(2000);
  
  motorDerecho.retroceder(255);
  delay(100);
  motorIzquierdo.retroceder(255);
  delay(2000);
  
  motorDerecho.avanzar(100);
  delay(100);
  motorIzquierdo.avanzar(100);
  delay(2000);

  motorDerecho.avanzar(255);
  delay(100);
  motorIzquierdo.avanzar(255);
  delay(2000);


  motorDerecho.detener();
  delay(100);
  motorIzquierdo.detener();
  
}

void loop() {

}
