//libreria con todas las definiciones de los codigos:
#ifndef _DEFINES_H
#define _DEFINES_H

#include <asignaciones.h>
#include <led.h>

//Definicion de los puntajes
#define SCORE_F 20              //Flippers dan 20pts
#define SCORE_S 15              //Slingshots dan 15pts
#define SCORE_B 10              //Pop Bumpers dan 10pts
#define SCORE_BR 5              //Inicio de Partida de 5pts
#define PUNTOS_POR_SEG 2.0      //Puntos por segundo de vida
 
//Defino funciones auxiliares

//Imprime en serial siguiente línea
#define IMPRIMIR(msg) Serial.println(msg);                         

// Definimos estado de los mecanismos para chequear feedback
#define FLIPPER_DERECHO_ACTIVO      digitalRead(FLIPPER_DERECHO_FBK)
#define FLIPPER_IZQUIERDO_ACTIVO    digitalRead(FLIPPER_IZQUIERDO_FBK)
#define SLINGSHOT_DERECHO_ACTIVO    digitalRead(SLINGSHOT_DERECHO_FBK)
#define SLINGSHOT_IZQUIERDO_ACTIVO  digitalRead(SLINGSHOT_IZQUIERDO_FBK)
#define BUMPER_DERECHO_ACTIVO       digitalRead(BUMPER_DERECHO_FBK)
#define BUMPER_IZQUIERDO_ACTIVO     digitalRead(BUMPER_IZQUIERDO_FBK)
#define BALL_RETURN_ACTIVO          digitalRead(BALL_RETURN_FBK)
//  Si el pin está en 1: sensor inductivo activo (la bola está ahí)
//  Si el pin está en 0: sensor inductivo inactivo (la bola NO está ahí)

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
/*
#define MEC_STANDBY 0
#define MEC_ACTIVO  1
#define MEC_ERROR   2
*/

// Chequea FBK, imprime por serial resultado
void chequeoFBK(int PIN_MECANISMO_FBK);

//Configura pines como entrada y salida
void pinConfig();


#endif
