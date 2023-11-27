// TO DO
#include<defines.h>

boolean flipperDerechoActivo;
boolean flipperIzquierdoActivo;
boolean slingshotDerechoActivo;
boolean slingshotIzquierdoActivo;
boolean bumperDerechoActivo;
boolean bumperIzquierdoActivo;
boolean ballReturnActivo;

#define FBK_OK IMPRIMIR("Feedback correcto")
#define FBK_ERROR IMPRIMIR("Feedback INCORRECTO, no se pudo detectar")
#define tiempoFBK 100 //Tiempo de delay para esperar feedback (us)

// F U N C I O N E S     A U X I L I A R E S 
void chequeoFBK(int PIN_MECANISMO_FBK) {
    if (digitalRead(PIN_MECANISMO_FBK)) {
        // Si recibo el FBK correctamente, determino FBK OK
        FBK_OK;
    } else {
        // Si no recibo FBK correctamente, espero un tiempo y vuelvo a intentar una vez más
        delay(tiempoFBK);
        if (digitalRead(PIN_MECANISMO_FBK)) {
            FBK_OK;
        } else {
            FBK_ERROR;
        }
    }
}


// Configura Pines como entrada y salida
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
    //Configuración por default
    digitalWrite(FLIPPER_DERECHO,LOW);
    digitalWrite(FLIPPER_IZQUIERDO,LOW);


  //Slingshot
    pinMode(SLINGSHOT_DERECHO, OUTPUT);
    pinMode(SLINGSHOT_DERECHO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Slingshot Izquierdo CONFIG OK");
    
    pinMode(SLINGSHOT_IZQUIERDO, OUTPUT);
    pinMode(SLINGSHOT_IZQUIERDO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Slingshot Derecho CONFIG OK");  
    //Configuración por default
    digitalWrite(SLINGSHOT_DERECHO,HIGH);
    digitalWrite(SLINGSHOT_IZQUIERDO,HIGH);

  //Bumpers
    pinMode(BUMPER_DERECHO, OUTPUT);
    pinMode(BUMPER_DERECHO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Bumper Derecho CONFIG OK");
    
    pinMode(BUMPER_IZQUIERDO, OUTPUT);
    pinMode(BUMPER_IZQUIERDO_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Bumper Izquierdo CONFIG OK");
    //Configuración por default
    digitalWrite(BUMPER_DERECHO,HIGH);
    digitalWrite(BUMPER_IZQUIERDO,HIGH);

//Ball Return
    pinMode(BALL_RETURN, OUTPUT);
    pinMode(BALL_RETURN_FBK, INPUT);
    //TO DO: Chequear feedback antes de dar OK
    IMPRIMIR("Ball Return CONFIG OK");
    //Configuración por default
    digitalWrite(BALL_RETURN,LOW);

}

