// Pines Mecanismos

//----------------- F L I P P E R S ----------------- //
#define LED_STATUS_FLIPPER A0

#define FLIPPER_DERECHO 2
#define FLIPPER_DERECHO_FBK 8

//Nombre consola: FD
#define SERIAL_FLIPPER_DERECHO "FD"

#define FLIPPER_IZQUIERDO 3
#define FLIPPER_IZQUIERDO_FBK 9
#define IZQUIERDO 'I'

//Nombre consola: FI
#define SERIAL_FLIPPER_IZQUIERDO "FI"

//----------------- S L I N G S H O T S ----------------- //
#define LED_STATUS_SLINGSHOT 13

#define SLINGSHOT_DERECHO 4
#define SLINGSHOT_DERECHO_FBK 10

//Nombre consola: SD
#define SERIAL_SLINGSHOT_DERECHO "SD"

#define SLINGSHOT_IZQUIERDO 5
#define SLINGSHOT_IZQUIERDO_FBK 11

//Nombre consola: SI
#define SERIAL_SLINGSHOT_IZQUIERDO "SI"


//----------------- B U M P E R S ----------------- //
#define LED_STATUS_BUMPER 13

#define BUMPER_DERECHO 6
#define BUMPER_DERECHO_FBK 12

//Nombre consola: BD
#define SERIAL_BUMPER_DERECHO "BD"

#define BUMPER_IZQUIERDO 7
#define BUMPER_IZQUIERDO_FBK 13

//Nombre consola: BI
#define SERIAL_BUMPER_IZQUIERDO "BI"

//----------------- B A L L   R E T U R N  ----------------- //
#define LED_STATUS_BALL_RETURN 13

#define BALL_RETURN 12
#define BALL_RETURN_FBK 13

//Nombre consola: BR
#define SERIAL_BALL_RETURN "BR"


// Comandos de juego
#define ACTIVAR_FLIPPER_IZQUIERDO()     activarMecanismo(SERIAL_FLIPPER_IZQUIERDO)
#define ACTIVAR_FLIPPER_DERECHO()       activarMecanismo(SERIAL_FLIPPER_DERECHO)
#define ACTIVAR_SLINGSHOT_IZQUIERDO()   activarMecanismo(SERIAL_SLINGSHOT_IZQUIERDO)
#define ACTIVAR_SLINGSHOT_DERECHO()     activarMecanismo(SERIAL_SLINGSHOT_DERECHO)
#define ACTIVAR_BUMPER_DERECHO()        activarMecanismo(SERIAL_BUMPER_DERECHO)
#define ACTIVAR_BUMPER_IZQUIERDO()      activarMecanismo(SERIAL_BUMPER_IZQUIERDO)
#define ACTIVAR_BALL_RETURN()           activarMecanismo(SERIAL_BALL_RETURN)

// Comandos generales
#define IMPRIMIR(msg) Serial.println(msg);
#define MEC_STANDBY 0
#define MEC_ACTIVO  1
#define MEC_ERROR   2


// Indicadores
#define LED_STATUS_MECANISMOS LED_BUILTIN

// ------ V A R I A B L E S    G L O B A L E S ------ //

//Delay no bloqueante
unsigned long previousMillis = 0;
unsigned long delayInterval = 1000;
bool delayInProgress = false;


void blinkLED(int led, int ms, int times = 1){
// Hace blink de un led por determinados ms "times" veces      
  for (int i = 0; i < times; i++) {
  digitalWrite(led, HIGH);
  delay(ms);
  digitalWrite(led, LOW);
  delay(ms);
  }
}

 void serialActivation(String input){
  
  if (input.length() > 0) {
    // Elimina el último carácter de la cadena
    input = input.substring(0, input.length() - 1);

    // Utiliza una serie de if-else para comparar la cadena de entrada
    if (input == SERIAL_FLIPPER_DERECHO) {
      Serial.println("Comando recibido: FD");
      ACTIVAR_FLIPPER_DERECHO();
      // Realiza acciones específicas para "SERIAL_FLIPPER_DERECHO" aquí
    } else if (input == SERIAL_FLIPPER_IZQUIERDO) {
      Serial.println("Comando recibido: FI");
      // Realiza acciones específicas para "SERIAL_FLIPPER_IZQUIERDO" aquí
      ACTIVAR_FLIPPER_IZQUIERDO();
      
    } else if (input == SERIAL_BALL_RETURN) {
      Serial.println("Comando recibido: BR");
      
      //Acciones para Ball Return aqui
      ACTIVAR_BALL_RETURN();

    } else if (input == SERIAL_BUMPER_IZQUIERDO) {
      Serial.println("Comando recibido: BI");
      
      // Realiza acciones específicas para "SERIAL_BUMPER_IZQUIERDO" aquí
      ACTIVAR_BUMPER_IZQUIERDO();
      
    } else if (input == SERIAL_BUMPER_DERECHO) {
      Serial.println("Comando recibido: BD");
      
      // Realiza acciones específicas para "SERIAL_BUMPER_DERECHO" aquí
      ACTIVAR_BUMPER_DERECHO();
      
    } else if (input == SERIAL_SLINGSHOT_DERECHO) {
      Serial.println("Comando recibido: SD");
     
      // Realiza acciones específicas para "SERIAL_SLINGSHOT_DERECHO" aquí
      ACTIVAR_SLINGSHOT_DERECHO();
      
    } else if (input == SERIAL_SLINGSHOT_IZQUIERDO) {
      Serial.println("Comando recibido: SI");
      
      // Realiza acciones específicas para "SERIAL_SLINGSHOT_IZQUIERDO" aquí
      ACTIVAR_SLINGSHOT_IZQUIERDO();
      
    } else {
      Serial.println("Comando no reconocido: " + input);
      // Realiza acciones para comandos no reconocidos aquí
    }
    
  } 
  else {
    IMPRIMIR("ERROR: Mensaje recibido por serial incorrecto de largo menor a 0");
  }
}



void setup() {
 
 //SERIAL
 Serial.begin(9600);
 IMPRIMIR(" ");
 IMPRIMIR("INICIALIZANDO");
 IMPRIMIR("Esperar 5 segundos");
 delay(5000);

 //PINES
 pinConfig();
  

}

void loop() {
    while (Serial.available() > 0) {  // Verifica si hay datos disponibles en el puerto serial
    String input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial

    //Usa el comando serial para activar mecanismos
    serialActivation(input); 
    
    }
  
}


// FUNCIONES

void pinConfig(){

  // Configura cada pin entrada/salida como corresponde
  // Hace una prueba rápida en los mecanismos y se fija de recibir feedback correctamente
  // Indica en LED_STATUS_MECANISMOS el estado de cada uno de los mecanismos
  // Comunica por Serial como va avanzando la configuración y su estado
  
  IMPRIMIR("****** P I N   C O N F I G *****");
  
  //Habilitar Interrupción por Serial
  
//    pinMode(RX_PIN, INPUT_PULLUP);
//    Interrupción a la función serialInterrupt cuando hay un cambio de HIGH a LOW
//    attachInterrupt(digitalPinToInterrupt(RX_PIN), serialInterrupt, FALLING);  
//    IMPRIMIR("RX Pin para interrupción CONFIG OK");
  
  //LED Status Mecanismos
    pinMode(LED_STATUS_MECANISMOS, OUTPUT);
    digitalWrite(LED_STATUS_MECANISMOS, LOW);
  
  //Flippers
    IMPRIMIR("LED de status flippers CONFIG OK");
  
    pinMode(FLIPPER_IZQUIERDO, OUTPUT);
    pinMode(FLIPPER_IZQUIERDO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Flipper Izquierdo CONFIG OK");
    
    pinMode(FLIPPER_DERECHO, OUTPUT);
    pinMode(FLIPPER_DERECHO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Flipper Derecho CONFIG OK");


  //Slingshot
    pinMode(SLINGSHOT_DERECHO, OUTPUT);
    pinMode(SLINGSHOT_DERECHO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Slingshot Izquierdo CONFIG OK");
    
    pinMode(SLINGSHOT_IZQUIERDO, OUTPUT);
    pinMode(SLINGSHOT_IZQUIERDO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Slingshot Derecho CONFIG OK");

  //Bumper
    pinMode(BUMPER_DERECHO, OUTPUT);
    pinMode(BUMPER_DERECHO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Bumper Derecho CONFIG OK");

    
    pinMode(BUMPER_IZQUIERDO, OUTPUT);
    pinMode(BUMPER_IZQUIERDO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Bumper Izquierdo CONFIG OK");
}

void activarMecanismo(String mecanismo){
  if (mecanismo == SERIAL_FLIPPER_DERECHO) {
    IMPRIMIR("Flipper   DERECHO");
    
    // Activar flipper derecho
    digitalWrite(FLIPPER_DERECHO, HIGH);
    blinkLED(LED_STATUS_MECANISMOS, 100);
    
    // TO DO: levantar feedback de activación
        
    // Soltar flipper derecho
    digitalWrite(FLIPPER_DERECHO, LOW);
    // digitalWrite(LED_STATUS_FLIPPER, LOW);

  } else if (mecanismo == SERIAL_FLIPPER_IZQUIERDO) {
    IMPRIMIR("Flipper   IZQUIERDO");
      
    // Activar flipper izquierdo
    digitalWrite(FLIPPER_IZQUIERDO, HIGH);
    digitalWrite(LED_STATUS_FLIPPER, HIGH);

    // TO DO: levantar feedback de activación

    // Soltar flipper izquierdo
    digitalWrite(FLIPPER_IZQUIERDO, LOW);
    digitalWrite(LED_STATUS_FLIPPER, LOW);

  } else if (mecanismo == SERIAL_BUMPER_DERECHO) {

    IMPRIMIR("Bumper   DERECHO");
      
    digitalWrite(BUMPER_DERECHO, HIGH);
    digitalWrite(LED_STATUS_BUMPER, HIGH);

    // TO DO: levantar feedback de activación

    // Soltar flipper izquierdo
    digitalWrite(BUMPER_DERECHO, LOW);
    digitalWrite(LED_STATUS_BUMPER, LOW);

  } else if (mecanismo == SERIAL_BUMPER_IZQUIERDO) {
     
    IMPRIMIR("Bumper   IZQUIERDO");
      
    // Activar flipper izquierdo
    digitalWrite(BUMPER_IZQUIERDO, HIGH);
    digitalWrite(LED_STATUS_BUMPER, HIGH);

    // TO DO: levantar feedback de activación

    // Soltar flipper izquierdo
    digitalWrite(BUMPER_IZQUIERDO, LOW);
    digitalWrite(LED_STATUS_BUMPER, LOW);
 
  } else if (mecanismo == SERIAL_SLINGSHOT_DERECHO) {
    
    IMPRIMIR("Slingshot   DERECHO");
      
    // Activar flipper izquierdo
    digitalWrite(SLINGSHOT_DERECHO, HIGH);
    digitalWrite(LED_STATUS_SLINGSHOT, HIGH);

    // TO DO: levantar feedback de activación

    // Soltar flipper izquierdo
    digitalWrite(SLINGSHOT_DERECHO, LOW);
    digitalWrite(LED_STATUS_SLINGSHOT, LOW);

  } else if (mecanismo == SERIAL_SLINGSHOT_IZQUIERDO) {
    
    IMPRIMIR("Slingshot   IZQUIERDO");
      
    // Activar flipper izquierdo
    digitalWrite(SLINGSHOT_IZQUIERDO, HIGH);
    digitalWrite(LED_STATUS_SLINGSHOT, HIGH);

    // TO DO: levantar feedback de activación

    // Soltar flipper izquierdo
    digitalWrite(SLINGSHOT_IZQUIERDO, LOW);
    digitalWrite(LED_STATUS_SLINGSHOT, LOW);

  } else if (mecanismo == SERIAL_BALL_RETURN) {
    
    IMPRIMIR("BALL RETURN");
      
    // Activar flipper izquierdo
    digitalWrite(BALL_RETURN, HIGH);
    digitalWrite(LED_STATUS_BALL_RETURN, HIGH);

    // TO DO: levantar feedback de activación

    //
    digitalWrite(BALL_RETURN, LOW);
    digitalWrite(LED_STATUS_BALL_RETURN, LOW);

  } else {
    IMPRIMIR("Mecanismo incorrecto");
  }
  
}

void ledStatusMecanismo(int estado){

  switch (estado) {
 
    case MEC_STANDBY: //Standby
      blinkLED(LED_STATUS_MECANISMOS, 300, 5);
      break;
      
    case MEC_ERROR: //Error
      blinkLED(LED_STATUS_MECANISMOS, 150, 10);
      break;
      
    default:
      IMPRIMIR("No se seleccionó un estado correcto. El mecanismo NO fue activado con éxito");
      break;
  } 
}

void _delay(unsigned long interval) {
  if (!delayInProgress) {
    // Iniciar el retraso no bloqueante
    previousMillis = millis();
    delayInterval = interval;
    delayInProgress = true;
  }
  
  // Verificar si ha pasado el intervalo deseado
  if (delayInProgress && (millis() - previousMillis >= delayInterval)) {
    // El retraso ha terminado
    delayInProgress = false;
    // Realizar acciones adicionales después del retraso aquí
  }
}

/*
void serialInterrupt(){
  
  IMPRIMIR("");
  IMPRIMIR("Interrupción: SERIAL");
  IMPRIMIR("");

  char recibido = Serial.read();  // Leer el carácter recibido
  IMPRIMIR("Caracter RECIBIDO");
  IMPRIMIR(recibido);
  IMPRIMIR(" ");
  activarFlipper(recibido);
  
}*/
