// - - CONTABILIZACION DEL SCORE DURANTE LA PARTIDA - -
//LOS PUNTOS SE OBTIENEN POR ACCION DE MECANISMOS Y POR DURACION DE LA PARTIDA.
//SE UTILIZAN LA FUNCION updateScore() Y SE CUENTA LA DURACION DE LA PARTIDA, AL FINAL DE LA MISMA.


//Librerias a incluir
#include <defines.h>                                            //Tiene todos los defines locales y globales.
#include <scores.h>                                             //Tiene las funciones que usamos en el conteo del SCORE.


//DECLARAMOS VARIABLES GLOBALES
unsigned long tiempoInicioPartida;                              // Tiempo en milisegundos en el que comenzó la partida.                              // Tiempo en milisegundos en el que comenzó la vida actual.
unsigned long duracionPartida;
unsigned long puntaje;                                                   // Varible usada para ir contando los puntos de la partida.
int vidas;                                                     //Cantidad de vidas de cada "juego".
char log[12];                                     
                                    
void setup() {
  //Configuraciones necesarias para el microprocesador:
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
    //Se chequea que la pelota esta lista, y se chequea el disparo. 
    //Hay dos errores posibles.
  if (BALL_RETURN_READY){
    if (ACTIVAR_BALL_RETURN()) {
      scoreInit();
    }else{
      IMPRIMIR("Error en el mecanismo: No se pudo disparar la bola");
  }
  else {
    IMPRIMIR("Ball return no está listo o no disponible");
  }
  
  //Paso 2: Iniciar la segunda y tercera vida.  
  //Partida ya inició, la bola está en juego.
  if (BALL_RETURN_READY && tiempoInicioPartida) {             //la partida ya inició, detecto se perdio una vida.
     vidas--;
    // Verificar si se han agotado todas las vidas.
      if (vidas == 0) {
        duracionPartida = millis() - tiempoInicioPartida;     //Calculo el tiempo final de la partida.
        scoreFinal();                                         //Se llama a scoreFinal, que cierra el juego.
      }
    }

  }
}
