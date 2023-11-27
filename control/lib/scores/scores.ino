#include <defines.h>


unsigned long puntaje;
int vidas;
unsigned long tiempoInicioPartida;
unsigned long duracionPartida;
char log[12];



//FUNCIONES QUE UTILIZAMOS EN LA LOGICA DEL JUEGO:

// Función para manejar el final del juego.
void scoreFinal(unsigned long duracionPartida) {
  //round redondea, al imprimir usar (msg,0) para sacar los decimales.
  puntaje = round(duracionPartida / 1000 * PUNTOS_POR_SEG);      //Se calculan puntajes en la partida y no en cada vida.
  IMPRIMIR("-----------------Game Over-----------------");
  IMPRIMIR("-------Puntaje total de la partida:-------");
  IMPRIMIR(puntaje);
  IMPRIMIR("-------Duracion total de la partida:-------");
  convierteTiempo(duracionPartida, log);
  Serial.println(log);
  //IMPRIMIR(log);
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

void convierteTiempo(unsigned long tiempoEnMillis, char* resultado) {
  unsigned long segundos = (tiempoEnMillis / 1000) % 60;
  unsigned long minutos = (tiempoEnMillis / (60000)) % 60;
  unsigned long horas = (tiempoEnMillis / (60000 * 60));

  // Formatea la duración en "hh:mm:ss"
  sprintf(resultado, "%02lu:%02lu:%02lu", horas, minutos, segundos);
}
