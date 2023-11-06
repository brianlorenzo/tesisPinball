#include <led.h>
#include <Adafruit_NeoPixel.h>

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
void blinkLED(int led, int ms, int times = 1){      
  for (int i = 0; i < times; i++) {
  digitalWrite(led, HIGH);
  delay(ms);
  digitalWrite(led, LOW);
  delay(ms);
  }
}
