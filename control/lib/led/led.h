#ifndef _LED_H
#define _LED_H

#include <Adafruit_NeoPixel.h>

#define LED_STATUS_MECANISMOS LED_BUILTIN
//Esta asignacion la usan otras funciones
//por eso está en el .h y no en el .cpp


void blinkLED(int led, int ms, int times);
void setLED(String mecanismo);
void ledSetup();

#endif