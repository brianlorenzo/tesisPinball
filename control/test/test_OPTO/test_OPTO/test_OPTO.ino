// Pines
#define FLIPPER_DERECHO 7
#define FLIPPER_DERECHO_FBK 8
#define DERECHO 'D'

#define FLIPPER_IZQUIERDO 6
#define FLIPPER_IZQUIERDO_FBK 9
#define IZQUIERDO 'I'

#define LED_STATUS_FLIPPER LED_BUILTIN

#define RX_PIN 0

// Comandos de juego
#define ACTIVAR_FLIPPER_IZQUIERDO(ms) activarFlipper(IZQUIERDO, ms)
#define ACTIVAR_FLIPPER_DERECHO(ms) activarFlipper(DERECHO,ms)

// Comandos generales
#define IMPRIMIR(msg) Serial.println(msg);



void setup() {
 Serial.begin(9600);
 IMPRIMIR(" ");
 IMPRIMIR("INICIALIZANDO");
 IMPRIMIR("Esperar 5 segundos");
 delay(5000);
 pinConfig();

}

void loop() {
   if (Serial.available()) {
    char c = Serial.read();
    
    IMPRIMIR("Recibido");
    IMPRIMIR(c);
    
    if (c != '\n'){
      activarFlipper(c, 500);
      
    }
    
   }
  
  /*
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

  */
    

}


// FUNCIONES

void serialInterrupt(){
  
  IMPRIMIR("");
  IMPRIMIR("Interrupción: SERIAL");
  IMPRIMIR("");

  char recibido = Serial.read();  // Leer el carácter recibido
  IMPRIMIR("Caracter RECIBIDO");
  IMPRIMIR(recibido);
  IMPRIMIR(" ");
  activarFlipper(recibido, 500);
  
}
void pinConfig(){
  
  IMPRIMIR("****** P I N   C O N F I G *****");
  
  //Serial
  
//    pinMode(RX_PIN, INPUT_PULLUP);
//    // Interrupción a la función serialInterrupt cuando hay un cambio de HIGH a LOW
//    attachInterrupt(digitalPinToInterrupt(RX_PIN), serialInterrupt, FALLING);  
//    IMPRIMIR("RX Pin para interrupción CONFIG OK");
  
  //Flippers
    pinMode(LED_STATUS_FLIPPER, OUTPUT);
    IMPRIMIR("LED de status flippers CONFIG OK");
  
    pinMode(FLIPPER_IZQUIERDO, OUTPUT);
    pinMode(FLIPPER_IZQUIERDO_FBK, INPUT);
    IMPRIMIR("Flipper Izquierdo CONFIG OK");
    
    pinMode(FLIPPER_DERECHO, OUTPUT);
    pinMode(FLIPPER_DERECHO_FBK, INPUT);
    IMPRIMIR("Flipper Derecho CONFIG OK");
}

void activarFlipper(char flipper, int tiempo_ms){

  if(flipper == DERECHO){
    IMPRIMIR("Flipper   DERECHO");
    
    //activar flipper derecho
    digitalWrite(FLIPPER_DERECHO,HIGH);
    digitalWrite(LED_STATUS_FLIPPER, HIGH);

    //levantar feedback de activacion
    delay(tiempo_ms);

    //soltar flipper derecho
    digitalWrite(FLIPPER_DERECHO,LOW);
    digitalWrite(LED_STATUS_FLIPPER,LOW);

  }
  else {

    if(flipper == IZQUIERDO){
      IMPRIMIR("Flipper   IZQUIERDO");
      
      //activar flipper izquierdo
    
      digitalWrite(FLIPPER_IZQUIERDO,HIGH);
      digitalWrite(LED_STATUS_FLIPPER, HIGH);
  
      //levantar feedback de activacion
      delay(tiempo_ms);
  
      //soltar flipper izquierdo
      digitalWrite(FLIPPER_IZQUIERDO,LOW);
      digitalWrite(LED_STATUS_FLIPPER,LOW);
    }
    else{
      //Error al activar flippers
      IMPRIMIR("ERROR al Activar Flippers")
      IMPRIMIR("No se seleccionó un flipper correctamente para activar");
      IMPRIMIR(">>> se recibió: ");
      IMPRIMIR(flipper)
    }

  }
  
}
