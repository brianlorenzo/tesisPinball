#include <led.h>
#include <Adafruit_NeoPixel.h>
#include <asignaciones.h>

// Parámetros de configuración del LED RGB de ESP32
#define NUM_PIXELS  1   // Número de LEDs en la tira (en este caso, solo uno)
#define BRIGHTNESS  50  // Brillo (0-255)
#define PIXEL_INDEX 0   // En ESP32 está el Neopixel interno 0
#define LED_INTERNO 18  // Pin donde se conecta internamente al Led RGB


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


// Define la variable para LED Neopixel
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, LED_INTERNO, NEO_GRB + NEO_KHZ800);

// Inicializa el LED de ESP y lo prende
void ledSetup(){
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Inicialmente, apagar el LED RGB
}

// Pone el LED RGB en un color asignado al mecanismo pasado como string
// (los colores se definen en led.h como COLOR_RED)
// --> podría cambiarse a un switchcase
void setLED(String mecanismo) {
  if (mecanismo == SERIAL_FLIPPER_DERECHO) {
    strip.setPixelColor(0, COLOR_RED);
  } else if (mecanismo == SERIAL_FLIPPER_IZQUIERDO) {
    strip.setPixelColor(0, COLOR_GREEN);
  } else if (mecanismo == SERIAL_SLINGSHOT_IZQUIERDO) {
    strip.setPixelColor(0, COLOR_YELLOW);
  } else if (mecanismo == SERIAL_SLINGSHOT_DERECHO) {
    strip.setPixelColor(0, COLOR_BLUE);
  } else if (mecanismo == SERIAL_BUMPER_DERECHO) {
    strip.setPixelColor(0, COLOR_WHITE);
  } else if (mecanismo == SERIAL_BUMPER_IZQUIERDO) {
    strip.setPixelColor(0, COLOR_ORANGE);
  } else if (mecanismo == SERIAL_BALL_RETURN) {
    strip.setPixelColor(0, COLOR_PURPLE);
  } else {
    // Si el color no es uno de los especificados, apagar el LED
    strip.setPixelColor(0, strip.Color(255, 255, 255));
    //strip.setPixelColor(0, COLOR_LED_OFF);
  }

  strip.show(); // Actualizar el LED RGB con el color seleccionado
}

// Hace blink de un led por determinados ms "times" veces (por defecto 1 vez)
// sirve para un pin y no para el led RGB de Neopixel
void blinkLED(int led, int ms, int times){      
  for (int i = 0; i < times; i++) {
  digitalWrite(led, HIGH);
  delay(ms);
  digitalWrite(led, LOW);
  delay(ms);
  }
}
