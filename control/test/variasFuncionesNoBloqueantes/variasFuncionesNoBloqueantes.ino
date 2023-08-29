const int ledPin1 = 2;  // Pin del primer LED
const int ledPin2 = 3;  // Pin del segundo LED
const int ledPin3 = 4;  // Pin del tercer LED

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

const long interval1 = 300;  // Intervalo de tiempo para el LED 1 en milisegundos (300 ms)
const long interval2 = 500;  // Intervalo de tiempo para el LED 2 en milisegundos (500 ms)
const long interval3 = 1000; // Intervalo de tiempo para el LED 3 en milisegundos (1 segundo)

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // Llamar a las tres funciones en paralelo
  function1();
  function2();
  function3();
}

void function1() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis1 >= interval1) {
    digitalWrite(ledPin1, !digitalRead(ledPin1));
    previousMillis1 = currentMillis;
  }
  // Agregar aquí el resto de la lógica de function1
}

void function2() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis2 >= interval2) {
    digitalWrite(ledPin2, !digitalRead(ledPin2));
    previousMillis2 = currentMillis;
  }
  // Agregar aquí el resto de la lógica de function2
}

void function3() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis3 >= interval3) {
    digitalWrite(ledPin3, !digitalRead(ledPin3));
    previousMillis3 = currentMillis;
  }
  // Agregar aquí el resto de la lógica de function3
}
