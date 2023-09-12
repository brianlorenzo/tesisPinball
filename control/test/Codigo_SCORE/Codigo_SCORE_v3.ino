//CODIGO PARA CONTABILIZAR SCORE DURANTE LA PARTIDA
//Septiembre 2023

//Librerias de defines
#include <lib/defines.h>

//Inicializamos todos los tiempos en 0.
unsigned long tiempoInicioPartida = 0;                              // Tiempo en milisegundos en el que comenzó la partida.
unsigned long tiempoInicioVida = 0;                                 // Tiempo en milisegundos en el que comenzó la vida actual.
unsigned long duracionPartida = 0;
unsigned long duracionVida = 0;

//inicializamos variables que cambian a lo largo del juego.

int puntaje = 0;                                                   // Puntaje acumulado, inicializado en 0.
int vidas = 3;                                                     //Cantidad de vidas de cada "juego".
                                               
                                    
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

// I N I C I A   E L   J U E G O

// Paso 1: Disparo la bola por primera vez
if (BALL_RETURN_READY){
  if (//Activar mecanismo//) {
    //score_init();
      // llevar tiempos a 0
      // Inicializar las vidas (vidas = 3)
      // Inicializar el tiempo de partida 
    //
  }else{

     //No se pudo activar Mecanismo 
     //ERROR EN MECANISMO
  }
  
}else {
  
  //Ball return no está ready
  //La bola no está o no está siendo detectada en el ball return

  //ERROR EN DETECCIÓN DE BOLA
  
}









void loop() {
  
  // Verificar si está la bola para iniciar juego calcular la duración
  if (BALL_RETURN_READY) {
    
    tiempoInicioPartida = millis();        // Iniciar el tiempo de la partida
    tiempoInicioVida = millis();           // Iniciar el tiempo de la vida también
  } else {
   
   // Verificar si el sensor inductivo indica el retorno de la pelota
    if (BALL_RETURN_READY) {
      duracionVida = millis() - tiempoInicioVida; 
            
      puntaje += calcularPuntosPorVida(duracionVida);

      // Reiniciar el tiempo de vida y reducir una vida
      tiempoInicioVida = millis();
      vidas--;

    // Verificar si se han agotado todas las vidas
      if (vidas <= 0) {
        duracionPartida = millis() - tiempoInicioPartida;
        manejarFinDelJuego();
      }
    }
  }



}
//FUNCIONES QUE UTILIZAMOS EN LA LOGICA DEL JUEGO:

//------------------------------------------------------------------------
// Función para manejar el final del juego
void manejarFinDelJuego() {
  IMPRIMIR("-----------------Game Over-----------------");
  IMPRIMIR("-------Puntaje total de la partida:-------");
  IMPRIMIR(puntaje);
  IMPRIMIR("-------Duracion total de la partida:-------");
  // TO DO: Formatear tiempo de partida como (mm:ss) para imprimir
  IMPRIMIR(duracionPartida);
  
  
}
//-------------------------------------------------------------------------

// Función para calcular puntos en función de la duración de la vida
int calcularPuntosPorVida(unsigned long duracion) {
  //le agrego el int para que devuelva un entero
  return int(duracion / 1000.0 * PUNTOS_POR_SEG + 0.5);           //2 punto por cada segundo de vida   ||  1000.0 para devolver un int
}
//-------------------------------------------------------------------------

// Función para chequear el feedback en un pin dado                     //POSIBLE CON DEFINE--> y el bool ??
//bool checkFeedback(int pin) {
//  return digitalRead(pin) == LOW;                                       // LOW indica que se ha detectado feedback
//}
//-------------------------------------------------------------------------
