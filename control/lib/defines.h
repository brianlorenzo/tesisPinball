//libreria con todas las definiciones de los codigos:

// Agregar: activarMecanismos o funcionesaux.h
//Definiciones del SCORE:

//Definicion de los puntajes
#define SCORE_F 20                                                 //Flippers dan 20pts
#define SCORE_S 15                                                 //Slingshots dan 15pts
#define SCORE_B 10                                                 //Pop Bumpers dan 10pts
#define SCORE_BR 5                                                 //Inicio de Partida de 5pts
#define PUNTOS_POR_SEG 2.0                                         //Puntos por segundo de vida

        
//Defino funciones
#define IMPRIMIR(msg) Serial.println(msg);                         
#define checkFeedback(int) digitalRead(int);



//----------------- F L I P P E R S ----------------- //
#define LED_STATUS_FLIPPER A0
#define FLIPPER_DERECHO 2
#define FLIPPER_DERECHO_FBK 8
//Nombre consola: FD
#define SERIAL_FLIPPER_DERECHO "FD"
//-----------------//-----------------//-----------------
#define FLIPPER_IZQUIERDO 3
#define FLIPPER_IZQUIERDO_FBK 9
#define IZQUIERDO 'I'
//Nombre consola: FI
#define SERIAL_FLIPPER_IZQUIERDO "FI"
//-----------------//-----------------//-----------------
//----------------- S L I N G S H O T S ----------------- //
#define LED_STATUS_SLINGSHOT 13
#define SLINGSHOT_DERECHO 4
#define SLINGSHOT_DERECHO_FBK 10
//Nombre consola: SD
#define SERIAL_SLINGSHOT_DERECHO "SD"
//-----------------//-----------------//-----------------
#define SLINGSHOT_IZQUIERDO 5
#define SLINGSHOT_IZQUIERDO_FBK 11
//Nombre consola: SI
#define SERIAL_SLINGSHOT_IZQUIERDO "SI"
//----------------- B U M P E R S ----------------- //
#define LED_STATUS_BUMPER 13
#define BUMPER_DERECHO 6
#define BUMPER_DERECHO_FBK 12
//Nombre consola: BD
#define SERIAL_BUMPER_DERECHO "BD"
//-----------------//-----------------//-----------------
#define BUMPER_IZQUIERDO 7
#define BUMPER_IZQUIERDO_FBK 13
//Nombre consola: BI
#define SERIAL_BUMPER_IZQUIERDO "BI"
//-----------------//-----------------//-----------------
//----------------- B A L L   R E T U R N  ----------------- //
#define LED_STATUS_BALL_RETURN 13
#define BALL_RETURN 12
#define BALL_RETURN_FBK 13
//Nombre consola: BR
#define SERIAL_BALL_RETURN "BR"
//-----------------//-----------------//-----------------


// Comandos de juego
#define ACTIVAR_FLIPPER_IZQUIERDO()     activarMecanismo(SERIAL_FLIPPER_IZQUIERDO)
#define ACTIVAR_FLIPPER_DERECHO()       activarMecanismo(SERIAL_FLIPPER_DERECHO)
#define ACTIVAR_SLINGSHOT_IZQUIERDO()   activarMecanismo(SERIAL_SLINGSHOT_IZQUIERDO)
#define ACTIVAR_SLINGSHOT_DERECHO()     activarMecanismo(SERIAL_SLINGSHOT_DERECHO)
#define ACTIVAR_BUMPER_DERECHO()        activarMecanismo(SERIAL_BUMPER_DERECHO)
#define ACTIVAR_BUMPER_IZQUIERDO()      activarMecanismo(SERIAL_BUMPER_IZQUIERDO)
#define ACTIVAR_BALL_RETURN()           activarMecanismo(SERIAL_BALL_RETURN)

#define BALL_RETURN_READY digitalRead(BALL_RETURN_FBK)
//  Si el pin está en 1: sensor inductivo activo (la bola está ahí)
//  Si el pin está en 0: sensor inductivo inactivo (la bola NO está ahí)


// Comandos generales
#define MEC_STANDBY 0
#define MEC_ACTIVO  1
#define MEC_ERROR   2


// L E D   I N T E R N O
#define LED_INTERNO 18 // El pin al que está conectado el LED RGB
#define LED_STATUS_MECANISMOS LED_BUILTIN

// Parámetros de configuración del LED RGB
#define NUM_PIXELS 1 // Número de LEDs en la tira (en este caso, solo uno)
#define BRIGHTNESS 50 // Brillo (ajusta según tus preferencias)

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