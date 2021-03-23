#include <Stepper.h>
#define STEPS 200
#define PDERECHO 2
#define PIZQUIERDO 3

int pot;
int direccion;

Stepper motor(STEPS, 8,9);

void setup() {
  // Velocidad del motor en RPM
  pinMode (PDERECHO, INPUT);
  pinMode (PIZQUIERDO, INPUT);
}

void loop() {
  // Girar una vuelta entera en un sentido
  pot = analogRead(A1);
  pot = map(pot, 0, 1023, 30, 150);

  motor.setSpeed(pot);
  motor.step(direccion);

  if(digitalRead(PIZQUIERDO)) direccion= 200;
  if(digitalRead(PDERECHO)) direccion= -200;
}
