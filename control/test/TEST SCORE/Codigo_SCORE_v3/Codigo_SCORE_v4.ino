//CODIGO PARA CONTABILIZAR SCORE DURANTE LA PARTIDA
//Septiembre 2023

//Libreria de defines
#include <defines.h>

//DECLARAMOS VARIABLES GLOBALES
unsigned long tiempoInicioPartida;                              // Tiempo en milisegundos en el que comenzó la partida.                              // Tiempo en milisegundos en el que comenzó la vida actual.
unsigned long duracionPartida;
int puntaje;                                                   // Puntaje acumulado, inicializado en 0.
int vidas;                                                     //Cantidad de vidas de cada "juego".


//FUNCIONES QUE UTILIZAMOS EN LA LOGICA DEL JUEGO:

// Función para manejar el final del juego
void scoreFinal() {
  puntaje = duracionPartida / 1000.0 * PUNTOS_POR_SEG + 0.5;      //Se calculan puntajes en la partida y no en cada vida.
  IMPRIMIR("-----------------Game Over-----------------");
  IMPRIMIR("-------Puntaje total de la partida:-------");
  IMPRIMIR(puntaje);
  IMPRIMIR("-------Duracion total de la partida:-------");
  // TO DO: Formatear tiempo de partida como (mm:ss) para imprimir
  IMPRIMIR(duracionPartida);
  
}


void scoreInit(){
  //Inicializamos todos los tiempos en 0.
  tiempoInicioPartida = 0;                              // Tiempo en milisegundos en el que comenzó la partida.                            // Tiempo en milisegundos en el que comenzó la vida actual.
  duracionPartida = 0;
  //Seteamos la cantidad de vidas y reseteamos el puntaje:
  vidas = 3;
  puntaje = 0;
  tiempoInicioPartida = millis();

}

//ScoreUpdate asume recibe string con mecanismos validos
void scoreUpdate(String mecanismo){
  if (mecanismo == SERIAL_FLIPPER_DERECHO || mecanismo == SERIAL_FLIPPER_IZQUIERDO){
    puntaje = puntaje + SCORE_F;
  }
  else if(mecanismo == SERIAL_BUMPER_DERECHO || mecanismo == SERIAL_BUMPER_IZQUIERDO){
    puntaje = puntaje + SCORE_B;
  }
  else if(mecanismo == SERIAL_SLINGSHOT_DERECHO || mecanismo == SERIAL_SLINGSHOT_IZQUIERDO){
    puntaje = puntaje + SCORE_S;
  }
  else {
    puntaje = puntaje + SCORE_BR;
  }
}                                               
                                    
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
  if (BALL_RETURN_ACTIVO){
    if (ACTIVAR_BALL_RETURN()) {
      scoreInit();
    }else{
      IMPRIMIR("Error en el mecanismo: No se pudo disparar la bola");
  }
  else {
    IMPRIMIR("Ball return no está listo o disponible");
  }
  
  
  //Partida ya inició (bola en juego)
  if (BALL_RETURN_ACTIVO && tiempoInicioPartida) {    //la partida ya inició, detecto se perdio una vida

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
