
#define BOTON 17
#define LED 18

#include <Adafruit_NeoPixel.h>

// Parámetros de configuración del LED RGB
#define NUM_PIXELS 1 // Número de LEDs en la tira (en este caso, solo uno)
#define BRIGHTNESS 50 // Brillo (ajusta según tus preferencias)

//Inicializa el LED Neopixel
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, LED, NEO_GRB + NEO_KHZ800);

// Define las constantes para los colores
#define COLOR_RED strip.Color(255, 0, 0)
#define COLOR_PURPLE strip.Color(128, 0, 128)


void setup() {
  // put your setup code here, to run once:
  strip.setPixelColor(0, COLOR_RED);
  strip.show();

  delay(5000);
  pinMode(BOTON,INPUT);
  pinMode(LED,OUTPUT);

  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Inicialmente, apagar el LED RGB

  Serial.begin(9600);
  
}




void loop() {
  
  if (digitalRead(BOTON) == HIGH){
    
     strip.setPixelColor(0, COLOR_PURPLE);
     strip.show();
     Serial.println("Boton apretado");
    
    }else{
     Serial.println("Boton NO apretado");
     strip.setPixelColor(0, COLOR_RED);
     strip.show();
    }
  
  // put your main code here, to run repeatedly:

}
