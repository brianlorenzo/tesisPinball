#include <defines.h> // C:\Program Files (x86)\Arduino\libraries\defines o ~/Documents/Arduino/libraries/defines 
//
#include <Adafruit_NeoPixel.h>
//#include "../Users/brianlorenzo/Desktop/UCU/TesisUCU/Pinball/tesisPinball/control/lib/Adafruit_NeoPixel/Adafruit_NeoPixel.h" SOLUCIONAR PORFA

//#define LED_STATUS_MECANISMOS LED_BUILTIN

// Delay no bloqueante
unsigned long previousMillis = 0;
unsigned long delayInterval = 1000;
bool delayInProgress = false;


 void serialActivation(String input){
  
  if (input.length() > 0) {
    // Elimina el último carácter de la cadena
    input = input.substring(0, input.length() - 1);

    //Muestra LED del mecanismo seleccionado

    Serial.println("Comando recibido: " + input);

    // Utiliza una serie de if-else para comparar la cadena de entrada
    if (input == SERIAL_FLIPPER_DERECHO) {
      if (ACTIVAR_FLIPPER_DERECHO()){
        IMPRIMIR("FLIPPER DERECHO Activado correctamente");
      }
      
    } else if (input == SERIAL_FLIPPER_IZQUIERDO) {
      if (ACTIVAR_FLIPPER_IZQUIERDO() ){
        IMPRIMIR("FLIPPER IZQUIERDO Activado correctamente");
      }
      
    } else if (input == SERIAL_BALL_RETURN) {
      if (ACTIVAR_BALL_RETURN()){
        IMPRIMIR("BALL RETURN Activado correctamente");
      }
   

    } else if (input == SERIAL_BUMPER_IZQUIERDO) {
      if (ACTIVAR_BUMPER_IZQUIERDO()){
        IMPRIMIR("BUMPER IZQUIERDO Activado correctamente");
      }
 
      
    } else if (input == SERIAL_BUMPER_DERECHO) {
      if (ACTIVAR_BUMPER_DERECHO()){
        IMPRIMIR("BUMPER DERECHO Activado correctamente");
      }
      
      
    } else if (input == SERIAL_SLINGSHOT_DERECHO) {
      if (ACTIVAR_SLINGSHOT_DERECHO()){
        IMPRIMIR("SLINGSHOT DERECHO Activado correctamente");
      }
      
    
    } else if (input == SERIAL_SLINGSHOT_IZQUIERDO) {
      if (ACTIVAR_SLINGSHOT_IZQUIERDO()){
        IMPRIMIR("SLINGSHOT IZQUIERDO Activado correctamente");
      }

      
    } else {
      Serial.println("  Comando no reconocido: ");
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

  //Bumpers
    pinMode(BUMPER_DERECHO, OUTPUT);
    pinMode(BUMPER_DERECHO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Bumper Derecho CONFIG OK");

    
    pinMode(BUMPER_IZQUIERDO, OUTPUT);
    pinMode(BUMPER_IZQUIERDO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Bumper Izquierdo CONFIG OK");

//Ball Return
    pinMode(BALL_RETURN, OUTPUT);
    pinMode(BALL_RETURN_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Ball Return CONFIG OK");
}

//void activarMecanismo(String mecanismo){
boolean activarMecanismo(String mecanismo){
  // Recibo String con mecanismo
  // la función activa el mecanismo 
  // y devuelve un bool si fue correcta la activación
  
  IMPRIMIR("ACTIVAR MECANISMO");

  setLED(mecanismo);
  
  if (mecanismo == SERIAL_FLIPPER_DERECHO) {
    IMPRIMIR("Flipper   DERECHO");
    
    // Activar flipper derecho
    digitalWrite(FLIPPER_DERECHO, HIGH);
    
    // Minimamente un delay acá? al menos de debug
    IMPRIMIR(mecanismo + "  fue activado. Se espera feedback");
    delay(100);

    // TO DO: levantar feedback de activación
    if( FLIPPER_DERECHO_ACTIVO ) {
      // Soltar flipper derecho
      digitalWrite(FLIPPER_DERECHO, LOW);
      //scoreUpdate(mecanismo);
      IMPRIMIR("feedback: Correcto");
      return true;
    } else {
      //Error con la activación (podría ser reintentar?)
      IMPRIMIR("ERROR con activación");
      digitalWrite(FLIPPER_DERECHO, LOW);
      return false;
    }
        

  } else if (mecanismo == SERIAL_FLIPPER_IZQUIERDO) {
    IMPRIMIR("Flipper   IZQUIERDO");
    
    // Activar flipper derecho
    digitalWrite(FLIPPER_IZQUIERDO, HIGH);
    
    // Minimamente un delay acá? al menos de debug
    IMPRIMIR(mecanismo + "  fue activado. Se espera feedback");
    delay(100);
    // Levantar feedback de activación
    if( FLIPPER_IZQUIERDO_ACTIVO ) {
      // Soltar flipper derecho
      digitalWrite(FLIPPER_IZQUIERDO, LOW);
      //scoreUpdate(mecanismo);
      IMPRIMIR("feedback: Correcto");
      return true;
    } else {
      //Error con la activación (podría ser reintentar?)
      IMPRIMIR("ERROR con activación");
      digitalWrite(FLIPPER_DERECHO, LOW);
      return false;
    }
    
  } else if (mecanismo == SERIAL_BUMPER_DERECHO) {
    // Activar bumper derecho
    digitalWrite(BUMPER_DERECHO, HIGH);
    
    // Minimamente un delay acá? al menos de debug
    IMPRIMIR(mecanismo + "  fue activado. Se espera feedback");
    delay(100);
    
    // Levantar feedback de activación
    if( BUMPER_DERECHO_ACTIVO ) {
      // Soltar BUMPER
      digitalWrite(BUMPER_DERECHO, LOW);
      //scoreUpdate(mecanismo);
      IMPRIMIR("feedback: Correcto");
      digitalWrite(FLIPPER_DERECHO, LOW);
      return true;
    } else {
      //Error con la activación (podría ser reintentar?)
      IMPRIMIR("ERROR con activación");
      return false;
    }
    
  } else if (mecanismo == SERIAL_BUMPER_IZQUIERDO) {
     
    digitalWrite(BUMPER_IZQUIERDO, HIGH);
    
    // Minimamente un delay acá? al menos de debug
    IMPRIMIR(mecanismo + "  fue activado. Se espera feedback");
    delay(100);  
      
    // Levantar feedback de activación
    if( BUMPER_IZQUIERDO_ACTIVO ) {
      // Soltar BUMPER
      digitalWrite(BUMPER_IZQUIERDO, LOW);
      //scoreUpdate(mecanismo);
      IMPRIMIR("feedback: Correcto");
      return true;
    } else {
      //Error con la activación (podría ser reintentar?)
      IMPRIMIR("ERROR con activación");
      digitalWrite(FLIPPER_DERECHO, LOW);
      return false;
    }
 
  } else if (mecanismo == SERIAL_SLINGSHOT_DERECHO) {
    
    digitalWrite(SLINGSHOT_DERECHO, HIGH);
    
    // Minimamente un delay acá? al menos de debug
    IMPRIMIR(mecanismo + "  fue activado. Se espera feedback");
    delay(100);   
    // Levantar feedback de activación
    if( SLINGSHOT_DERECHO_ACTIVO ) {
      // Soltar SLINGSHOT
      digitalWrite(SLINGSHOT_DERECHO, LOW);
      //scoreUpdate(mecanismo);
      IMPRIMIR("feedback: Correcto");
      return true;
    } else {
      //Error con la activación (podría ser reintentar?)
      IMPRIMIR("ERROR con activación");
      digitalWrite(FLIPPER_DERECHO, LOW);
      return false;
    }
  } else if (mecanismo == SERIAL_SLINGSHOT_IZQUIERDO) {
    
    digitalWrite(SLINGSHOT_IZQUIERDO, HIGH);
    
    // Minimamente un delay acá? al menos de debug
    IMPRIMIR(mecanismo + "  fue activado. Se espera feedback");
    delay(100);     
    // Levantar feedback de activación
    if( SLINGSHOT_IZQUIERDO_ACTIVO ) {
      // Soltar SLINGSHOT
      digitalWrite(SLINGSHOT_IZQUIERDO, LOW);
      //scoreUpdate(mecanismo);
      IMPRIMIR("feedback: Correcto");
      return true;
    } else {
      //Error con la activación (podría ser reintentar?)
      IMPRIMIR("ERROR con activación");
      digitalWrite(FLIPPER_DERECHO, LOW);
      return false;
    }
  } else if (mecanismo == SERIAL_BALL_RETURN) {
    digitalWrite(BALL_RETURN, HIGH);
    
    // Minimamente un delay acá? al menos de debug
    IMPRIMIR(mecanismo + "  fue activado. Se espera feedback");
    delay(100);   
    // Levantar feedback de activación
    if( BALL_RETURN_ACTIVO ) {
      // Soltar BALL RETURN
      digitalWrite(BALL_RETURN, LOW);
      //scoreUpdate(mecanismo);
      IMPRIMIR("feedback: Correcto");
      return true;
    } else {
      //Error con la activación (podría ser reintentar?)
      IMPRIMIR("ERROR con activación");
      digitalWrite(FLIPPER_DERECHO, LOW);
      return false;
    }

  }
}
/*
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
*/

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


void loop() {
    
    while (Serial.available() > 0) {  // Verifica si hay datos disponibles en el puerto serial
    String input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial

    //Usa el comando serial para activar mecanismos
    serialActivation(input); 
   
    }
  
}
