//CODIGO PARA CONTABILIZAR SCORE DURANTE LA PARTIDA
//Septiembre 2023

//Inicializamos todos los tiempos en 0.
unsigned long tiempoInicioPartida = 0;                              // Tiempo en milisegundos en el que comenzó la partida.
unsigned long tiempoInicioVida = 0;                                 // Tiempo en milisegundos en el que comenzó la vida actual.
unsigned long duracionPartida = 0;
unsigned long duracionVida = 0;

//inicializamos variables que cambian a lo largo del juego.

int puntaje = 0;                                                   // Puntaje acumulado, inicializado en 0.
int vidas = 3;                                                     //Cantidad de vidas de cada "juego".
                                               
#define SENSORPIN 1                                                //Pin de entrada del sensor de proximidad inductivo

#define SCORE_F 20                                                 //Flippers dan 20pts
#define SCORE_S 15                                                 //Slingshots dan 15pts
#define SCORE_B 10                                                 //Pop Bumpers dan 10pts
#define SCORE_BR 5                                                 //Inicio de Partida de 5pts
#define PUNTOS_POR_SEG 2                                           //Puntos por segundo de vida


//Defino los pines de feedback de los mecanismos.                  //Tomados del codigo original
#define FLIPPER_DERECHO_FBK 8
#define FLIPPER_IZQUIERDO_FBK 9
#define SLINGSHOT_DERECHO_FBK 10
#define SLINGSHOT_IZQUIERDO_FBK 11
#define BUMPER_DERECHO_FBK 12
#define BUMPER_IZQUIERDO_FBK 13
#define BALL_RETURN_FBK 13
        

#define IMPRIMIR(msg) Serial.println(msg);                         
#define checkFeedback(int) digitalRead(int);

void setup() {
  Serial.begin(9600);
  pinMode(SENSORPIN, INPUT_PULLUP);       
  
  pinMode(FLIPPER_DERECHO_FBK, INPUT_PULLUP);
  pinMode(FLIPPER_IZQUIERDO_FBK, INPUT_PULLUP);
  pinMode(SLINGSHOT_DERECHO_FBK, INPUT_PULLUP);      
  pinMode(SLINGSHOT_IZQUIERDO_FBK, INPUT_PULLUP);
  pinMode(BUMPER_DERECHO_FBK, INPUT_PULLUP);
  pinMode(BUMPER_IZQUIERDO_FBK, INPUT_PULLUP);
  pinMode(BALL_RETURN_FBK, INPUT_PULLUP);
}

void loop() {
  
  
  // Verificar si la partida ha comenzado y calcular la duración
  if (tiempoInicioPartida == 0) {
    tiempoInicioPartida = millis();        // Iniciar el tiempo de la partida
    tiempoInicioVida = millis();           // Iniciar el tiempo de la vida también
  } else {
   
   // Verificar si el sensor inductivo indica el retorno de la pelota
    if (digitalRead(SENSORPIN) == HIGH) {
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
