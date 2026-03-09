#include <Arduino.h>

struct Button {
  const uint8_t PIN;
  uint32_t numberKeyPresses;
  bool pressed;
};

// Se usa el pin 18 para el botón
Button button1 = {18, 0, false};

// Rutina de Servicio de Interrupción (ISR)
void IRAM_ATTR isr() {
  button1.numberKeyPresses += 1;
  button1.pressed = true;
}

void setup() {
  Serial.begin(115200);
  pinMode(button1.PIN, INPUT_PULLUP); // Activa resistencia pull-up interna
  // Se dispara cuando el pin pasa de HIGH a LOW (al pulsar)
  Serial.printf("programa iniciado");
  attachInterrupt(button1.PIN, isr, FALLING); 
}

void loop() {
  if (button1.pressed) {
      Serial.printf("Button 1 has been pressed %u times\n", button1.numberKeyPresses);
      button1.pressed = false;
  }

  // Desconecta la interrupción después de 1 minuto (60000 ms)
  static uint32_t lastMillis = 0;
  if (millis() - lastMillis > 60000) {
    lastMillis = millis();
    detachInterrupt(button1.PIN);
    Serial.println("Interrupt Detached!");
  }

  delay (10);
}