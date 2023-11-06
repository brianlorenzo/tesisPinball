#ifndef LED_H_
#define LED_H_
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip;

// Parámetros de configuración del LED RGB de ESP32
#define NUM_PIXELS  1   // Número de LEDs en la tira (en este caso, solo uno)
#define BRIGHTNESS  50  // Brillo (0-255)
#define PIXEL_INDEX 0   // En ESP32 está el Neopixel interno 0
#define LED_INTERNO 18  // Pin donde se conecta internamente al Led RGB

#define LED_STATUS_MECANISMOS LED_BUILTIN

// Define las constantes para los colores
// strip.color toma valores RGB y lo transforma 
// en un 32-bit RGB que precisa las funciones como setPixelColor()
#define COLOR_RED       strip.Color(255, 0, 0)
#define COLOR_GREEN     strip.Color(0, 255, 0)
#define COLOR_YELLOW    strip.Color(255, 255, 0)
#define COLOR_BLUE      strip.Color(0, 0, 255)
#define COLOR_WHITE     strip.Color(255, 255, 255)
#define COLOR_ORANGE    strip.Color(255, 165, 0)
#define COLOR_PURPLE    strip.Color(128, 0, 128)
#define COLOR_LED_OFF   strip.Color(0, 0, 0) 

#define OFF "OFF"

void blinkLED(int led, int ms, int times = 1);
void setLED(String mecanismo);
void ledSetup();

#endif