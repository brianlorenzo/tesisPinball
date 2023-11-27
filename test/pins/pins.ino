const int numGpios = 42;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int numero = Serial.parseInt(); // Lee el número enviado por serial

    if (numero >= 1 && numero <= numGpios) {
      // Configura el pin como salida
      pinMode(numero, OUTPUT);
      Serial.print("Se activa el PIN: ");
      Serial.println(numero);
      // Activa el pin durante 2 segundos
      digitalWrite(numero, HIGH);
      delay(2000);
      digitalWrite(numero, LOW);
    } else {
      Serial.println("Número fuera de rango. Debe ser entre 1 y 42.");
    }

    // Limpia el buffer serial
    while (Serial.available() > 0) {
      Serial.read();
    }
  }
}
