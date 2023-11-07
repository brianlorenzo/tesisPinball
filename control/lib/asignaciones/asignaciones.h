// Contiene solo #defines para identificar cada mecanismo
// con su pin de conexión correspondiente
#ifndef _ASIGNACIONES_H
#define _ASIGNACIONES_H

//----------------- M E C A N I S M O S ----------------- //
#define FLIPPER_DERECHO     3 
#define FLIPPER_IZQUIERDO   4

#define SLINGSHOT_DERECHO   5
#define SLINGSHOT_IZQUIERDO 6

#define BUMPER_DERECHO      7
#define BUMPER_IZQUIERDO    8

#define BALL_RETURN         9

//----------------- F E E D B A C K  ----------------- //
#define FLIPPER_DERECHO_FBK     14
#define FLIPPER_IZQUIERDO_FBK   12

#define SLINGSHOT_DERECHO_FBK   16
#define SLINGSHOT_IZQUIERDO_FBK 11

#define BUMPER_DERECHO_FBK      15
#define BUMPER_IZQUIERDO_FBK    13

#define BALL_RETURN_FBK         17

//----------------- C O M A N D O   S E R I A L  ----------------- //
#define SERIAL_FLIPPER_DERECHO      "FD"
#define SERIAL_FLIPPER_IZQUIERDO    "FI"

#define SERIAL_SLINGSHOT_DERECHO    "SD"
#define SERIAL_SLINGSHOT_IZQUIERDO  "SI"

#define SERIAL_BUMPER_DERECHO       "BD"
#define SERIAL_BUMPER_IZQUIERDO     "BI"

#define SERIAL_BALL_RETURN          "BR"

#endif