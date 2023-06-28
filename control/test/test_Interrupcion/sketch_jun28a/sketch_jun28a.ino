#define RX_PIN 0  
// Puerto digital utilizado para la recepción (RX)

int i = 0;

void setup() {
  Serial.begin(9600);  // Inicializar la comunicación serial a 9600 baudios

  pinMode(RX_PIN, INPUT_PULLUP);  // Configurar el pin RX como entrada con resistencia pull-up
  attachInterrupt(digitalPinToInterrupt(RX_PIN), serialInterrupt, FALLING);  // Asociar la interrupción a la función serialInterrupt cuando hay un cambio de HIGH a LOW
}

void loop() {
  // Tu código principal aquí
  while( i < 500){
    i += 1;
    Serial.println(i);
    delay(1000);
  }
}

void serialInterrupt() {
  Serial.println("Se recibio algo");
  
  if (Serial.available()) {
    char c = Serial.read();  // Leer el carácter recibido
    Serial.println(c);
    // Realizar la acción deseada en función del carácter recibido
    if (c == 'A') {
      // Ejecutar la función correspondiente a la acción 'A'
      funcionA();
    } else if (c == 'B') {
      // Ejecutar la función correspondiente a la acción 'B'
      funcionB();
    }
    else{
      if (c == '\n'){
        Serial.println(".");
      }
    }
  }
}

void funcionA() {
  // Implementar la lógica de la función A
  Serial.println("FUNCION A");
}

void funcionB() {
  // Implementar la lógica de la función B
  Serial.println("FUNCION A");
}
