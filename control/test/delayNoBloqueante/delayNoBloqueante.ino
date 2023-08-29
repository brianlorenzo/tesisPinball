const int ledPin = LED_BUILTIN;  // Pin del LED
unsigned long previousMillisLED = 0;  // Almacena el valor de millis() en la última ejecución del LED
const long ledInterval = 300;  // Intervalo de tiempo para el LED en milisegundos (300 ms)

unsigned long previousMillisCounter = 0;  // Almacena el valor de millis() en la última actualización del contador
const long counterInterval = 1000;  // Intervalo de tiempo para el contador en milisegundos (1000 ms)
int count = 10;  // Variable para contar de 10 a 0

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Hacer blink del LED cada 300 ms utilizando _delay (delay no bloqueante)
  blinkLED();

  // Actualizar el contador cada 1 segundo
  updateCounter();

  // Tu código de loop principal continúa aquí
}

void _delay(unsigned long milliseconds) {
  unsigned long startMillis = millis();
  
  // Esperar hasta que haya pasado el intervalo deseado
  while (millis() - startMillis < milliseconds) {
    // No hacer nada, solo esperar
  }
}

void blinkLED() {
  unsigned long currentMillis = millis();
  
  // Verificar si ha pasado el intervalo deseado para el LED
  if (currentMillis - previousMillisLED >= ledInterval) {
    digitalWrite(ledPin, !digitalRead(ledPin));  // Invierte el estado del LED
    previousMillisLED = currentMillis;
  }
}

void updateCounter() {
  unsigned long currentMillis = millis();
  
  // Verificar si ha pasado el intervalo deseado para actualizar el contador
  if (currentMillis - previousMillisCounter >= counterInterval) {
    Serial.print("Contador: ");
    Serial.println(count);
    count--;

    // Reiniciar el contador cuando llega a 0
    if (count < 0) {
      count = 10;
    }

    previousMillisCounter = currentMillis;
  }
}
