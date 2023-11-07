// ----------------------Pines Mecanismos ------------------------//
// >>>>>>>> REVISAR ASIGNACIONES <<<<<<<<<<
//----------------- F L I P P E R S -----------------//
#define LED_STATUS_FLIPPER A0

#define FLIPPER_DERECHO 3
#define FLIPPER_DERECHO_FBK 14

#define FLIPPER_DERECHO_ACTIVO digitalRead(FLIPPER_DERECHO_FBK)
boolean flipperDerechoActivo;

//Nombre consola: FD
#define SERIAL_FLIPPER_DERECHO "FD"
//********************//
#define FLIPPER_IZQUIERDO 4
#define FLIPPER_IZQUIERDO_FBK 12

#define FLIPPER_IZQUIERDO_ACTIVO digitalRead(FLIPPER_IZQUIERDO_FBK)
boolean flipperIzquierdoActivo;

//Nombre consola: FI
#define SERIAL_FLIPPER_IZQUIERDO "FI"
//********************//

//----------------- S L I N G S H O T S -----------------//
#define LED_STATUS_SLINGSHOT 13

#define SLINGSHOT_DERECHO 5
#define SLINGSHOT_DERECHO_FBK 16

#define SLINGSHOT_DERECHO_ACTIVO digitalRead(SLINGSHOT_DERECHO_FBK)
boolean slingshotDerechoActivo;

//Nombre consola: SD
#define SERIAL_SLINGSHOT_DERECHO "SD"
//********************//
#define SLINGSHOT_IZQUIERDO 6
#define SLINGSHOT_IZQUIERDO_FBK 11

#define SLINGSHOT_IZQUIERDO_ACTIVO digitalRead(SLINGSHOT_IZQUIERDO_FBK)
boolean slingshotIzquierdoActivo;

//Nombre consola: SI
#define SERIAL_SLINGSHOT_IZQUIERDO "SI"
//********************//

//----------------- B U M P E R S ----------------- //
#define LED_STATUS_BUMPER 13

#define BUMPER_DERECHO 7
#define BUMPER_DERECHO_FBK 15

#define BUMPER_DERECHO_ACTIVO digitalRead(BUMPER_DERECHO_FBK)
boolean bumperDerechoActivo;

//Nombre consola: BD
#define SERIAL_BUMPER_DERECHO "BD"
//********************//
#define BUMPER_IZQUIERDO 8
#define BUMPER_IZQUIERDO_FBK 13

#define BUMPER_IZQUIERDO_ACTIVO digitalRead(BUMPER_IZQUIERDO_FBK)
boolean bumperIzquierdoActivo;

//Nombre consola: BI
#define SERIAL_BUMPER_IZQUIERDO "BI"
//********************//

//----------------- B A L L   R E T U R N  ----------------- //
#define LED_STATUS_BALL_RETURN 13

#define BALL_RETURN 9
#define BALL_RETURN_FBK 17

#define BALL_RETURN_ACTIVO digitalRead(BALL_RETURN_FBK)
//  Si el pin está en 1: sensor inductivo activo (la bola está ahí)
//  Si el pin está en 0: sensor inductivo inactivo (la bola NO está ahí)
boolean ballReturnActivo;

//Nombre consola: BR
#define SERIAL_BALL_RETURN "BR"
//********************//

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

// ------------ I N D I C A D O R E S ------------ //
#include <Adafruit_NeoPixel.h>

// L E D   I N T E R N O
#define LED_INTERNO 18 // El pin al que está conectado el LED RGB
#define LED_STATUS_MECANISMOS LED_BUILTIN

// Parámetros de configuración del LED RGB
#define NUM_PIXELS 1 // Número de LEDs en la tira (en este caso, solo uno)
#define BRIGHTNESS 50 // Brillo (ajusta según tus preferencias)

//Inicializa el LED Neopixel
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, LED_INTERNO, NEO_GRB + NEO_KHZ800);

// Define las constantes para los colores
#define COLOR_RED strip.Color(255, 0, 0)
#define COLOR_GREEN strip.Color(0, 255, 0)
#define COLOR_YELLOW strip.Color(255, 255, 0)
#define COLOR_BLUE strip.Color(0, 0, 255)
#define COLOR_WHITE strip.Color(255, 255, 255)
#define COLOR_ORANGE strip.Color(255, 165, 0)
#define COLOR_PURPLE strip.Color(128, 0, 128)
#define COLOR_LED_OFF strip.Color(0, 0, 0) 

#define OFF "OFF"

// Led interno Neopixel
void ledSetup(){
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Inicialmente, apagar el LED RGB
}

// Led interno Neopixel
void setLED(String color) {
  if (color == SERIAL_FLIPPER_DERECHO) {
    strip.setPixelColor(0, COLOR_RED);
  } else if (color == SERIAL_FLIPPER_IZQUIERDO) {
    strip.setPixelColor(0, COLOR_GREEN);
  } else if (color == SERIAL_SLINGSHOT_IZQUIERDO) {
    strip.setPixelColor(0, COLOR_YELLOW);
  } else if (color == SERIAL_SLINGSHOT_DERECHO) {
    strip.setPixelColor(0, COLOR_BLUE);
  } else if (color == SERIAL_BUMPER_DERECHO) {
    strip.setPixelColor(0, COLOR_WHITE);
  } else if (color == SERIAL_BUMPER_IZQUIERDO) {
    strip.setPixelColor(0, COLOR_ORANGE);
  } else if (color == SERIAL_BALL_RETURN) {
    strip.setPixelColor(0, COLOR_PURPLE);
  } else {
    // Si el color no es uno de los especificados, apagar el LED
    strip.setPixelColor(0, strip.Color(0, 0, 0));
  }

  strip.show(); // Actualizar el LED RGB con el color seleccionado
}

// Led en pin digital
void blinkLED(int led, int ms, int times = 1){
// Hace blink de un led por determinados ms "times" veces      
  for (int i = 0; i < times; i++) {
  digitalWrite(led, HIGH);
  delay(ms);
  digitalWrite(led, LOW);
  delay(ms);
  }
}

// ------ V A R I A B L E S    G L O B A L E S ------ //

// Delay no bloqueante
unsigned long previousMillis = 0;
unsigned long delayInterval = 1000;
bool delayInProgress = false;


 void serialActivation(String input){
  
  if (input.length() > 0) {
    // Elimina el último carácter de la cadena
    input = input.substring(0, input.length() - 1);

    //Muestra LED del mecanismo seleccionado

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

  IMPRIMIR("ACTIVAR MECANISMO");

  setLED(mecanismo);
  
  if (mecanismo == SERIAL_FLIPPER_DERECHO) {
    IMPRIMIR("Flipper   DERECHO");
    
    // Activar flipper derecho
    digitalWrite(FLIPPER_DERECHO, HIGH);
    
    // LED status mecanismo
    blinkLED(LED_STATUS_MECANISMOS, 100);
    
    // TO DO: levantar feedback de activación
    if( digitalRead(FLIPPER_DERECHO_FBK) ) {

      // Soltar flipper derecho
      digitalWrite(FLIPPER_DERECHO, LOW);
      IMPRIMIR("FEEDBACK OK");
    } else {

    }
        
    
    // digitalWrite(LED_STATUS_FLIPPER, LOW);

    //scoreUpdate(SERIAL_FLIPPER_DERECHO);
    //return booleano de que se activó

  } else if (mecanismo == SERIAL_FLIPPER_IZQUIERDO) {
    IMPRIMIR("Flipper   IZQUIERDO");
      
    // Activar flipper izquierdo
    digitalWrite(FLIPPER_IZQUIERDO, HIGH);
    digitalWrite(LED_STATUS_FLIPPER, HIGH);

    // TO DO: levantar feedback de activación
  delay(100);
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

  //Aguantar LED y luego apagarlo
  delay(1000);
  setLED(OFF);
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
