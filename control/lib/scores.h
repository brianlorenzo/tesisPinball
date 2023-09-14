#include <lib/defines.h>

//FUNCIONES QUE UTILIZAMOS EN LA LOGICA DEL JUEGO:

// Función para manejar el final del juego.
void scoreFinal() {
  //round redondea, al imprimir usar (msg,0) para sacar los decimales.
  puntaje = round(duracionPartida / 1000 * PUNTOS_POR_SEG);      //Se calculan puntajes en la partida y no en cada vida.
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