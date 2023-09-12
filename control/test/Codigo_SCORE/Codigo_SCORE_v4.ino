//CODIGO PARA CONTABILIZAR SCORE DURANTE LA PARTIDA
//Septiembre 2023

//Libreria de defines
#include <defines.h>
#include <scores.h>

//DECLARAMOS VARIABLES GLOBALES
unsigned long tiempoInicioPartida;                              // Tiempo en milisegundos en el que comenzó la partida.                              // Tiempo en milisegundos en el que comenzó la vida actual.
unsigned long duracionPartida;
int puntaje;                                                   // Puntaje acumulado, inicializado en 0.
int vidas;                                                     //Cantidad de vidas de cada "juego".
                                     
                                    
void setup() {
  Serial.begin(9600);     
  
  pinMode(FLIPPER_DERECHO_FBK, INPUT_PULLUP);
  pinMode(FLIPPER_IZQUIERDO_FBK, INPUT_PULLUP);
  pinMode(SLINGSHOT_DERECHO_FBK, INPUT_PULLUP);      
  pinMode(SLINGSHOT_IZQUIERDO_FBK, INPUT_PULLUP);
  pinMode(BUMPER_DERECHO_FBK, INPUT_PULLUP);
  pinMode(BUMPER_IZQUIERDO_FBK, INPUT_PULLUP);
  pinMode(BALL_RETURN_FBK, INPUT_PULLUP);
  
}


void loop() {
     // I  N  I  C  I  A     E  L     J  U  E  G  O
    // Paso 1: Disparo la bola por primera vez.
  if (BALL_RETURN_READY){
    if (ACTIVAR_BALL_RETURN()) {
      scoreInit();
    }else{
      IMPRIMIR("Error en el mecanismo: No se pudo disparar la bola");
  }
  else {
    IMPRIMIR("Ball return no está listo o disponible");
  }
  
  
  //Partida ya inició (bola en juego)
  if (BALL_RETURN_READY && tiempoInicioPartida) {    //la partida ya inició, detecto se perdio una vida

     // Reiniciar el tiempo de vida y reducir una vida
     vidas--;
    // Verificar si se han agotado todas las vidas
      if (vidas == 0) {
        duracionPartida = millis() - tiempoInicioPartida;
        scoreFinal();
      }
    }

  }
}
